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

Return::~Return() {
    delete _expr;
}

string Return::decompile(int indent) const {
    string ret = "return ";

    if (_expr != nullptr) {
        ret += _expr->decompile(indent);
    }

    return ret;
}

void Return::resolveEnvironment(Environment *parent) {
    _expr->resolveEnvironment(parent);
}
