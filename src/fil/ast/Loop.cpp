/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractLoop::AbstractLoop() : _body(nullptr) {}

IndentPrinter *AbstractLoop::print(IndentPrinter *printer) const {
    return printer->writeIndent("AbstractLoop\n");
}

// ====================

While::While() : _condition(nullptr) {}

While::While(ast::ExprParenthesis *condition, ast::AbstractExpr *body)
        : _condition(condition) {
    _body = body;
}

IndentPrinter *While::print(IndentPrinter *printer) const {
    printer->writeIndent("While =>\n")
            ->indent();
    printer->writeIndent("Condition =>\n")
            ->indent();
    _condition->print(printer);
    printer->unindent();
    printer->writeIndent("Body =>\n")
            ->indent();
    _body->print(printer);
    printer->unindent();

    return printer->unindent();
}
