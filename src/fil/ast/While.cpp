/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

While::While(AbstractExpr *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

string While::decompile(int indent) const {
    return "while (" + _condition->decompile(indent) + ") "
           + _body->decompile(indent);
}

Symbol *While::resolveSymbols(Environment *parent) {
    _condition->resolveSymbols(parent);

    _environment = new Environment(parent);
    _body->resolveSymbols(_environment);

    return nullptr;
}

AbstractType *While::inferType(Environment *parent) {
    auto condType = _condition->inferType(parent);
    if (condType->getName() != "bool") {
        ErrorsRegister::addError(
                new Error("Type mismatch: while condition must be a boolean, but got " + condType->getName(),
                          _condition->getPosition())
        );
    }

    _exprType = _body->inferType(parent);

    return _exprType;
}

string While::dump(int indent) const {
    string res = string(indent, '\t') + "[While]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
