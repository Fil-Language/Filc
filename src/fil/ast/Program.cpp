/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

#include <utility>

using namespace std;
using namespace ast;

Program::Program() : _imports(vector<Program>()), _exprs(vector<AbstractExpr>()) {}

Program::Program(string moduleName) : _moduleName(std::move(moduleName)), _imports(vector<Program>()),
                                      _exprs(vector<AbstractExpr>()) {}

Program::Program(string moduleName, vector<Program> &imports, vector<AbstractExpr> &exprs) :
        _moduleName(std::move(moduleName)), _imports(imports), _exprs(exprs) {}

std::string Program::toString() const {
    string res;
    res += "Program: " + _moduleName + "\n";

    for (const auto &import: _imports) {
        res += "\t" + import.toString() + "\n";
    }

    for (const auto &expr: _exprs) {
        res += "\t" + expr.toString() + "\n";
    }

    return res;
}
