/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Lambda::Lambda(const vector<FunctionParam *> &params, AbstractType *type, AbstractExpr *body)
        : _params(params), _type(type), _body(body), _environment(nullptr) {}

string Lambda::decompile(int indent) const {
    string res = "(";
    for (auto it = _params.begin(); it != _params.end(); ++it) {
        res += (*it)->decompile(indent);
        if (it + 1 != _params.end()) {
            res += ", ";
        }
    }
    res += ")";

    if (_type) {
        res += " : " + _type->decompile(indent);
    }

    res += " -> " + _body->decompile(indent);

    return res;
}

string Lambda::dump(int indent) const {
    string res = string(indent, '\t') + "[Lambda]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    for (auto param: _params) {
        res += param->dump(indent + 1);
    }

    res += _body->dump(indent + 1);

    return res;
}
