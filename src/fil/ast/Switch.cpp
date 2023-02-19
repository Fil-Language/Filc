/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Switch::Switch(AbstractExpr *condition, const vector<SwitchCase *> &cases)
        : _condition(condition), _cases(cases) {}

string Switch::decompile(int indent) const {
    string res = "switch (" + _condition->decompile(indent) + ") {\n";

    for (auto &c: _cases) {
        res += string(indent + 1, '\t') + c->decompile(indent);
    }

    res += "}";

    return res;
}

string Switch::dump(int indent) const {
    string res = string(indent, '\t') + "[Switch]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);

    for (auto &c: _cases) {
        res += c->dump(indent + 1);
    }

    return res;
}
