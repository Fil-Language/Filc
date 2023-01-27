/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_AST_HPP
#define FILC_AST_HPP

#include <string>
#include <vector>
#include "antlr4-runtime.h"

#include "AST_decl.h"
#include "utils.h"
#include "Environment.h"
#include "ErrorsRegister.h"

namespace ast {
    class AST {
    public:
        AST();

        virtual std::string decompile(int indent) const;

        virtual std::string dump(int indent) const;

        void setPosition(antlr4::Token *token);

        Position *getPosition() const;

    protected:
        Position *_pos;
    };

    class AbstractExpr : public AST {
    public:
        std::string decompile(int indent) const override;

        void isExported(bool exported);

        bool isExported() const;

        //virtual void resolveEnvironment(Environment *parent);

        virtual bool isVar() const;

        virtual bool isFunc() const;

        virtual bool isReturn() const;

        //virtual AbstractType *inferType(Environment *env);

        AbstractType *getExprType() const;

    protected:
        AbstractExpr();

    protected:
        bool _isExported;
        AbstractType *_exprType;
    };

    class Program : public AST {
    public:
        Program(const std::string &module,
                const std::vector<Program *> &imports,
                const std::vector<AbstractExpr *> &exprs);

        std::string decompile(int indent) const override;

        std::string dump(int indent) const override;

        //void resolveGlobalEnvironment();

        //void inferTypes();

    private:
//        Environment *getPublicEnvironment() const;

//        void resolveEnvironment();

    private:
        std::string _module;
        std::vector<Program *> _imports;
        std::vector<AbstractExpr *> _exprs;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Identifier : public AbstractExpr {
    public:
        explicit Identifier(const std::string &name);

        std::string decompile(int indent) const override;

//        Symbol *resolveVar(Environment *parent);

//        Symbol *resolveFunc(Environment *parent);

        //void resolveEnvironment(Environment *parent) override;

        const std::string &getName() const;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        std::string _name;
    };

    class AbstractType : public AST {
    protected:
        AbstractType() = default;

    public:
        virtual std::string getName() const = 0;

        bool equals(const AbstractType &other) const;

        virtual bool isIterable() const;

        virtual AbstractType *getIterableType();
    };

    class Type : public AbstractType {
    public:
        explicit Type(Identifier *name); // IDENTIFIER

        Type(int arraySize, AbstractType *subType); // IDENTIFIER '[' INTEGER ']'

        explicit Type(AbstractType *subType); // IDENTIFIER '*'

        std::string decompile(int indent) const override;

        std::string getName() const override;

        bool isIterable() const override;

        AbstractType *getIterableType() override;

    private:
        Identifier *_name;

        bool _isArray;
        int _arraySize;

        bool _isPointer;
        AbstractType *_subType;
    };

    class LambdaType : public AbstractType {
    public:
        LambdaType(const std::vector<AbstractType *> &args, AbstractType *ret);

        std::string decompile(int indent) const override;

        std::string getName() const override;

        AbstractType *getReturnType() const;

        void setReturnType(AbstractType *ret);

        const std::vector<AbstractType *> &getArgsTypes() const;

    private:
        std::vector<AbstractType *> _args;
        AbstractType *_ret;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class BlockBody : public AbstractExpr {
    public:
        explicit BlockBody(const std::vector<AbstractExpr *> &exprs);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        std::vector<AbstractExpr *> _exprs;
        Environment *_environment;
    };

    class ParenthesisBody : public AbstractExpr {
    public:
        explicit ParenthesisBody(AbstractExpr *expr);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        AbstractExpr *_expr;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class AbstractLiteral : public AbstractExpr {
    public:
        //void resolveEnvironment(Environment *parent) override;
    };

    class BooleanLiteral : public AbstractLiteral {
    public:
        explicit BooleanLiteral(bool value);

        std::string decompile(int indent) const override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        bool _value;
    };

    class IntegerLiteral : public AbstractLiteral {
    public:
        explicit IntegerLiteral(int value);

        std::string decompile(int indent) const override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        int _value;
    };

    class FloatLiteral : public AbstractLiteral {
    public:
        explicit FloatLiteral(float value);

        std::string decompile(int indent) const override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        float _value;
    };

    class CharLiteral : public AbstractLiteral {
    public:
        explicit CharLiteral(const std::string &value);

        std::string decompile(int indent) const override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        char _value;
    };

    class StringLiteral : public AbstractLiteral {
    public:
        explicit StringLiteral(const std::string &value);

        std::string decompile(int indent) const override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    protected:
        std::string _value;
    };

    class FStringLiteral : public StringLiteral {
    public:
        explicit FStringLiteral(const std::string &value);

        std::string decompile(int indent) const override;

        std::string dump(int indent) const override;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Assignation : public AbstractExpr {
    public:
        explicit Assignation(AbstractExpr *expr);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        AbstractExpr *_expr;
    };

    class VariableDeclaration : public AbstractExpr {
    public:
        VariableDeclaration(bool isVal, Identifier *name, AbstractType *type, Assignation *assignation);

        std::string decompile(int indent) const override;

        bool isVar() const override;

        Symbol *getSymbol() const;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        bool _isVal;
        Identifier *_name;
        AbstractType *_type;
        Assignation *_assignation;
        Symbol *_symbol;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Operator : public AST {
    public:
        typedef enum {
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
        } Op;

    public:
        explicit Operator(Op op);

        explicit Operator(AbstractExpr *index);

        std::string decompile(int indent) const override;

        Op getOp() const;

    private:
        Op _op;
        AbstractExpr *_index;
    };

