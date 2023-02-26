/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Program::Program(const string &module,
                 const vector<Program *> &imports,
                 const vector<AbstractExpr *> &exprs)
        : _module(module), _imports(imports), _exprs(exprs), _environment(nullptr), _resolved(false) {}

string Program::decompile(int indent) const {
    string result = "module " + _module + "\n\n";

    for (auto &import: _imports) {
        result += "use " + import->_module + "\n";
    }

    result += "\n";

    for (auto &expr: _exprs) {
        result += (expr->isExported() ? "export " : "") + expr->decompile(indent) + "\n\n";
    }

    return result;
}

void Program::resolveEnvironment() {
    // TODO : resolve imports

    // TODO : merge imports env to _environment

    // TODO : resolve exprs
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

void Program::setEnvironment(Environment *environment) {
    _environment = environment;
}
