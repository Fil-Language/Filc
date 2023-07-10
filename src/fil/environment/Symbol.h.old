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
#ifndef FILC_SYMBOL_H
#define FILC_SYMBOL_H

#include "AST_decl.h"
#include "utils.h"
#include <string>

class Symbol {
public:
    enum SymbolKind {
        FUNCTION,
        VARIABLE,
        TYPE
    };

    Symbol(std::string name, Position *position, SymbolKind kind);

    ~Symbol();

    [[nodiscard]] auto getName() const -> std::string;

    [[nodiscard]] auto getPosition() const -> Position *;

    [[nodiscard]] auto getKind() const -> SymbolKind;

    [[nodiscard]] auto getSignature() const -> ast::AbstractType *;

    auto setSignature(ast::AbstractType *signature) -> ast::AbstractType *;

    auto operator==(const Symbol &other) const -> bool;

    auto operator!=(const Symbol &other) const -> bool;

private:
    std::string _name;
    Position *_position;
    SymbolKind _kind;
    ast::AbstractType *_signature;
};

#endif//FILC_SYMBOL_H
