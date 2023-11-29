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
#include "DevWarning.h"

namespace filc::ast {
    ArrayOperator::ArrayOperator(filc::ast::AbstractExpression *expression)
            : _expression(expression) {}

    auto ArrayOperator::getExpression() const -> AbstractExpression * {
        return _expression;
    }

    ArrayOperator::~ArrayOperator() {
        delete _expression;
    }

    auto ArrayOperator::dump() const -> std::string {
        return "[]";
    }

    auto ArrayOperator::dumpPreLambdaType(std::shared_ptr<AbstractType> type,
                                          filc::environment::Environment *environment,
                                          filc::message::MessageCollector *collector,
                                          filc::utils::AbstractPosition *position) const -> std::shared_ptr<LambdaType> {
        collector->addError(new filc::message::DevWarning(
                3,
                position,
                "ArrayOperator::dumpPreLambdaType should not be called but has been called"
        ));

        return nullptr;
    }

    auto ArrayOperator::dumpPostLambdaType(std::shared_ptr<AbstractType> type,
                                           filc::environment::Environment *environment,
                                           filc::message::MessageCollector *collector,
                                           filc::utils::AbstractPosition *position) const -> std::shared_ptr<LambdaType> {
        _expression->resolveType(environment, collector, nullptr);
        auto expression_type = _expression->getExpressionType();
        if (expression_type == nullptr) {
            return nullptr;
        }

        return std::make_shared<LambdaType>(std::vector<std::shared_ptr<AbstractType>>({expression_type}),
                                            type->getInnerType());
    }
}
