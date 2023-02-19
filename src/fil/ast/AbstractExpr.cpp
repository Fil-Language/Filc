/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractExpr::AbstractExpr() : _isExported(false), _exprType(nullptr) {}

string AbstractExpr::decompile(int indent) const {
    throw;
}

void AbstractExpr::isExported(bool exported) {
    _isExported = exported;
}

bool AbstractExpr::isExported() const {
    return _isExported;
}

bool AbstractExpr::isVar() const {
    return false;
}

bool AbstractExpr::isFunc() const {
    return false;
}

bool AbstractExpr::isReturn() const {
    return false;
}

AbstractType *AbstractExpr::getExprType() const {
    return _exprType;
}
