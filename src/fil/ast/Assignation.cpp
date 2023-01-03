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

string Assignation::decompile(int indent) const {
    return "= " + _expr->decompile(indent);
}

void Assignation::resolveEnvironment(Environment *parent) {
    _expr->resolveEnvironment(parent);
}

AbstractType *Assignation::inferType(Environment *env) {
    _exprType = _expr->inferType(env);

    return _exprType;
}

string Assignation::dump(int indent) const {
    string res = string(indent, '\t') + "[Assignation]" + (_isExported ? " <exported>" : "") +
                 " <type:" + _exprType->getName() + ">\n";

    res += _expr->dump(indent + 1);

    return res;
}
