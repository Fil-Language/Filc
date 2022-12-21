/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForICondition::ForICondition(VariableDeclaration *declaration, AbstractExpr *condition, AbstractExpr *increment)
        : _declaration(declaration), _condition(condition), _increment(increment) {}

ForICondition::~ForICondition() {
    delete _declaration;
    delete _condition;
    delete _increment;
}

string ForICondition::decompile(int indent) const {
    return _declaration->decompile(indent) + "; "
           + _condition->decompile(indent) + "; "
           + _increment->decompile(indent);
}

void ForICondition::resolveCondition(Environment *loop) {
    _declaration->resolveEnvironment(loop);
    _condition->resolveEnvironment(loop);
    _increment->resolveEnvironment(loop);
}

void ForICondition::inferCondition(Environment *env) {
    if (_declaration)
        _declaration->inferType(env);
    if (_condition)
        _condition->inferType(env);
    if (_increment)
        _increment->inferType(env);
}
