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

string BlockBody::decompile(int indent) const {
    string result = "{\n";

    for (auto expr: _exprs) {
        result += string(indent + 1, '\t') + expr->decompile(indent + 1) + "\n";
    }

    result += string(indent, '\t') + "}";

    return result;
}

string BlockBody::dump(int indent) const {
    string res = string(indent, '\t') + "[BlockBody]" + (_isExported ? " <exported>" : "") +
                 " <type:" + _exprType->getName() + ">\n";

    for (auto expr: _exprs) {
        res += expr->dump(indent + 1);
    }

    return res;
}
