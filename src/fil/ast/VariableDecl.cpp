/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

VariableDecl::VariableDecl() : _isVal(false), _name(nullptr), _type(nullptr) {}

VariableDecl::VariableDecl(bool isVal, ast::Identifier *name, ast::Type *type)
        : _isVal(isVal), _name(name), _type(type) {}

IndentPrinter *VariableDecl::print(IndentPrinter *printer) const {
    printer->writeIndent("VariableDecl => ");
    _name->print(printer);
    printer->write(" ");
    _type->print(printer);

    return printer->write("\n");
}
