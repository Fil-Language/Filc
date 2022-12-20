/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Assignation::Assignation(AbstractExpr *expr)
        : _expr(expr) {}

Assignation::~Assignation() {
    delete _expr;
}

string Assignation::decompile(int indent) const {
    return "= " + _expr->decompile(indent);
}

void Assignation::resolveEnvironment(Environment *parent) {
    _expr->resolveEnvironment(parent);
}
