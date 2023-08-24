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

TEST(AbstractExpression, position) {
    class : public filc::ast::AbstractExpression {
    } obj1;

    ASSERT_EQ(nullptr, obj1.getPosition());

    obj1.setPosition(new filc::utils::Position("test.fil", 1, 2));
    auto *position = obj1.getPosition();
    ASSERT_STREQ("test.fil", position->getFilename().c_str());
    ASSERT_EQ(1, position->getLine());
    ASSERT_EQ(2, position->getColumn());
}

TEST(AbstractExpression, exported) {
    class : public filc::ast::AbstractExpression {
    } obj1;

    ASSERT_FALSE(obj1.isExported());

    obj1.setExported(true);
    ASSERT_TRUE(obj1.isExported());
}