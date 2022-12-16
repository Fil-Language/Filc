/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
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
