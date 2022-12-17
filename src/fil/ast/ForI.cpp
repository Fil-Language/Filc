/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForI::ForI(AbstractExpr *body)
        : _body(body) {}

ForI::~ForI() {
    delete _body;
}

string ForI::decompile(int indent) const {
    return _body->decompile(indent);
}
