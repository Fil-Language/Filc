/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionCall::FunctionCall() : _name(nullptr) {}

FunctionCall::FunctionCall(Identifier *name, vector<AbstractExpr *> &args)
        : _name(name), _args(args) {}

FunctionCall::~FunctionCall() {
    delete _name;
    for (auto &arg: _args) {
        delete arg;
    }
}

string FunctionCall::decompile(int indent) const {
    string res = _name->decompile(indent) + "(";

    for (auto it = _args.begin(); it != _args.end(); it++) {
        res += (*it)->decompile(indent);
        if (it != _args.end() - 1) {
            res += ", ";
        }
    }

    return res + ")";
}
