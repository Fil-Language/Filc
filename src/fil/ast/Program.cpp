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
        : _module(module), _imports(imports), _exprs(exprs), _environment(nullptr) {}

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

void Program::resolveGlobalEnvironment() {
    _environment = Environment::getGlobalEnvironment();
    resolveEnvironment();
}

void Program::resolveEnvironment() {
    // Resolve imports
    for (auto &imp: _imports) {
        imp->resolveEnvironment();
        _environment->merge(imp->getPublicEnvironment());
    }

    // Resolve exprs
    for (auto &expr: _exprs) {
        expr->resolveEnvironment(_environment);
    }
}

Environment *Program::getPublicEnvironment() const {
    auto *env = new Environment();

    for (auto &expr: _exprs) {
        if (expr->isExported()) {
            // TODO : add expr to env
        }
    }

    return env;
}
