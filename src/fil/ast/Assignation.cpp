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

string Assignation::decompile(int indent) const {
    return _left->decompile(indent) + " " + _op->decompile(indent) + " " + _right->decompile(indent);
}

// ====================

AssignationOperator::AssignationOperator() = default;

AssignationOperator::AssignationOperator(Operator *prefix) {
    if (prefix) {
        _op = prefix->_op;
    }
}

string AssignationOperator::decompile(int indent) const {
    return Operator::decompile(indent) + "=";
}
