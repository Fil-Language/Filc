/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
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

string ParenthesisBody::dump(int indent) const {
    string res = string(indent, '\t') + "[ParenthesisBody]" + (_isExported ? " <exported>" : "") +
                 " <type:" + _exprType->getName() + ">\n";

    res += _expr->dump(indent + 1);

    return res;
}
