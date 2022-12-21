/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

IntegerLiteral::IntegerLiteral(int value)
        : _value(value) {}

string IntegerLiteral::decompile(int indent) const {
    return to_string(_value);
}

AbstractType *IntegerLiteral::inferType(Environment *env) {
    _exprType = env->getSymbol("int")->getType();

    return _exprType;
}

string IntegerLiteral::dump(int indent) const {
    return string(indent, '\t') + "[IntegerLiteral] <value:" + to_string(_value) + ">\n";
}
