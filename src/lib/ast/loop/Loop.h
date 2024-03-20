/**
 * MIT License
 *
 * Copyright (c) 2024-Present Kevin Traini
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
#ifndef FILC_LOOP_H
#define FILC_LOOP_H

#include "AbstractExpression.h"
#include "AST_decl.h"
#include "Environment.h"

namespace filc::ast {
    class ForI : public AbstractExpression {
    public:
        ForI(
            const std::shared_ptr<VariableDeclaration> &declaration,
            const std::shared_ptr<AbstractExpression> &condition,
            const std::shared_ptr<AbstractExpression> &iteration,
            const std::shared_ptr<BlockBody> &body
        );

        ~ForI() override;

        [[nodiscard]] auto getDeclaration() const -> std::shared_ptr<VariableDeclaration>;

        [[nodiscard]] auto getCondition() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getIteration() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getBody() const -> std::shared_ptr<BlockBody>;

    private:
        std::shared_ptr<VariableDeclaration> _declaration;
        std::shared_ptr<AbstractExpression> _condition;
        std::shared_ptr<AbstractExpression> _iteration;
        std::shared_ptr<BlockBody> _body;
        std::shared_ptr<environment::Environment> _body_environment;
    };

    class ForIter : public AbstractExpression {
    public:
        ForIter(
            bool constant,
            const std::shared_ptr<Identifier> &identifier,
            const std::shared_ptr<AbstractExpression> &array,
            const std::shared_ptr<BlockBody> &body
        );

        ~ForIter() override;

        [[nodiscard]] auto isConstant() const -> bool;

        [[nodiscard]] auto getIdentifier() const -> std::shared_ptr<Identifier>;

        [[nodiscard]] auto getArray() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getBody() const -> std::shared_ptr<BlockBody>;

    private:
        bool _constant;
        std::shared_ptr<Identifier> _identifier;
        std::shared_ptr<AbstractExpression> _array;
        std::shared_ptr<BlockBody> _body;
        std::shared_ptr<environment::Environment> _body_environment;
    };

    class While : public AbstractExpression {
    public:
        While(const std::shared_ptr<AbstractExpression> &condition, const std::shared_ptr<BlockBody> &body);

        ~While() override;

        [[nodiscard]] auto getCondition() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getBody() const -> std::shared_ptr<BlockBody>;

    private:
        std::shared_ptr<AbstractExpression> _condition;
        std::shared_ptr<BlockBody> _body;
    };
} // namespace filc::ast

#endif // FILC_LOOP_H
