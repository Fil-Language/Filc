/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDecl::FunctionDecl() : _name(nullptr), _returnType(nullptr) {}

FunctionDecl::FunctionDecl(Identifier *name, vector<FunctionParam *> &params, Type *returnType)
        : _name(name), _params(params), _returnType(returnType) {}

FunctionDecl::~FunctionDecl() {
    delete _name;
    for (auto &param: _params) {
        delete param;
    }
    delete _returnType;
}

string FunctionDecl::decompile(int indent) const {
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

    return res;
}
