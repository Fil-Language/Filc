/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Interface::Interface() : _name(nullptr) {}

Interface::Interface(Identifier *name, std::vector<ClassParam *> &params, std::vector<FunctionDecl *> &functions)
        : _name(name), _params(params), _functions(functions) {}

IndentPrinter *Interface::print(IndentPrinter *printer) const {
    printer->writeIndent("Interface => ");
    _name->print(printer);

    if (!_params.empty()) {
        printer->write(" (");
        for (auto it = _params.begin(); it != _params.end(); ++it) {
            (*it)->print(printer);
            if (it != _params.end() - 1) {
                printer->write(", ");
            }
        }
        printer->write(")");
    }

    printer->write("\n")
            ->indent();

    for (const auto &function: _functions) {
        function->print(printer);
    }

    return printer->unindent();
}
