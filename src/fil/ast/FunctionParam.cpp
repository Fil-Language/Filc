/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionParam::FunctionParam(Identifier *name, AbstractType *type)
        : _name(name), _type(type) {}

FunctionParam::~FunctionParam() {
    delete _name;
    delete _type;
}

string FunctionParam::decompile(int indent) const {
    string result = _name->decompile(indent);

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}

void FunctionParam::resolveParam(Environment *function) {
    if (_name->resolveVar(function) == nullptr) {
        std::string n = _name->getName();
        ErrorsRegister::addWarning(
                n + " already exists, previous declaration here: " +
                function->getSymbol(n)->getPosition()->dump(),
                _name->getPosition()
        );
    }

    if (_type && !function->hasType(_type->getName())) {
        ErrorsRegister::addError(
                "Unknown type " + _type->getName(),
                _type->getPosition()
        );
    }
}
