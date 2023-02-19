/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
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

string BooleanLiteral::dump(int indent) const {
    string res = string(indent, '\t') + "[BooleanLiteral]" + (_isExported ? " <exported>" : "") + " <value:";
    res += _value ? "true" : "false";

    return res + ">\n";
}
