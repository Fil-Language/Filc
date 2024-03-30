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
#ifndef FILC_LLVMFUNCTION_H
#define FILC_LLVMFUNCTION_H

#include "Error.h"
#include "llvm/IR/Verifier.h"

#define DEFINE_FUNCTION(name, params, rtype, body, var, operator_name, operator_type)                              \
    {                                                                                                              \
        std::vector<llvm::Type *> types_##var = params;                                                            \
        auto *type_##var                      = llvm::FunctionType::get(rtype, types_##var, false);                \
        auto *function_##var = llvm::Function::Create(type_##var, llvm::Function::ExternalLinkage, name, *module); \
        if (!function_##var->empty()) {                                                                            \
            collector->addError(new filc::message::BasicError("Tried to redefine " name));                         \
            return;                                                                                                \
        }                                                                                                          \
        llvm::BasicBlock *basic_block_##var = llvm::BasicBlock::Create(*context, "entry", function_##var);         \
        builder->SetInsertPoint(basic_block_##var);                                                                \
        body llvm::verifyFunction(*function_##var);                                                                \
        getName(operator_name, operator_type)->setFunction(function_##var);                                        \
    }

#endif // FILC_LLVMFUNCTION_H
