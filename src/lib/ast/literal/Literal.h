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
#ifndef FILC_LITERAL_H
#define FILC_LITERAL_H

#include "AbstractExpression.h"
#include "AST_decl.h"

namespace filc::ast {
    template<typename T> class AbstractLiteral : public AbstractExpression {
    public:
        auto getValue() const -> T {
            return _value;
        }

    private:
        T _value;

    protected:
        explicit AbstractLiteral(T value): AbstractExpression(), _value(value) {};
    };

    class BooleanLiteral : public AbstractLiteral<bool> {
    public:
        explicit BooleanLiteral(bool value);

        auto accept(Visitor *visitor) -> void override;
    };

    class IntegerLiteral : public AbstractLiteral<int> {
    public:
        explicit IntegerLiteral(int value);

        auto accept(Visitor *visitor) -> void override;
    };

    class FloatLiteral : public AbstractLiteral<double> {
    public:
        explicit FloatLiteral(double value, bool is_double = false);

        [[nodiscard]] auto isDouble() const -> bool;

        auto accept(Visitor *visitor) -> void override;

    private:
        bool _double;
    };

    class CharacterLiteral : public AbstractLiteral<char> {
    public:
        explicit CharacterLiteral(char value);

        static auto stringToChar(const std::string &snippet, antlr4::Token *token = nullptr) -> char;

        auto accept(Visitor *visitor) -> void override;
    };

    class StringLiteral : public AbstractLiteral<std::string> {
    public:
        explicit StringLiteral(const std::string &value);

        auto accept(Visitor *visitor) -> void override;
    };
} // namespace filc::ast

#endif // FILC_LITERAL_H
