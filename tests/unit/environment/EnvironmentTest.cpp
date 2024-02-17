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
#include "Environment.h"
#include "AST.h"
#include "test_tools.h"

TEST(Environment, constructor) {
    filc::environment::Environment env1("parent");
    ASSERT_EQ(nullptr, env1.getParent());
    ASSERT_STREQ("parent", env1.getModule().c_str());

    filc::environment::Environment env2("children", &env1);
    ASSERT_EQ(&env1, env2.getParent());
    ASSERT_STREQ("children", env2.getModule().c_str());
}

TEST(Environment, names) {
    filc::environment::Environment env1;
    ASSERT_FALSE(env1.hasName("hello", nullptr));
    ASSERT_TRUE(env1.addName("hello", new filc::ast::Type(new filc::ast::Identifier("int"))));
    ASSERT_TRUE(env1.hasName("hello", nullptr));
    ASSERT_FALSE(env1.addName("hello", nullptr));
    ASSERT_TRUE(env1.hasName("hello", nullptr));
    ASSERT_STREQ("hello", env1.getName("hello", nullptr)->getName().c_str());
    ASSERT_TYPE("int", env1.getName("hello", nullptr)->getType());

    filc::environment::Environment parent;
    parent.addName("a", nullptr);
    filc::environment::Environment env2("", &parent);
    ASSERT_TRUE(env2.hasName("a", nullptr));
    ASSERT_FALSE(env2.hasName("b", nullptr));
}

TEST(Environment, types) {
    filc::environment::Environment env1;
    ASSERT_FALSE(env1.hasType("int"));
    ASSERT_TRUE(env1.addType(std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int"))));
    ASSERT_TRUE(env1.hasType("int"));
    ASSERT_FALSE(env1.addType(std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int"))));
    ASSERT_TRUE(env1.hasType("int"));
    ASSERT_TYPE("int", env1.getType("int"));

    filc::environment::Environment parent;
    parent.addType(std::make_shared<filc::ast::Type>(new filc::ast::Identifier("float")));
    filc::environment::Environment env2("", &parent);
    ASSERT_TRUE(env2.hasType("float"));
    ASSERT_FALSE(env2.hasName("bool", nullptr));
}

TEST(Environment, getGlobalEnvironment) {
    const filc::environment::Environment *env1 = nullptr;
    const filc::environment::Environment *env2 = nullptr;
    ASSERT_NO_THROW(env1 = filc::environment::Environment::getGlobalEnvironment());
    ASSERT_NO_THROW(env2 = filc::environment::Environment::getGlobalEnvironment());
    ASSERT_NE(nullptr, env1);
    ASSERT_NE(nullptr, env2);
    ASSERT_EQ(env1, env2);
}

TEST(Environment, generateIR) {
    filc::environment::Environment env1("env1", filc::environment::Environment::getGlobalEnvironment());
    auto *context = new llvm::LLVMContext;
    auto *module = new llvm::Module("module", *context);
    auto *ir_builder = new llvm::IRBuilder<>(*context);
    env1.generateIR(COLLECTOR, context, module, ir_builder);
    ASSERT_FALSE(COLLECTOR->hasErrors());
}