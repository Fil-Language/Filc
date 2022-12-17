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
        : _condition(condition), _body(body) {}

ForIter::~ForIter() {
    delete _condition;
    delete _body;
}

string ForIter::decompile(int indent) const {
    return "for (" + _condition->decompile(indent) + ") " + _body->decompile(indent);
}
