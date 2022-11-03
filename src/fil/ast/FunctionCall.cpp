/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionCall::FunctionCall() : _name(nullptr) {}

FunctionCall::FunctionCall(Identifier *name, vector<AbstractExpr *> &args)
        : _name(name), _args(args) {}

IndentPrinter *FunctionCall::print(IndentPrinter *printer) const {
    printer->writeIndent("FunctionCall => ");
    _name->print(printer);
    printer->write("\n");

    if (!_args.empty()) {
        printer->indent()
                ->writeIndent("Args =>\n")
                ->indent();
        for (auto &arg: _args) {
            arg->print(printer);
        }
        printer->unindent();
    }

    return printer;
}
