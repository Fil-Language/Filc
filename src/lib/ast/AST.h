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

        ~Program();

        [[nodiscard]] auto getModule() const -> const std::string &;

        [[nodiscard]] auto getImports() const -> const std::vector<std::string> &;

        [[nodiscard]] auto getExpressions() const -> const std::vector<AbstractExpression *> &;

        [[nodiscard]] auto getFilename() const -> const std::string &;

        auto setFilename(const std::string &filename) -> void;

    private:
        std::string _module;
        std::vector<std::string> _imports;
        std::vector<AbstractExpression *> _expressions;
        std::string _filename;
    };

    class AbstractExpression {
    public:
        virtual ~AbstractExpression();

        auto setPosition(utils::Position *position) -> void;

        AbstractExpression(const AbstractExpression &other) = default;

        AbstractExpression(AbstractExpression &&other) = default;

        auto operator=(const AbstractExpression &other) -> AbstractExpression & = default;

        auto operator=(AbstractExpression &&other) -> AbstractExpression & = default;

        [[nodiscard]] auto isExported() const -> bool;

        auto setExported(bool exported) -> void;

        [[nodiscard]] auto getPosition() const -> utils::Position *;

    private:
        bool _exported{false};
        filc::utils::Position *_position{nullptr};

    protected:
        AbstractExpression() = default;
    };

    class Identifier : public AbstractExpression {
    public:
        explicit Identifier(antlr4::Token *token);

        explicit Identifier(std::string name);

        [[nodiscard]] auto getName() const -> const std::string &;

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
        VariableDeclaration(bool is_constant, Identifier *identifier, AbstractType *type);

        ~VariableDeclaration() override;

        [[nodiscard]] auto isConstant() const -> bool;

        [[nodiscard]] auto getIdentifier() const -> Identifier *;

        [[nodiscard]] auto getType() const -> AbstractType *;

        [[nodiscard]] auto getAssignation() const -> AbstractExpression *;

        auto setAssignation(AbstractExpression *assignation) -> void;

    private:
        bool _constant;
        Identifier *_identifier;
        AbstractType *_type;
        AbstractExpression *_assignation;
    };

    class AbstractType {
    public:
        virtual ~AbstractType() = default;

        AbstractType(const AbstractType &other) = default;

        AbstractType(AbstractType &&other) = default;

        auto operator=(const AbstractType &other) -> AbstractType & = default;

        auto operator=(AbstractType &&other) -> AbstractType & = default;

        [[nodiscard]] virtual auto dump() const -> std::string = 0;

    protected:
        AbstractType() = default;
    };

    class Type : public AbstractType {
    public:
        explicit Type(Identifier *name);

        ~Type() override;

        [[nodiscard]] auto getName() const -> Identifier *;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        Identifier *_name;
    };

    class ArrayType : public AbstractType {
    public:
        ArrayType(AbstractType *inner_type, unsigned int size);

        ~ArrayType() override;

        [[nodiscard]] auto getInnerType() const -> AbstractType *;

        [[nodiscard]] auto getSize() const -> unsigned int;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        AbstractType *_inner_type;
        unsigned int _size;
    };

    class PointerType : public AbstractType {
    public:
        explicit PointerType(AbstractType *inner_type);

        ~PointerType() override;

        [[nodiscard]] auto getInnerType() const -> AbstractType *;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        AbstractType *_inner_type;
    };

    class LambdaType : public AbstractType {
    public:
        LambdaType(const std::vector<AbstractType *> &argument_types, AbstractType *return_type);

        ~LambdaType() override;

        [[nodiscard]] auto getArgumentTypes() const -> const std::vector<AbstractType *> &;

        [[nodiscard]] auto getReturnType() const -> AbstractType *;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        std::vector<AbstractType *> _argument_types;
        AbstractType *_return_type;
    };

    class UnaryCalcul : public AbstractExpression {
    public:
        explicit UnaryCalcul(Identifier *variable, Operator *p_operator);

        ~UnaryCalcul() override;

        [[nodiscard]] auto getVariable() const -> Identifier *;

        [[nodiscard]] auto getOperator() const -> Operator *;

    protected:
        Identifier *_variable;
        Operator *_operator;
    };

    class PreUnaryCalcul : public UnaryCalcul {
    public:
        PreUnaryCalcul(Identifier *variable, Operator *p_operator);
    };

    class PostUnaryCalcul : public UnaryCalcul {
    public:
        PostUnaryCalcul(Identifier *variable, Operator *p_operator);
    };

    class BinaryCalcul : public AbstractExpression {
    public:
        BinaryCalcul(AbstractExpression *left_expression, Operator *p_operator, AbstractExpression *right_expression);

        ~BinaryCalcul() override;

        [[nodiscard]] auto getLeftExpression() const -> AbstractExpression *;

        [[nodiscard]] auto getRightExpression() const -> AbstractExpression *;

        [[nodiscard]] auto getOperator() const -> Operator *;

    private:
        AbstractExpression *_left_expression;
        AbstractExpression *_right_expression;
        Operator *_operator;
    };

    class Operator {
    public:
        Operator(const Operator &other) = default;

        Operator(Operator &&other) = default;

        virtual ~Operator() = default;

        auto operator=(const Operator &other) -> Operator & = default;

        auto operator=(Operator &&other) -> Operator & = default;

    protected:
        Operator() = default;
    };

    class ClassicOperator : public Operator {
    public:
        using OPERATOR = enum {
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

        [[nodiscard]] auto getOperator() const -> OPERATOR;

    private:
        OPERATOR _operator;
    };

    class ArrayOperator : public Operator {
    public:
        explicit ArrayOperator(AbstractExpression *expression);

        ~ArrayOperator() override;

        [[nodiscard]] auto getExpression() const -> AbstractExpression *;

    private:
        AbstractExpression *_expression;
    };

    class FunctionOperator : public Operator {
    public:
        explicit FunctionOperator(const std::vector<AbstractExpression *> &expressions);

        ~FunctionOperator() override;

        [[nodiscard]] auto getExpressions() const -> const std::vector<AbstractExpression *> &;

    private:
        std::vector<AbstractExpression *> _expressions;
    };

    class Lambda : public AbstractExpression {
    public:
        Lambda(const std::vector<FunctionParameter *> &parameters, AbstractType *return_type,
               const std::vector<AbstractExpression *> &body);

        ~Lambda() override;

        [[nodiscard]] auto getParameters() const -> const std::vector<FunctionParameter *> &;

        [[nodiscard]] auto getReturnType() const -> AbstractType *;

        [[nodiscard]] auto getBody() const -> const std::vector<AbstractExpression *> &;

    protected:
        std::vector<FunctionParameter *> _parameters;
        AbstractType *_return_type;
        std::vector<AbstractExpression *> _body;
    };

    class Function : public Lambda {
    public:
        Function(Identifier *name, const std::vector<FunctionParameter *> &parameters, AbstractType *return_type,
                 const std::vector<AbstractExpression *> &body);

        ~Function() override;

        [[nodiscard]] auto getName() const -> Identifier *;

    private:
        Identifier *_name;
    };

    class FunctionParameter {
    public:
        FunctionParameter(Identifier *name, AbstractType *type);

        ~FunctionParameter();

        [[nodiscard]] auto getName() const -> Identifier *;

        [[nodiscard]] auto getType() const -> AbstractType *;

    private:
        Identifier *_name;
        AbstractType *_type;
    };

    class If : public AbstractExpression {
    public:
        If(AbstractExpression *condition, const std::vector<AbstractExpression *> &body);

        ~If() override;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> const std::vector<AbstractExpression *> &;

        [[nodiscard]] auto getElse() const -> If *;

        auto setElse(If *p_else) -> void;

    private:
        AbstractExpression *_condition;
        std::vector<AbstractExpression *> _body;
        If* _else;
    };

    class Switch : public AbstractExpression {
    public:
        Switch(AbstractExpression *condition, const std::vector<SwitchCase *> &cases);

        ~Switch() override;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getCases() const -> const std::vector<SwitchCase *> &;

    private:
        AbstractExpression *_condition;
        std::vector<SwitchCase *> _cases;
    };

    class SwitchCase {
    public:
        SwitchCase(AbstractExpression *pattern, const std::vector<AbstractExpression *> &body);

        ~SwitchCase();

        [[nodiscard]] auto getPattern() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> const std::vector<AbstractExpression *> &;

    private:
        AbstractExpression *_pattern;
        std::vector<AbstractExpression *> _body;
    };

    class ForI : public AbstractExpression {
    public:
        ForI(VariableDeclaration *declaration, AbstractExpression *condition, AbstractExpression *iteration,
             const std::vector<AbstractExpression *> &body);

        ~ForI() override;

        [[nodiscard]] auto getDeclaration() const -> VariableDeclaration *;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getIteration() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> const std::vector<AbstractExpression *> &;

    private:
        VariableDeclaration *_declaration;
        AbstractExpression *_condition;
        AbstractExpression *_iteration;
        std::vector<AbstractExpression *> _body;
    };

    class ForIter : public AbstractExpression {
    public:
        ForIter(bool constant, Identifier *identifier, AbstractExpression *array,
                const std::vector<AbstractExpression *> &body);

        ~ForIter() override;

        [[nodiscard]] auto isConstant() const -> bool;

        [[nodiscard]] auto getIdentifier() const -> Identifier *;

        [[nodiscard]] auto getArray() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> const std::vector<AbstractExpression *> &;

    private:
        bool _constant;
        Identifier *_identifier;
        AbstractExpression *_array;
        std::vector<AbstractExpression *> _body;
    };

    class While : public AbstractExpression {
    public:
        While(AbstractExpression *condition, const std::vector<AbstractExpression *> &body);

        ~While() override;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> const std::vector<AbstractExpression *> &;

    private:
        AbstractExpression *_condition;
        std::vector<AbstractExpression *> _body;
    };
}

#endif //FILC_AST_H
