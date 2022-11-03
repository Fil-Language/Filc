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

IndentPrinter *Program::print(IndentPrinter *printer) const {
    /*printer->writeIndent("Program => " + _moduleName + "\n")
            ->indent();

    for (const auto &import: _imports) {
        import->print(printer);
    }

    for (const auto &expr: _exprs) {
        expr->print(printer);
    }

    printer->unindent();*/

    return printer->write("Commented");
}
