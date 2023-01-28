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

Symbol *Function::resolveSymbols(Environment *parent) {
    _symbol = _declaration->resolveSymbols(parent);

    _environment = new Environment(parent);
    _declaration->resolveParams(_environment);
    _body->resolveSymbols(_environment);

    return _symbol;
}

AbstractType *Function::inferType(Environment *parent) {
    _declaration->inferParamsTypes(_environment);
    auto declarationType = (LambdaType *) _declaration->inferType(parent);
    auto returnType = declarationType->getReturnType();
    auto bodyType = _body->inferType(_environment);

    if (returnType) {
        if (*bodyType != *returnType) {
            ErrorsRegister::addError(
                    new Error("Type mismatch: function " + _symbol->getName() + " must returns " + returnType->getName()
                              + ", but its body returns " + bodyType->getName(),
                              _pos)
            );
        }
    } else {
        declarationType->setReturnType(bodyType);
    }

    _exprType = declarationType;

    return _exprType;
}

string Function::dump(int indent) const {
    string res = string(indent, '\t') + "[Function]" + (_isExported ? " <exported> " : " ")
                 + "<name:" + _symbol->getName() + "> "
                 + " <type:" + _exprType->getName() + ">\n";

    res += _declaration->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
