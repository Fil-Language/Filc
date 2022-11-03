/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ArrowExpr::ArrowExpr() : _left(nullptr), _right(nullptr) {}

ArrowExpr::ArrowExpr(AbstractExpr *left, AbstractExpr *right)
        : _left(left), _right(right) {}

IndentPrinter *ArrowExpr::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}
