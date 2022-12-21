/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForI::ForI(ForICondition *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

ForI::~ForI() {
    delete _condition;
    delete _body;
}

string ForI::decompile(int indent) const {
    return "for (" + _condition->decompile(indent) + ") " + _body->decompile(indent);
}

void ForI::resolveEnvironment(Environment *parent) {
    _environment = new Environment(parent);

    _condition->resolveCondition(_environment);
    _body->resolveEnvironment(_environment);
}

AbstractType *ForI::inferType(Environment *env) {
    _condition->inferCondition(env);

    _exprType = _body->inferType(_environment);

    return _exprType;
}

string ForI::dump(int indent) const {
    string res = string(indent, '\t') + "[ForI] <type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
