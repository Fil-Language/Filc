/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDeclaration::FunctionDeclaration(Identifier *name, Type *type)
        : _name(name), _type(type) {}

FunctionDeclaration::~FunctionDeclaration() {
    delete _name;
    delete _type;
}

string FunctionDeclaration::decompile(int indent) const {
    string result = _name->decompile(indent);

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}
