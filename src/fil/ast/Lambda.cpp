/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Lambda::Lambda() : _body(nullptr) {}

Lambda::Lambda(std::vector<FunctionParam *> &params, ast::AbstractExpr *body) : _params(params), _body(body) {}

Lambda::~Lambda() {
    for (auto &param: _params) {
        delete param;
    }
    delete _body;
}

string Lambda::decompile(int indent) const {
    string res = "(";

    for (auto it = _params.begin(); it != _params.end(); it++) {
        res += (*it)->decompile(indent);
        if (it != _params.end() - 1) {
            res += ", ";
        }
    }

    return res + ") -> " + _body->decompile(indent);
}
