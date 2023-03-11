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

Type::Type(Identifier *name)
        : _name(name), _isArray(false), _arraySize(0), _isPointer(false), _subType(nullptr) {}

Type::Type(int arraySize, AbstractType *subType)
        : _name(nullptr), _isArray(true), _arraySize(arraySize), _isPointer(false), _subType(subType) {}

Type::Type(AbstractType *subType)
        : _name(nullptr), _isArray(false), _arraySize(0), _isPointer(true), _subType(subType) {}

string Type::decompile(int indent) const {
    if (_isPointer) {
        return _subType->decompile(indent) + "*";
    } else if (_isArray) {
        return _subType->decompile(indent) + "[" + to_string(_arraySize) + "]";
    } else {
        return _name->decompile(indent);
    }
}

string Type::getName() const {
    if (_isPointer) {
        return _subType->getName() + "*";
    } else if (_isArray) {
        return _subType->getName() + "[" + to_string(_arraySize) + "]";
    } else {
        return _name->getName();
    }
}

bool Type::isIterable() const {
    return _isArray;
}

AbstractType *Type::getIterableType() {
    if (isIterable()) {
        return _subType;
    } else {
        return AbstractType::getIterableType();
    }
}
