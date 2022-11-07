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

Program::Program() : _imports(vector<Program *>()), _exprs(vector<AbstractExpr *>()) {}

Program::Program(string moduleName) : _moduleName(std::move(moduleName)), _imports(vector<Program *>()),
                                      _exprs(vector<AbstractExpr *>()) {}

Program::Program(string moduleName, vector<Program *> &imports, vector<AbstractExpr *> &exprs) :
        _moduleName(std::move(moduleName)), _imports(imports), _exprs(exprs) {}
