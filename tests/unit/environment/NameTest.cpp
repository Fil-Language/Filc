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
#include "Name.h"
#include "AST.h"
#include "test_tools.h"

TEST(Name, constructor) {
    filc::environment::Name var1("my_var", new filc::ast::Type(new filc::ast::Identifier("int")));
    ASSERT_STREQ("my_var", var1.getName().c_str());
    ASSERT_TYPE("int", var1.getType());
}

TEST(Name, value) {
    filc::environment::Name var1("my_var", new filc::ast::Type(new filc::ast::Identifier("int")));
    auto *context = new llvm::LLVMContext();
    ASSERT_EQ(nullptr, var1.getValue());
    var1.setValue(llvm::ConstantFP::get(*context, llvm::APFloat(3.6)));
    ASSERT_NE(nullptr, var1.getValue());
}

TEST(Name, function) {
    filc::environment::Name fun1(
            "my_fun",
            new filc::ast::LambdaType({}, new filc::ast::Type(new filc::ast::Identifier("int")))
    );
    auto *context = new llvm::LLVMContext();
    auto *module = new llvm::Module("test", *context);
    ASSERT_EQ(nullptr, fun1.getFunction());
    fun1.setFunction(llvm::Function::Create(
            llvm::FunctionType::get(llvm::Type::getInt64Ty(*context), {}, false),
            llvm::Function::ExternalLinkage,
            "my_fun",
            *module
    ));
    ASSERT_NE(nullptr, fun1.getFunction());
}