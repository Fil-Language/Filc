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

string AbstractLoop::decompile(int indent) const {
    throw;
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

string While::decompile(int indent) const {
    string res = "while " + _condition->decompile(indent) + "\n";

    return res + _body->decompile(indent + 1);
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

string For::decompile(int indent) const {
    string res = "for (" + _iterator->decompile(indent) + "; "
                 + _condition->decompile(indent) + "; "
                 + _increment->decompile(indent) + ")\n";

    return res + _body->decompile(indent + 1);
}

// ====================

ForIter::ForIter() : _iterator(nullptr), _iterable(nullptr) {}

ForIter::ForIter(const string &modifier, Identifier *iterator, Identifier *iterable, AbstractExpr *body)
        : _modifier(modifier), _iterator(iterator), _iterable(iterable) {}

ForIter::~ForIter() {
    delete _iterator;
    delete _iterable;
}

string ForIter::decompile(int indent) const {
    string res = "for (" + _modifier + " " + _iterator->decompile(indent)
                 + " : " + _iterable->decompile(indent) + ")\n";

    return res + _body->decompile(indent + 1);
}
