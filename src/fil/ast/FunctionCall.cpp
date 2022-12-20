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

string FunctionCall::decompile(int level) const {
    string res = _name->decompile(level) + "(";
    for (auto it = _args.begin(); it != _args.end(); ++it) {
        res += (*it)->decompile(level);
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
