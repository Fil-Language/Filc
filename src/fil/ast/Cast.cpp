/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Cast::Cast(AbstractType *type, AbstractExpr *expr)
        : _type(type), _expr(expr) {}

string Cast::decompile(int indent) const {
    return "(" + _type->decompile(indent) + ")" + _expr->decompile(indent);
}

Symbol *Cast::resolveSymbols(Environment *parent) {
    return _expr->resolveSymbols(parent);
}

//void Cast::resolveEnvironment(Environment *parent) {
//    if (!parent->hasType(_type->getName())) {
//        ErrorsRegister::addError(
//                "Unknown type " + _type->getName(),
//                _type->getPosition()
//        );
//    }
//
//    _expr->resolveEnvironment(parent);
//}
//
//AbstractType *Cast::inferType(Environment *env) {
//    _exprType = _type;
//
//    _expr->inferType(env);
//
//    return _exprType;
//}

string Cast::dump(int indent) const {
    string res = string(indent, '\t') + "[Cast]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _expr->dump(indent + 1);

    return res;
}
