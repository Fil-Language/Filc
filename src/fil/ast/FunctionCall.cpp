/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionCall::FunctionCall(Identifier *name, const vector<AbstractExpr *> &args)
        : _name(name), _args(args) {}

string FunctionCall::decompile(int indent) const {
    string res = _name->decompile(indent) + "(";
    for (auto it = _args.begin(); it != _args.end(); ++it) {
        res += (*it)->decompile(indent);
        if (it + 1 != _args.end()) {
            res += ", ";
        }
    }
    res += ")";

    return res;
}

Symbol *FunctionCall::resolveSymbols(Environment *parent) {
    for (auto &arg: _args) {
        arg->resolveSymbols(parent);
    }

    return nullptr;
}

AbstractType *FunctionCall::inferType(Environment *parent) {
    auto functionType = (LambdaType *) _name->inferType(parent);

    // Check args types
    auto argsTypes = functionType->getArgsTypes();
    if (argsTypes.size() == _args.size()) {
        for (long unsigned int i = 0; i < argsTypes.size(); i++) {
            auto expected = argsTypes[i];
            auto argType = _args[i]->inferType(parent);

            if (*argType != *expected) {
                ErrorsRegister::addError(
                        new Error("Argument " + to_string(i) + " of " + _name->getName() + " expects type " +
                                  expected->getName() + ", " + argType->getName() + " provided",
                                  _args[i]->getPosition())
                );
            }
        }
    } else {
        ErrorsRegister::addError(
                new Error("Function " + _name->getName() + " expects " + to_string(argsTypes.size()) + " arguments, " +
                          to_string(_args.size()) + " provided",
                          _name->getPosition())
        );
    }

    _exprType = functionType->getReturnType();

    return _exprType;
}

string FunctionCall::dump(int indent) const {
    string res = string(indent, '\t') + "[FunctionCall]" + (_isExported ? " <exported> " : " ") +
                 "<name:" + _name->getName() + ">";
    if (_exprType) { // Problem from recursive call, see inferType
        res += " <type:" + _exprType->getName() + ">";
    }
    res += "\n";

    for (auto &arg: _args) {
        res += arg->dump(indent + 1);
    }

    return res;
}
