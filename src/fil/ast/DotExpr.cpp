/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

DotExpr::DotExpr() : _left(nullptr), _right(nullptr) {}

DotExpr::DotExpr(AbstractExpr *left, AbstractExpr *right)
        : _left(left), _right(right) {}

DotExpr::~DotExpr() {
    delete _left;
    delete _right;
}
