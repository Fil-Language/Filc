/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ExprBlock::ExprBlock() : _exprs(vector<AbstractExpr *>()) {}

ExprBlock::ExprBlock(std::vector<AbstractExpr *> &exprs) : _exprs(exprs) {}

ExprBlock::~ExprBlock() {
    for (auto expr: _exprs) {
        delete expr;
    }
}

string ExprBlock::decompile(int indent) const {
    string res = "{\n";

    for (auto expr: _exprs) {
        res += expr->decompile(indent + 1) + "\n";
    }

    return res + "}";
}
