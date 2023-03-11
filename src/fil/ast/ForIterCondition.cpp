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

ForIterCondition::ForIterCondition(bool isVal, Identifier *iterator, Identifier *iterable)
        : _isVal(isVal), _iterator(iterator), _iterable(iterable), _iteratorSymbol(nullptr) {}

string ForIterCondition::decompile(int indent) const {
    return (_isVal ? "val " : "var ")
           + _iterator->decompile(indent)
           + ": "
           + _iterable->decompile(indent);
}

string ForIterCondition::dump(int indent) const {
    string res = string(indent, '\t') + "[ForIterCondition] " + (_isVal ? "<val>" : "<var>") + "\n";

    res += _iterator->dump(indent + 1);
    res += _iterable->dump(indent + 1);

    return res;
}
