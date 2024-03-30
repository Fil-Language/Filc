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
#ifndef FILC_ENVIRONMENT_H
#define FILC_ENVIRONMENT_H

#include "MessageCollector.h"
#include "Name.h"
#include "llvm/IR/IRBuilder.h"
#include <vector>

namespace filc::environment {
    typedef struct BasicTypes {
        std::shared_ptr<ast::AbstractType> _int_type;
        std::shared_ptr<ast::AbstractType> _double_type;
        std::shared_ptr<ast::AbstractType> _float_type;
        std::shared_ptr<ast::AbstractType> _char_type;
        std::shared_ptr<ast::AbstractType> _bool_type;
    } BasicTypes;

    class Environment {
    public:
        explicit Environment(const std::string &module = "", const std::shared_ptr<Environment> &parent = nullptr);

        ~Environment();

        [[nodiscard]] auto getModule() const -> const std::string &;

        [[nodiscard]] auto getParent() const -> std::shared_ptr<Environment>;

        [[nodiscard]] auto
        hasName(const std::string &name, const std::shared_ptr<ast::AbstractType> &type = nullptr) const -> bool;

        [[nodiscard]] auto hasName(const std::string &name, ast::AbstractType *type = nullptr) const -> bool;

        auto addName(const std::string &name, const std::shared_ptr<ast::AbstractType> &type) -> bool;

        auto addName(const std::string &name, ast::AbstractType *type) -> bool;

        [[nodiscard]] auto
        getName(const std::string &name, const std::shared_ptr<ast::AbstractType> &type = nullptr) const -> Name *;

        [[nodiscard]] auto getName(const std::string &name, ast::AbstractType *type = nullptr) const -> Name *;

        [[nodiscard]] auto hasType(const std::string &type) const -> bool;

        auto addType(const std::shared_ptr<ast::AbstractType> &type) -> bool;

        [[nodiscard]] auto getType(const std::string &type) const -> std::shared_ptr<ast::AbstractType>;

        static auto getGlobalEnvironment() -> std::shared_ptr<Environment>;

        auto generateIR(
            const std::shared_ptr<message::MessageCollector> &collector,
            llvm::LLVMContext *context,
            llvm::Module *module,
            llvm::IRBuilder<> *builder
        ) const -> void;

    private:
        std::string _module;
        std::shared_ptr<Environment> _parent;
        std::vector<Name *> _names;
        std::vector<std::shared_ptr<ast::AbstractType>> _types;

        static auto addBasicTypes(std::shared_ptr<Environment> global) -> BasicTypes;

        static auto addConstants(std::shared_ptr<Environment> global, BasicTypes &basic_types) -> void;

        static auto addAssignations(std::shared_ptr<Environment> global, BasicTypes &basic_types) -> void;

        static auto addPrefixUnary(std::shared_ptr<Environment> global, BasicTypes &basic_types) -> void;

        static auto addPostfixUnary(std::shared_ptr<Environment> global, BasicTypes &basic_types) -> void;

        static auto addBinary(std::shared_ptr<Environment> global, BasicTypes &basic_types) -> void;

        auto generateAssignations(
            const std::shared_ptr<message::MessageCollector> &collector,
            llvm::LLVMContext *context,
            llvm::Module *module,
            llvm::IRBuilder<> *builder
        ) const -> void;

        auto generatePrefixUnary(
            const std::shared_ptr<message::MessageCollector> &collector,
            llvm::LLVMContext *context,
            llvm::Module *module,
            llvm::IRBuilder<> *builder
        ) const -> void;

        auto generatePostFixUnary(
            const std::shared_ptr<message::MessageCollector> &collector,
            llvm::LLVMContext *context,
            llvm::Module *module,
            llvm::IRBuilder<> *builder
        ) const -> void;

        auto generateBinary(
            const std::shared_ptr<message::MessageCollector> &collector,
            llvm::LLVMContext *context,
            llvm::Module *module,
            llvm::IRBuilder<> *builder
        ) const -> void;
    };
} // namespace filc::environment

#endif // FILC_ENVIRONMENT_H
