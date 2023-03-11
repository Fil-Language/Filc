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

Switch::Switch(AbstractExpr *condition, const vector<SwitchCase *> &cases)
        : _condition(condition), _cases(cases) {}

string Switch::decompile(int indent) const {
    string res = "switch (" + _condition->decompile(indent) + ") {\n";

    for (auto &c: _cases) {
        res += string(indent + 1, '\t') + c->decompile(indent);
    }

    res += "}";

    return res;
}

string Switch::dump(int indent) const {
    string res = string(indent, '\t') + "[Switch]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);

    for (auto &c: _cases) {
        res += c->dump(indent + 1);
    }

    return res;
}
