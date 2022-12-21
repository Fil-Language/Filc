/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

BlockBody::BlockBody(const vector<AbstractExpr *> &exprs)
        : _exprs(exprs), _environment(nullptr) {}

BlockBody::~BlockBody() {
    for (auto expr: _exprs) {
        delete expr;
    }
}

string BlockBody::decompile(int indent) const {
    string result = "{\n";

    for (auto expr: _exprs) {
        result += string(indent + 1, '\t') + expr->decompile(indent + 1) + "\n";
    }

    result += string(indent, '\t') + "}";

    return result;
}

void BlockBody::resolveEnvironment(Environment *parent) {
    _environment = new Environment(parent);

    for (auto expr: _exprs) {
        expr->resolveEnvironment(_environment);
    }
}

AbstractType *BlockBody::inferType(Environment *env) {
    for (auto expr: _exprs) {
        if (expr->isReturn()) {
            _exprType = expr->inferType(_environment);
            break;
        } else {
            expr->inferType(_environment);
        }
    }

    return _exprType;
}
