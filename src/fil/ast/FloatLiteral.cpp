/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FloatLiteral::FloatLiteral(float value)
        : _value(value) {}

string FloatLiteral::decompile(int indent) const {
    return to_string(_value);
}

AbstractType *FloatLiteral::inferType(Environment *env) {
    _exprType = env->getSymbol("float")->getType();

    return _exprType;
}

string FloatLiteral::dump(int indent) const {
    return string(indent, '\t') + "[FloatLiteral] <value:" + to_string(_value) + ">\n";
}
