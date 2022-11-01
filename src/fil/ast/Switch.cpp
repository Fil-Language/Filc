/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Switch::Switch() : _condition(nullptr) {}

Switch::Switch(ExprParenthesis *condition, vector<SwitchCase *> &cases)
        : _condition(condition), _cases(cases) {}

IndentPrinter *Switch::print(IndentPrinter *printer) const {
    printer->writeIndent("Switch =>\n")
            ->indent();
    printer->writeIndent("Condition =>\n")
            ->indent();
    _condition->print(printer);
    printer->unindent();

    for (auto &c: _cases) {
        c->print(printer);
    }

    return printer->unindent()
            ->write("\n");
}

// ====================

SwitchCase::SwitchCase() : _value(nullptr), _body(nullptr) {}

SwitchCase::SwitchCase(ast::AbstractExpr *body)
        : _value(nullptr), _body(body) {}

SwitchCase::SwitchCase(ast::AbstractLiteral *value, ast::AbstractExpr *body)
        : _value(value), _body(body) {}

IndentPrinter *SwitchCase::print(IndentPrinter *printer) const {
    printer->writeIndent("Case => ");
    if (_value) {
        _value->print(printer);
    } else {
        printer->write("default");
    }
    printer->write("\n")
            ->indent();

    _body->print(printer);

    return printer->unindent();
}
