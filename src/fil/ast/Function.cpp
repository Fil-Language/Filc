/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace ast;

Function::Function() = default;

Function::Function(const std::string &name) : _name(name) {}

IndentPrinter *Function::print(IndentPrinter *printer) const {
    return printer->writeIndent("Function =>\n");
}
