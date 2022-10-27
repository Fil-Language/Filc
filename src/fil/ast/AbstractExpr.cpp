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

string AbstractExpr::toString() const {
    return _export ? "export" : "";
}
