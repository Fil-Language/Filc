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
