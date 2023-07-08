/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

VariableDeclaration::VariableDeclaration(bool is_val, Identifier *name, AbstractType *type, Assignation *assignation)
    : _is_val(is_val), _name(name), _type(type), _assignation(assignation), _symbol(nullptr) {}

auto VariableDeclaration::decompile(int indent) const -> string {
    string result = (_is_val ? "val " : "var ") + _name->decompile(indent);

    if (_type != nullptr) {
        result += " : " + _type->decompile(indent);
    }

    if (_assignation != nullptr) {
        result += " " + _assignation->decompile(indent);
    }

    return result;
}

auto VariableDeclaration::isVar() const -> bool {
    return true;
}

auto VariableDeclaration::getSymbol() const -> Symbol * {
    return _symbol;
}

auto VariableDeclaration::dump(int indent) const -> string {
    string res = string(indent, '\t') + "[VariableDeclaration]" + (_is_exported ? " <exported> " : " ") + (_is_val ? "<val> " : "<var> ") + "<name:" + _name->getName() + "> " + "<type:" + _expr_type->getName() + ">\n";

    if (_assignation != nullptr) {
        res += _assignation->dump(indent + 1);
    }

    return res;
}
