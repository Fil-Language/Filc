/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForI::ForI(ForICondition *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

string ForI::decompile(int indent) const {
    return "for (" + _condition->decompile(indent) + ") " + _body->decompile(indent);
}

Symbol *ForI::resolveSymbols(Environment *parent) {
    _environment = new Environment(parent);

    _condition->resolveSymbols(_environment);
    _body->resolveSymbols(_environment);

    return nullptr;
}

AbstractType *ForI::inferType(Environment *parent) {
    _condition->inferTypes(_environment);

    _exprType = _body->inferType(_environment);

    return _exprType;
}

string ForI::dump(int indent) const {
    string res = string(indent, '\t') + "[ForI]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
