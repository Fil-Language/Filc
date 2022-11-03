/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractCalcul::AbstractCalcul() : _op(nullptr) {}

IndentPrinter *AbstractCalcul::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}

// ====================

UnaryCalcul::UnaryCalcul() : _isPrefix(false), _expr(nullptr) {}

UnaryCalcul::UnaryCalcul(Operator *op, AbstractExpr *expr)
        : _isPrefix(true), _expr(expr) {
    _op = op;
}

UnaryCalcul::UnaryCalcul(AbstractExpr *expr, Operator *op)
        : _isPrefix(false), _expr(expr) {
    _op = op;
}

IndentPrinter *UnaryCalcul::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}
