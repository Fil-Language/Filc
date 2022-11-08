/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ExprParenthesis::ExprParenthesis() : _exprs(vector<AbstractExpr *>()) {}

ExprParenthesis::ExprParenthesis(vector<AbstractExpr *> &exprs) : _exprs(exprs) {}

ExprParenthesis::~ExprParenthesis() {
    for (auto &expr: _exprs) {
        delete expr;
    }
}

string ExprParenthesis::decompile(int indent) const {
    string res = "(\n";

    for (auto &expr: _exprs) {
        res += expr->decompile(indent + 1) + "\n";
    }

    return res + ")";
}

