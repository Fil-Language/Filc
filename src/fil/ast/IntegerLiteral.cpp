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

AbstractType *IntegerLiteral::inferType(Environment *parent) {
    _exprType = parent->getSymbol("int")->getSignature();

    return _exprType;
}

string IntegerLiteral::dump(int indent) const {
    return string(indent, '\t') + "[IntegerLiteral]" + (_isExported ? " <exported>" : "") +
           " <value:" + to_string(_value) + ">\n";
}
