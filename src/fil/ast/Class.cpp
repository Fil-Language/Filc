/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Class::Class() : _name(nullptr) {};

Class::Class(const string &modifier, ClassIdentifier *name)
        : _modifier(modifier), _name(name) {}

IndentPrinter *Class::print(IndentPrinter *printer) const {
    printer->writeIndent("Class => [")
            ->write(_modifier)
            ->write("] ");

    if (_name)
        _name->print(printer);

    return printer->write("\n");
}

// ====================

ClassIdentifier::ClassIdentifier() = default;

ClassIdentifier::ClassIdentifier(const string &name, vector<string> &generics)
        : _name(name), _generics(generics) {}

IndentPrinter *ClassIdentifier::print(IndentPrinter *printer) const {
    printer->write(_name);

    if (!_generics.empty()) {
        printer->write("<");
        for (auto it = _generics.begin(); it != _generics.end(); ++it) {
            printer->write(*it);
            if (it != _generics.end() - 1)
                printer->write(", ");
        }
        printer->write(">");
    }

    return printer;
}
