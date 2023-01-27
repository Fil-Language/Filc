/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function(FunctionDeclaration *declaration, AbstractExpr *body)
        : _declaration(declaration), _body(body), _symbol(nullptr), _environment(nullptr) {}

string Function::decompile(int indent) const {
    return "fun " + _declaration->decompile(indent) + " " + _body->decompile(indent);
}

bool Function::isFunc() const {
    return true;
}

Symbol *Function::getSymbol() const {
    return _symbol;
}

//void Function::resolveEnvironment(Environment *parent) {
//    _environment = new Environment(parent);
//
//    _symbol = _declaration->resolveDeclaration(parent, _environment);
//
//    _body->resolveEnvironment(_environment);
//}
//
//AbstractType *Function::inferType(Environment *env) {
//    _exprType = _declaration->inferType(_environment);
//    env->getSymbol(_symbol->getName())->setSignature(_exprType);
//
//    auto returnType = ((LambdaType *) _exprType)->getReturnType();
//    auto bodyType = _body->inferType(_environment);
//    if (returnType) {
//        if (*returnType != *bodyType) {
//            ErrorsRegister::addError(
//                    "Type mismatch: function " + _symbol->getName() + " must returns " + returnType->getName()
//                    + ", but its body returns " + bodyType->getName(),
//                    _pos
//            );
//        }
//    } else {
//        ((LambdaType *) _exprType)->setReturnType(bodyType);
//    }
//
//    return _exprType;
//}

string Function::dump(int indent) const {
    string res = string(indent, '\t') + "[Function]" + (_isExported ? " <exported> " : " ")
                 + "<name:" + _symbol->getName() + "> "
                 + " <type:" + _exprType->getName() + ">\n";

    res += _declaration->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
