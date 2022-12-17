/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

SwitchCase::SwitchCase(AbstractExpr *body)
        : _body(body) {}

SwitchCase::~SwitchCase() {
    delete _body;
}

string SwitchCase::decompile(int indent) const {
    string res;

    res += " -> " + _body->decompile(indent) + "\n";

    return res;
}
