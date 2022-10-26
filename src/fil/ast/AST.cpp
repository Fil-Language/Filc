/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.h"

std::ostream &operator<<(std::ostream &os, const ast::AST &ast) {
    os << ast.toString();
    return os;
}