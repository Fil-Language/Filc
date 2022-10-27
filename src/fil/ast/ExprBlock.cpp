/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ExprBlock::ExprBlock() : _exprs(vector<AbstractExpr>()) {
    _export = false;
}

ExprBlock::ExprBlock(std::vector<AbstractExpr> &exprs) : _exprs(exprs) {
    _export = false;
}

std::string ExprBlock::toString() const {
    string res = "{\n";

    for (const auto &expr: _exprs) {
        res += "\t" + expr.toString() + "\n";
    }

    res += "}\n";

    return res;
}
