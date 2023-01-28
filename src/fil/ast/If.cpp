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

string If::decompile(int indent) const {
    string res = "if (" + _condition->decompile(indent) + ") " + _then->decompile(indent);

    if (_else) {
        res += " else " + _else->decompile(indent);
    }

    return res;
}

Symbol *If::resolveSymbols(Environment *parent) {
    _condition->resolveSymbols(parent);
    _then->resolveSymbols(parent);
    if (_else)
        _else->resolveSymbols(parent);

    return nullptr;
}

AbstractType *If::inferType(Environment *parent) {
    auto condType = _condition->inferType(parent);
    if (condType->getName() != "bool") {
        ErrorsRegister::addError(new Error("Condition must be a boolean", _condition->getPosition()));
    }

    auto thenType = _then->inferType(parent);
    if (_else) {
        auto elseType = _else->inferType(parent);
        if (*elseType != *thenType) {
            ErrorsRegister::addError(
                    new Error("Then and Else branch must have the same type, " + thenType->getName() + " and " +
                              elseType->getName() + " found", _pos)
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
