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

IndentPrinter *ExprBlock::print(IndentPrinter *printer) const {
    printer->writeIndent("ExprBlock =>\n")
            ->indent();

    for (const auto &expr: _exprs) {
        if (expr)
            expr->print(printer);
    }

    printer->unindent();

    return printer;
}
