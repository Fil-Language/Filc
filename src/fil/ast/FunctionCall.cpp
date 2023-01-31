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
