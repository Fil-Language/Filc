/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"
#include "FilCompiler.h"

using namespace std;
using namespace ast;

Program::Program(const string &module,
                 const vector<std::string> &imports,
                 const vector<AbstractExpr *> &exprs)
        : _module(module), _imports(imports), _exprs(exprs), _environment(nullptr), _resolved(false) {}

string Program::decompile(int indent) const {
    string result = "module " + _module + "\n";

    if (!_imports.empty())
        result += "\n";
    for (auto &import: _imports) {
        result += "use " + import + "\n";
    }

    if (!_exprs.empty())
        result += "\n";
    for (auto &expr: _exprs) {
        result += (expr->isExported() ? "export " : "") + expr->decompile(indent) + "\n\n";
    }

    return result;
}

void Program::resolveEnvironment() {
    if (_resolved) // Fix infinite loop of resolve
        return;
    _resolved = true;

    // Remove duplicate imports
    sort(_imports.begin(), _imports.end());
    _imports.erase(unique(_imports.begin(), _imports.end()), _imports.end());

    // Resolve imports
    for (auto &import: _imports) {
        auto module = FilCompiler::getModule(import);
        if (module == nullptr) {
            ErrorsRegister::addWarning(
                    new BasicWarning("\033[1mDev code 2\033[21m\nModule '" + import + "' not found")
            );
            continue;
        }

        module->resolveEnvironment();
        _importedModules.push_back(module);
    }

    // TODO : merge imports env to _environment

    // TODO : resolve exprs
}

string Program::dump(int indent) const {
    string res = string(indent, '\t') + "[Program] <module:" + _module + ">\n";

    for (auto &imp: _importedModules) {
        res += imp->dump(indent + 1);
    }

    for (auto &expr: _exprs) {
        res += expr->dump(indent + 1);
    }

    return res;
}

void Program::setEnvironment(Environment *environment) {
    _environment = environment;
}
