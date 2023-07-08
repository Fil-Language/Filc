/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
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
#ifndef FILC_AST_HPP
#define FILC_AST_HPP

#include "antlr4-runtime.h"
#include <string>
#include <vector>

#include "AST_decl.h"
#include "Environment.h"
#include "ErrorsRegister.h"
#include "utils.h"

namespace ast {
    class AST {
    public:
        AST();

        virtual ~AST() = default;

        [[nodiscard]] virtual auto decompile(int indent) const -> std::string;

        [[nodiscard]] virtual auto dump(int indent) const -> std::string;

        void setPosition(antlr4::Token *token);

        [[nodiscard]] auto getPosition() const -> Position *;

    protected:
        Position *_pos;
    };

    class AbstractExpr : public AST {
    public:
        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        void isExported(bool exported);

        [[nodiscard]] auto isExported() const -> bool;

        [[nodiscard]] virtual auto isVar() const -> bool;

        [[nodiscard]] virtual auto isFunc() const -> bool;

        [[nodiscard]] auto getExprType() const -> AbstractType *;

    protected:
        AbstractExpr();

        bool _is_exported;
        AbstractType *_expr_type;
    };

    class Program : public AST {
    public:
        Program(std::string module,
                const std::vector<std::string> &imports,
                const std::vector<AbstractExpr *> &exprs);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

        void resolveEnvironment();

        void setEnvironment(Environment *environment);

    private:
        std::string _module;
        std::vector<std::string> _imports;
        std::vector<Program *> _imported_modules;
        std::vector<AbstractExpr *> _exprs;
        Environment *_environment;

        bool _resolved;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Identifier : public AbstractExpr {
    public:
        explicit Identifier(std::string name);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto getName() const -> const std::string &;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        std::string _name;
        Symbol *_symbol;
    };

    class AbstractType : public AST {
    protected:
        AbstractType() = default;

    public:
        [[nodiscard]] virtual auto getName() const -> std::string = 0;

        [[nodiscard]] auto equals(const AbstractType &other) const -> bool;

        [[nodiscard]] virtual auto isIterable() const -> bool;

        virtual auto getIterableType() -> AbstractType *;
    };

    class Type : public AbstractType {
    public:
        explicit Type(Identifier *name);// IDENTIFIER

        Type(int array_size, AbstractType *sub_type);// IDENTIFIER '[' INTEGER ']'

        explicit Type(AbstractType *sub_type);// IDENTIFIER '*'

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto getName() const -> std::string override;

        [[nodiscard]] auto isIterable() const -> bool override;

        auto getIterableType() -> AbstractType * override;

    private:
        Identifier *_name;

        bool _is_array;
        int _array_size;

        bool _is_pointer;
        AbstractType *_sub_type;
    };

    class LambdaType : public AbstractType {
    public:
        LambdaType(const std::vector<AbstractType *> &args, AbstractType *ret);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto getName() const -> std::string override;

        [[nodiscard]] auto getReturnType() const -> AbstractType *;

        void setReturnType(AbstractType *ret);

        [[nodiscard]] auto getArgsTypes() const -> const std::vector<AbstractType *> &;

    private:
        std::vector<AbstractType *> _args;
        AbstractType *_ret;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class BlockBody : public AbstractExpr {
    public:
        explicit BlockBody(const std::vector<AbstractExpr *> &exprs);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        std::vector<AbstractExpr *> _exprs;
        Environment *_environment;
    };

    class ParenthesisBody : public AbstractExpr {
    public:
        explicit ParenthesisBody(AbstractExpr *expr);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        AbstractExpr *_expr;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class AbstractLiteral : public AbstractExpr {
    };

    class BooleanLiteral : public AbstractLiteral {
    public:
        explicit BooleanLiteral(bool value);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        bool _value;
    };

    class IntegerLiteral : public AbstractLiteral {
    public:
        explicit IntegerLiteral(int value);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        int _value;
    };

    class FloatLiteral : public AbstractLiteral {
    public:
        explicit FloatLiteral(float value);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        float _value;
    };

    class CharLiteral : public AbstractLiteral {
    public:
        explicit CharLiteral(const std::string &value);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        char _value;
    };

    class StringLiteral : public AbstractLiteral {
    public:
        explicit StringLiteral(const std::string &value);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    protected:
        std::string _value;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Assignation : public AbstractExpr {
    public:
        explicit Assignation(AbstractExpr *expr);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        AbstractExpr *_expr;
    };

    class VariableDeclaration : public AbstractExpr {
    public:
        VariableDeclaration(bool is_val, Identifier *name, AbstractType *type, Assignation *assignation);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto isVar() const -> bool override;

