/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Switch::Switch() : _condition(nullptr) {}

Switch::Switch(ExprParenthesis *condition, vector<SwitchCase *> &cases)
        : _condition(condition), _cases(cases) {}

// ====================

SwitchCase::SwitchCase() : _value(nullptr), _body(nullptr) {}

SwitchCase::SwitchCase(ast::AbstractExpr *body)
        : _value(nullptr), _body(body) {}

SwitchCase::SwitchCase(ast::AbstractLiteral *value, ast::AbstractExpr *body)
        : _value(value), _body(body) {}