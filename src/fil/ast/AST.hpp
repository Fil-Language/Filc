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

        virtual std::string decompile(int indent) const = 0; // FIXME: change return type to std::string &
    };

    // ====================

    class Type : public AST {
    public:
        Type();

        explicit Type(const std::string &name);

        Type(const std::string &name, bool isPointer);

        Type(const std::string &name, int arraySize);

        std::string decompile(int indent) const override;

    private:
        std::string _name;
        bool _isPointer;
        bool _isArray;
        int _arraySize;
    };

    // ====================

    class AbstractExpr : public AST {
    public:
        AbstractExpr();

        void setExport(bool export_);

        std::string decompile(int indent) const override;

    protected:
        bool _export;
    };

    // ====================

    class Identifier : public AbstractExpr {
    public:
        Identifier();

        explicit Identifier(const std::string &name);

        std::string decompile(int indent) const override;

    protected:
        std::string _name;
    };

    // ====================

    class Program : public AST {
    public:
        Program();

        explicit Program(std::string moduleName);

        Program(std::string moduleName, std::vector<Program *> &imports, std::vector<AbstractExpr *> &exprs);

        ~Program();

        std::string decompile(int indent) const override;

    private:
        std::string _moduleName;
        std::vector<Program *> _imports;
        std::vector<AbstractExpr *> _exprs;
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

        ~Operator();

        std::string decompile(int indent) const override;

        Operator::OP _op;

    protected:
        AbstractExpr *_expr;
    };

    // ====================

    class AssignationOperator : public Operator {
    public:
        AssignationOperator();

        explicit AssignationOperator(Operator *prefix);

        std::string decompile(int indent) const override;
    };

    // ====================

    class VariableDecl : public AbstractExpr {
    public:
        VariableDecl();

        VariableDecl(bool isVal, Identifier *name, Type *type);

        VariableDecl(bool isVal, Identifier *name, Type *type, AssignationOperator *op, AbstractExpr *value);

        ~VariableDecl();

        std::string decompile(int indent) const override;

    private:
        bool _isVal;
        Identifier *_name;
        Type *_type;
        AssignationOperator *_op;
        AbstractExpr *_value;
    };

    // ====================

    class ExprBlock : public AbstractExpr {
    public:
        ExprBlock();

        explicit ExprBlock(std::vector<AbstractExpr *> &exprs);

        ~ExprBlock();

        std::string decompile(int indent) const override;

    private:
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class ExprParenthesis : public AbstractExpr {
    public:
        ExprParenthesis();

        explicit ExprParenthesis(std::vector<AbstractExpr *> &exprs);

        ~ExprParenthesis();

        std::string decompile(int indent) const override;

    private:
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class AbstractLiteral : public AbstractExpr {
    public:
        AbstractLiteral();

        std::string decompile(int indent) const override;
    };

    // ====================

    class Integer : public AbstractLiteral {
    public:
        Integer();

        explicit Integer(int value);

        std::string decompile(int indent) const override;

    private:
        int _value;
    };

    // ====================

    class Float : public AbstractLiteral {
    public:
        Float();

        explicit Float(float value);

        std::string decompile(int indent) const override;

    private:
        float _value;
    };

    // ====================

    class Double : public AbstractLiteral {
    public:
        Double();

        explicit Double(double value);

        std::string decompile(int indent) const override;

    private:
        double _value;
    };

    // ====================

    class String : public AbstractLiteral {
    public:
        String();

        explicit String(const std::string &value);

        std::string decompile(int indent) const override;

    protected:
        std::string _value;
    };

    // ====================

    class FString : public String {
    public:
        explicit FString(const std::string &value);

        std::string decompile(int indent) const override;
    };

    // ====================

    class Char : public AbstractLiteral {
    public:
        Char();

        explicit Char(char value);

        std::string decompile(int indent) const override;

    private:
        char _value;
    };

    // ====================

    class AbstractBool : public AbstractLiteral {
    public:
        AbstractBool();

        std::string decompile(int indent) const override;
    };

    // ====================

    class True : public AbstractBool {
    public:
        True();

        std::string decompile(int indent) const override;
    };

    // ====================

    class False : public AbstractBool {
    public:
        False();

        std::string decompile(int indent) const override;
    };

    // ====================

    class Null : public AbstractLiteral {
    public:
        Null();

        std::string decompile(int indent) const override;
    };

    // ====================

    class FunctionParam : public AST {
    public:
        FunctionParam();

        FunctionParam(Identifier *name, Type *type);

        ~FunctionParam();

        std::string decompile(int indent) const override;

    private:
        Identifier *_name;
        Type *_type;
    };

    // ====================

    class Function : public AbstractExpr {
    public:
        Function();

        Function(Identifier *name, std::vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType);

        ~Function();

        std::string decompile(int indent) const override;

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

        ~FunctionDecl();

        std::string decompile(int indent) const override;

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

        ~Lambda();

        std::string decompile(int indent) const override;

    private:
        std::vector<FunctionParam *> _params;
        AbstractExpr *_body;
    };

    // ====================

    class ClassIdentifier : public Identifier {
    public:
        ClassIdentifier();

        explicit ClassIdentifier(const std::string &name, std::vector<Type *> &generics);

        ~ClassIdentifier();

        std::string decompile(int indent) const override;

    private:
        std::vector<Type *> _generics;
    };

    // ====================

    class ClassParam : public AST {
    public:
        ClassParam();

        explicit ClassParam(VariableDecl *decl);

        ClassParam(Identifier *name, Type *type, AbstractLiteral *defaultValue);

        ~ClassParam();

        std::string decompile(int indent) const override;

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

        ~ClassExtend();

        std::string decompile(int indent) const override;

    private:
        ClassIdentifier *_identifier;
        std::vector<AbstractExpr *> _args;
    };

    // ====================

    class ClassVariable : public AST {
    public:
        ClassVariable();

        ClassVariable(const std::string &visibility, VariableDecl *decl);

        ~ClassVariable();

        std::string decompile(int indent) const override;

    private:
        std::string _visibility;
        VariableDecl *_decl;
    };

    // ====================

    class ClassFunction : public AST {
    public:
        ClassFunction();

        ClassFunction(const std::string &modifier, const std::string &visibility, AST *function);

        ~ClassFunction();

        std::string decompile(int indent) const override;

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

        ~Class();

        std::string decompile(int indent) const override;

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

        Interface(Identifier *name, std::vector<FunctionDecl *> &functions);

        ~Interface();

        std::string decompile(int indent) const override;

    private:
        Identifier *_name;
        std::vector<FunctionDecl *> _functions;
    };

    // ====================

    class Enum : public AbstractExpr {
    public:
        Enum();

        Enum(Identifier *name, std::vector<Identifier *> &values);

        ~Enum();

        std::string decompile(int indent) const override;

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

        ~If();

        std::string decompile(int indent) const override;

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

        ~SwitchCase();

        std::string decompile(int indent) const override;

    private:
        AbstractLiteral *_value;
        AbstractExpr *_body;
    };

    // ====================

    class Switch : public AbstractExpr {
    public:
        Switch();

        Switch(ExprParenthesis *condition, std::vector<SwitchCase *> &cases);

        ~Switch();

        std::string decompile(int indent) const override;

    private:
        ExprParenthesis *_condition;
        std::vector<SwitchCase *> _cases;
    };

    // ====================

    class AbstractLoop : public AbstractExpr {
    public:
        AbstractLoop();

        ~AbstractLoop();

        std::string decompile(int indent) const override;

    protected:
        AbstractExpr *_body;
    };

    // ====================

    class While : public AbstractLoop {
    public:
        While();

        While(ExprParenthesis *condition, AbstractExpr *body);

        ~While();

        std::string decompile(int indent) const override;

    private:
        ExprParenthesis *_condition;
    };

    // ====================

    class For : public AbstractLoop {
    public:
        For();

        For(VariableDecl *iterator, AbstractExpr *condition, AbstractExpr *increment, AbstractExpr *body);

        ~For();

        std::string decompile(int indent) const override;

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

        ~ForIter();

        std::string decompile(int indent) const override;

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

        ~FunctionCall();

        std::string decompile(int indent) const override;

    private:
        Identifier *_name;
        std::vector<AbstractExpr *> _args;
    };

    // ====================

    class Catch : public AbstractExpr {
    public:
        Catch();

        Catch(FunctionParam *param, AbstractExpr *body);

        ~Catch();

        std::string decompile(int indent) const override;

    private:
        FunctionParam *_param;
        AbstractExpr *_body;
    };

    // ====================

    class Try : public AbstractExpr {
    public:
        Try();

        Try(AbstractExpr *body, std::vector<Catch *> &catches);

        ~Try();

        std::string decompile(int indent) const override;

    private:
        AbstractExpr *_body;
        std::vector<Catch *> _catches;
    };

    // ====================

    class DotExpr : public AbstractExpr {
    public:
        DotExpr();

        DotExpr(AbstractExpr *left, AbstractExpr *right);

        ~DotExpr();

        std::string decompile(int indent) const override;

    private:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };

    // ====================

    class ArrowExpr : public AbstractExpr {
    public:
        ArrowExpr();

        ArrowExpr(AbstractExpr *left, AbstractExpr *right);

        ~ArrowExpr();

        std::string decompile(int indent) const override;

    private:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };

    // ====================

    class OperatorIdentifier : public Identifier {
    public:
        OperatorIdentifier();

        OperatorIdentifier(const std::string &name, Operator *op);

        ~OperatorIdentifier();

        std::string decompile(int indent) const override;

    private:
        Operator *_op;
    };

    // ====================

    class AbstractCalcul : public AbstractExpr {
    public:
        AbstractCalcul();

        ~AbstractCalcul();

        std::string decompile(int indent) const override;

    protected:
        Operator *_op;
    };

    // ====================

    class UnaryCalcul : public AbstractCalcul {
    public:
        UnaryCalcul();

        UnaryCalcul(Operator *op, AbstractExpr *expr);

        UnaryCalcul(AbstractExpr *expr, Operator *op);

        ~UnaryCalcul();

        std::string decompile(int indent) const override;

    private:
        bool _isPrefix;
        AbstractExpr *_expr;
    };

    // ====================

    class BinaryCalcul : public AbstractCalcul {
    public:
        BinaryCalcul();

        BinaryCalcul(AbstractExpr *left, Operator *op, AbstractExpr *right);

        ~BinaryCalcul();

        std::string decompile(int indent) const override;

    protected:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };

    // ====================

    class Assignation : public BinaryCalcul {
    public:
        Assignation();

        Assignation(AbstractExpr *left, AssignationOperator *op, AbstractExpr *right);

        std::string decompile(int indent) const override;
    };

    // ====================

    class Cast : public AbstractExpr {
    public:
        Cast();

        Cast(Type *type, AbstractExpr *expr);

        ~Cast();

        std::string decompile(int indent) const override;

    private:
        Type *_type;
        AbstractExpr *_expr;
    };

    // ====================

    class Return : public AbstractExpr {
    public:
        Return();

        explicit Return(AbstractExpr *expr);

        ~Return();

        std::string decompile(int indent) const override;

    private:
        AbstractExpr *_expr;
    };

    // ====================

    class Array : public AbstractExpr {
    public:
        Array();

        explicit Array(std::vector<AbstractExpr *> &values);

        ~Array();

        std::string decompile(int indent) const override;

    private:
        std::vector<AbstractExpr *> _values;
    };

    // ====================

    class New : public AbstractExpr {
    public:
        New();

        New(ClassIdentifier *identifier, std::vector<AbstractExpr *> &args);

        New(ClassIdentifier *identifier, std::vector<AbstractExpr *> &args, bool isPointer);

        ~New();

        std::string decompile(int indent) const override;

    private:
        ClassIdentifier *_identifier;
        std::vector<AbstractExpr *> _args;
        bool _isPointer;
    };
}

#endif //FILC_AST_HPP
