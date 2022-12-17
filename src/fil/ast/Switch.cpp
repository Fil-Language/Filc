/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Switch::Switch(AbstractExpr *condition)
        : _condition(condition) {}

Switch::~Switch() {
    delete _condition;
}

string Switch::decompile(int indent) const {
    string res = "switch (" + _condition->decompile(indent) + "\n";

    return res;
}
