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

UnaryCalcul::UnaryCalcul(Identifier *identifier, Operator *op)
        : _op(op), _identifier(identifier), _isPrefix(false) {}

UnaryCalcul::UnaryCalcul(Operator *op, Identifier *identifier)
        : _op(op), _identifier(identifier), _isPrefix(true) {}

std::string UnaryCalcul::decompile(int indent) const {
    if (_isPrefix) {
        return _op->decompile(indent) + _identifier->decompile(indent);
    } else {
        return _identifier->decompile(indent) + _op->decompile(indent);
    }
}

string UnaryCalcul::dump(int indent) const {
    string res = string(indent, '\t') + "[UnaryCalcul]"
                 + (_isExported ? " <exported> " : " ")
                 + (_isPrefix ? "<prefix>" : "<postfix>")
                 + " <operator:" + _op->decompile(indent) + ">"
                 + " <type:" + _exprType->getName() + ">\n";

    res += _identifier->dump(indent + 1);

    return res;
}
