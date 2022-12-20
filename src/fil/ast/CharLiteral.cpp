/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

CharLiteral::CharLiteral(const string &value) {
    _value = value[1];
}

string CharLiteral::decompile(int indent) const {
    return "'" + string(1, _value) + "'";
}

AbstractType *CharLiteral::inferType(Environment *env) {
    _exprType = env->getSymbol("char")->getType();

    return _exprType;
}
