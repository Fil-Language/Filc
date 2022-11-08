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

Interface::Interface(Identifier *name, std::vector<FunctionDecl *> &functions)
        : _name(name), _functions(functions) {}

Interface::~Interface() {
    delete _name;
    for (auto &function: _functions) {
        delete function;
    }
}

string Interface::decompile(int indent) const {
    string res = "interface " + _name->decompile(indent);

    if (!_functions.empty()) {
        res += " {\n";
        for (auto &function: _functions) {
            res += function->decompile(indent + 1) + "\n";
        }
        res += "}";
    }

    return res;
}
