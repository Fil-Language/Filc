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

    class Program : public AST {
    public:
        Program(const std::string &module, const std::vector<Program *> &imports);

        ~Program();

        std::string decompile(int indent) const override;

    private:
        std::string _module;
        std::vector<Program *> _imports;
    };
}

#endif //FILC_AST_HPP
