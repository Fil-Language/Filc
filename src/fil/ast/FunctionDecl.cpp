/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDecl::FunctionDecl() : _name(nullptr), _returnType(nullptr) {}

FunctionDecl::FunctionDecl(Identifier *name, vector<FunctionParam *> &params, Type *returnType)
        : _name(name), _params(params), _returnType(returnType) {}

IndentPrinter *FunctionDecl::print(IndentPrinter *printer) const {
    printer->writeIndent("FunctionDecl => ");
    _name->print(printer);
    printer->write(" (");

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

    return printer->write("\n");
}
