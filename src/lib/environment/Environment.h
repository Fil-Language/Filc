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

#include "Name.h"
#include "MessageCollector.h"
#include <vector>
#include "llvm/IR/IRBuilder.h"

namespace filc::environment {
    using BasicTypes = struct {
        filc::ast::AbstractType *_int_type;
        filc::ast::AbstractType *_double_type;
        filc::ast::AbstractType *_float_type;
        filc::ast::AbstractType *_char_type;
        filc::ast::AbstractType *_bool_type;
    };

    class Environment {
    public:
        explicit Environment(std::string module = "", const Environment *parent = nullptr);

        [[nodiscard]] auto getModule() const -> const std::string &;

        [[nodiscard]] auto getParent() const -> const Environment *;

        [[nodiscard]] auto hasName(const std::string &name, filc::ast::AbstractType *type = nullptr) const -> bool;

        auto addName(const std::string &name, filc::ast::AbstractType *type) -> bool;

        [[nodiscard]] auto getName(const std::string &name, filc::ast::AbstractType *type = nullptr) const -> Name *;

        [[nodiscard]] auto hasType(const std::string &type) const -> bool;

        auto addType(filc::ast::AbstractType *type) -> bool;

        [[nodiscard]] auto getType(const std::string &type) const -> filc::ast::AbstractType *;

        static auto getGlobalEnvironment() -> const Environment *;

        auto generateIR(filc::message::MessageCollector *collector,
                        llvm::LLVMContext *context,
                        llvm::Module *module,
                        llvm::IRBuilder<> *builder) const -> void;

    private:
        std::string _module;
        const Environment *_parent;
        std::vector<Name *> _names;
        std::vector<filc::ast::AbstractType *> _types;

        static auto addBasicTypes(Environment *global) -> BasicTypes;

        static auto addConstants(Environment *global, BasicTypes &basic_types) -> void;

        static auto addAssignations(Environment *global, BasicTypes &basic_types) -> void;

        static auto addPrefixUnary(Environment *global, BasicTypes &basic_types) -> void;

        static auto addPostfixUnary(Environment *global, BasicTypes &basic_types) -> void;

        static auto addBinary(Environment *global, BasicTypes &basic_types) -> void;

        auto generateAssignations(filc::message::MessageCollector *collector,
                                  llvm::LLVMContext *context,
                                  llvm::Module *module,
                                  llvm::IRBuilder<> *builder) const -> void;

        auto generatePrefixUnary(filc::message::MessageCollector *collector,
                                 llvm::LLVMContext *context,
                                 llvm::Module *module,
                                 llvm::IRBuilder<> *builder) const -> void;

        auto generatePostFixUnary(filc::message::MessageCollector *collector,
                                  llvm::LLVMContext *context,
                                  llvm::Module *module,
                                  llvm::IRBuilder<> *builder) const -> void;

        auto generateBinary(filc::message::MessageCollector *collector,
                            llvm::LLVMContext *context,
                            llvm::Module *module,
                            llvm::IRBuilder<> *builder) const -> void;
    };
}

#endif //FILC_ENVIRONMENT_H
