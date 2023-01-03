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

string ParenthesisBody::decompile(int indent) const {
    return "(" + _expr->decompile(indent) + ")";
}

void ParenthesisBody::resolveEnvironment(Environment *parent) {
    _expr->resolveEnvironment(parent);
}

AbstractType *ParenthesisBody::inferType(Environment *env) {
    _exprType = _expr->inferType(env);

    return _exprType;
}

string ParenthesisBody::dump(int indent) const {
    string res = string(indent, '\t') + "[ParenthesisBody]" + (_isExported ? " <exported>" : "") +
                 " <type:" + _exprType->getName() + ">\n";

    res += _expr->dump(indent + 1);

    return res;
}
