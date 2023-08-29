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
    ForI::ForI(filc::ast::VariableDeclaration *declaration, filc::ast::AbstractExpression *condition,
               filc::ast::AbstractExpression *iteration, const std::vector<AbstractExpression *> &body)
            : _declaration(declaration), _condition(condition), _iteration(iteration), _body(body),
              _body_environment(nullptr) {}

    auto ForI::getDeclaration() const -> VariableDeclaration * {
        return _declaration;
    }

    auto ForI::getCondition() const -> AbstractExpression * {
        return _condition;
    }

    auto ForI::getIteration() const -> AbstractExpression * {
        return _iteration;
    }

    auto ForI::getBody() const -> const std::vector<AbstractExpression *> & {
        return _body;
    }

    ForI::~ForI() {
        delete _declaration;
        delete _condition;
        delete _iteration;
        for (const auto &expression: _body) {
            delete expression;
        }
    }

    auto ForI::resolveType(filc::environment::Environment *environment,
                           filc::message::MessageCollector *collector,
                           AbstractType *preferred_type) -> void {
        _body_environment = new filc::environment::Environment(environment);

        if (_declaration != nullptr) {
            _declaration->resolveType(_body_environment, collector, nullptr);
        }

        if (_condition != nullptr) {
            _condition->resolveType(_body_environment, collector, environment->getType("bool"));
            auto *condition_type = _condition->getExpressionType();
            if (condition_type == nullptr || *condition_type != *environment->getType("bool")) {
                collector->addError(new filc::message::Error(
                        filc::message::ERROR,
                        "Condition of for must return bool, found: " + condition_type->dump(),
                        _condition->getPosition()
                ));
                return;
            }
        }

        if (_iteration != nullptr) {
            _iteration->resolveType(_body_environment, collector);
        }

        AbstractType *body_type = nullptr;
        for (auto iter = _body.begin(); iter != _body.end(); iter++) {
            (*iter)->resolveType(_body_environment, collector);
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
