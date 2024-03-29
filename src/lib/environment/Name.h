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
#ifndef FILC_NAME_H
#define FILC_NAME_H

#include <string>
#include "AST_decl.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"

namespace filc::environment {
    class Name {
    public:
        Name(std::string name, const std::shared_ptr<filc::ast::AbstractType> &type);

        [[nodiscard]] auto getName() const -> const std::string &;

        [[nodiscard]] auto getType() const -> std::shared_ptr<filc::ast::AbstractType>;

        [[nodiscard]] auto getValue() const -> llvm::Value *;

        auto setValue(llvm::Value *value) -> void;

        [[nodiscard]] auto getFunction() const -> llvm::Function *;

        auto setFunction(llvm::Function *function) -> void;

    private:
        std::string _name;
        std::shared_ptr<filc::ast::AbstractType> _type;
        llvm::Value *_value;
        llvm::Function *_function;
    };
}

#endif //FILC_NAME_H
