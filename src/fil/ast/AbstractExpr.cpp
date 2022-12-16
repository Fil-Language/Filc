/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractExpr::AbstractExpr() : _isExported(false) {}

string AbstractExpr::decompile(int indent) const {
    throw;
}

void AbstractExpr::isExported(bool exported) {
    _isExported = exported;
}
