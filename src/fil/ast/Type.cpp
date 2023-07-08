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
    : _name(name), _is_array(false), _array_size(0), _is_pointer(false), _sub_type(nullptr) {}

Type::Type(int array_size, AbstractType *sub_type)
    : _name(nullptr), _is_array(true), _array_size(array_size), _is_pointer(false), _sub_type(sub_type) {}

Type::Type(AbstractType *sub_type)
    : _name(nullptr), _is_array(false), _array_size(0), _is_pointer(true), _sub_type(sub_type) {}

auto Type::decompile(int indent) const -> string {
    if (_is_pointer) {
        return _sub_type->decompile(indent) + "*";
    }
    if (_is_array) {
        return _sub_type->decompile(indent) + "[" + to_string(_array_size) + "]";
    }
    return _name->decompile(indent);
}

auto Type::getName() const -> string {
    if (_is_pointer) {
        return _sub_type->getName() + "*";
    }
    if (_is_array) {
        return _sub_type->getName() + "[" + to_string(_array_size) + "]";
    }
    return _name->getName();
}

auto Type::isIterable() const -> bool {
    return _is_array;
}

auto Type::getIterableType() -> AbstractType * {
    return isIterable() ? _sub_type : AbstractType::getIterableType();
}
