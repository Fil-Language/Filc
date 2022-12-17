/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Lambda::Lambda(const vector<FunctionParam *> &params, Type *type, AbstractExpr *body)
        : _params(params), _type(type), _body(body) {}

Lambda::~Lambda() {
    for (auto param: _params) {
        delete param;
    }
    delete _type;
    delete _body;
}

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
