/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ArrowExpr::ArrowExpr() : _left(nullptr), _right(nullptr) {}

ArrowExpr::ArrowExpr(AbstractExpr *left, AbstractExpr *right)
        : _left(left), _right(right) {}

ArrowExpr::~ArrowExpr() {
    delete _left;
    delete _right;
}

string ArrowExpr::decompile(int indent) const {
    return _left->decompile(indent) + "->" + _right->decompile(indent);
}
