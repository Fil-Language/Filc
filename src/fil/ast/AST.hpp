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

    class FunctionParam : public AbstractExpr {
    public:
        FunctionParam();

        explicit FunctionParam(const std::string &name);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::string _name;
    };

    // ====================

    class Function : public AbstractExpr {
    public:
        Function();

        Function(const std::string &name, std::vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::string _name;
        std::vector<FunctionParam *> _params;
        AbstractExpr *_body;
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
}

std::ostream &operator<<(std::ostream &os, const ast::AST &ast);

#endif //FILC_AST_HPP
