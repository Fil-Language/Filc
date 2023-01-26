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

    if (_type && !parent->hasType(_type->getName())) {
        ErrorsRegister::addError(
                "Unknown type " + _type->getName(),
                _type->getPosition()
        );
    }

    if (_assignation) {
        _assignation->resolveEnvironment(parent);
    }
}

AbstractType *VariableDeclaration::inferType(Environment *env) {
    if (_assignation) {
        auto valueType = _assignation->inferType(env);

        if (_type == nullptr) {
            _type = valueType;
        } else if (_type != valueType) {
            ErrorsRegister::addError(
                    "Type mismatch, expected " + _type->getName() + " but got " + valueType->getName(),
                    _assignation->getPosition()
            );
        }
    }

    env->getSymbol(_name->getName())->setSignature(_type);

    _exprType = _type;

    return _exprType;
}

string VariableDeclaration::dump(int indent) const {
    string res = string(indent, '\t') + "[VariableDeclaration]"
                 + (_isExported ? " <exported> " : " ")
                 + (_isVal ? "<val> " : "<var> ")
                 + "<name:" + _name->getName() + "> "
                 + "<type:" + _exprType->getName() + ">\n";

    if (_assignation) {
        res += _assignation->dump(indent + 1);
    }

    return res;
}
