/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AST::~AST() = default;

AST::AST() = default;

string &AST::decompile(int indent) const {
    throw;
}
