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
