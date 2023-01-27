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

//void Program::resolveGlobalEnvironment() {
//    _environment = Environment::getGlobalEnvironment();
//    resolveEnvironment();
//}
//
//void Program::resolveEnvironment() {
//    // Merge imports
//    for (auto &imp: _imports) {
//        _environment->merge(imp->getPublicEnvironment());
//    }
//
//    // Resolve exprs
//    for (auto &expr: _exprs) {
//        expr->resolveEnvironment(_environment);
//    }
//}
//
//Environment *Program::getPublicEnvironment() const {
//    auto *env = new Environment();
//
//    for (auto &expr: _exprs) {
//        if (expr->isExported()) {
//            if (expr->isVar()) {
//                auto *symbol = ((VariableDeclaration *) expr)->getSymbol();
//                env->addVariable(symbol);
//            } else if (expr->isFunc()) {
//                auto *symbol = ((Function *) expr)->getSymbol();
//                env->addFunction(symbol);
//            } else {
//                auto pos = expr->getPosition();
//                auto symbol = new Symbol(replace(_module, '.', '_') + "_" + to_string(pos->getLine()), pos);
//                symbol->setSignature(expr->getExprType());
//                env->addVariable(symbol);
//            }
//        }
//    }
//
//    return env;
//}
//
//void Program::inferTypes() {
//    // Merge imports
//    for (auto &imp: _imports) {
//        _environment->merge(imp->getPublicEnvironment());
//    }
//
//    // Infer exprs
//    for (auto &expr: _exprs) {
//        expr->inferType(_environment);
//    }
//}

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
