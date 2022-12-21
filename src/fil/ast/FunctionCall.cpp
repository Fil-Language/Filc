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

FunctionCall::~FunctionCall() {
    delete _name;
    for (auto &arg: _args) {
        delete arg;
    }
}

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

void FunctionCall::resolveEnvironment(Environment *parent) {
    if (!parent->hasFunction(_name->getName())) {
        ErrorsRegister::addError(
                "Unknown function " + _name->getName(),
                _name->getPosition()
        );
    }

    for (auto &arg: _args) {
        arg->resolveEnvironment(parent);
    }
}

AbstractType *FunctionCall::inferType(Environment *env) {
    auto functionType = env->getSymbol(_name->getName())->getType();
    // If it's a recursive call, the return type is nullptr here
    _exprType = ((LambdaType *) functionType)->getReturnType();

    // Check args types
    auto argsTypes = ((LambdaType *) functionType)->getArgsTypes();
    if (argsTypes.size() != _args.size()) {
        ErrorsRegister::addError(
                _name->getName() + " expects " + to_string(argsTypes.size()) + " arguments, " +
                to_string(_args.size()) + " provided",
                _name->getPosition()
        );
    } else {
        for (int i = 0; i < _args.size(); i++) {
            auto argType = _args[i]->inferType(env);
            if (*argType != *argsTypes[i]) {
                ErrorsRegister::addError(
                        "Argument " + to_string(i) + " of " + _name->getName() + " expects type " +
                        argsTypes[i]->getName() + ", " + argType->getName() + " provided",
                        _args[i]->getPosition()
                );
            }
        }
    }

    return _exprType;
}

string FunctionCall::dump(int indent) const {
    string res = string(indent, '\t') + "[FunctionCall] <name:" + _name->getName() + ">";
    if (_exprType) { // Problem from recursive call, see inferType
        res += " <type:" + _exprType->getName() + ">";
    }
    res += "\n";

    for (auto &arg: _args) {
        res += arg->dump(indent + 1);
    }

    return res;
}
