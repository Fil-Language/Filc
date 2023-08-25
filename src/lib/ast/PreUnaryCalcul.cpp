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
    PreUnaryCalcul::PreUnaryCalcul(filc::ast::Identifier *variable, filc::ast::Operator *p_operator)
            : UnaryCalcul(variable, p_operator) {}

    auto PreUnaryCalcul::resolveType(filc::environment::Environment *environment,
                                     filc::message::MessageCollector *collector) -> void {
        _variable->resolveType(environment, collector);
        auto *variable_type = _variable->getExpressionType();
        if (variable_type == nullptr) {
            return;
        }

        auto operator_name = "operator" + _operator->dump();
        if (environment->getName(operator_name, new LambdaType({}, variable_type)) == nullptr) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR,
                                             "There is no operator " + _operator->dump() +
                                             " for type " + variable_type->dump(),
                                             getPosition())
            );
            return;
        }

        setExpressionType(variable_type);
    }
}
