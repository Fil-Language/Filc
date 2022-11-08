/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Cast::Cast() : _type(nullptr), _expr(nullptr) {}

Cast::Cast(ast::Type *type, ast::AbstractExpr *expr)
        : _type(type), _expr(expr) {}

Cast::~Cast() {
    delete _type;
    delete _expr;
}

string Cast::decompile(int indent) const {
    return "(" + _type->decompile(indent) + ")" + _expr->decompile(indent);
}
