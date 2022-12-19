/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

VariableDeclaration::VariableDeclaration(bool isVal, Identifier *name, AbstractType *type, Assignation *assignation)
        : _isVal(isVal), _name(name), _type(type), _assignation(assignation), _symbol(nullptr) {}

VariableDeclaration::~VariableDeclaration() {
    delete _name;
    delete _type;
    delete _assignation;
}

string VariableDeclaration::decompile(int indent) const {
    string result = (_isVal ? "val " : "var ") + _name->decompile(indent);

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    if (_assignation) {
        result += " " + _assignation->decompile(indent);
    }

    return result;
}

bool VariableDeclaration::isVar() const {
    return true;
}

Symbol *VariableDeclaration::getSymbol() const {
    return _symbol;
}
