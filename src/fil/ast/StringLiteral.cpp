/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

StringLiteral::StringLiteral(const std::string &value) {
    _value = value;
}

string StringLiteral::decompile(int indent) const {
    return "\"" + _value + "\"";
}
