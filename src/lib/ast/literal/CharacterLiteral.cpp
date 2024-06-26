/**
 * MIT License
 *
 * Copyright (c) 2023-Present Kevin Traini
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
#include "DevWarning.h"
#include "Literal.h"
#include "MessageCollector.h"
#include "tools.h"

using namespace filc::ast;

CharacterLiteral::CharacterLiteral(char value): AbstractLiteral<char>(value) {}

auto CharacterLiteral::stringToChar(const std::string &snippet, antlr4::Token *token) -> char {
    auto value = snippet.substr(1, snippet.size() - 2);

    if (value.size() == 1) {
        // Just a simple char
        return value[0];
    }

    if (value.size() == 2) {
        // An escaped char \\ + ['"?abfnrtv\\]
        return filc::utils::parseEscapedChar(value);
    }

    // There is a problem with the lexer
    if (token != nullptr) {
        message::MessageCollector::getCollector()->addError(new message::DevWarning(
            2, std::make_shared<utils::SimplePosition>(token), "Lexer found a character that is not regular: " + snippet
        ));
    }

    return '\0';
}

auto CharacterLiteral::accept(Visitor *visitor) -> void {
    visitor->visitCharacterLiteral(this);
}
