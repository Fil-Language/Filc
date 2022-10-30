/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Identifier::Identifier() = default;

Identifier::Identifier(const std::string &name) : _name(name) {}

IndentPrinter *Identifier::print(IndentPrinter *printer) const {
    return printer->write(_name);
}
