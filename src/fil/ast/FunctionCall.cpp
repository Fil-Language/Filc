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
