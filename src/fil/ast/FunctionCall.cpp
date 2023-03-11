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

FunctionCall::FunctionCall(Identifier *name, const vector<AbstractExpr *> &args)
        : _name(name), _args(args) {}

string FunctionCall::decompile(int indent) const {
    string res = _name->decompile(indent) + "(";
    for (auto it = _args.begin(); it != _args.end(); ++it) {
        res += (*it)->decompile(indent);
        if (it + 1 != _args.end()) {
            res += ", ";
        }
    }
    res += ")";

    return res;
}

string FunctionCall::dump(int indent) const {
    string res = string(indent, '\t') + "[FunctionCall]" + (_isExported ? " <exported> " : " ") +
                 "<name:" + _name->getName() + ">";
    if (_exprType) { // Problem from recursive call, see inferType
        res += " <type:" + _exprType->getName() + ">";
    }
    res += "\n";

    for (auto &arg: _args) {
        res += arg->dump(indent + 1);
    }

    return res;
}
