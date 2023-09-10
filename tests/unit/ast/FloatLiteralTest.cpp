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

TEST(FloatLiteral, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/grammar/float1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    ASSERT_TYPE("float", program1->getExpressions()[0]->getExpressionType());

    filc::grammar::Parser parser2(FIXTURES_PATH "/grammar/float2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_NO_THROW(program2->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    ASSERT_TYPE("float", program2->getExpressions()[0]->getExpressionType());

    filc::grammar::Parser parser3(FIXTURES_PATH "/grammar/float3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_NO_THROW(program3->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    ASSERT_TYPE("float", program3->getExpressions()[0]->getExpressionType());

    filc::grammar::Parser parser4(FIXTURES_PATH "/grammar/float4.fil", COLLECTOR);
    auto *program4 = parser4.getProgram();
    ASSERT_NO_THROW(program4->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program4->getExpressions(), SizeIs(1));
    ASSERT_TYPE("double", program4->getExpressions()[0]->getExpressionType());
}

TEST(FloatLiteral, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/float1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("test_float1_3"));
    ASSERT_TYPE("float", env1->getName("test_float1_3")->getType());
}

TEST(FloatLiteral, generateIR) {
    filc::ast::FloatLiteral fl1(3.6);
    fl1.resolveType(new filc::environment::Environment, COLLECTOR, nullptr);
    auto *value = fl1.generateIR(COLLECTOR, new filc::environment::Environment,
                                 new llvm::LLVMContext, nullptr, nullptr);
    ASSERT_TRUE(value->getType()->isDoubleTy());
}