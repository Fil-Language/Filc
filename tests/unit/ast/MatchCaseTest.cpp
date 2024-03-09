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

TEST(MatchCase, constructor) {
    filc::ast::MatchCase mc1(new filc::ast::Identifier("_"), new filc::ast::BlockBody({}));
    ASSERT_IDENTIFIER("_", mc1.getPattern());
    ASSERT_THAT(mc1.getBody()->getExpressions(), IsEmpty());
}

TEST(MatchCase, isDefault) {
    filc::ast::MatchCase mc1(new filc::ast::Identifier("_"), {});
    ASSERT_TRUE(mc1.isDefault());

    filc::ast::MatchCase mc2(new filc::ast::Identifier("abcd"), {});
    ASSERT_FALSE(mc2.isDefault());

    filc::ast::MatchCase mc3(new filc::ast::IntegerLiteral(2), {});
    ASSERT_FALSE(mc3.isDefault());
}