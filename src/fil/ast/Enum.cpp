/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Enum::Enum() : _name(nullptr) {}

Enum::Enum(Identifier *name, vector<Identifier *> &values)
        : _name(name), _values(values) {}

IndentPrinter *Enum::print(IndentPrinter *printer) const {
    printer->writeIndent("Enum => ");
    _name->print(printer);

    printer->write("\n")
            ->indent();

    if (!_values.empty()) {
        printer->writeIndent("");
        for (auto it = _values.begin(); it != _values.end(); it++) {
            (*it)->print(printer);
            if (it != _values.end() - 1) {
                printer->write(", ");
            }
        }
        printer->write("\n");
    }

    return printer->unindent();
}
