/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function() : _name(nullptr), _body(nullptr), _returnType(nullptr) {}

Function::Function(Identifier *name, vector<FunctionParam *> &params, AbstractExpr *body, Type *returnType)
        : _name(name), _params(params), _body(body), _returnType(returnType) {}

Function::~Function() {
    delete _name;
    for (auto &param: _params) {
        delete param;
    }
    delete _body;
    delete _returnType;
}
