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
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_tools.h"

using namespace ::testing;

TEST(LambdaType, constructor) {
    auto *arg1 = new filc::ast::Type(new filc::ast::Identifier("arg1"));
    auto *arg2 = new filc::ast::Type(new filc::ast::Identifier("arg2"));
    auto *arg3 = new filc::ast::Type(new filc::ast::Identifier("arg3"));
    auto *return_type = new filc::ast::Type(new filc::ast::Identifier("return_type"));
    filc::ast::LambdaType lt1({arg1, arg2, arg3}, return_type);
    ASSERT_TYPE("return_type", lt1.getReturnType());
    ASSERT_THAT(lt1.getArgumentTypes(), ElementsAre(arg1, arg2, arg3));
    ASSERT_TYPE("(arg1, arg2, arg3) -> return_type", (&lt1));
}