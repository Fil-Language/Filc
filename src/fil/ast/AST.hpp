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

namespace ast {
    class AST {
    public:
        AST();

        ~AST();

        virtual std::string toString() const = 0;
    };

    // ====================

    class AbstractExpr : public AST {
    public:
        AbstractExpr();

        void setExport(bool export_);

        std::string toString() const override;

    private:
        bool _export;
    };

    // ====================

    class Program : public AST {
    public:
        Program();

        explicit Program(std::string moduleName);

        Program(std::string moduleName, std::vector<Program> &imports, std::vector<AbstractExpr> &exprs);

        std::string toString() const override;

    private:
        std::string _moduleName;
        std::vector<Program> _imports;
        std::vector<AbstractExpr> _exprs;
    };
}

std::ostream &operator<<(std::ostream &os, const ast::AST &ast);

#endif //FILC_AST_HPP
