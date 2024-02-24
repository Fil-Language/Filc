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

TEST(ClassicOperator, constructor) {
    filc::ast::ClassicOperator co1(filc::ast::ClassicOperator::PLUSPLUS);
    ASSERT_EQ(filc::ast::ClassicOperator::PLUSPLUS, co1.getOperator());
}

TEST(ClassicOperator, dump) {
    ASSERT_STREQ("++", filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUSPLUS).dump().c_str());
    ASSERT_STREQ("--", filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUSMINUS).dump().c_str());
    ASSERT_STREQ("+", filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS).dump().c_str());
    ASSERT_STREQ("-", filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUS).dump().c_str());
    ASSERT_STREQ("&", filc::ast::ClassicOperator(filc::ast::ClassicOperator::REF).dump().c_str());
    ASSERT_STREQ("*", filc::ast::ClassicOperator(filc::ast::ClassicOperator::STAR).dump().c_str());
    ASSERT_STREQ("!", filc::ast::ClassicOperator(filc::ast::ClassicOperator::NOT).dump().c_str());
    ASSERT_STREQ("/", filc::ast::ClassicOperator(filc::ast::ClassicOperator::DIV).dump().c_str());
    ASSERT_STREQ("%", filc::ast::ClassicOperator(filc::ast::ClassicOperator::MOD).dump().c_str());
    ASSERT_STREQ("<<", filc::ast::ClassicOperator(filc::ast::ClassicOperator::FLEFT).dump().c_str());
    ASSERT_STREQ(">>", filc::ast::ClassicOperator(filc::ast::ClassicOperator::FRIGHT).dump().c_str());
    ASSERT_STREQ("<", filc::ast::ClassicOperator(filc::ast::ClassicOperator::LESS).dump().c_str());
    ASSERT_STREQ(">", filc::ast::ClassicOperator(filc::ast::ClassicOperator::GREATER).dump().c_str());
    ASSERT_STREQ("==", filc::ast::ClassicOperator(filc::ast::ClassicOperator::EQEQ).dump().c_str());
    ASSERT_STREQ("<=", filc::ast::ClassicOperator(filc::ast::ClassicOperator::LEQ).dump().c_str());
    ASSERT_STREQ(">=", filc::ast::ClassicOperator(filc::ast::ClassicOperator::GEQ).dump().c_str());
    ASSERT_STREQ("!=", filc::ast::ClassicOperator(filc::ast::ClassicOperator::NEQ).dump().c_str());
    ASSERT_STREQ("&&", filc::ast::ClassicOperator(filc::ast::ClassicOperator::AND).dump().c_str());
    ASSERT_STREQ("||", filc::ast::ClassicOperator(filc::ast::ClassicOperator::OR).dump().c_str());

    auto non_existing = (filc::ast::ClassicOperator::OPERATOR) -1;
    ASSERT_THROW(filc::ast::ClassicOperator(non_existing).dump(), std::logic_error);
}
