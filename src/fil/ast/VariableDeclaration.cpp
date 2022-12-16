/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

VariableDeclaration::VariableDeclaration(bool isVal, const std::string &name, Type *type)
        : _isVal(isVal), _name(name), _type(type) {}

string VariableDeclaration::decompile(int indent) const {
    string result = (_isVal ? "val " : "var ") + _name;

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}
