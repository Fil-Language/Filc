/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Interface::Interface() : _name(nullptr) {}

Interface::Interface(Identifier *name, std::vector<ClassParam *> &params, std::vector<FunctionDecl *> &functions)
        : _name(name), _params(params), _functions(functions) {}

Interface::~Interface() {
    delete _name;
    for (auto &param: _params) {
        delete param;
    }
    for (auto &function: _functions) {
        delete function;
    }
}
