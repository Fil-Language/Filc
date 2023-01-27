/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Symbol *AbstractLiteral::resolveSymbols(Environment *parent) {
    // Do nothing
    return nullptr;
}
