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
#include <utility>

class TypeA : public filc::ast::AbstractType {
public:
    [[nodiscard]] auto dump() const -> std::string override {
        return "TypeA";
    }

    [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override {
        return nullptr;
    }
};

class TypeB : public filc::ast::AbstractType {
public:
    explicit TypeB(std::string name)
            : _name(std::move(name)) {}

    [[nodiscard]] auto dump() const -> std::string override {
        return _name;
    }

    [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override {
        return nullptr;
    }

private:
    std::string _name;
};

TEST(AbstractType, equality) {
    const auto type_1 = TypeA();
    const auto type_2 = TypeA();
    ASSERT_EQ(type_1, type_2);

    const auto type_3 = TypeB("a");
    const auto type_4 = TypeB("b");
    const auto type_5 = TypeB("b");
    ASSERT_NE(type_1, type_3);
    ASSERT_NE(type_3, type_4);
    ASSERT_EQ(type_4, type_5);
}

TEST(AbstractType, LLVMType) {
    auto type = TypeA();
    ASSERT_EQ(nullptr, type.getLLVMType());
    auto *context = new llvm::LLVMContext;
    auto llvm_type = llvm::Type::getInt32Ty(*context);
    type.setLLVMType(llvm_type);
    ASSERT_EQ(llvm_type, type.getLLVMType());
    delete context;
}
