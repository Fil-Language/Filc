/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForIter::ForIter(ForIterCondition *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

ForIter::~ForIter() {
    delete _condition;
    delete _body;
}

string ForIter::decompile(int indent) const {
    return "for (" + _condition->decompile(indent) + ") " + _body->decompile(indent);
}

void ForIter::resolveEnvironment(Environment *parent) {
    _environment = new Environment(parent);

    _condition->resolveCondition(_environment);
    _body->resolveEnvironment(_environment);
}

AbstractType *ForIter::inferType(Environment *env) {
    _condition->inferCondition(env, _environment);

    _exprType = _body->inferType(_environment);

    return _exprType;
}
