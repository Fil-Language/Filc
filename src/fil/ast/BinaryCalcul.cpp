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

void BinaryCalcul::resolveEnvironment(Environment *parent) {
    _left->resolveEnvironment(parent);
    _right->resolveEnvironment(parent);
}

AbstractType *BinaryCalcul::inferType(Environment *env) {
    auto leftType = _left->inferType(env);
    auto rightType = _right->inferType(env);

    if (leftType != rightType) {
        ErrorsRegister::addError(
                "Type mismatch: " + leftType->getName() + " and " + rightType->getName(),
                _pos
        );
    }

    _exprType = leftType;

    return _exprType;
}
