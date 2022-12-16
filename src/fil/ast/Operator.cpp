/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Operator::Operator(Op op)
        : _op(op), _index(nullptr) {}

Operator::Operator(AbstractExpr *index)
        : _op(ARRAY), _index(index) {}

Operator::~Operator() {
    delete _index;
}

string Operator::decompile(int indent) const {
    if (_op == ARRAY) {
        return "[" + _index->decompile(indent) + "]";
    } else {
        return to_string(_op);
    }
}
