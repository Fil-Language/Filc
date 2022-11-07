/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractLoop::AbstractLoop() : _body(nullptr) {}

AbstractLoop::~AbstractLoop() {
    delete _body;
}

// ====================

While::While() : _condition(nullptr) {}

While::While(ast::ExprParenthesis *condition, ast::AbstractExpr *body)
        : _condition(condition) {
    _body = body;
}

While::~While() {
    delete _condition;
}

// ====================

For::For() : _iterator(nullptr), _condition(nullptr), _increment(nullptr) {}

For::For(VariableDecl *iterator, AbstractExpr *condition, AbstractExpr *increment, AbstractExpr *body)
        : _iterator(iterator), _condition(condition), _increment(increment) {
    _body = body;
}

For::~For() {
    delete _iterator;
    delete _condition;
    delete _increment;
}

// ====================

ForIter::ForIter() : _iterator(nullptr), _iterable(nullptr) {}

ForIter::ForIter(const string &modifier, Identifier *iterator, Identifier *iterable, AbstractExpr *body)
        : _modifier(modifier), _iterator(iterator), _iterable(iterable) {}

ForIter::~ForIter() {
    delete _iterator;
    delete _iterable;
}
