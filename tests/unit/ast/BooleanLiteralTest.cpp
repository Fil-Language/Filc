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

TEST(BooleanLiteral, constructor) {
    filc::ast::BooleanLiteral bl1(true);
    ASSERT_TRUE(bl1.getValue());

    filc::ast::BooleanLiteral bl2(false);
    ASSERT_FALSE(bl2.getValue());
}

TEST(BooleanLiteral, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/grammar/bool1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    ASSERT_TYPE("bool", program1->getExpressions()[0]->getExpressionType());

    filc::grammar::Parser parser2(FIXTURES_PATH "/grammar/bool2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_NO_THROW(program2->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    ASSERT_TYPE("bool", program2->getExpressions()[0]->getExpressionType());
}

TEST(BooleanLiteral, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/bool1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("test_bool1_3", nullptr));
    ASSERT_TYPE("bool", env1->getName("test_bool1_3", nullptr)->getType());
}

TEST(BooleanLiteral, generateIR) {
    filc::ast::BooleanLiteral bl1(true);
    bl1.resolveType(new filc::environment::Environment, COLLECTOR, nullptr);
    auto *value = bl1.generateIR(COLLECTOR, new filc::environment::Environment,
                                 new llvm::LLVMContext, nullptr, nullptr);
    ASSERT_TRUE(value->getType()->isIntegerTy());
}