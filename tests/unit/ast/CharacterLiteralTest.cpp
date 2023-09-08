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

TEST(CharacterLiteral, constructor) {
    filc::ast::CharacterLiteral cl1('a');
    ASSERT_EQ('a', cl1.getValue());
}

TEST(CharacterLiteral, stringToChar) {
    ASSERT_EQ('a', filc::ast::CharacterLiteral::stringToChar("'a'"));
    ASSERT_EQ('5', filc::ast::CharacterLiteral::stringToChar("'5'"));
    ASSERT_EQ('\n', filc::ast::CharacterLiteral::stringToChar("'\\n'"));
    ASSERT_EQ('\t', filc::ast::CharacterLiteral::stringToChar("'\\t'"));
}

TEST(CharacterLiteral, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/grammar/char1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    ASSERT_TYPE("char", program1->getExpressions()[0]->getExpressionType());

    filc::grammar::Parser parser2(FIXTURES_PATH "/grammar/char2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_NO_THROW(program2->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    ASSERT_TYPE("char", program2->getExpressions()[0]->getExpressionType());

    filc::grammar::Parser parser3(FIXTURES_PATH "/grammar/char3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_NO_THROW(program3->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    ASSERT_TYPE("char", program3->getExpressions()[0]->getExpressionType());
}

TEST(CharacterLiteral, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/char1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("test_char1_3"));
    ASSERT_TYPE("char", env1->getName("test_char1_3")->getType());
}

TEST(CharacterLiteral, generateIR) {
    filc::ast::CharacterLiteral cl1('a');
    cl1.resolveType(new filc::environment::Environment, COLLECTOR, nullptr);
    auto *value = cl1.generateIR(COLLECTOR, new filc::environment::Environment,
                                 new llvm::LLVMContext, nullptr, nullptr);
    ASSERT_TRUE(value->getType()->isIntegerTy(8));
}