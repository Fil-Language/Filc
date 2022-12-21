/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDeclaration::FunctionDeclaration(Identifier *name, const vector<FunctionParam *> &params, AbstractType *type)
        : _name(name), _params(params), _type(type) {}

FunctionDeclaration::~FunctionDeclaration() {
    delete _name;
    for (auto param: _params) {
        delete param;
    }
    delete _type;
}

string FunctionDeclaration::decompile(int indent) const {
    string result = _name->decompile(indent);

    result += "(";
    for (auto it = _params.begin(); it != _params.end(); ++it) {
        result += (*it)->decompile(indent);
        if (it + 1 != _params.end()) {
            result += ", ";
        }
    }
    result += ")";

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}

Symbol *FunctionDeclaration::resolveDeclaration(Environment *parent, Environment *function) {
    auto symbol = _name->resolveFunc(parent);
    if (symbol == nullptr) {
        std::string n = _name->getName();
        symbol = parent->getSymbol(n);
        ErrorsRegister::addError(
                n + " already exists, previous declaration here: " +
                symbol->getPosition()->dump(),
                _name->getPosition()
        );
    }

    for (auto param: _params) {
        param->resolveParam(function);
    }

    if (_type && !parent->hasType(_type->getName())) {
        ErrorsRegister::addError(
                "Unknown type " + _type->getName(),
                _type->getPosition()
        );
    }

    return symbol;
}

AbstractType *FunctionDeclaration::inferType(Environment *env) {
    vector<AbstractType *> params;
    for (auto param: _params) {
        params.push_back(param->getType());
    }

    _exprType = new LambdaType(params, _type);
    env->getSymbol(_name->getName())->setType(_exprType);

    return _exprType;
}

string FunctionDeclaration::dump(int indent) const {
    string res = string(indent, '\t') + "[FunctionDeclaration] <name:" + _name->getName() + "> "
                 + "<type:" + _exprType->getName() + ">\n";

    for (auto param: _params) {
        res += param->dump(indent + 1);
    }

    return res;
}
