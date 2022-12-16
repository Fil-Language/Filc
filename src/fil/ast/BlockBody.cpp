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
        : _exprs(exprs) {}

BlockBody::~BlockBody() {
    for (auto expr: _exprs) {
        delete expr;
    }
}

string BlockBody::decompile(int indent) const {
    string result = "{\n";

    for (auto expr: _exprs) {
        result += expr->decompile(indent + 1) + ";\n";
    }

    result += string(indent, '\t') + "}";

    return result;
}
