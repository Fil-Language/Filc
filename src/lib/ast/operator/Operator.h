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
#ifndef FILC_OPERATOR_H
#define FILC_OPERATOR_H

#include "AST_decl.h"
#include "Visitor.h"
#include <memory>
#include <string>
#include <vector>

namespace filc::ast {
    class Operator : public Visitable {
    public:
        Operator(const Operator &other) = default;

        Operator(Operator &&other) = default;

        virtual ~Operator() = default;

        auto operator=(const Operator &other) -> Operator & = default;

        auto operator=(Operator &&other) -> Operator & = default;

        [[nodiscard]] virtual auto dump() const -> std::string = 0;

        auto accept(Visitor *visitor) -> void override {}

    protected:
        Operator() = default;
    };

    class ClassicOperator : public Operator {
    public:
        using OPERATOR = enum : uint8_t {
            PLUSPLUS,
            MINUSMINUS,
            PLUS,
            MINUS,
            REF,
            STAR,
            NOT,
            DIV,
            MOD,
            FLEFT,
            FRIGHT,
            LESS,
            GREATER,
            EQEQ,
            LEQ,
            GEQ,
            NEQ,
            AND,
            OR
        };

        explicit ClassicOperator(OPERATOR p_operator);

        explicit ClassicOperator(const std::string &p_operator);

        [[nodiscard]] auto getOperator() const -> OPERATOR;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        OPERATOR _operator;
    };

    class ArrayOperator : public Operator {
    public:
        explicit ArrayOperator(const std::shared_ptr<AbstractExpression> &expression);

        ~ArrayOperator() override;

        [[nodiscard]] auto getExpression() const -> std::shared_ptr<AbstractExpression>;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        std::shared_ptr<AbstractExpression> _expression;
    };

    class FunctionOperator : public Operator {
    public:
        explicit FunctionOperator(const std::vector<std::shared_ptr<AbstractExpression>> &expressions);

        ~FunctionOperator() override;

        [[nodiscard]] auto getExpressions() const -> const std::vector<std::shared_ptr<AbstractExpression>> &;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        std::vector<std::shared_ptr<AbstractExpression>> _expressions;
    };

    class AssignationOperator : public Operator {
    public:
        explicit AssignationOperator(const std::shared_ptr<Operator> &inner_operator);

        ~AssignationOperator() override;

        [[nodiscard]] auto getInnerOperator() const -> std::shared_ptr<Operator>;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        std::shared_ptr<Operator> _inner_operator;
    };
} // namespace filc::ast

#endif // FILC_OPERATOR_H
