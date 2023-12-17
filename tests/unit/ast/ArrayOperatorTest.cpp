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

TEST(ArrayOperator, constructor) {
    auto *il1 = new filc::ast::IntegerLiteral(3);
    filc::ast::ArrayOperator ao1(il1);
    ASSERT_EQ(il1, ao1.getExpression());
}

TEST(ArrayOperator, dump) {
    filc::ast::ArrayOperator ao1(nullptr);
    ASSERT_STREQ("[]", ao1.dump().c_str());
}

TEST(ArrayOperator, dumpPreLambdaType) {
    filc::ast::ArrayOperator ao1(nullptr);
    ASSERT_EQ(nullptr, ao1.dumpPreLambdaType(nullptr, nullptr, COLLECTOR, nullptr));
    ASSERT_TRUE(COLLECTOR->hasErrors());
    COLLECTOR->flush();
}

TEST(ArrayOperator, dumpPostLambdaType) {
    auto environment = filc::environment::Environment("env", filc::environment::Environment::getGlobalEnvironment());
    auto int_type = environment.getType("int");
    auto int_pointer = std::make_shared<filc::ast::PointerType>(int_type);
    auto expression1 = filc::ast::IntegerLiteral(1);
    filc::ast::ArrayOperator ao1(&expression1);
    const auto result_type = ao1.dumpPostLambdaType(int_pointer, &environment, COLLECTOR, nullptr);
    ASSERT_NE(nullptr, result_type);
    ASSERT_TYPE("(int) -> int", result_type);
}
