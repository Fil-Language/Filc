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

TEST(ForIter, constructor) {
    filc::ast::ForIter fi1(
            true,
            new filc::ast::Identifier("item"),
            new filc::ast::Identifier("my_array"),
            {}
    );
    ASSERT_TRUE(fi1.isConstant());
    ASSERT_IDENTIFIER("item", fi1.getIdentifier());
    ASSERT_IDENTIFIER("my_array", fi1.getArray());
    ASSERT_THAT(fi1.getBody(), IsEmpty());
}

TEST(ForIter, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/for_iter1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR));
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    ASSERT_TYPE("char*", program1->getExpressions()[0]->getExpressionType());
}