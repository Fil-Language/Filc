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

SwitchPattern::SwitchPattern()
        : _isDefault(true), _literal(nullptr) {}

SwitchPattern::SwitchPattern(AbstractLiteral *literal)
        : _isDefault(false), _literal(literal) {}

string SwitchPattern::decompile(int indent) const {
    return _isDefault ? "default" : _literal->decompile(indent);
}

AbstractLiteral *SwitchPattern::getLiteral() const {
    return _literal;
}

string SwitchPattern::dump(int indent) const {
    if (_isDefault) {
        return string(indent, '\t') + "[SwitchPattern] <default>\n";
    } else {
        string res = string(indent, '\t') + "[SwitchPattern]\n";

        res += _literal->dump(indent + 1);

        return res;
    }
}

bool SwitchPattern::isDefault() const {
    return _isDefault;
}
