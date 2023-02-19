/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
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

string IntegerLiteral::dump(int indent) const {
    return string(indent, '\t') + "[IntegerLiteral]" + (_isExported ? " <exported>" : "") +
           " <value:" + to_string(_value) + ">\n";
}
