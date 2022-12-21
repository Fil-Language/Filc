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

Symbol *Identifier::resolveVar(Environment *parent) {
    return parent->addVariable(_name, _pos);
}

Symbol *Identifier::resolveFunc(Environment *parent) {
    return parent->addFunction(_name, _pos);
}

const string &Identifier::getName() const {
    return _name;
}

void Identifier::resolveEnvironment(Environment *parent) {
    if (!parent->hasSymbol(_name)) {
        ErrorsRegister::addError("Unknown symbol " + _name, _pos);
    }
}

AbstractType *Identifier::inferType(Environment *env) {
    // Infer
    _exprType = env->getSymbol(_name)->getType();

    // Check
    if (_exprType == nullptr) {
        ErrorsRegister::addError(_name + " has no type", _pos);
    }

    return _exprType;
}

string Identifier::dump(int indent) const {
    return string(indent, '\t') + "[Identifier] <name:" + _name + "> <type:" + _exprType->getName() + ">\n";
}
