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

Lambda::~Lambda() {
    for (auto param: _params) {
        delete param;
    }
    delete _type;
    delete _body;
}

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

void Lambda::resolveEnvironment(Environment *parent) {
    _environment = new Environment(parent);

    for (auto param: _params) {
        param->resolveParam(_environment);
    }

    if (_type && !parent->hasType(_type->getName())) {
        ErrorsRegister::addError(
                "Unknown type " + _type->getName(),
                _type->getPosition()
        );
    }

    _body->resolveEnvironment(_environment);
}

AbstractType *Lambda::inferType(Environment *env) {
    vector<AbstractType *> params;
    for (auto param: _params) {
        params.push_back(param->getType());
    }

    auto bodyType = _body->inferType(_environment);

    if (_type == nullptr) {
        _type = bodyType;
        _exprType = new LambdaType(params, bodyType);
    } else {
        if (bodyType != _type) {
            ErrorsRegister::addError(
                    "Lambda body type " + bodyType->getName() +
                    " does not match lambda return type " + _type->getName(),
                    _type->getPosition()
            );
        }

        _exprType = new LambdaType(params, _type);
    }


    return _exprType;
}

string Lambda::dump(int indent) const {
    string res = string(indent, '\t') + "[Lambda] <type:" + _exprType->getName() + ">\n";

    for (auto param: _params) {
        res += param->dump(indent + 1);
    }

    res += _body->dump(indent + 1);

    return res;
}
