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
    Lambda::Lambda(const std::vector<FunctionParameter *> &parameters, filc::ast::AbstractType *return_type,
                   const std::vector<AbstractExpression *> &body)
            : _parameters(parameters), _return_type(return_type), _body(body) {}

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
}
