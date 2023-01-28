/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Return::Return(AbstractExpr *expr)
        : _expr(expr) {}

string Return::decompile(int indent) const {
    string ret = "return ";

    if (_expr != nullptr) {
        ret += _expr->decompile(indent);
    }

    return ret;
}

Symbol *Return::resolveSymbols(Environment *parent) {
    return _expr->resolveSymbols(parent);
}

AbstractType *Return::inferType(Environment *parent) {
    _exprType = _expr->inferType(parent);

    return _exprType;
}

bool Return::isReturn() const {
    return true;
}

string Return::dump(int indent) const {
    string res = string(indent, '\t') + "[Return]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _expr->dump(indent + 1);

    return res;
}
