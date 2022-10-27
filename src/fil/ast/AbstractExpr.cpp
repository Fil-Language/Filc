/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractExpr::AbstractExpr() : _export(false) {}

void AbstractExpr::setExport(bool export_) {
    _export = export_;
}

IndentPrinter *AbstractExpr::print(IndentPrinter *printer) const {
    return printer->writeIndent("AbstractExpr => ")
            ->write(_export ? "export\n" : "\n");
}
