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

// ====================

For::For() : _iterator(nullptr), _condition(nullptr), _increment(nullptr) {}

For::For(VariableDecl *iterator, AbstractExpr *condition, AbstractExpr *increment, AbstractExpr *body)
        : _iterator(iterator), _condition(condition), _increment(increment) {
    _body = body;
}

IndentPrinter *For::print(IndentPrinter *printer) const {
    printer->writeIndent("For =>\n")
            ->indent();
    printer->writeIndent("Iterator =>\n")
            ->indent();
    _iterator->print(printer);
    printer->unindent();
    printer->writeIndent("Condition =>\n")
            ->indent();
    _condition->print(printer);
    printer->unindent();
    printer->writeIndent("Increment =>\n")
            ->indent();
    _increment->print(printer);
    printer->unindent();
    printer->writeIndent("Body =>\n")
            ->indent();
    _body->print(printer);
    printer->unindent();

    return printer->unindent();
}

// ====================

ForIter::ForIter() : _iterator(nullptr), _iterable(nullptr) {}

ForIter::ForIter(const string &modifier, Identifier *iterator, Identifier *iterable, AbstractExpr *body)
        : _modifier(modifier), _iterator(iterator), _iterable(iterable) {}

IndentPrinter *ForIter::print(IndentPrinter *printer) const {
    printer->writeIndent("ForIter =>\n")
            ->indent();
    printer->writeIndent("Iteration => ")
            ->write(_modifier)
            ->write(" ");
    _iterator->print(printer);
    printer->write(" in ");
    _iterable->print(printer);
    printer->write("\n")
            ->unindent()
            ->writeIndent("Body =>\n")
            ->indent();
    _body->print(printer);
    printer->unindent();

    return printer->unindent();
}
