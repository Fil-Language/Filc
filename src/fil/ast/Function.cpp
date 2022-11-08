/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function() : _name(nullptr), _body(nullptr), _returnType(nullptr) {}

Function::Function(Identifier *name, vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType)
        : _name(name), _params(params), _body(body), _returnType(returnType) {}

Function::~Function() {
    delete _name;
    for (auto &param: _params) {
        delete param;
    }
    delete _body;
    delete _returnType;
}

string Function::decompile(int indent) const {
    string res = "fun " + _name->decompile(indent) + "(";

    for (auto it = _params.begin(); it != _params.end(); it++) {
        res += (*it)->decompile(indent);
        if (it != _params.end() - 1) {
            res += ", ";
        }
    }

    res += ")";

    if (_returnType != nullptr) {
        res += " -> " + _returnType->decompile(indent);
    }

    res += "\n";

    res += _body->decompile(indent + 1);

    return res;
}
