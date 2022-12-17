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
        : _condition(condition), _body(body) {}

While::~While() {
    delete _condition;
    delete _body;
}

string While::decompile(int indent) const {
    return "while (" + _condition->decompile(indent) + ") "
           + _body->decompile(indent + 1);
}
