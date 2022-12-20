/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ParenthesisBody::ParenthesisBody(AbstractExpr *expr)
        : _expr(expr) {}

ParenthesisBody::~ParenthesisBody() {
    delete _expr;
}

string ParenthesisBody::decompile(int indent) const {
    return "(" + _expr->decompile(indent) + ")";
}

void ParenthesisBody::resolveEnvironment(Environment *parent) {
    _expr->resolveEnvironment(parent);
}
