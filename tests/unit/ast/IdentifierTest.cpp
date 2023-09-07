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

TEST(Identifier, constructor) {
    filc::ast::Identifier id1("identifier 1");
    ASSERT_IDENTIFIER("identifier 1", (&id1));
}

TEST(Identifier, resolveType) {
    auto *environment = new filc::environment::Environment;

    filc::ast::Identifier id1("hello");
    id1.resolveType(environment, COLLECTOR, nullptr);
    ASSERT_TRUE(COLLECTOR->hasErrors());
    COLLECTOR->flush();

    environment->addName("hello", new filc::ast::Type(new filc::ast::Identifier("int")));
    id1.resolveType(environment, COLLECTOR, nullptr);
    ASSERT_FALSE(COLLECTOR->hasErrors());
    ASSERT_TYPE("int", id1.getExpressionType());
}

TEST(Identifier, addNameToEnvironment) {
    auto *env1 = new filc::environment::Environment;
    env1->addName("hello", new filc::ast::Type(new filc::ast::Identifier("int")));
    filc::ast::Identifier id1("hello");
    id1.resolveType(env1, COLLECTOR, nullptr);

    auto *env2 = new filc::environment::Environment;
    ASSERT_FALSE(env2->hasName("hello"));
    id1.addNameToEnvironment(env2);
    ASSERT_TRUE(env2->hasName("hello", new filc::ast::Type(new filc::ast::Identifier("int"))));
}

TEST(Identifier, generateIR) {
    filc::ast::Identifier id1("var1");
    auto *environment = new filc::environment::Environment;
    environment->addName("var1", new filc::ast::Type(new filc::ast::Identifier("int")));
    auto *context = new llvm::LLVMContext();
    auto *value = llvm::ConstantFP::get(*context, llvm::APFloat(3.6));
    environment->getName("var1")->setValue(value);
    id1.resolveType(environment, COLLECTOR, nullptr);
    ASSERT_EQ(value, id1.generateIR(COLLECTOR, environment, nullptr, nullptr, nullptr));
    ASSERT_FALSE(COLLECTOR->hasErrors());
}