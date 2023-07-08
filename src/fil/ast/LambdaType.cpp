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

LambdaType::LambdaType(const vector<AbstractType *> &args, AbstractType *ret)
    : _args(args), _ret(ret) {}

auto LambdaType::decompile(int indent) const -> string {
    string res = "(";
    for (auto it = _args.begin(); it != _args.end(); ++it) {
        res += (*it)->decompile(indent);
        if (it + 1 != _args.end()) {
            res += ", ";
        }
    }
    res += ") -> " + _ret->decompile(indent);

    return res;
}

auto LambdaType::getName() const -> string {
    string res = "(";
    for (auto it = _args.begin(); it != _args.end(); ++it) {
        res += (*it)->getName();
        if (it + 1 != _args.end()) {
            res += ", ";
        }
    }

    return res + ") -> " + _ret->getName();
}

auto LambdaType::getReturnType() const -> AbstractType * {
    return _ret;
}

auto LambdaType::getArgsTypes() const -> const vector<AbstractType *> & {
    return _args;
}

void LambdaType::setReturnType(AbstractType *ret) {
    _ret = ret;
}
