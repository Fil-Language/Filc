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
        : _name(name), _symbol(nullptr) {}

string Identifier::decompile(int indent) const {
    return _name;
}

const string &Identifier::getName() const {
    return _name;
}

string Identifier::dump(int indent) const {
    return string(indent, '\t') + "[Identifier]" + (_isExported ? " <exported>" : "") +
           " <name:" + _name + "> <type:" + _exprType->getName() + ">\n";
}
