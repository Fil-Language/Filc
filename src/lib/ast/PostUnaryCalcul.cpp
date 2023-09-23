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
#include "AST.h"
#include "Error.h"

namespace filc::ast {
    PostUnaryCalcul::PostUnaryCalcul(filc::ast::Identifier *variable, filc::ast::Operator *p_operator)
            : UnaryCalcul(variable, p_operator) {}

    auto PostUnaryCalcul::resolveType(filc::environment::Environment *environment,
                                      filc::message::MessageCollector *collector,
                                      const std::shared_ptr<AbstractType> &preferred_type) -> void {
        getVariable()->resolveType(environment, collector, nullptr);
        auto variable_type = getVariable()->getExpressionType();
        if (variable_type == nullptr) {
            return;
        }

        if (dynamic_cast<PointerType *>(variable_type.get()) != nullptr
            && dynamic_cast<ArrayOperator *>(getOperator()) != nullptr) {
            setExpressionType(variable_type->getInnerType());
            return;
        }

        auto operator_name = "operator" + getOperator()->dump();
        auto operator_type = getOperator()->dumpPostLambdaType(variable_type, environment, collector, getPosition());
        if (environment->getName(operator_name, operator_type) == nullptr) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR,
                                             "There is no operator " + getOperator()->dump() +
                                             " for type " + variable_type->dump(),
                                             getPosition())
            );
            return;
        }

        setExpressionType(operator_type->getReturnType());
    }

    auto PostUnaryCalcul::generateIR(filc::message::MessageCollector *collector,
                                     filc::environment::Environment *environment,
                                     llvm::LLVMContext *context,
                                     llvm::Module *module,
                                     llvm::IRBuilder<> *builder) const -> llvm::Value * {
        auto operator_name = "operator" + getOperator()->dump();
        auto variable_type = getVariable()->getExpressionType();
        auto operator_type = getOperator()->dumpPostLambdaType(variable_type, environment, collector, getPosition());

        auto *function = environment->getName(operator_name, operator_type)->getFunction();
        if (function == nullptr) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    "LLVM function for " + operator_name + ": " + operator_type->dump() + " not implemented",
                    getPosition()
            ));
            return nullptr;
        }
        auto *variable = getVariable()->generateIR(collector, environment, context, module, builder);
        if (variable == nullptr) {
            return nullptr;
        }

        return builder->CreateCall(function, {variable});
    }
}
