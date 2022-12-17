/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Program::Program(const string &module,
                 const vector<Program *> &imports,
                 const vector<AbstractExpr *> &exprs)
        : _module(module), _imports(imports), _exprs(exprs) {}

Program::~Program() {
    for (auto &import: _imports) {
        delete import;
    }
    for (auto &expr: _exprs) {
        delete expr;
    }
}

string Program::decompile(int indent) const {
    string result = "module " + _module + "\n\n";

    for (auto &import: _imports) {
        result += "import " + import->_module + "\n";
    }

    result += "\n";

    for (auto &expr: _exprs) {
        result += expr->decompile(indent) + "\n\n";
    }

    return result;
}
