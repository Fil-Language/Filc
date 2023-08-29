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

using namespace ::testing;

TEST(Function, constructor) {
    filc::ast::Function fun1(
            new filc::ast::Identifier("fact"),
            {},
            new filc::ast::Type(new filc::ast::Identifier("int")),
            {}
    );
    ASSERT_IDENTIFIER("fact", fun1.getName());
    ASSERT_THAT(fun1.getParameters(), IsEmpty());
    ASSERT_TYPE("int", fun1.getReturnType());
    ASSERT_THAT(fun1.getBody(), IsEmpty());
}

TEST(Function, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/grammar/function1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR));
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    ASSERT_TYPE("(int, int) -> int", program1->getExpressions()[0]->getExpressionType());

    COLLECTOR->flush();
    filc::grammar::Parser parser2(FIXTURES_PATH "/grammar/function2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_NO_THROW(program2->resolveEnvironment(COLLECTOR));
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    ASSERT_TRUE(COLLECTOR->hasErrors());
    ASSERT_EQ(nullptr, program2->getExpressions()[0]->getExpressionType());
}