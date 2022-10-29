/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace ast;

Function::Function() : _body(nullptr) {}

Function::Function(const std::string &name, AbstractExpr *body) : _name(name), _body(body) {}

IndentPrinter *Function::print(IndentPrinter *printer) const {
    printer->writeIndent("Function => ")
            ->write(_name)
            ->write("\n") // TODO : write params and return type
            ->indent();

    _body->print(printer);

    return printer->unindent();
}
