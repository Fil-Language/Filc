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
#include "tools.h"
#include "llvm/IR/Constants.h"

namespace filc::ast {
    StringLiteral::StringLiteral(const std::string &value)
            : AbstractLiteral<std::string>(filc::utils::parseEscapedString(value.substr(1, value.length() - 2))) {}

    auto StringLiteral::resolveType(filc::environment::Environment *environment,
                                    filc::message::MessageCollector *collector,
                                    const std::shared_ptr<AbstractType> &preferred_type) -> void {
        if (!environment->hasType("char*")) {
            if (!environment->hasType("char")) {
                environment->addType(std::make_shared<Type>(new Identifier("char")));
            }
            environment->addType(std::make_shared<PointerType>(environment->getType("char")));
        }

        setExpressionType(environment->getType("char*"));
    }

    auto StringLiteral::generateIR(filc::message::MessageCollector *collector,
                                   filc::environment::Environment *environment,
                                   llvm::LLVMContext *context,
                                   llvm::Module *module,
                                   llvm::IRBuilder<> *builder) const -> llvm::Value * {
        return llvm::ConstantDataArray::getString(*context, getValue());
    }
}