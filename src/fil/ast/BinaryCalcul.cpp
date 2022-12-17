/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

BinaryCalcul::BinaryCalcul(AbstractExpr *left, Operator *op, AbstractExpr *right)
        : _left(left), _op(op), _right(right) {}

BinaryCalcul::~BinaryCalcul() {
    delete _left;
    delete _op;
    delete _right;
}

string BinaryCalcul::decompile(int indent) const {
    return _left->decompile(indent) + " " + _op->decompile(indent) + " " + _right->decompile(indent);
}