        [[nodiscard]] auto getSymbol() const -> Symbol *;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        bool _is_val;
        Identifier *_name;
        AbstractType *_type;
        Assignation *_assignation;
        Symbol *_symbol;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Operator : public AST {
    public:
        using Op = enum {
            STAR,
            PLUSPLUS,
            MINUSMINUS,
            REF,
            NOT,
            AND,
            OR,
            LESS,
            GREATER,
            EQEQ,
            LEQ,
            GEQ,
            NEQ,
            FLEFT,
            FRIGHT,
            PLUS,
            MINUS,
            DIV,
            MOD,
            ARRAY,
            FUNCTION,
        };

        explicit Operator(Op p_operator);

        explicit Operator(AbstractExpr *index);

        explicit Operator(const std::vector<AbstractExpr *> &args);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto getOp() const -> Op;

    private:
        Op _operator;
        AbstractExpr *_index;
        std::vector<AbstractExpr *> _args;
    };

    class UnaryCalcul : public AbstractExpr {
    public:
        UnaryCalcul(Operator *p_operator, Identifier *identifier);

        UnaryCalcul(Identifier *identifier, Operator *p_operator);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        Operator *_operator;
        Identifier *_identifier;
        bool _is_prefix;
    };

    class BinaryCalcul : public AbstractExpr {
    public:
        BinaryCalcul(AbstractExpr *left, Operator *p_operator, AbstractExpr *right);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        AbstractExpr *_left;
        Operator *_op;
        AbstractExpr *_right;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class FunctionParam : public AST {
    public:
        FunctionParam(Identifier *name, AbstractType *type);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        Identifier *_name;
        AbstractType *_type;
    };

    class FunctionDeclaration : public AbstractExpr {
    public:
        FunctionDeclaration(Identifier *name, const std::vector<FunctionParam *> &params, AbstractType *type);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        Identifier *_name;
        std::vector<FunctionParam *> _params;
        AbstractType *_type;
    };

    class Function : public AbstractExpr {
    public:
        Function(FunctionDeclaration *declaration, AbstractExpr *body);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto isFunc() const -> bool override;

        [[nodiscard]] auto getSymbol() const -> Symbol *;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        FunctionDeclaration *_declaration;
        AbstractExpr *_body;
        Symbol *_symbol;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Lambda : public AbstractExpr {
    public:
        Lambda(const std::vector<FunctionParam *> &params, AbstractType *type, AbstractExpr *body);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        std::vector<FunctionParam *> _params;
        AbstractType *_type;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class If : public AbstractExpr {
    public:
        If(AbstractExpr *condition, AbstractExpr *then_case, AbstractExpr *else_case);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        AbstractExpr *_condition;
        AbstractExpr *_then;
        AbstractExpr *_else;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class SwitchPattern : public AST {
    public:
        SwitchPattern();

        explicit SwitchPattern(AbstractLiteral *literal);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto getLiteral() const -> AbstractLiteral *;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

        [[nodiscard]] auto isDefault() const -> bool;

    private:
        bool _is_default;
        AbstractLiteral *_literal;
    };

    class SwitchCase : public AbstractExpr {
    public:
        explicit SwitchCase(SwitchPattern *pattern, AbstractExpr *body);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        SwitchPattern *_pattern;
        AbstractExpr *_body;
    };

    class Switch : public AbstractExpr {
    public:
        Switch(AbstractExpr *condition, const std::vector<SwitchCase *> &cases);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        AbstractExpr *_condition;
        std::vector<SwitchCase *> _cases;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class ForICondition : public AST {
    public:
        ForICondition(VariableDeclaration *declaration, AbstractExpr *condition, AbstractExpr *increment);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        VariableDeclaration *_declaration;
        AbstractExpr *_condition;
        AbstractExpr *_increment;
    };

    class ForI : public AbstractExpr {
    public:
        ForI(ForICondition *condition, AbstractExpr *body);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        ForICondition *_condition;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class ForIterCondition : public AST {
    public:
        ForIterCondition(bool is_val, Identifier *iterator, Identifier *iterable);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        bool _is_val;
        Identifier *_iterator;
        Identifier *_iterable;
        Symbol *_iterator_symbol;
    };

    class ForIter : public AbstractExpr {
    public:
        ForIter(ForIterCondition *condition, AbstractExpr *body);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        ForIterCondition *_condition;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class While : public AbstractExpr {
    public:
        While(AbstractExpr *condition, AbstractExpr *body);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        AbstractExpr *_condition;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class FunctionCall : public AbstractExpr {
    public:
        FunctionCall(Identifier *name, const std::vector<AbstractExpr *> &args);

        [[nodiscard]] auto decompile(int indent) const -> std::string override;

        [[nodiscard]] auto dump(int indent) const -> std::string override;

    private:
        Identifier *_name;
        std::vector<AbstractExpr *> _args;
    };
}// namespace ast

auto operator==(const ast::AbstractType &first, const ast::AbstractType &other) -> bool;

auto operator!=(const ast::AbstractType &first, const ast::AbstractType &other) -> bool;

#endif//FILC_AST_HPP
