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

TEST(Lambda, constructor) {
    filc::ast::Lambda lb1({}, std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int")), {});
    ASSERT_THAT(lb1.getParameters(), IsEmpty());
    ASSERT_TYPE("int", lb1.getReturnType());
    ASSERT_THAT(lb1.getBody(), IsEmpty());
}

TEST(Lambda, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/grammar/lambda1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    ASSERT_TYPE("(int) -> bool", program1->getExpressions()[0]->getExpressionType());
}

TEST(Lambda, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/lambda1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("test_lambda1_3", nullptr));
    ASSERT_TYPE("() -> char*", env1->getName("test_lambda1_3", nullptr)->getType());
}