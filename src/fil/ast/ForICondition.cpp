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

ForICondition::ForICondition(VariableDeclaration *declaration, AbstractExpr *condition, AbstractExpr *increment)
        : _declaration(declaration), _condition(condition), _increment(increment) {}

string ForICondition::decompile(int indent) const {
    return _declaration->decompile(indent) + "; "
           + _condition->decompile(indent) + "; "
           + _increment->decompile(indent);
}

string ForICondition::dump(int indent) const {
    string res = string(indent, '\t') + "[ForICondition]\n";

    if (_declaration)
        res += _declaration->dump(indent + 1);
    else
        res += string(indent + 1, '\t') + "_\n";

    if (_condition)
        res += _condition->dump(indent + 1);
    else
        res += string(indent + 1, '\t') + "_\n";

    if (_increment)
        res += _increment->dump(indent + 1);
    else
        res += string(indent + 1, '\t') + "_\n";

    return res;
}
