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
