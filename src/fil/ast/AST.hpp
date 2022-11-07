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

#include "utils.h"

namespace ast {
    class AST {
    public:
        AST();

        ~AST();
    };

    // ====================

    class Type : public AST {
    public:
        Type();

        explicit Type(const std::string &name);

    private:
        std::string _name;
    };

    // ====================

    class AbstractExpr : public AST {
    public:
        AbstractExpr();

        void setExport(bool export_);

    protected:
        bool _export;
    };

    // ====================

    class Identifier : public AbstractExpr {
    public:
        Identifier();

        explicit Identifier(const std::string &name);

    protected:
        std::string _name;
    };

    // ====================

    class Program : public AST {
    public:
        Program();

        explicit Program(std::string moduleName);

        Program(std::string moduleName, std::vector<Program *> &imports, std::vector<AbstractExpr *> &exprs);

    private:
        std::string _moduleName;
        std::vector<Program *> _imports;
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class VariableDecl : public AbstractExpr {
    public:
        VariableDecl();

        VariableDecl(bool isVal, Identifier *name, Type *type);

    private:
        bool _isVal;
        Identifier *_name;
        Type *_type;
    };

    // ====================

    class ExprBlock : public AbstractExpr {
    public:
        ExprBlock();

        explicit ExprBlock(std::vector<AbstractExpr *> &exprs);

