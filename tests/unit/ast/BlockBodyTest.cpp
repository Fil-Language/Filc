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

TEST(BlockBody, constructor) {
    std::vector<filc::ast::AbstractExpression *> expressions = {
            new TestExpression(),
            new TestExpression(),
    };
    filc::ast::BlockBody bb1(expressions);
    ASSERT_THAT(bb1.getExpressions(), ContainerEq(expressions));
}

TEST(BlockBody, resolveType) {
    DEFINE_ENVIRONMENT(env);
    auto int_type = env->getType("int");
    auto expression1 = TestExpression().withExpressionType(env->getType("char"));
    auto expression2 = TestExpression().withExpressionType(int_type);
    std::vector<filc::ast::AbstractExpression *> expressions = {&expression1, &expression2};
    filc::ast::BlockBody bb1(expressions);
    bb1.resolveType(env, COLLECTOR, nullptr);
    ASSERT_TRUE(expression1.isResolveTypeCalled());
    ASSERT_TRUE(expression2.isResolveTypeCalled());
    ASSERT_FALSE(COLLECTOR->hasErrors());
    auto result_type = bb1.getExpressionType();
    ASSERT_NE(nullptr, result_type);
    ASSERT_TYPE("int", result_type);
}
