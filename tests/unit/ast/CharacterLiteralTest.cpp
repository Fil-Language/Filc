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
#include "AST.h"
#include "test_tools.h"
#include "Parser.h"
#include "FilLexer.h"

TEST(CharacterLiteral, constructor) {
    filc::ast::CharacterLiteral cl1('a');
    ASSERT_EQ('a', cl1.getValue());
}

TEST(CharacterLiteral, stringToChar) {
    ASSERT_EQ('a', filc::ast::CharacterLiteral::stringToChar("'a'", nullptr));
    ASSERT_EQ('5', filc::ast::CharacterLiteral::stringToChar("'5'", nullptr));
    ASSERT_EQ('\n', filc::ast::CharacterLiteral::stringToChar("'\\n'", nullptr));
    ASSERT_EQ('\t', filc::ast::CharacterLiteral::stringToChar("'\\t'", nullptr));
    ASSERT_EQ('\0', filc::ast::CharacterLiteral::stringToChar("abcdefghijklmnopqrstuvwxyz", nullptr));
    ASSERT_FALSE(COLLECTOR->hasErrors());

    antlr4::ANTLRFileStream input;
    input.loadFromFile(FIXTURES_PATH "/grammar/bool1.fil");
    filc::antlr::FilLexer lexer(&input);
    const auto factory = antlr4::CommonTokenFactory::DEFAULT.get();
    auto token = factory->create(
            {&lexer, &input},
            0,
            "text",
            0, 0, 0, 0, 0
    );
    ASSERT_EQ('\0', filc::ast::CharacterLiteral::stringToChar("abcdefghijklmnopqrstuvwxyz", token.get()));
    ASSERT_TRUE(COLLECTOR->hasErrors());
    COLLECTOR->flush();
}