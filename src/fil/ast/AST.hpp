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

        virtual std::string decompile(int indent) const = 0;
    };

    class AbstractExpr : public AST {
    public:
        std::string decompile(int indent) const override;

        void isExported(bool exported);

    protected:
        AbstractExpr();

    protected:
        bool _isExported;
    };

    class Program : public AST {
    public:
        Program(const std::string &module,
                const std::vector<Program *> &imports,
                const std::vector<AbstractExpr *> &exprs);

        ~Program();

        std::string decompile(int indent) const override;

    private:
        std::string _module;
        std::vector<Program *> _imports;
        std::vector<AbstractExpr *> _exprs;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class AbstractLiteral : public AbstractExpr {
    };

    class BooleanLiteral : public AbstractLiteral {
    public:
        explicit BooleanLiteral(bool value);

        std::string decompile(int indent) const override;

    private:
        bool _value;
    };
}

#endif //FILC_AST_HPP
