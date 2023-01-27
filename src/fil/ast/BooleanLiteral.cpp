/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

BooleanLiteral::BooleanLiteral(bool value)
        : _value(value) {}

string BooleanLiteral::decompile(int indent) const {
    return _value ? "true" : "false";
}

//AbstractType *BooleanLiteral::inferType(Environment *env) {
//    _exprType = env->getSymbol("bool")->getSignature();
//
//    return _exprType;
//}

string BooleanLiteral::dump(int indent) const {
    string res = string(indent, '\t') + "[BooleanLiteral]" + (_isExported ? " <exported>" : "") + " <value:";
    res += _value ? "true" : "false";

    return res + ">\n";
}
