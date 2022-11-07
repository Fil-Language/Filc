/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Assignation::Assignation() = default;

Assignation::Assignation(AbstractExpr *left, AssignationOperator *op, AbstractExpr *right) {
    _left = left;
    _op = op;
    _right = right;
}

IndentPrinter *Assignation::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}

// ====================

AssignationOperator::AssignationOperator() = default;

AssignationOperator::AssignationOperator(Operator *prefix) {
    _op = prefix->_op;
}

IndentPrinter *AssignationOperator::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}
