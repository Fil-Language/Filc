/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Operator::Operator() : _expr(nullptr) {}

Operator::Operator(Operator::OP op)
        : _op(op), _expr(nullptr) {}

Operator::Operator(Operator::OP op, AbstractExpr *expr)
        : _op(op), _expr(expr) {}

IndentPrinter *Operator::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}
