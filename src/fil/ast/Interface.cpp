/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Interface::Interface() = default;

Interface::Interface(const std::string &name, std::vector<FunctionDecl *> &functions)
        : _name(name), _functions(functions) {}

IndentPrinter *Interface::print(IndentPrinter *printer) const {
    printer->writeIndent("Interface => ")
            ->write(_name)
            ->write("\n");

    printer->indent();

    for (const auto &function: _functions) {
        function->print(printer);
    }

    return printer->unindent();
}
