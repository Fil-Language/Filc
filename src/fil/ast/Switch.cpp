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

Switch::~Switch() {
    delete _condition;
    for (auto &c: _cases) {
        delete c;
    }
}

string Switch::decompile(int indent) const {
    string res = "switch " + _condition->decompile(indent) + " {\n";

    for (auto &c: _cases) {
        res += c->decompile(indent + 1) + "\n";
    }

    return res + "}";
}

// ====================

SwitchCase::SwitchCase() : _value(nullptr), _body(nullptr) {}

SwitchCase::SwitchCase(ast::AbstractExpr *body)
        : _value(nullptr), _body(body) {}

SwitchCase::SwitchCase(ast::AbstractLiteral *value, ast::AbstractExpr *body)
        : _value(value), _body(body) {}

SwitchCase::~SwitchCase() {
    delete _value;
    delete _body;
}

string SwitchCase::decompile(int indent) const {
    string res = (_value ? _value->decompile(indent) : "default") + " -> " + _body->decompile(indent);
}
