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

string Program::decompile(int indent) const {
    string result = "module " + _module + "\n\n";

    for (auto &import: _imports) {
        result += "import " + import->_module + "\n";
    }

    result += "\n";

    for (auto &expr: _exprs) {
        result += (expr->isExported() ? "export " : "") + expr->decompile(indent) + "\n\n";
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
            if (expr->isVar()) {
                auto *symbol = ((VariableDeclaration *) expr)->getSymbol();
                env->addVariable(symbol->getName(), symbol->getPosition());
            } else if (expr->isFunc()) {
                auto *symbol = ((Function *) expr)->getSymbol();
                env->addFunction(symbol->getName(), symbol->getPosition());
            } else {
                auto pos = expr->getPosition();
                env->addVariable(replace(_module, '.', '_') + "_" + to_string(pos->getLine()), pos);
            }
        }
    }

    return env;
}

void Program::inferTypes() {
    for (auto &expr: _exprs) {
        expr->inferType(_environment);
    }
}

string Program::dump(int indent) const {
    string res = string(indent, '\t') + "[Program] <module:" + _module + ">\n";

    for (auto &imp: _imports) {
        res += imp->dump(indent + 1);
    }

    for (auto &expr: _exprs) {
        res += expr->dump(indent + 1);
    }

    return res;
}
