/**
 * MIT License
 *
 * Copyright (c) 2023-Present Kevin Traini
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <utility>
#include "AST.h"
#include "Error.h"
#include "llvm/IR/Verifier.h"

namespace filc::ast {
    int Lambda::name_index = 0;

    Lambda::Lambda(const std::vector<FunctionParameter *> &parameters, std::shared_ptr<AbstractType> return_type,
                   const std::vector<AbstractExpression *> &body)
            : _parameters(parameters), _return_type(std::move(return_type)), _body(body), _body_environment(nullptr) {}

    auto Lambda::getParameters() const -> const std::vector<FunctionParameter *> & {
        return _parameters;
    }

    auto Lambda::getReturnType() const -> std::shared_ptr<AbstractType> {
        return _return_type;
    }

    auto Lambda::getBody() const -> const std::vector<AbstractExpression *> & {
        return _body;
    }

    auto Lambda::getBodyEnvironment() const -> filc::environment::Environment * {
        return _body_environment;
    }

    Lambda::~Lambda() {
        for (const auto &parameter: _parameters) {
            delete parameter;
        }
        for (const auto &expression: _body) {
            delete expression;
        }
    }

    auto Lambda::resolveType(filc::environment::Environment *environment,
                             filc::message::MessageCollector *collector,
                             const std::shared_ptr<AbstractType> &preferred_type) -> void {
        _body_environment = new filc::environment::Environment("", environment);

        std::vector<std::shared_ptr<AbstractType>> parameters_types;
        for (const auto &parameter: _parameters) {
            auto parameter_type = parameter->getType();
            auto *parameter_name = parameter->getName();
            if (_body_environment->hasName(parameter_name->getName(), nullptr)) {
                collector->addError(new filc::message::Error(
                        filc::message::ERROR,
                        "Name " + parameter_name->getName() + " is already defined",
                        getPosition()
                ));
                return;
            }
            _body_environment->addName(parameter_name->getName(), parameter_type);
            parameters_types.push_back(parameter_type);
        }

        std::shared_ptr<AbstractType> body_type = nullptr;
        for (auto iter = _body.begin(); iter != _body.end(); iter++) {
            if (iter + 1 != _body.end()) {
                (*iter)->resolveType(_body_environment, collector, nullptr);
            } else {
                (*iter)->resolveType(_body_environment, collector, _return_type);
                body_type = (*iter)->getExpressionType();
            }
        }
        if (body_type == nullptr) {
            return;
        }
        if (*body_type != *_return_type) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    "Lambda return type and body type are not equivalent: "
                    + _return_type->dump() + " and " + body_type->dump(),
                    getPosition()
            ));
            return;
        }

        setExpressionType(std::make_shared<LambdaType>(parameters_types, _return_type));
    }

    auto Lambda::generateIR(filc::message::MessageCollector *collector,
                            filc::environment::Environment *environment,
                            llvm::LLVMContext *context,
                            llvm::Module *module,
                            llvm::IRBuilder<> *builder) const -> llvm::Value * {
        std::vector<llvm::Type *> parameters_types;
        for (const auto &parameter: _parameters) {
            parameters_types.push_back(parameter->getType()->getLLVMType());
        }

        auto *function_type = llvm::FunctionType::get(_return_type->getLLVMType(), parameters_types, false);
        auto function_name = "anonymous_" + environment->getModule() + "_" + std::to_string(Lambda::name_index++);
        auto *function = llvm::Function::Create(function_type, llvm::Function::ExternalLinkage, function_name, module);

        unsigned int nb_arg = 0;
        for (auto &arg: function->args()) {
            _body_environment->getName(_parameters[nb_arg]->getName()->getName(), nullptr)->setValue(&arg);
            arg.setName(_parameters[nb_arg]->getName()->getName());
            nb_arg++;
        }

        auto *block = llvm::BasicBlock::Create(*context, "entry", function);
        builder->SetInsertPoint(block);

        for (auto iter = _body.begin(); iter != _body.end(); iter++) {
            if (iter + 1 != _body.end()) {
                if ((*iter)->generateIR(collector, _body_environment, context, module, builder) == nullptr) {
                    function->eraseFromParent();
                    return nullptr;
                }
            } else {
                if (auto *ret = (*iter)->generateIR(collector, _body_environment, context, module, builder)) {
                    builder->CreateRet(ret);
                    llvm::verifyFunction(*function);

                    return function;
                }
            }
        }

        function->eraseFromParent();
        return nullptr;
    }
}
