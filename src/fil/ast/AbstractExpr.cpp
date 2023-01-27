/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
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

Symbol *AbstractExpr::resolveSymbols(Environment *parent) {
    throw;
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

//AbstractType *AbstractExpr::inferType(Environment *env) {
//    throw;
//}

AbstractType *AbstractExpr::getExprType() const {
    return _exprType;
}
