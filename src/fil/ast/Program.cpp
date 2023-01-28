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

bool Program::hasMain() const {
    if (_environment == nullptr) {
        return false;
    }

    return _environment->hasSymbol("main", nullptr);
}

void Program::resolveSymbols() {
    _environment = Environment::getGlobalEnvironment();

    // Resolve exprs
    for (auto &expr: _exprs) {
        expr->resolveSymbols(_environment);
    }
}

void Program::mergeImports() {
    Environment *prev = Environment::getGlobalEnvironment();

    for (auto &imp: _imports) {
        imp->_environment->setParent(prev);
        prev = imp->getPublicEnvironment();
    }

    if (prev)
        _environment->setParent(prev);
}

Environment *Program::getPublicEnvironment() const {
    auto *env = new Environment();

    for (auto &expr: _exprs) {
        if (expr->isExported()) {
            if (expr->isVar()) {
                auto symbol = ((VariableDeclaration *) expr)->getSymbol();
                env->addSymbol(symbol->getName(), symbol->getPosition(), Symbol::VARIABLE)
                        ->setSignature(symbol->getSignature());
            } else if (expr->isFunc()) {
                auto symbol = ((Function *) expr)->getSymbol();
                env->addSymbol(symbol->getName(), symbol->getPosition(), Symbol::FUNCTION)
                        ->setSignature(symbol->getSignature());
            } else {
                auto pos = expr->getPosition();
                env->addSymbol(replace(_module, '.', '_') + "_" + to_string(pos->getLine()), pos, Symbol::VARIABLE)
                        ->setSignature(expr->getExprType());
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

void Program::setEnvironment(Environment *environment) {
    _environment = environment;
}
