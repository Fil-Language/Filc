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

TEST(VariableDeclaration, constructor) {
    auto tp1 = std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int"));
    filc::ast::VariableDeclaration vd1(false, new filc::ast::Identifier("my_var"), tp1);
    ASSERT_FALSE(vd1.isConstant());
    ASSERT_IDENTIFIER("my_var", vd1.getIdentifier());
    ASSERT_TYPE("int", vd1.getType());

    auto tp2 = std::make_shared<filc::ast::Type>(new filc::ast::Identifier("float"));
    filc::ast::VariableDeclaration vd2(true, new filc::ast::Identifier("my_val"), tp2);
    ASSERT_TRUE(vd2.isConstant());
    ASSERT_IDENTIFIER("my_val", vd2.getIdentifier());
    ASSERT_TYPE("float", vd2.getType());
}

TEST(VariableDeclaration, assignation) {
    auto tp1 = std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int"));
    filc::ast::VariableDeclaration vd1(false, new filc::ast::Identifier("my_var"), tp1);
    auto *exp1 = new filc::ast::IntegerLiteral(12);
    vd1.setAssignation(exp1);
    ASSERT_EQ(exp1, vd1.getAssignation());
}

TEST(VariableDeclaration, resolveType) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/grammar/variable_declaration1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_NO_THROW(program1->resolveEnvironment(COLLECTOR, {}));
    ASSERT_THAT(program1->getExpressions(), SizeIs(2));
    ASSERT_TYPE("float", program1->getExpressions()[0]->getExpressionType());
    ASSERT_TYPE("int", program1->getExpressions()[1]->getExpressionType());
}

TEST(VariableDeclaration, addNameToEnvironment) {
    filc::grammar::Parser parser1(FIXTURES_PATH "/ast/variable_declaration1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    program1->resolveEnvironment(COLLECTOR, {});
    auto *env1 = program1->getPublicEnvironment(nullptr);
    ASSERT_TRUE(env1->hasName("pi", nullptr));
    ASSERT_TYPE("double", env1->getName("pi", nullptr)->getType());
}

TEST(VariableDeclaration, generateIR) {
    filc::ast::VariableDeclaration vd1(true, new filc::ast::Identifier("my_var"),
                                       std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int")));
    vd1.setAssignation(new filc::ast::IntegerLiteral(2));
    auto *env = new filc::environment::Environment("", filc::environment::Environment::getGlobalEnvironment());
    vd1.resolveType(env, COLLECTOR, nullptr);
    ASSERT_FALSE(COLLECTOR->hasErrors());
    auto *context = new llvm::LLVMContext;
    auto *value = vd1.generateIR(COLLECTOR, env, context, nullptr, nullptr);
    ASSERT_NE(nullptr, value);
    ASSERT_TRUE(value->getType()->isIntegerTy());
}