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
    FunctionOperator::FunctionOperator(const std::vector<AbstractExpression *> &expressions)
            : _expressions(expressions) {}

    auto FunctionOperator::getExpressions() const -> const std::vector<AbstractExpression *> & {
        return _expressions;
    }

    FunctionOperator::~FunctionOperator() {
        for (const auto &expression: _expressions) {
            delete expression;
        }
    }

    auto FunctionOperator::dump() const -> std::string {
        return "()";
    }

    auto FunctionOperator::dumpPreLambdaType(AbstractType *return_type,
                                             AbstractType *called_on,
                                             filc::environment::Environment *environment,
                                             filc::message::MessageCollector *collector,
                                             filc::utils::Position *position) const -> LambdaType * {
        collector->addError(new filc::message::DevWarning(
                3,
                position,
                "FunctionOperator::dumpPreLambdaType should not be called but has been called"
        ));

        return nullptr;
    }

    auto FunctionOperator::dumpPostLambdaType(AbstractType *return_type,
                                              AbstractType *called_on,
                                              filc::environment::Environment *environment,
                                              filc::message::MessageCollector *collector,
                                              filc::utils::Position *position) const -> LambdaType * {
        std::vector<AbstractType *> args_types;
        for (const auto &expression: _expressions) {
            expression->resolveType(environment, collector, nullptr);
            auto *expression_type = expression->getExpressionType();
            if (expression_type != nullptr) {
                args_types.push_back(expression_type);
            }
        }
        if (args_types.size() != _expressions.size()) {
            return nullptr;
        }

        return new LambdaType(args_types, return_type, called_on);
    }
}