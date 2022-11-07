/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Return::Return() : _expr(nullptr) {}

Return::Return(AbstractExpr *expr) : _expr(expr) {}

Return::~Return() {
    delete _expr;
}
