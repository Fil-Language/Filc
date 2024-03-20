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
#ifndef FILC_CONDITION_H
#define FILC_CONDITION_H

#include "AbstractExpression.h"
#include "AST_decl.h"

namespace filc::ast {
    class If : public AbstractExpression {
    public:
        If(const std::shared_ptr<AbstractExpression> &condition, const std::shared_ptr<BlockBody> &body);

        ~If() override;

        [[nodiscard]] auto getCondition() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getBody() const -> std::shared_ptr<BlockBody>;

        [[nodiscard]] auto getElse() const -> std::shared_ptr<BlockBody>;

        auto setElse(const std::shared_ptr<BlockBody> &p_else) -> void;

    private:
        std::shared_ptr<AbstractExpression> _condition;
        std::shared_ptr<BlockBody> _body;
        std::shared_ptr<BlockBody> _else;
    };

    class Match : public AbstractExpression {
    public:
        Match(
            const std::shared_ptr<AbstractExpression> &condition, const std::vector<std::shared_ptr<MatchCase>> &cases
        );

        ~Match() override;

        [[nodiscard]] auto getCondition() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getCases() const -> const std::vector<std::shared_ptr<MatchCase>> &;

    private:
        std::shared_ptr<AbstractExpression> _condition;
        std::vector<std::shared_ptr<MatchCase>> _cases;
    };

    class MatchCase : public AbstractExpression {
    public:
        MatchCase(const std::shared_ptr<AbstractExpression> &pattern, const std::shared_ptr<BlockBody> &body);

        ~MatchCase() override;

        [[nodiscard]] auto getPattern() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto isDefault() const -> bool;

        [[nodiscard]] auto getBody() const -> std::shared_ptr<BlockBody>;

    private:
        std::shared_ptr<AbstractExpression> _pattern;
        std::shared_ptr<BlockBody> _body;
    };
} // namespace filc::ast

#endif // FILC_CONDITION_H
