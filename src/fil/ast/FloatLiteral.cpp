/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
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

string FloatLiteral::dump(int indent) const {
    return string(indent, '\t') + "[FloatLiteral]" + (_isExported ? " <exported>" : "") +
           " <value:" + to_string(_value) + ">\n";
}
