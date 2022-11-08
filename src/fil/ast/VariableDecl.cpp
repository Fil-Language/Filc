/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

VariableDecl::VariableDecl() : _isVal(false), _name(nullptr), _type(nullptr), _op(nullptr), _value(nullptr) {}

VariableDecl::VariableDecl(bool isVal, ast::Identifier *name, ast::Type *type)
        : _isVal(isVal), _name(name), _type(type), _op(nullptr), _value(nullptr) {}

VariableDecl::VariableDecl(bool isVal, Identifier *name, Type *type, AssignationOperator *op, AbstractExpr *value)
        : _isVal(isVal), _name(name), _type(type), _op(op), _value(value) {}

VariableDecl::~VariableDecl() {
    delete _name;
    delete _type;
    delete _op;
    delete _value;
}

string VariableDecl::decompile(int indent) const {
    string res = (_isVal ? "val " : "var ") + _name->decompile(indent);

    if (_type != nullptr) {
        res += ": " + _type->decompile(indent);
    }

    if (_op != nullptr) {
        res += " " + _op->decompile(indent) + " " + _value->decompile(indent);
    }

    return res;
}
