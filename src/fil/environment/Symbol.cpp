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
#include "Symbol.h"

#include <utility>

using namespace std;
using namespace ast;

Symbol::Symbol(string name, Position *position, SymbolKind kind)
    : _name(std::move(name)), _position(position), _kind(kind), _signature(nullptr) {}

Symbol::~Symbol() {
    delete _position;
}

auto Symbol::getName() const -> std::string {
    return _name;
}

auto Symbol::getPosition() const -> Position * {
    return _position;
}

auto Symbol::getKind() const -> Symbol::SymbolKind {
    return _kind;
}

auto Symbol::getSignature() const -> ast::AbstractType * {
    return _signature;
}

auto Symbol::setSignature(AbstractType *signature) -> AbstractType * {
    _signature = signature;

    return _signature;
}

auto Symbol::operator==(const Symbol &other) const -> bool {
    return _name == other._name &&
           _kind == other._kind &&
           _signature == other._signature;
}

auto Symbol::operator!=(const Symbol &other) const -> bool {
    return !(other == *this);
}
