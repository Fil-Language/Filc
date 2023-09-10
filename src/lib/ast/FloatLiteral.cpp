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
#include "llvm/IR/Constants.h"

namespace filc::ast {
    FloatLiteral::FloatLiteral(double value, bool is_double)
            : AbstractLiteral<double>(value), _double(is_double) {}

    auto FloatLiteral::resolveType(filc::environment::Environment *environment,
                                   filc::message::MessageCollector *collector,
                                   AbstractType *preferred_type) -> void {
        auto looking_type = _double ? "double" : "float";

        if (!environment->hasType(looking_type)) {
            environment->addType(new filc::ast::Type(new filc::ast::Identifier(looking_type)));
        }

        setExpressionType(environment->getType(looking_type));
    }

    auto FloatLiteral::generateIR(filc::message::MessageCollector *collector,
                                  filc::environment::Environment *environment,
                                  llvm::LLVMContext *context,
                                  llvm::Module *module,
                                  llvm::IRBuilder<> *builder) const -> llvm::Value * {
        return llvm::ConstantFP::get(*context, llvm::APFloat(getValue()));
    }

    auto FloatLiteral::isDouble() const -> bool {
        return _double;
    }
}