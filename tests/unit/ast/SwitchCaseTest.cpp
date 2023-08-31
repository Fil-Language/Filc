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

TEST(SwitchCase, constructor) {
    filc::ast::SwitchCase sc1(new filc::ast::Identifier("default"), {});
    ASSERT_IDENTIFIER("default", sc1.getPattern());
    ASSERT_THAT(sc1.getBody(), IsEmpty());
}

TEST(SwitchCase, isDefault) {
    filc::ast::SwitchCase sc1(new filc::ast::Identifier("default"), {});
    ASSERT_TRUE(sc1.isDefault());

    filc::ast::SwitchCase sc2(new filc::ast::Identifier("abcd"), {});
    ASSERT_FALSE(sc2.isDefault());

    filc::ast::SwitchCase sc3(new filc::ast::IntegerLiteral(2), {});
    ASSERT_FALSE(sc3.isDefault());
}