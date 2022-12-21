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
    delete _environment;
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

string ForIter::dump(int indent) const {
    string res = string(indent, '\t') + "[ForIter]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
