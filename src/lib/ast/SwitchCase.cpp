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

namespace filc::ast {
    SwitchCase::SwitchCase(filc::ast::AbstractExpression *pattern, const std::vector<AbstractExpression *> &body)
            : _pattern(pattern), _body(body) {}

    auto SwitchCase::getPattern() const -> AbstractExpression * {
        return _pattern;
    }

    auto SwitchCase::isDefault() const -> bool {
        auto *identifier = dynamic_cast<Identifier *>(_pattern);
        if (identifier == nullptr) {
            return false;
        }

        return identifier->getName() == "default";
    }

    auto SwitchCase::getBody() const -> const std::vector<AbstractExpression *> & {
        return _body;
    }

    SwitchCase::~SwitchCase() {
        delete _pattern;
        for (const auto &expression: _body) {
            delete expression;
        }
    }

    auto SwitchCase::resolveType(filc::environment::Environment *environment,
                                 filc::message::MessageCollector *collector,
                                 const std::shared_ptr<AbstractType> &preferred_type) -> void {
        if (!isDefault()) {
            _pattern->resolveType(environment, collector, nullptr);
            if (_pattern->getExpressionType() == nullptr) {
                return;
            }
        }

        std::shared_ptr<AbstractType> body_type = nullptr;
        for (auto iter = _body.begin(); iter != _body.end(); iter++) {
            if (iter + 1 != _body.end()) {
                (*iter)->resolveType(environment, collector, nullptr);
            } else {
                (*iter)->resolveType(environment, collector, preferred_type);
                body_type = (*iter)->getExpressionType();
            }
        }

        setExpressionType(body_type);
    }
}
