/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

SwitchCase::SwitchCase(SwitchPattern *pattern, AbstractExpr *body)
        : _pattern(pattern), _body(body) {}

string SwitchCase::decompile(int indent) const {
    return _pattern->decompile(indent) + " -> " + _body->decompile(indent) + "\n";
}

string SwitchCase::dump(int indent) const {
    string res = string(indent, '\t') + "[SwitchCase]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _pattern->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
