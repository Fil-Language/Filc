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
#ifndef FILC_CALCUL_H
#define FILC_CALCUL_H

#include "AbstractExpression.h"
#include "AST_decl.h"

namespace filc::ast {
    class UnaryCalcul : public AbstractExpression {
    public:
        explicit UnaryCalcul(const std::shared_ptr<Identifier> &variable, const std::shared_ptr<Operator> &p_operator);

        ~UnaryCalcul() override;

        [[nodiscard]] auto getVariable() const -> std::shared_ptr<Identifier>;

        [[nodiscard]] auto getOperator() const -> std::shared_ptr<Operator>;

    private:
        std::shared_ptr<Identifier> _variable;
        std::shared_ptr<Operator> _operator;
    };

    class PreUnaryCalcul : public UnaryCalcul {
    public:
        PreUnaryCalcul(const std::shared_ptr<Identifier> &variable, const std::shared_ptr<Operator> &p_operator);
    };

    class PostUnaryCalcul : public UnaryCalcul {
    public:
        PostUnaryCalcul(const std::shared_ptr<Identifier> &variable, const std::shared_ptr<Operator> &p_operator);
    };

    class BinaryCalcul : public AbstractExpression {
    public:
        BinaryCalcul(
            const std::shared_ptr<AbstractExpression> &left_expression,
            const std::shared_ptr<Operator> &p_operator,
            const std::shared_ptr<AbstractExpression> &right_expression
        );

        ~BinaryCalcul() override;

        [[nodiscard]] auto getLeftExpression() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getRightExpression() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto getOperator() const -> std::shared_ptr<Operator>;

        auto accept(Visitor *visitor) -> void override;

    private:
        std::shared_ptr<AbstractExpression> _left_expression;
        std::shared_ptr<AbstractExpression> _right_expression;
        std::shared_ptr<Operator> _operator;
        std::shared_ptr<LambdaType> _binary_type;
    };
} // namespace filc::ast

#endif // FILC_CALCUL_H
