/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Lambda::Lambda(const vector<FunctionParam *> &params, AbstractType *type, AbstractExpr *body)
        : _params(params), _type(type), _body(body), _environment(nullptr) {}

string Lambda::decompile(int indent) const {
    string res = "(";
    for (auto it = _params.begin(); it != _params.end(); ++it) {
        res += (*it)->decompile(indent);
        if (it + 1 != _params.end()) {
            res += ", ";
        }
    }
    res += ")";

    if (_type) {
        res += " : " + _type->decompile(indent);
    }

    res += " -> " + _body->decompile(indent);

    return res;
}

Symbol *Lambda::resolveSymbols(Environment *parent) {
    _environment = new Environment(parent);

    for (auto param: _params) {
        param->resolveSymbol(_environment);
    }

    return _body->resolveSymbols(_environment);
}

AbstractType *Lambda::inferType(Environment *parent) {
    vector<AbstractType *> paramsTypes;
    for (auto param: _params) {
        paramsTypes.push_back(param->inferType(_environment));
    }

    auto bodyType = _body->inferType(_environment);

    if (_type) {
        if (*bodyType != *_type) {
            ErrorsRegister::addError(
                    new Error("Type mismatch: lambda must returns " + _type->getName()
                              + ", but its body returns " + bodyType->getName(),
                              _type->getPosition())
            );
        }
    } else {
        _type = bodyType;
    }

    _exprType = new LambdaType(paramsTypes, _type);

    return _exprType;
}

string Lambda::dump(int indent) const {
    string res = string(indent, '\t') + "[Lambda]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    for (auto param: _params) {
        res += param->dump(indent + 1);
    }

    res += _body->dump(indent + 1);

    return res;
}
