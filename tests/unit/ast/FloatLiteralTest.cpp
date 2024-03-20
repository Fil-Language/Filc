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
#include "Literal.h"
#include "test_tools.h"

TEST(FloatLiteral, constructor) {
    filc::ast::FloatLiteral fl1(42);
    ASSERT_EQ(42, fl1.getValue());
    ASSERT_FALSE(fl1.isDouble());

    filc::ast::FloatLiteral fl2(2.3);
    ASSERT_EQ(2.3, fl2.getValue());
    ASSERT_FALSE(fl2.isDouble());

    filc::ast::FloatLiteral fl3(-4.5, true);
    ASSERT_EQ(-4.5, fl3.getValue());
    ASSERT_TRUE(fl3.isDouble());
}
