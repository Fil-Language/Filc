/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

If::If(AbstractExpr *condition, AbstractExpr *thenCase, AbstractExpr *elseCase)
        : _condition(condition), _then(thenCase), _else(elseCase) {}

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
    res += string(indent, '\t') + "<then>\n";
    res += _then->dump(indent + 1);
    if (_else) {
        res += string(indent, '\t') + "<else>\n";
        res += _else->dump(indent + 1);
    }

    return res;
}
