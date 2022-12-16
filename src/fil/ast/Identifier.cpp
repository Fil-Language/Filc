/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Identifier::Identifier(const string &name)
        : _name(name) {}

string Identifier::decompile(int indent) const {
    return _name;
}
