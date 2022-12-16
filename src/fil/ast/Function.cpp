/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Function::Function() {}

Function::~Function() {}

string Function::decompile(int indent) const {
    return "fun ";
}
