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