    class UnaryCalcul : public AbstractExpr {
    public:
        UnaryCalcul(Operator *op, Identifier *identifier);

        UnaryCalcul(Identifier *identifier, Operator *op);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        Operator *_op;
        Identifier *_identifier;
        bool _isPrefix;
    };

    class BinaryCalcul : public AbstractExpr {
    public:
        BinaryCalcul(AbstractExpr *left, Operator *op, AbstractExpr *right);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        AbstractExpr *_left;
        Operator *_op;
        AbstractExpr *_right;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class FunctionParam : public AST {
    public:
        FunctionParam(Identifier *name, AbstractType *type);

        std::string decompile(int indent) const override;

//        void resolveParam(Environment *function);

//        AbstractType *inferType(Environment *env) const;

        std::string dump(int indent) const override;

    private:
        Identifier *_name;
        AbstractType *_type;
    };

    class FunctionDeclaration : public AbstractExpr {
    public:
        FunctionDeclaration(Identifier *name, const std::vector<FunctionParam *> &params, AbstractType *type);

        std::string decompile(int indent) const override;

//        Symbol *resolveDeclaration(Environment *parent, Environment *function);

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        Identifier *_name;
        std::vector<FunctionParam *> _params;
        AbstractType *_type;
    };

    class Function : public AbstractExpr {
    public:
        Function(FunctionDeclaration *declaration, AbstractExpr *body);

        std::string decompile(int indent) const override;

        bool isFunc() const override;

        Symbol *getSymbol() const;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        FunctionDeclaration *_declaration;
        AbstractExpr *_body;
        Symbol *_symbol;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Return : public AbstractExpr {
    public:
        explicit Return(AbstractExpr *expr);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        bool isReturn() const override;

        std::string dump(int indent) const override;

    private:
        AbstractExpr *_expr;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Lambda : public AbstractExpr {
    public:
        Lambda(const std::vector<FunctionParam *> &params, AbstractType *type, AbstractExpr *body);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        std::vector<FunctionParam *> _params;
        AbstractType *_type;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class If : public AbstractExpr {
    public:
        If(AbstractExpr *condition, AbstractExpr *then, AbstractExpr *else_);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

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

        std::string decompile(int indent) const override;

        AbstractLiteral *getLiteral() const;

        std::string dump(int indent) const override;

        bool isDefault() const;

    private:
        bool _isDefault;
        AbstractLiteral *_literal;
    };

    class SwitchCase : public AbstractExpr {
    public:
        explicit SwitchCase(SwitchPattern *pattern, AbstractExpr *body);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

//        AbstractType *inferPatternType(Environment *env);

        std::string dump(int indent) const override;

    private:
        SwitchPattern *_pattern;
        AbstractExpr *_body;
    };

    class Switch : public AbstractExpr {
    public:
        Switch(AbstractExpr *condition, const std::vector<SwitchCase *> &cases);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        AbstractExpr *_condition;
        std::vector<SwitchCase *> _cases;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class ForICondition : public AST {
    public:
        ForICondition(VariableDeclaration *declaration, AbstractExpr *condition, AbstractExpr *increment);

        std::string decompile(int indent) const override;

//        void resolveCondition(Environment *loop);

//        void inferCondition(Environment *env, Environment *loop);

        std::string dump(int indent) const override;

    private:
        VariableDeclaration *_declaration;
        AbstractExpr *_condition;
        AbstractExpr *_increment;
    };

    class ForI : public AbstractExpr {
    public:
        ForI(ForICondition *condition, AbstractExpr *body);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        ForICondition *_condition;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class ForIterCondition : public AST {
    public:
        ForIterCondition(bool isVal, Identifier *iterator, Identifier *iterable);

        std::string decompile(int indent) const override;

//        void resolveCondition(Environment *loop);

//        void inferCondition(Environment *env, Environment *loop);

        std::string dump(int indent) const override;

    private:
        bool _isVal;
        Identifier *_iterator;
        Identifier *_iterable;
    };

    class ForIter : public AbstractExpr {
    public:
        ForIter(ForIterCondition *condition, AbstractExpr *body);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        ForIterCondition *_condition;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class While : public AbstractExpr {
    public:
        While(AbstractExpr *condition, AbstractExpr *body);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        AbstractExpr *_condition;
        AbstractExpr *_body;
        Environment *_environment;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class FunctionCall : public AbstractExpr {
    public:
        FunctionCall(Identifier *name, const std::vector<AbstractExpr *> &args);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        Identifier *_name;
        std::vector<AbstractExpr *> _args;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class Cast : public AbstractExpr {
    public:
        Cast(AbstractType *type, AbstractExpr *expr);

        std::string decompile(int indent) const override;

        //void resolveEnvironment(Environment *parent) override;

        //AbstractType *inferType(Environment *env) override;

        std::string dump(int indent) const override;

    private:
        AbstractType *_type;
        AbstractExpr *_expr;
    };
}

bool operator==(const ast::AbstractType &a, const ast::AbstractType &b);

bool operator!=(const ast::AbstractType &a, const ast::AbstractType &b);

#endif //FILC_AST_HPP
