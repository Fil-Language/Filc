/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function() : _body(nullptr) {}

Function::Function(const string &name, vector<FunctionParam *> &params, AbstractExpr *body)
        : _name(name), _params(params), _body(body) {}

IndentPrinter *Function::print(IndentPrinter *printer) const {
    printer->writeIndent("Function => ")
            ->write(_name)
            ->write(" (");

    for (auto it = _params.begin(); it != _params.end(); it++) {
        (*it)->print(printer);
        if (it != _params.end() - 1) {
            printer->write(", ");
        }
    }
    printer->write(")\n")
            ->indent();

    _body->print(printer);

    return printer->unindent();
}
