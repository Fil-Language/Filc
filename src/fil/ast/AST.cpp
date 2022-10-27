/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ostream &operator<<(ostream &os, const AST &ast) {
    os << ast.toString();
    return os;
}

AST::~AST() = default;

AST::AST() = default;
