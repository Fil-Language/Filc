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

void VariableDeclaration::resolveEnvironment(Environment *parent) {
    _symbol = _name->resolveVar(parent);
    if (_symbol == nullptr) {
        std::string n = _name->getName();
        ErrorsRegister::addError(
                n + " already exists, previous declaration here: " +
                parent->getSymbol(n)->getPosition()->dump(),
                _name->getPosition()
        );
    }

    if (_assignation) {
        _assignation->resolveEnvironment(parent);
    }
}
