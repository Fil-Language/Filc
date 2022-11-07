/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

If::If() : _condition(nullptr), _then(nullptr), _else(nullptr) {}

If::If(ast::ExprParenthesis *condition, ast::AbstractExpr *then)
        : _condition(condition), _then(then), _else(new ExprBlock()) {}

If::If(ast::ExprParenthesis *condition, ast::AbstractExpr *then, std::vector<If *> &elseIf, ast::AbstractExpr *else_)
        : _condition(condition), _then(then), _elseIf(elseIf), _else(else_) {}

If::~If() {
    delete _condition;
    delete _then;
    for (auto &i: _elseIf) {
        delete i;
    }
    delete _else;
}
