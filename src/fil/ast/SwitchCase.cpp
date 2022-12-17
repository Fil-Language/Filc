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

SwitchCase::~SwitchCase() {
    delete _pattern;
    delete _body;
}

string SwitchCase::decompile(int indent) const {
    return _pattern->decompile(indent) + " -> " + _body->decompile(indent) + "\n";
}
