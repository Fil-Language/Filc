/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_AST_HPP
#define FILC_AST_HPP

#include "AST.h"

#include <iostream>

namespace ast {
    class AST {
    public:
        AST() = default;

        virtual ~AST() = default;

        virtual std::string toString() const = 0;
    };
}

std::ostream &operator<<(std::ostream &os, const ast::AST &ast);

#endif //FILC_AST_HPP
