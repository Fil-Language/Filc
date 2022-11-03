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

        virtual IndentPrinter *print(IndentPrinter *printer) const = 0;
    };

    // ====================

    class Type : public AST {
    public:
        Type();

        explicit Type(const std::string &name);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::string _name;
    };

    // ====================

    class AbstractExpr : public AST {
    public:
        AbstractExpr();

        void setExport(bool export_);

        IndentPrinter *print(IndentPrinter *printer) const override;

    protected:
        bool _export;
    };

    // ====================

    class Identifier : public AbstractExpr {
    public:
        Identifier();

        explicit Identifier(const std::string &name);

        IndentPrinter *print(IndentPrinter *printer) const override;

    protected:
        std::string _name;
    };

    // ====================

    class Program : public AST {
    public:
        Program();

        explicit Program(std::string moduleName);

        Program(std::string moduleName, std::vector<Program *> &imports, std::vector<AbstractExpr *> &exprs);

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class ExprParenthesis : public AbstractExpr {
    public:
        ExprParenthesis();

        explicit ExprParenthesis(std::vector<AbstractExpr *> &exprs);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::vector<AbstractExpr *> _exprs;
    };

    // ====================

    class AbstractLiteral : public AbstractExpr {
    public:
        AbstractLiteral();

        IndentPrinter *print(IndentPrinter *printer) const override;
    };

    // ====================

    class Integer : public AbstractLiteral {
    public:
        Integer();

        explicit Integer(int value);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        int _value;
    };

    // ====================

    class Float : public AbstractLiteral {
    public:
        Float();

        explicit Float(float value);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        float _value;
    };

    // ====================

    class Double : public AbstractLiteral {
    public:
        Double();

        explicit Double(double value);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        double _value;
    };

    // ====================

    class String : public AbstractLiteral {
    public:
        String();

        explicit String(const std::string &value);

        IndentPrinter *print(IndentPrinter *printer) const override;

    protected:
        std::string _value;
    };

    // ====================

    class FString : public String {
    public:
        explicit FString(const std::string &value);

        IndentPrinter *print(IndentPrinter *printer) const override;
    };

    // ====================

    class Char : public AbstractLiteral {
    public:
        Char();

        explicit Char(char value);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        char _value;
    };

    // ====================

    class AbstractBool : public AbstractLiteral {
    public:
        AbstractBool();

        IndentPrinter *print(IndentPrinter *printer) const override;
    };

    // ====================

    class True : public AbstractBool {
    public:
        True();

        IndentPrinter *print(IndentPrinter *printer) const override;
    };

    // ====================

    class False : public AbstractBool {
    public:
        False();

        IndentPrinter *print(IndentPrinter *printer) const override;
    };

    // ====================

    class Null : public AbstractLiteral {
    public:
        Null();

        IndentPrinter *print(IndentPrinter *printer) const override;
    };

    // ====================

    class FunctionParam : public AST {
    public:
        FunctionParam();

        FunctionParam(Identifier *name, Type *type);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        Identifier *_name;
        Type *_type;
    };

    // ====================

    class Function : public AbstractExpr {
    public:
        Function();

        Function(Identifier *name, std::vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType);

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::vector<FunctionParam *> _params;
        AbstractExpr *_body;
    };

    // ====================

    class ClassIdentifier : public Identifier {
    public:
        ClassIdentifier();

        explicit ClassIdentifier(const std::string &name, std::vector<Type *> &generics);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::vector<Type *> _generics;
    };

    // ====================

    class ClassParam : public AST {
    public:
        ClassParam();

        explicit ClassParam(VariableDecl *decl);

        ClassParam(Identifier *name, Type *type, AbstractLiteral *defaultValue);

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        ClassIdentifier *_identifier;
        std::vector<AbstractExpr *> _args;
    };

    // ====================

    class ClassVariable : public AST {
    public:
        ClassVariable();

        ClassVariable(const std::string &visibility, VariableDecl *decl);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::string _visibility;
        VariableDecl *_decl;
    };

    // ====================

    class ClassFunction : public AST {
    public:
        ClassFunction();

        ClassFunction(const std::string &modifier, const std::string &visibility, AST *function);

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        AbstractLiteral *_value;
        AbstractExpr *_body;
    };

    // ====================

    class Switch : public AbstractExpr {
    public:
        Switch();

        Switch(ExprParenthesis *condition, std::vector<SwitchCase *> &cases);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        ExprParenthesis *_condition;
        std::vector<SwitchCase *> _cases;
    };

    // ====================

    class AbstractLoop : public AbstractExpr {
    public:
        AbstractLoop();

        IndentPrinter *print(IndentPrinter *printer) const override;

    protected:
        AbstractExpr *_body;
    };

    // ====================

    class While : public AbstractLoop {
    public:
        While();

        While(ExprParenthesis *condition, AbstractExpr *body);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        ExprParenthesis *_condition;
    };

    // ====================

    class For : public AbstractLoop {
    public:
        For();

        For(VariableDecl *iterator, AbstractExpr *condition, AbstractExpr *increment, AbstractExpr *body);

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

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

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        Identifier *_name;
        std::vector<AbstractExpr *> _args;
    };

    // ====================

    class Catch : public AbstractExpr {
    public:
        Catch();

        Catch(FunctionParam *param, AbstractExpr *body);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        FunctionParam *_param;
        AbstractExpr *_body;
    };

    // ====================

    class Try : public AbstractExpr {
    public:
        Try();

        Try(AbstractExpr *body, std::vector<Catch *> &catches);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        AbstractExpr *_body;
        std::vector<Catch *> _catches;
    };

    // ====================

    class DotExpr : public AbstractExpr {
    public:
        DotExpr();

        DotExpr(AbstractExpr *left, AbstractExpr *right);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        AbstractExpr *_left;
        AbstractExpr *_right;
    };
}

std::ostream &operator<<(std::ostream &os, const ast::AST &ast);

#endif //FILC_AST_HPP
