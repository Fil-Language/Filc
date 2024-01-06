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
    BinaryCalcul::BinaryCalcul(AbstractExpression *left_expression, Operator *p_operator,
                               AbstractExpression *right_expression)
            : _left_expression(left_expression), _right_expression(right_expression), _operator(p_operator),
              _binary_type(nullptr) {}

    auto BinaryCalcul::getLeftExpression() const -> AbstractExpression * {
        return _left_expression;
    }

    auto BinaryCalcul::getRightExpression() const -> AbstractExpression * {
        return _right_expression;
    }

    auto BinaryCalcul::getOperator() const -> Operator * {
        return _operator;
    }

    BinaryCalcul::~BinaryCalcul() = default;

    auto BinaryCalcul::resolveType(filc::environment::Environment *environment,
                                   filc::message::MessageCollector *collector,
                                   const std::shared_ptr<AbstractType> &preferred_type) -> void {
        _left_expression->resolveType(environment, collector, nullptr);
        auto left_type = _left_expression->getExpressionType();
        _right_expression->resolveType(environment, collector, nullptr);
        auto right_type = _right_expression->getExpressionType();
        if (left_type == nullptr || right_type == nullptr) {
            return;
        }

        auto operator_name = "operator" + _operator->dump();
        auto has_found_preferred = false;
        auto has_found_left = false;
        std::shared_ptr<LambdaType> preferred_lambda;
        std::shared_ptr<LambdaType> left_lambda;
        if (dynamic_cast<AssignationOperator *>(_operator) != nullptr) {
            auto ptr_left = std::make_shared<PointerType>(left_type);
            preferred_lambda = std::make_shared<LambdaType>(
                    std::vector<std::shared_ptr<AbstractType>>({ptr_left, right_type}), preferred_type);
            has_found_preferred = preferred_type != nullptr && environment->hasName(
                    operator_name,
                    preferred_lambda
            );
            left_lambda = std::make_shared<LambdaType>(
                    std::vector<std::shared_ptr<AbstractType>>({ptr_left, right_type}), left_type);
            has_found_left = environment->hasName(
                    operator_name,
                    left_lambda
            );
        } else {
            preferred_lambda = std::make_shared<LambdaType>(
                    std::vector<std::shared_ptr<AbstractType>>({left_type, right_type}), preferred_type);
            has_found_preferred = preferred_type != nullptr && environment->hasName(
                    operator_name,
                    preferred_lambda
            );
            left_lambda = std::make_shared<LambdaType>(
                    std::vector<std::shared_ptr<AbstractType>>({left_type, right_type}), left_type);
            has_found_left = environment->hasName(
                    operator_name,
                    left_lambda
            );
        }
        if ((preferred_type != nullptr && (!has_found_preferred || !has_found_left)) || !has_found_left) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR,
                                             "There is no operator " + getOperator()->dump() +
                                             " for types " + left_type->dump() + " and " + right_type->dump(),
                                             getPosition())
            );
            return;
        }

        _binary_type = has_found_preferred ? preferred_lambda : left_lambda;
        setExpressionType(has_found_preferred ? preferred_type : left_type);
    }

    auto BinaryCalcul::generateIR(filc::message::MessageCollector *collector,
                                  filc::environment::Environment *environment,
                                  llvm::LLVMContext *context,
                                  llvm::Module *module,
                                  llvm::IRBuilder<> *builder) const -> llvm::Value * {
        auto operator_name = "operator" + getOperator()->dump();
        auto *name = environment->getName(operator_name, _binary_type);
        auto *function = name->getFunction();
        if (function == nullptr) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    "LLVM function for " + operator_name + ": " + _binary_type->dump() + " not implemented",
                    getPosition()
            ));
            return nullptr;
        }
        auto *left_value = _left_expression->generateIR(collector, environment, context, module, builder);
        auto *right_value = _right_expression->generateIR(collector, environment, context, module, builder);
        if (left_value == nullptr || right_value == nullptr) {
            return nullptr;
        }

        return builder->CreateCall(function, {left_value, right_value});
    }
}
