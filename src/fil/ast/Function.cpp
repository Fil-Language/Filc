/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function() : _body(nullptr), _returnType(nullptr) {}

Function::Function(const string &name, vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType)
        : _name(name), _params(params), _body(body), _returnType(returnType) {}

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
    printer->write(")");

    if (_returnType) {
        printer->write(" -> ");
        _returnType->print(printer);
    }
    printer->write("\n")
            ->indent();

    _body->print(printer);

    return printer->unindent();
}
