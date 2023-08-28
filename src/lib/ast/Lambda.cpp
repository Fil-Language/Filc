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
    Lambda::Lambda(const std::vector<FunctionParameter *> &parameters, filc::ast::AbstractType *return_type,
                   const std::vector<AbstractExpression *> &body)
            : _parameters(parameters), _return_type(return_type), _body(body), _body_environment(nullptr) {}

    auto Lambda::getParameters() const -> const std::vector<FunctionParameter *> & {
        return _parameters;
    }

    auto Lambda::getReturnType() const -> AbstractType * {
        return _return_type;
    }

    auto Lambda::getBody() const -> const std::vector<AbstractExpression *> & {
        return _body;
    }

    Lambda::~Lambda() {
        for (const auto &parameter: _parameters) {
            delete parameter;
        }
        delete _return_type;
        for (const auto &expression: _body) {
            delete expression;
        }
    }

    auto Lambda::resolveType(filc::environment::Environment *environment,
                             filc::message::MessageCollector *collector,
                             AbstractType *preferred_type) -> void {
        _body_environment = new filc::environment::Environment(environment);

        std::vector<AbstractType *> parameters_types;
        for (const auto &parameter: _parameters) {
            auto *parameter_type = parameter->getType();
            auto *parameter_name = parameter->getName();
            if (_body_environment->hasName(parameter_name->getName())) {
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

        AbstractType *body_type = nullptr;
        for (auto iter = _body.begin(); iter != _body.end(); iter++) {
            if (iter + 1 != _body.end()) {
                (*iter)->resolveType(_body_environment, collector);
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

        setExpressionType(new filc::ast::LambdaType(parameters_types, _return_type, environment->getType("void")));
    }
}
