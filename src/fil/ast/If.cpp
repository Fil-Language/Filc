/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

If::If(AbstractExpr *condition, AbstractExpr *then, AbstractExpr *else_)
        : _condition(condition), _then(then), _else(else_) {}

string If::decompile(int indent) const {
    string res = "if (" + _condition->decompile(indent) + ") " + _then->decompile(indent);

    if (_else) {
        res += " else " + _else->decompile(indent);
    }

    return res;
}

string If::dump(int indent) const {
    string res = string(indent, '\t') + "[If]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _then->dump(indent + 1);
    if (_else) {
        res += _else->dump(indent + 1);
    }

    return res;
}
