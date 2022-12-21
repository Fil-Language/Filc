/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

While::While(AbstractExpr *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

While::~While() {
    delete _condition;
    delete _body;
}

string While::decompile(int indent) const {
    return "while (" + _condition->decompile(indent) + ") "
           + _body->decompile(indent + 1);
}

void While::resolveEnvironment(Environment *parent) {
    _environment = new Environment(parent);

    _condition->resolveEnvironment(parent);
    _body->resolveEnvironment(_environment);
}

AbstractType *While::inferType(Environment *env) {
    _condition->inferType(env);

    _exprType = _body->inferType(_environment);

    return _exprType;
}
