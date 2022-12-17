/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDeclaration::FunctionDeclaration(Identifier *name, const vector<FunctionParam *> &params, Type *type)
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

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}