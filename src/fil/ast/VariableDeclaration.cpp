/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

VariableDeclaration::VariableDeclaration(bool isVal, const std::string &name)
        : _isVal(isVal), _name(name) {}

string VariableDeclaration::decompile(int indent) const {
    return (_isVal ? "val " : "var ") + _name;
}
