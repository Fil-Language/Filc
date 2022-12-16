/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function(FunctionDeclaration *declaration, AbstractExpr *body)
        : _declaration(declaration), _body(body) {}

Function::~Function() {
    delete _declaration;
    delete _body;
}

string Function::decompile(int indent) const {
    return "fun " + _declaration->decompile(indent) + " " + _body->decompile(indent);
}