    private:
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class ExprParenthesis : public AbstractExpr {
    public:
        ExprParenthesis();

        explicit ExprParenthesis(std::vector<AbstractExpr *> &exprs);

    private:
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class AbstractLiteral : public AbstractExpr {
    public:
        AbstractLiteral();
    };

    // ====================

    class Integer : public AbstractLiteral {
    public:
        Integer();

        explicit Integer(int value);

    private:
        int _value;
    };

    // ====================

    class Float : public AbstractLiteral {
    public:
        Float();

        explicit Float(float value);

    private:
        float _value;
    };

    // ====================

    class Double : public AbstractLiteral {
    public:
        Double();

        explicit Double(double value);

    private:
        double _value;
    };

    // ====================

    class String : public AbstractLiteral {
    public:
        String();

        explicit String(const std::string &value);

    protected:
        std::string _value;
    };

    // ====================

    class FString : public String {
    public:
        explicit FString(const std::string &value);
    };

    // ====================

    class Char : public AbstractLiteral {
    public:
        Char();

        explicit Char(char value);

    private:
        char _value;
    };

    // ====================

    class AbstractBool : public AbstractLiteral {
    public:
        AbstractBool();
    };

    // ====================

    class True : public AbstractBool {
    public:
        True();
    };

    // ====================

    class False : public AbstractBool {
    public:
        False();
    };

    // ====================

    class Null : public AbstractLiteral {
    public:
        Null();
    };

    // ====================

    class FunctionParam : public AST {
    public:
        FunctionParam();

        FunctionParam(Identifier *name, Type *type);

    private:
        Identifier *_name;
        Type *_type;
    };

    // ====================

    class Function : public AbstractExpr {
    public:
        Function();

        Function(Identifier *name, std::vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType);

    private:
        Identifier *_name;
        std::vector<FunctionParam *> _params;
        AbstractExpr *_body;
        Type *_returnType;
    };

    // ====================

    class FunctionDecl : public AST {
    public:
        FunctionDecl();

        FunctionDecl(Identifier *name, std::vector<FunctionParam *> &params, Type *returnType);

    private:
        Identifier *_name;
        std::vector<FunctionParam *> _params;
        Type *_returnType;
    };

    // ====================

    class Lambda : public AbstractExpr {
    public:
        Lambda();

        Lambda(std::vector<FunctionParam *> &params, AbstractExpr *body);

    private:
        std::vector<FunctionParam *> _params;
        AbstractExpr *_body;
    };

    // ====================

    class ClassIdentifier : public Identifier {
    public:
        ClassIdentifier();

        explicit ClassIdentifier(const std::string &name, std::vector<Type *> &generics);

    private:
        std::vector<Type *> _generics;
    };

    // ====================

    class ClassParam : public AST {
    public:
        ClassParam();

        explicit ClassParam(VariableDecl *decl);

        ClassParam(Identifier *name, Type *type, AbstractLiteral *defaultValue);

    private:
        bool _isDecl;
        VariableDecl *_decl;
        Identifier *_name;
        Type *_type;
        AbstractLiteral *_defaultValue;
    };

    // ====================

    class ClassExtend : public AST {
    public:
        ClassExtend();

        explicit ClassExtend(ClassIdentifier *identifier, std::vector<AbstractExpr *> &args);

    private:
        ClassIdentifier *_identifier;
        std::vector<AbstractExpr *> _args;
    };

    // ====================

    class ClassVariable : public AST {
    public:
        ClassVariable();

        ClassVariable(const std::string &visibility, VariableDecl *decl);

    private:
        std::string _visibility;
        VariableDecl *_decl;
    };

    // ====================

    class ClassFunction : public AST {
    public:
        ClassFunction();

        ClassFunction(const std::string &modifier, const std::string &visibility, AST *function);

    private:
        std::string _modifier;
        std::string _visibility;
        AST *_function; // Function or FunctionDecl
    };

    // ====================

    class Class : public AbstractExpr {
    public:
        Class();

        Class(const std::string &modifier,
              ClassIdentifier *name,
              std::vector<ClassParam *> &params,
              std::vector<ClassExtend *> &extends,
              ExprBlock *constructor,
              std::vector<ClassVariable *> &variables,
              std::vector<ClassFunction *> &functions);

    private:
        std::string _modifier;
        ClassIdentifier *_name;
        std::vector<ClassParam *> _params;
        std::vector<ClassExtend *> _extends;
        ExprBlock *_constructor;
        std::vector<ClassVariable *> _variables;
        std::vector<ClassFunction *> _functions;
    };

    // ====================

    class Interface : public AbstractExpr {
    public:
        Interface();

        Interface(Identifier *name, std::vector<ClassParam *> &params, std::vector<FunctionDecl *> &functions);

    private:
        Identifier *_name;
        std::vector<ClassParam *> _params;
        std::vector<FunctionDecl *> _functions;
    };

    // ====================

    class Enum : public AbstractExpr {
    public:
        Enum();

        Enum(Identifier *name, std::vector<Identifier *> &values);

    private:
        Identifier *_name;
        std::vector<Identifier *> _values;
    };

    // ====================

    class If : public AbstractExpr {
    public:
        If();

        If(ExprParenthesis *condition, AbstractExpr *then);

        If(ExprParenthesis *condition, AbstractExpr *then, std::vector<If *> &elseIf, AbstractExpr *else_);

    private:
        ExprParenthesis *_condition;
        AbstractExpr *_then;
        std::vector<If *> _elseIf;
        AbstractExpr *_else;
    };

    // ====================

    class SwitchCase : public AST {
    public:
        SwitchCase();

        explicit SwitchCase(AbstractExpr *body);

        SwitchCase(AbstractLiteral *value, AbstractExpr *body);

    private:
        AbstractLiteral *_value;
        AbstractExpr *_body;
    };

    // ====================

    class Switch : public AbstractExpr {
    public:
        Switch();

        Switch(ExprParenthesis *condition, std::vector<SwitchCase *> &cases);

    private:
        ExprParenthesis *_condition;
        std::vector<SwitchCase *> _cases;
    };

    // ====================

    class AbstractLoop : public AbstractExpr {
    public:
        AbstractLoop();

    protected:
        AbstractExpr *_body;
    };

    // ====================

    class While : public AbstractLoop {
    public:
        While();

        While(ExprParenthesis *condition, AbstractExpr *body);

    private:
        ExprParenthesis *_condition;
    };

    // ====================

    class For : public AbstractLoop {
    public:
        For();

        For(VariableDecl *iterator, AbstractExpr *condition, AbstractExpr *increment, AbstractExpr *body);

    private:
        VariableDecl *_iterator;
        AbstractExpr *_condition;
        AbstractExpr *_increment;
    };

    // ====================

    class ForIter : public AbstractLoop {
    public:
        ForIter();

        ForIter(const std::string &modifier, Identifier *iterator, Identifier *iterable, AbstractExpr *body);

    private:
        std::string _modifier;
        Identifier *_iterator;
        Identifier *_iterable;
    };

    // ====================

    class FunctionCall : public AbstractExpr {
    public:
        FunctionCall();

        FunctionCall(Identifier *name, std::vector<AbstractExpr *> &args);

    private:
        Identifier *_name;
        std::vector<AbstractExpr *> _args;
    };

    // ====================

    class Catch : public AbstractExpr {
    public:
        Catch();

        Catch(FunctionParam *param, AbstractExpr *body);

    private:
        FunctionParam *_param;
        AbstractExpr *_body;
    };

    // ====================

    class Try : public AbstractExpr {
    public:
        Try();

        Try(AbstractExpr *body, std::vector<Catch *> &catches);

    private:
        AbstractExpr *_body;
        std::vector<Catch *> _catches;
    };

    // ====================

    class DotExpr : public AbstractExpr {
    public:
        DotExpr();

        DotExpr(AbstractExpr *left, AbstractExpr *right);

    private:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };

    // ====================

    class ArrowExpr : public AbstractExpr {
    public:
        ArrowExpr();

        ArrowExpr(AbstractExpr *left, AbstractExpr *right);

    private:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };

    // ====================

    class Operator : public AST {
    public:
        typedef enum {
            PLUS,
            MINUS,
            DIVIDE,
            TIMES,
            MOD,
            FLEFT,
            FRIGHT,
            AND,
            OR,
            LT,
            GT,
            EQEQ,
            LEQ,
            GEQ,
            NEQ,
            BAND,
            BOR,
            BXOR,
            PLUSPLUS,
            MINMIN,
            NOT,
            ARRAY,
        } OP;

        Operator();

        explicit Operator(Operator::OP op);

        Operator(Operator::OP op, AbstractExpr *expr);

        Operator::OP _op;

    protected:
        AbstractExpr *_expr;
    };

    // ====================

    class OperatorIdentifier : public Identifier {
    public:
        OperatorIdentifier();

        OperatorIdentifier(const std::string &name, Operator *op);

    private:
        Operator *_op;
    };

    // ====================

    class AbstractCalcul : public AbstractExpr {
    public:
        AbstractCalcul();

    protected:
        Operator *_op;
    };

    // ====================

    class UnaryCalcul : public AbstractCalcul {
    public:
        UnaryCalcul();

        UnaryCalcul(Operator *op, AbstractExpr *expr);

        UnaryCalcul(AbstractExpr *expr, Operator *op);

    private:
        bool _isPrefix;
        AbstractExpr *_expr;
    };

    // ====================

    class BinaryCalcul : public AbstractCalcul {
    public:
        BinaryCalcul();

        BinaryCalcul(AbstractExpr *left, Operator *op, AbstractExpr *right);

    protected:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };

    // ====================

    class AssignationOperator : public Operator {
    public:
        AssignationOperator();

        explicit AssignationOperator(Operator *prefix);
    };

    // ====================

    class Assignation : public BinaryCalcul {
    public:
        Assignation();

        Assignation(AbstractExpr *left, AssignationOperator *op, AbstractExpr *right);
    };

    // ====================

    class Cast : public AbstractExpr {
    public:
        Cast();

        Cast(Type *type, AbstractExpr *expr);

    private:
        Type *_type;
        AbstractExpr *_expr;
    };

    // ====================

    class Return : public AbstractExpr {
    public:
        Return();

        explicit Return(AbstractExpr *expr);

    private:
        AbstractExpr *_expr;
    };

    // ====================

    class Array : public AbstractExpr {
    public:
        Array();

        explicit Array(std::vector<AbstractExpr *> &values);

    private:
        std::vector<AbstractExpr *> _values;
    };
}

#endif //FILC_AST_HPP
