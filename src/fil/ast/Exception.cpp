/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Try::Try() : _body(nullptr) {}

Try::Try(AbstractExpr *body, vector<Catch *> &catches)
        : _body(body), _catches(catches) {}

Try::~Try() {
    delete _body;
    for (auto &c: _catches) {
        delete c;
    }
}

string Try::decompile(int indent) const {
    string res = "try\n";

    res += _body->decompile(indent + 1);

    for (auto &c: _catches) {
        res += c->decompile(indent + 1);
    }

    return res;
}

// ====================

Catch::Catch() : _param(nullptr), _body(nullptr) {}

Catch::Catch(FunctionParam *param, AbstractExpr *body)
        : _param(param), _body(body) {}

Catch::~Catch() {
    delete _param;
    delete _body;
}

string Catch::decompile(int indent) const {
    string res = "catch(" + _param->decompile(indent) + ")\n";

    return res + _body->decompile(indent + 1);
}
