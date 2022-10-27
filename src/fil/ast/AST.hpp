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

        Program(std::string moduleName, std::vector<Program> &imports, std::vector<AbstractExpr> &exprs);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::string _moduleName;
        std::vector<Program> _imports;
        std::vector<AbstractExpr> _exprs;
    };

    // ====================

    class ExprBlock : public AbstractExpr {
    public:
        ExprBlock();

        explicit ExprBlock(std::vector<AbstractExpr> &exprs);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::vector<AbstractExpr> _exprs;
    };

    // ====================

    class ExprParenthesis : public AbstractExpr {
    public:
        ExprParenthesis();

        explicit ExprParenthesis(std::vector<AbstractExpr> &exprs);

        IndentPrinter *print(IndentPrinter *printer) const override;

    private:
        std::vector<AbstractExpr> _exprs;
    };
}

std::ostream &operator<<(std::ostream &os, const ast::AST &ast);

#endif //FILC_AST_HPP
