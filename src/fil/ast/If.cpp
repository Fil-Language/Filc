/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

If::If() : _condition(nullptr), _then(nullptr), _else(nullptr) {}

If::If(ast::ExprParenthesis *condition, ast::AbstractExpr *then)
        : _condition(condition), _then(then), _else(new ExprBlock()) {}

If::If(ast::ExprParenthesis *condition, ast::AbstractExpr *then, std::vector<If *> &elseIf, ast::AbstractExpr *else_)
        : _condition(condition), _then(then), _elseIf(elseIf), _else(else_) {}

IndentPrinter *If::print(IndentPrinter *printer) const {
    printer->writeIndent("If =>\n")
            ->indent();
    printer->writeIndent("Condition =>\n")
            ->indent();
    _condition->print(printer);
    printer->unindent();
    printer->writeIndent("Then =>\n")
            ->indent();
    _then->print(printer);
    printer->unindent();

    for (const auto &if_: _elseIf) {
        if_->print(printer);
    }

    if (_else != nullptr) {
        printer->writeIndent("Else =>\n")
                ->indent();
        _else->print(printer);
        printer->unindent();
    }

    return printer->unindent()
            ->write("\n");
}
