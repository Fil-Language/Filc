/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FStringLiteral::FStringLiteral(const string &value)
        : StringLiteral(value) {}

string FStringLiteral::decompile(int indent) const {
    return "f\"" + _value + "\"";
}
