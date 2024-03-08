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
#include "Environment.h"
#include "MessageCollector.h"
#include "Position.h"
#include "Visitor.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include <map>
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

        auto setImports(const std::vector<Program *> &imports) -> void;

        [[nodiscard]] auto getExpressions() const -> const std::vector<AbstractExpression *> &;

        [[nodiscard]] auto getFilename() const -> const std::string &;

        auto setFilename(const std::string &filename) -> void;

    private:
        std::string _module;
        std::vector<std::string> _import_modules;
        std::vector<Program *> _imports;
        std::vector<AbstractExpression *> _expressions;
        std::string _filename;
        filc::environment::Environment *_environment;
        filc::environment::Environment *_public_environment;
    };

    class AbstractExpression : public Visitable {
    public:
        virtual ~AbstractExpression();

        auto setPosition(filc::utils::AbstractPosition *position) -> void;

        AbstractExpression(const AbstractExpression &other) = default;

        AbstractExpression(AbstractExpression &&other) = default;

        auto operator=(const AbstractExpression &other) -> AbstractExpression & = default;

        auto operator=(AbstractExpression &&other) -> AbstractExpression & = default;

        [[nodiscard]] auto isExported() const -> bool;

        auto setExported(bool exported) -> void;

        [[nodiscard]] auto getPosition() const -> filc::utils::AbstractPosition *;

        [[nodiscard]] auto getExpressionType() const -> std::shared_ptr<AbstractType>;

        auto accept(Visitor *visitor) -> void override;

    private:
        bool _exported{false};
        filc::utils::AbstractPosition *_position{nullptr};
        std::shared_ptr<AbstractType> _expression_type;

    protected:
        AbstractExpression() = default;

        auto setExpressionType(std::shared_ptr<AbstractType> expression_type) -> void;
    };

    class Identifier : public AbstractExpression {
    public:
        explicit Identifier(antlr4::Token *token);

        explicit Identifier(std::string name);

        [[nodiscard]] auto getName() const -> const std::string &;

        auto accept(Visitor *visitor) -> void override;

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
        explicit AbstractLiteral(T value) : AbstractExpression(), _value(value){};
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

    class VariableDeclaration : public AbstractExpression {
    public:
        VariableDeclaration(bool is_constant, Identifier *identifier, std::shared_ptr<AbstractType> type);

        ~VariableDeclaration() override;

        [[nodiscard]] auto isConstant() const -> bool;

        [[nodiscard]] auto getIdentifier() const -> Identifier *;

        [[nodiscard]] auto getType() const -> std::shared_ptr<AbstractType>;

        [[nodiscard]] auto getAssignation() const -> AbstractExpression *;

        auto setAssignation(AbstractExpression *assignation) -> void;

    private:
        bool _constant;
        Identifier *_identifier;
        std::shared_ptr<AbstractType> _type;
        AbstractExpression *_assignation;
    };

    class AbstractType {
    public:
        virtual ~AbstractType() = default;

        AbstractType(const AbstractType &other) = default;

        AbstractType(AbstractType &&other) = default;

        auto operator=(const AbstractType &other) -> AbstractType & = delete;

        auto operator=(AbstractType &&other) -> AbstractType & = delete;

        [[nodiscard]] virtual auto dump() const -> std::string = 0;

        [[nodiscard]] virtual auto getInnerType() const -> std::shared_ptr<AbstractType> = 0;

        [[nodiscard]] auto getLLVMType() const -> llvm::Type *;

        auto setLLVMType(llvm::Type *type) -> void;

    protected:
        explicit AbstractType() = default;

    private:
        llvm::Type *_llvm_type{nullptr};
    };

    class Type : public AbstractType {
    public:
        explicit Type(Identifier *name);

        [[nodiscard]] auto getName() const -> Identifier *;

        [[nodiscard]] auto dump() const -> std::string override;

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

    private:
        Identifier *_name;
    };

    class ArrayType : public AbstractType {
    public:
        ArrayType(std::shared_ptr<AbstractType> inner_type, unsigned int size);

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

        [[nodiscard]] auto getSize() const -> unsigned int;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        std::shared_ptr<AbstractType> _inner_type;
        unsigned int _size;
    };

    class PointerType : public AbstractType {
    public:
        explicit PointerType(std::shared_ptr<AbstractType> inner_type);

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        std::shared_ptr<AbstractType> _inner_type;
    };

    class LambdaType : public AbstractType {
    public:
        LambdaType(const std::vector<std::shared_ptr<AbstractType>> &argument_types,
                   std::shared_ptr<AbstractType> return_type);

        [[nodiscard]] auto getArgumentTypes() const -> const std::vector<std::shared_ptr<AbstractType>> &;

        [[nodiscard]] auto getReturnType() const -> std::shared_ptr<AbstractType>;

        [[nodiscard]] auto dump() const -> std::string override;

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

    private:
        std::vector<std::shared_ptr<AbstractType>> _argument_types;
        std::shared_ptr<AbstractType> _return_type;
    };

    class UnaryCalcul : public AbstractExpression {
    public:
        explicit UnaryCalcul(Identifier *variable, Operator *p_operator);

        ~UnaryCalcul() override;

        [[nodiscard]] auto getVariable() const -> Identifier *;

        [[nodiscard]] auto getOperator() const -> Operator *;

    private:
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

        auto accept(Visitor *visitor) -> void override;

    private:
        AbstractExpression *_left_expression;
        AbstractExpression *_right_expression;
        Operator *_operator;
        std::shared_ptr<LambdaType> _binary_type;
    };

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
        explicit ArrayOperator(AbstractExpression *expression);

        ~ArrayOperator() override;

        [[nodiscard]] auto getExpression() const -> AbstractExpression *;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        AbstractExpression *_expression;
    };

    class FunctionOperator : public Operator {
    public:
        explicit FunctionOperator(const std::vector<AbstractExpression *> &expressions);

        ~FunctionOperator() override;

        [[nodiscard]] auto getExpressions() const -> const std::vector<AbstractExpression *> &;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        std::vector<AbstractExpression *> _expressions;
    };

    class AssignationOperator : public Operator {
    public:
        explicit AssignationOperator(Operator *inner_operator);

        ~AssignationOperator() override;

        [[nodiscard]] auto getInnerOperator() const -> Operator *;

        [[nodiscard]] auto dump() const -> std::string override;

        auto accept(Visitor *visitor) -> void override;

    private:
        Operator *_inner_operator;
    };

    class Lambda : public AbstractExpression {
    public:
        Lambda(const std::vector<FunctionParameter *> &parameters, std::shared_ptr<AbstractType> return_type,
               BlockBody *body);

        ~Lambda() override;

        [[nodiscard]] auto getParameters() const -> const std::vector<FunctionParameter *> &;

        [[nodiscard]] auto getReturnType() const -> std::shared_ptr<AbstractType>;

        [[nodiscard]] auto getBody() const -> BlockBody *;

        [[nodiscard]] auto getBodyEnvironment() const -> filc::environment::Environment *;

    private:
        std::vector<FunctionParameter *> _parameters;
        std::shared_ptr<AbstractType> _return_type;
        BlockBody *_body;
        filc::environment::Environment *_body_environment;
        static int name_index;
    };

    class Function : public Lambda {
    public:
        Function(Identifier *name, const std::vector<FunctionParameter *> &parameters,
                 std::shared_ptr<AbstractType> return_type, BlockBody *body);

        ~Function() override;

        [[nodiscard]] auto getName() const -> Identifier *;

    private:
        Identifier *_name;
    };

    class FunctionParameter {
    public:
        FunctionParameter(Identifier *name, std::shared_ptr<AbstractType> type);

        ~FunctionParameter();

        [[nodiscard]] auto getName() const -> Identifier *;

        [[nodiscard]] auto getType() const -> std::shared_ptr<AbstractType>;

    private:
        Identifier *_name;
        std::shared_ptr<AbstractType> _type;
    };

    class If : public AbstractExpression {
    public:
        If(AbstractExpression *condition, BlockBody *body);

        ~If() override;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> BlockBody *;

        [[nodiscard]] auto getElse() const -> BlockBody *;

        auto setElse(BlockBody *p_else) -> void;

    private:
        AbstractExpression *_condition;
        BlockBody *_body;
        BlockBody *_else;
    };

    class Match : public AbstractExpression {
    public:
        Match(AbstractExpression *condition, const std::vector<MatchCase *> &cases);

        ~Match() override;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getCases() const -> const std::vector<MatchCase *> &;

    private:
        AbstractExpression *_condition;
        std::vector<MatchCase *> _cases;
    };

    class MatchCase : public AbstractExpression {
    public:
        MatchCase(AbstractExpression *pattern, BlockBody *body);

        ~MatchCase() override;

        [[nodiscard]] auto getPattern() const -> AbstractExpression *;

        [[nodiscard]] auto isDefault() const -> bool;

        [[nodiscard]] auto getBody() const -> BlockBody *;

    private:
        AbstractExpression *_pattern;
        BlockBody *_body;
    };

    class ForI : public AbstractExpression {
    public:
        ForI(VariableDeclaration *declaration, AbstractExpression *condition, AbstractExpression *iteration,
             BlockBody *body);

        ~ForI() override;

        [[nodiscard]] auto getDeclaration() const -> VariableDeclaration *;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getIteration() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> BlockBody *;

    private:
        VariableDeclaration *_declaration;
        AbstractExpression *_condition;
        AbstractExpression *_iteration;
        BlockBody *_body;
        filc::environment::Environment *_body_environment;
    };

    class ForIter : public AbstractExpression {
    public:
        ForIter(bool constant, Identifier *identifier, AbstractExpression *array, BlockBody *body);

        ~ForIter() override;

        [[nodiscard]] auto isConstant() const -> bool;

        [[nodiscard]] auto getIdentifier() const -> Identifier *;

        [[nodiscard]] auto getArray() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> BlockBody *;

    private:
        bool _constant;
        Identifier *_identifier;
        AbstractExpression *_array;
        BlockBody *_body;
        filc::environment::Environment *_body_environment;
    };

    class While : public AbstractExpression {
    public:
        While(AbstractExpression *condition, BlockBody *body);

        ~While() override;

        [[nodiscard]] auto getCondition() const -> AbstractExpression *;

        [[nodiscard]] auto getBody() const -> BlockBody *;

    private:
        AbstractExpression *_condition;
        BlockBody *_body;
    };

    class BlockBody : public AbstractExpression {
    public:
        explicit BlockBody(const std::vector<AbstractExpression *> &expressions);

        ~BlockBody() override;

        [[nodiscard]] auto getExpressions() const -> const std::vector<AbstractExpression *> &;

        auto accept(Visitor *visitor) -> void override;

    private:
        std::vector<AbstractExpression *> _expressions;
    };
}// namespace filc::ast

auto operator==(const filc::ast::AbstractType &type1, const filc::ast::AbstractType &type2) -> bool;

auto operator!=(const filc::ast::AbstractType &type1, const filc::ast::AbstractType &type2) -> bool;

#endif//FILC_AST_H
