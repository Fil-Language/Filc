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
#include "Parser.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using namespace ::testing;

#define FIXTURES_PATH "../../tests/unit/Fixtures/grammar"

TEST(Parser, filename) {
    filc::grammar::Parser parser(FIXTURES_PATH "/module1.fil");
    auto *program = parser.getProgram();
    ASSERT_STREQ(FIXTURES_PATH "/module1.fil", program->getFilename().c_str());
}

TEST(Parser, module) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/module1.fil");
    auto *program1 = parser1.getProgram();
    ASSERT_STREQ("a", program1->getModule().c_str());

    filc::grammar::Parser parser2(FIXTURES_PATH "/module2.fil");
    auto *program2 = parser2.getProgram();
    ASSERT_STREQ("a.b", program2->getModule().c_str());

    filc::grammar::Parser parser3(FIXTURES_PATH "/module3.fil");
    auto *program3 = parser3.getProgram();
    ASSERT_STREQ("an.example.with.many.dots", program3->getModule().c_str());
}

TEST(Parser, use) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/use1.fil");
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getImports(), SizeIs(1));
    ASSERT_THAT(program1->getImports(), Contains("a"));

    filc::grammar::Parser parser2(FIXTURES_PATH "/use2.fil");
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getImports(), SizeIs(1));
    ASSERT_THAT(program2->getImports(), Contains("a.b"));

    filc::grammar::Parser parser3(FIXTURES_PATH "/use3.fil");
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getImports(), SizeIs(1));
    ASSERT_THAT(program3->getImports(), Contains("an.example.with.many.dots"));

    filc::grammar::Parser parser4(FIXTURES_PATH "/use4.fil");
    auto *program4 = parser4.getProgram();
    ASSERT_THAT(program4->getImports(), SizeIs(3));
    ASSERT_THAT(program4->getImports(), Contains("a.b"));
    ASSERT_THAT(program4->getImports(), Contains("c.d"));
    ASSERT_THAT(program4->getImports(), Contains("e.f"));
}