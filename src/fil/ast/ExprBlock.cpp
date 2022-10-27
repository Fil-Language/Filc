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

IndentPrinter *ExprBlock::print(IndentPrinter *printer) const {
    printer->writeIndent("ExprBlock =>\n")
            ->indent();

    for (const auto &expr: _exprs) {
        expr.print(printer);
    }

    printer->unindent()
            ->writeIndent("}\n");

    return printer;
}
