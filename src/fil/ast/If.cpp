/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

If::If(AbstractExpr *condition, AbstractExpr *then, AbstractExpr *else_)
        : _condition(condition), _then(then), _else(else_) {}

If::~If() {
    delete _condition;
    delete _then;
    delete _else;
}

string If::decompile(int indent) const {
    string res = "if (" + _condition->decompile(indent) + ") " + _then->decompile(indent);

    if (_else) {
        res += " else " + _else->decompile(indent);
    }

    return res;
}

void If::resolveEnvironment(Environment *parent) {
    _condition->resolveEnvironment(parent);
    _then->resolveEnvironment(parent);
    if (_else) {
        _else->resolveEnvironment(parent);
    }
}

AbstractType *If::inferType(Environment *env) {
    _condition->inferType(env);

    auto thenType = _then->inferType(env);
    if (_else) {
        auto elseType = _else->inferType(env);
        if (*thenType != *elseType) {
            ErrorsRegister::addError(
                    "Then and Else branch must have the same type\nThen: " + thenType->getName() + "\nElse: " +
                    elseType->getName(),
                    _pos
            );
        }
    }

    _exprType = thenType;

    return _exprType;
}

string If::dump(int indent) const {
    string res = string(indent, '\t') + "[If]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _then->dump(indent + 1);
    if (_else) {
        res += _else->dump(indent + 1);
    }

    return res;
}
