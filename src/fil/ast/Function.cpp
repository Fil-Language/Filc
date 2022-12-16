/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function(FunctionDeclaration *declaration)
        : _declaration(declaration) {}

Function::~Function() {
    delete _declaration;
}

string Function::decompile(int indent) const {
    return "fun ";
}
