/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

StringLiteral::StringLiteral(const std::string &value) {
    _value = value.substr(1, value.size() - 2);
}

string StringLiteral::decompile(int indent) const {
    return "\"" + _value + "\"";
}

string StringLiteral::dump(int indent) const {
    return string(indent, '\t') + "[StringLiteral]" + (_isExported ? " <exported>" : "") +
           " <value:" + _value + ">\n";
}
