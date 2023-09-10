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
    BinaryCalcul::BinaryCalcul(filc::ast::AbstractExpression *left_expression, filc::ast::Operator *p_operator,
                               filc::ast::AbstractExpression *right_expression)
            : _left_expression(left_expression), _right_expression(right_expression), _operator(p_operator) {}

    auto BinaryCalcul::getLeftExpression() const -> AbstractExpression * {
        return _left_expression;
    }

    auto BinaryCalcul::getRightExpression() const -> AbstractExpression * {
        return _right_expression;
    }

    auto BinaryCalcul::getOperator() const -> Operator * {
        return _operator;
    }

    BinaryCalcul::~BinaryCalcul() {
        delete _left_expression;
        delete _operator;
        delete _right_expression;
    }

    auto BinaryCalcul::resolveType(filc::environment::Environment *environment,
                                   filc::message::MessageCollector *collector,
                                   AbstractType *preferred_type) -> void {
        _left_expression->resolveType(environment, collector);
        auto *left_type = _left_expression->getExpressionType();
        _right_expression->resolveType(environment, collector);
        auto *right_type = _right_expression->getExpressionType();
        if (left_type == nullptr || right_type == nullptr) {
            return;
        }

        auto operator_name = "operator" + _operator->dump();
        auto has_found_preferred = preferred_type != nullptr &&
                                   environment->hasName(operator_name,
                                                        new LambdaType({left_type, right_type}, preferred_type));
        auto has_found_left = environment->hasName(operator_name, new LambdaType({left_type, right_type}, left_type));
        if ((preferred_type != nullptr && (!has_found_preferred || !has_found_left)) || !has_found_left) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR,
                                             "There is no operator " + getOperator()->dump() +
                                             " for types " + left_type->dump() + " and " + right_type->dump(),
                                             getPosition())
            );
            return;
        }

        setExpressionType(has_found_preferred ? preferred_type : left_type);
    }
}
