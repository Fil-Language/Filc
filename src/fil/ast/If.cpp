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

If::If(AbstractExpr *condition, AbstractExpr *then_case, AbstractExpr *else_case)
    : _condition(condition), _then(then_case), _else(else_case) {}

auto If::decompile(int indent) const -> string {
    string res = "if (" + _condition->decompile(indent) + ") " + _then->decompile(indent);

    if (_else != nullptr) {
        res += " else " + _else->decompile(indent);
    }

    return res;
}

auto If::dump(int indent) const -> string {
    string res = string(indent, '\t') + "[If]" + (_is_exported ? " <exported> " : " ") +
                 "<type:" + _expr_type->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += string(indent, '\t') + "<then>\n";
    res += _then->dump(indent + 1);
    if (_else != nullptr) {
        res += string(indent, '\t') + "<else>\n";
        res += _else->dump(indent + 1);
    }

    return res;
}
