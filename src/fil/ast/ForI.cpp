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
        : _condition(condition), _body(body) {}

ForI::~ForI() {
    delete _condition;
    delete _body;
}

string ForI::decompile(int indent) const {
    return "for (" + _condition->decompile(indent) + ") " + _body->decompile(indent);
}
