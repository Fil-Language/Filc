/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_AST_HPP
#define FILC_AST_HPP

#include <string>

namespace ast {
    class AST {
    public:
        AST();

        ~AST();

        virtual std::string toString() const = 0;
    };

    // ====================

    class Program : public AST {
    public:
        Program();

        explicit Program(std::string moduleName);

        std::string toString() const override;

    private:
        std::string _moduleName;
    };
}

std::ostream &operator<<(std::ostream &os, const ast::AST &ast);

#endif //FILC_AST_HPP
