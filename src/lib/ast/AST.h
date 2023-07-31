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
#ifndef FILC_AST_H
#define FILC_AST_H

#include "AST_decl.h"
#include "Position.h"
#include <string>
#include <vector>

namespace filc::ast {
    class Program {
    public:
        explicit Program(std::string module, const std::vector<std::string> &imports,
                         const std::vector<AbstractExpression *> &expressions);

        auto getModule() const -> const std::string &;

        auto getImports() const -> const std::vector<std::string> &;

        auto getExpressions() const -> const std::vector<AbstractExpression *> &;

        auto getFilename() const -> const std::string &;

        auto setFilename(const std::string &filename) -> void;

    private:
        std::string _module;
        std::vector<std::string> _imports;
        std::vector<AbstractExpression *> _expressions;
        std::string _filename;
    };

    class AbstractExpression {
    public:
        auto isExported() const -> bool;

        auto setExported(bool exported) -> void;

        auto getPosition() const -> utils::Position *;

        auto setPosition(utils::Position *position) -> void;

    private:
        bool _exported;
        filc::utils::Position *_position;

    protected:
        AbstractExpression() = default;

        AbstractExpression(const AbstractExpression &other) = default;

        AbstractExpression(AbstractExpression &&other) = default;

        ~AbstractExpression() = default;

        auto operator=(const AbstractExpression &other) -> AbstractExpression & = default;

        auto operator=(AbstractExpression &&other) -> AbstractExpression & = default;
    };

    class Identifier : public AbstractExpression {
    public:
        explicit Identifier(antlr4::Token *token);

        explicit Identifier(std::string name);

        auto getName() const -> const std::string &;

    private:
        std::string _name;
    };

    template<typename T>
    class AbstractLiteral : public AbstractExpression {
    public:
        auto getValue() const -> T {
            return _value;
        };

    private:
        T _value;

    protected:
        explicit AbstractLiteral(T value) : AbstractExpression(), _value(value) {};
    };

    class BooleanLiteral : public AbstractLiteral<bool> {
    public:
        explicit BooleanLiteral(bool value);
    };

    class IntegerLiteral : public AbstractLiteral<int> {
    public:
        explicit IntegerLiteral(int value);
    };

    class FloatLiteral : public AbstractLiteral<double> {
    public:
        explicit FloatLiteral(double value);
    };

    class CharacterLiteral : public AbstractLiteral<char> {
    public:
        explicit CharacterLiteral(char value);

        static auto stringToChar(const std::string &snippet, antlr4::Token *token = nullptr) -> char;
    };

    class StringLiteral : public AbstractLiteral<std::string> {
    public:
        explicit StringLiteral(const std::string &value);
    };

    class VariableDeclaration : public AbstractExpression {
    public:
        VariableDeclaration(bool is_constant, Identifier *identifier);

        auto isConstant() const -> bool;

        auto getIdentifier() const -> Identifier *;

    private:
        bool _constant;
        Identifier *_identifier;
    };

    class AbstractType {
    protected:
        AbstractType() = default;

        AbstractType(const AbstractType &other) = default;

        AbstractType(AbstractType &&other) = default;

        ~AbstractType() = default;

        auto operator=(const AbstractType &other) -> AbstractType & = default;

        auto operator=(AbstractType &&other) -> AbstractType & = default;
    };

    class Type : public AbstractType {
    public:
        explicit Type(Identifier *name);

        auto getName() const -> Identifier *;

    private:
        Identifier *_name;
    };

    class ArrayType : public AbstractType {
    public:
        ArrayType(AbstractType *inner_type, unsigned int size);

        auto getInnerType() const -> AbstractType *;

        auto getSize() const -> unsigned int;

    private:
        AbstractType *_inner_type;
        unsigned int _size;
    };
}

#endif //FILC_AST_H
