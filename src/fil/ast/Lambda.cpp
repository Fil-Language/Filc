/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Lambda::Lambda() : _body(nullptr) {}

Lambda::Lambda(std::vector<FunctionParam *> &params, ast::AbstractExpr *body) : _params(params), _body(body) {}

IndentPrinter *Lambda::print(IndentPrinter *printer) const {
    printer->writeIndent("Lambda => (");

    for (auto it = _params.begin(); it != _params.end(); it++) {
        (*it)->print(printer);
        if (it != _params.end() - 1) {
            printer->write(", ");
        }
    }
    printer->write(")\n")
            ->indent();

    _body->print(printer);

    return printer->unindent();
}
