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

UnaryCalcul::UnaryCalcul(Identifier *identifier, Operator *p_operator)
    : _operator(p_operator), _identifier(identifier), _is_prefix(false) {}

UnaryCalcul::UnaryCalcul(Operator *p_operator, Identifier *identifier)
    : _operator(p_operator), _identifier(identifier), _is_prefix(true) {}

auto UnaryCalcul::decompile(int indent) const -> std::string {
    if (_is_prefix) {
        return _operator->decompile(indent) + _identifier->decompile(indent);
    }
    return _identifier->decompile(indent) + _operator->decompile(indent);
}

auto UnaryCalcul::dump(int indent) const -> string {
    string res = string(indent, '\t') + "[UnaryCalcul]" + (_is_exported ? " <exported> " : " ") + (_is_prefix ? "<prefix>" : "<postfix>") + " <operator:" + _operator->decompile(indent) + ">" + " <type:" + _expr_type->getName() + ">\n";

    res += _identifier->dump(indent + 1);

    return res;
}
