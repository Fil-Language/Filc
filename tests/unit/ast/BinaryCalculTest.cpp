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
}

TEST(BinaryCalcul, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/binary_calcul3.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("test_binary_calcul3_3"));
    ASSERT_TYPE("int", env1->getName("test_binary_calcul3_3")->getType());
}