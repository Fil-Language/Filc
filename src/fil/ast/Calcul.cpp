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
