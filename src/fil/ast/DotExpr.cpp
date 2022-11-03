/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

DotExpr::DotExpr() : _left(nullptr), _right(nullptr) {}

DotExpr::DotExpr(AbstractExpr *left, AbstractExpr *right)
        : _left(left), _right(right) {}

IndentPrinter *DotExpr::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}
