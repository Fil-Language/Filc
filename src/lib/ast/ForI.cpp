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
    ForI::ForI(filc::ast::VariableDeclaration *declaration, filc::ast::AbstractExpression *condition,
               filc::ast::AbstractExpression *iteration, const std::vector<AbstractExpression *> &body)
            : AbstractExpression(), _declaration(declaration), _condition(condition), _iteration(iteration),
              _body(body) {}

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
}
