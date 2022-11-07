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

// ====================

Catch::Catch() : _param(nullptr), _body(nullptr) {}

Catch::Catch(FunctionParam *param, AbstractExpr *body)
        : _param(param), _body(body) {}

Catch::~Catch() {
    delete _param;
    delete _body;
}
