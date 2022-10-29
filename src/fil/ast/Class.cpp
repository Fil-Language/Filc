/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Class::Class() = default;

Class::Class(const std::string &modifier, const std::string &name)
        : _modifier(modifier), _name(name) {}

IndentPrinter *Class::print(IndentPrinter *printer) const {
    printer->writeIndent("Class => [")
            ->write(_modifier)
            ->write("] ")
            ->write(_name)
            ->write("\n");

    return printer;
}
