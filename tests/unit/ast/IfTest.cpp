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
#include "Parser.h"
#include "test_tools.h"

TEST(If, constructor) {
    filc::ast::If if1(new filc::ast::Identifier("isTrue"), new filc::ast::BlockBody({}));
    ASSERT_IDENTIFIER("isTrue", if1.getCondition());
    ASSERT_THAT(if1.getBody()->getExpressions(), IsEmpty());
}

TEST(If, setElse) {
    filc::ast::If if1(new filc::ast::Identifier("isFalse"), new filc::ast::BlockBody({}));
    if1.setElse(new filc::ast::BlockBody({}));
    auto *ielse = if1.getElse();
    ASSERT_NE(nullptr, ielse);
    ASSERT_THAT(ielse->getExpressions(), IsEmpty());
}