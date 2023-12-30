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

TEST(BinaryCalcul, constructor) {
    filc::ast::BinaryCalcul bc1(
            new filc::ast::Identifier("a"),
            new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS),
            new filc::ast::Identifier("b")
    );
    ASSERT_IDENTIFIER("a", bc1.getLeftExpression());
    ASSERT_IDENTIFIER("b", bc1.getRightExpression());
    ASSERT_CLASSIC_OPERATOR(PLUS, bc1.getOperator());
}

TEST(BinaryCalcul, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/binary_calcul1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program1->getExpressions(), SizeIs(3));
    ASSERT_TYPE("int", program1->getExpressions()[0]->getExpressionType());
    ASSERT_TYPE("int", program1->getExpressions()[1]->getExpressionType());
    ASSERT_TYPE("int", program1->getExpressions()[2]->getExpressionType());

    filc::grammar::Parser parser2(FIXTURES_PATH "/ast/binary_calcul2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_NO_THROW(program2->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    ASSERT_TYPE("bool", program2->getExpressions()[0]->getExpressionType());

    DEFINE_ENVIRONMENT(env);
    auto left_expression1 = TestExpression().withExpressionType(nullptr);
    auto right_expression1 = TestExpression().withExpressionType(nullptr);
    filc::ast::BinaryCalcul bc1(&left_expression1, nullptr, &right_expression1);
    bc1.resolveType(env, COLLECTOR, nullptr);
    ASSERT_EQ(nullptr, bc1.getExpressionType());

    auto left_expression2 = TestExpression().withExpressionType(env->getType("int"));
    auto right_expression2 = TestExpression().withExpressionType(env->getType("bool"));
    filc::ast::BinaryCalcul bc2(
            &left_expression2,
            new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FLEFT),
            &right_expression2
    );
    bc2.resolveType(env, COLLECTOR, nullptr);
    ASSERT_EQ(nullptr, bc2.getExpressionType());
    ASSERT_TRUE(COLLECTOR->hasErrors());
    COLLECTOR->flush();
}

TEST(BinaryCalcul, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/binary_calcul3.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("test_binary_calcul3_3", nullptr));
    ASSERT_TYPE("int", env1->getName("test_binary_calcul3_3", nullptr)->getType());
}

TEST(BinaryCalcul, generateIR) {
    filc::ast::BinaryCalcul bc1(
            new filc::ast::Identifier("var1"),
            new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LEQ),
            new filc::ast::Identifier("var2")
    );
    DEFINE_ENVIRONMENT(env);
    auto float_type1 = env->getType("float");
    env->addName("var1", float_type1);
    env->addName("var2", float_type1);
    bc1.resolveType(env, COLLECTOR, env->getType("bool"));
    ASSERT_FALSE(COLLECTOR->hasErrors());
    DEFINE_LLVM;
    env->generateIR(COLLECTOR, context, module, builder);
    env->getName("var1", nullptr)->setValue(llvm::ConstantFP::get(*context, llvm::APFloat(2.0F)));
    env->getName("var2", nullptr)->setValue(llvm::ConstantFP::get(*context, llvm::APFloat(2.0F)));
    auto *value1 = bc1.generateIR(COLLECTOR, env, context, module, builder);
    ASSERT_NE(nullptr, value1);
    ASSERT_TRUE(value1->getType()->isIntegerTy(1));

    DEFINE_ENVIRONMENT(env2);
    filc::ast::BinaryCalcul bc2(
            new filc::ast::Identifier("var1"),
            new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LEQ),
            new filc::ast::Identifier("var2")
    );
    auto float_type2 = env->getType("float");
    env2->addName("var1", float_type2);
    env2->addName("var2", float_type2);
    bc1.resolveType(env, COLLECTOR, env2->getType("bool"));
    auto *value2 = bc2.generateIR(COLLECTOR, env2, context, module, builder);
    ASSERT_EQ(nullptr, value2);
    ASSERT_TRUE(COLLECTOR->hasErrors());
    COLLECTOR->flush();

    env2->generateIR(COLLECTOR, context, module, builder);
    auto value2_2 = bc2.generateIR(COLLECTOR, env2, context, module, builder);
    ASSERT_EQ(nullptr, value2_2);
    ASSERT_TRUE(COLLECTOR->hasErrors());
    COLLECTOR->flush();
}