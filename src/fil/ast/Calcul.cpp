/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractCalcul::AbstractCalcul() : _op(nullptr) {}

AbstractCalcul::~AbstractCalcul() {
    delete _op;
}

string AbstractCalcul::decompile(int indent) const {
    throw;
}

// ====================

UnaryCalcul::UnaryCalcul() : _isPrefix(false), _expr(nullptr) {}

UnaryCalcul::UnaryCalcul(Operator *op, AbstractExpr *expr)
        : _isPrefix(true), _expr(expr) {
    _op = op;
}

UnaryCalcul::UnaryCalcul(AbstractExpr *expr, Operator *op)
        : _isPrefix(false), _expr(expr) {
    _op = op;
}

UnaryCalcul::~UnaryCalcul() {
    delete _expr;
}

string UnaryCalcul::decompile(int indent) const {
    if (_isPrefix) {
        return _op->decompile(indent) + _expr->decompile(indent);
    } else {
        return _expr->decompile(indent) + _op->decompile(indent);
    }
}

// ====================

BinaryCalcul::BinaryCalcul() : _left(nullptr), _right(nullptr) {}

BinaryCalcul::BinaryCalcul(AbstractExpr *left, Operator *op, AbstractExpr *right)
        : _left(left), _right(right) {
    _op = op;
}

BinaryCalcul::~BinaryCalcul() {
    delete _left;
    delete _right;
}

string BinaryCalcul::decompile(int indent) const {
    return _left->decompile(indent) + _op->decompile(indent) + _right->decompile(indent);
}
