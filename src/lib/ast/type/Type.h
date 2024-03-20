/**
 * MIT License
 *
 * Copyright (c) 2024-Present Kevin Traini
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
#ifndef FILC_TYPE_H
#define FILC_TYPE_H

#include "AST_decl.h"
#include <llvm/IR/Type.h>

namespace filc::ast {
    class AbstractType {
    public:
        virtual ~AbstractType() = default;

        AbstractType(const AbstractType &other) = default;

        AbstractType(AbstractType &&other) = default;

        auto operator=(const AbstractType &other) -> AbstractType & = delete;

        auto operator=(AbstractType &&other) -> AbstractType & = delete;

        [[nodiscard]] virtual auto dump() const -> std::string = 0;

        [[nodiscard]] virtual auto getInnerType() const -> std::shared_ptr<AbstractType> = 0;

        [[nodiscard]] auto getLLVMType() const -> llvm::Type *;

        auto setLLVMType(llvm::Type *type) -> void;

    protected:
        explicit AbstractType() = default;

    private:
        llvm::Type *_llvm_type;
    };

    class Type : public AbstractType {
    public:
        explicit Type(const std::shared_ptr<Identifier> &name);

        [[nodiscard]] auto getName() const -> std::shared_ptr<Identifier>;

        [[nodiscard]] auto dump() const -> std::string override;

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

    private:
        std::shared_ptr<Identifier> _name;
    };

    class ArrayType : public AbstractType {
    public:
        ArrayType(const std::shared_ptr<AbstractType> &inner_type, unsigned int size);

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

        [[nodiscard]] auto getSize() const -> unsigned int;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        std::shared_ptr<AbstractType> _inner_type;
        unsigned int _size;
    };

    class PointerType : public AbstractType {
    public:
        explicit PointerType(const std::shared_ptr<AbstractType> &inner_type);

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

        [[nodiscard]] auto dump() const -> std::string override;

    private:
        std::shared_ptr<AbstractType> _inner_type;
    };

    class LambdaType : public AbstractType {
    public:
        LambdaType(
            const std::vector<std::shared_ptr<AbstractType>> &argument_types,
            const std::shared_ptr<AbstractType> &return_type
        );

        [[nodiscard]] auto getArgumentTypes() const -> const std::vector<std::shared_ptr<AbstractType>> &;

        [[nodiscard]] auto getReturnType() const -> std::shared_ptr<AbstractType>;

        [[nodiscard]] auto dump() const -> std::string override;

        [[nodiscard]] auto getInnerType() const -> std::shared_ptr<AbstractType> override;

    private:
        std::vector<std::shared_ptr<AbstractType>> _argument_types;
        std::shared_ptr<AbstractType> _return_type;
    };
} // namespace filc::ast

#endif // FILC_TYPE_H
