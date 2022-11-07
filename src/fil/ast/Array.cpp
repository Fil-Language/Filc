/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Array::Array() = default;

Array::Array(vector<AbstractExpr *> &values) : _values(values) {}
