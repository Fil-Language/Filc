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
    While::While(filc::ast::AbstractExpression *condition, const std::vector<AbstractExpression *> &body)
            : _condition(condition), _body(body) {}

    auto While::getCondition() const -> AbstractExpression * {
        return _condition;
    }

    auto While::getBody() const -> const std::vector<AbstractExpression *> & {
        return _body;
    }

    While::~While() {
        delete _condition;
        for (const auto &expression: _body) {
            delete expression;
        }
    }

    auto While::resolveType(filc::environment::Environment *environment,
                            filc::message::MessageCollector *collector,
                            AbstractType *preferred_type) -> void {
        _condition->resolveType(environment, collector, environment->getType("bool"));
        auto *condition_type = _condition->getExpressionType();
        if (condition_type == nullptr) {
            return;
        }
        if (*condition_type != *environment->getType("bool")) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    "Condition must return bool, found: " + condition_type->dump(),
                    _condition->getPosition()
            ));
            return;
        }

        AbstractType *body_type = nullptr;
        for (auto iter = _body.begin(); iter != _body.end(); iter++) {
            (*iter)->resolveType(environment, collector);
            if (iter + 1 == _body.end()) {
                body_type = (*iter)->getExpressionType();
            }
        }
        if (body_type == nullptr) {
            return;
        }

        setExpressionType(new PointerType(body_type));
    }
}