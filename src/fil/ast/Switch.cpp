/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Switch::Switch(AbstractExpr *condition, const vector<SwitchCase *> &cases)
        : _condition(condition), _cases(cases) {}

Switch::~Switch() {
    delete _condition;
    for (auto &c: _cases) {
        delete c;
    }
}

string Switch::decompile(int indent) const {
    string res = "switch (" + _condition->decompile(indent) + " {\n";

    for (auto &c: _cases) {
        res += c->decompile(indent);
    }

    res += "}";

    return res;
}
