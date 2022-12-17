/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForIter::ForIter(AbstractExpr *body)
        : _body(body) {}

ForIter::~ForIter() {
    delete _body;
}

string ForIter::decompile(int indent) const {
    return _body->decompile(indent);
}
