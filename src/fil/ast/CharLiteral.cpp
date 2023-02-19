/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
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

string CharLiteral::dump(int indent) const {
    return string(indent, '\t') + "[CharLiteral]" + (_isExported ? " <exported>" : "") +
           " <value:" + string(1, _value) + ">\n";
}
