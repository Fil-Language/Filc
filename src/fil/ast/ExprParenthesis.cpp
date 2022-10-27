/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ExprParenthesis::ExprParenthesis() : _exprs(vector<AbstractExpr>()) {
    _export = false;
}

ExprParenthesis::ExprParenthesis(vector<AbstractExpr> &exprs) : _exprs(exprs) {
    _export = false;
}

IndentPrinter *ExprParenthesis::print(IndentPrinter *printer) const {
    printer->writeIndent("ExprParenthesis =>\n")
            ->indent();

    for (const auto &expr: _exprs) {
        expr.print(printer);
    }

    printer->unindent();

    return printer;
}

