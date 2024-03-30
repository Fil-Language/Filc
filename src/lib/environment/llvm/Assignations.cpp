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
#include "Environment.h"
#include "Type.h"
#include "Error.h"
#include "llvm/IR/Verifier.h"

using namespace filc::environment;

#define ASSIGNATION_FUNCTION(var, name, type, operator_type)                                                       \
    {                                                                                                              \
        std::vector<llvm::Type *> types_##var = {llvm::PointerType::getUnqual(type), type};                        \
        auto *type_##var                      = llvm::FunctionType::get(type, types_##var, false);                 \
        auto *function_##var = llvm::Function::Create(type_##var, llvm::Function::ExternalLinkage, name, *module); \
        function_##var->getArg(0)->setName("a");                                                                   \
        function_##var->getArg(1)->setName("b");                                                                   \
        if (!function_##var->empty()) {                                                                            \
            collector->addError(new filc::message::BasicError("Tried to redefine " name));                         \
            return;                                                                                                \
        }                                                                                                          \
        llvm::BasicBlock *basic_block_##var = llvm::BasicBlock::Create(*context, "entry", function_##var);         \
        builder->SetInsertPoint(basic_block_##var);                                                                \
        auto *variable_##var = builder->CreateLoad(function_##var->getArg(0)->getType(), function_##var);          \
        builder->CreateStore(function_##var->getArg(1), variable_##var);                                           \
        builder->CreateRet(variable_##var);                                                                        \
        llvm::verifyFunction(*function_##var);                                                                     \
        getName("operator=", operator_type)->setFunction(function_##var);                                          \
    }

auto Environment::generateAssignations(
    const std::shared_ptr<filc::message::MessageCollector>& collector,
    llvm::LLVMContext *context,
    llvm::Module *module,
    llvm::IRBuilder<> *builder
) const -> void {
    auto int_type    = getType("int");
    auto double_type = getType("double");
    auto float_type  = getType("float");
    auto char_type   = getType("char");
    auto bool_type   = getType("bool");
    auto ptr_int     = std::make_shared<ast::PointerType>(int_type);
    auto ptr_double  = std::make_shared<ast::PointerType>(double_type);
    auto ptr_float   = std::make_shared<ast::PointerType>(float_type);
    auto ptr_char    = std::make_shared<ast::PointerType>(char_type);
    auto ptr_bool    = std::make_shared<ast::PointerType>(bool_type);
    ASSIGNATION_FUNCTION(
        int_int,
        "operator=(int*, int) -> int",
        llvm::Type::getInt64Ty(*context),
        new filc::ast::LambdaType({ptr_int, int_type}, int_type)
    )
    ASSIGNATION_FUNCTION(
        double_double,
        "operator=(double*, double) -> double",
        llvm::Type::getDoubleTy(*context),
        new filc::ast::LambdaType({ptr_double, double_type}, double_type)
    )
    ASSIGNATION_FUNCTION(
        float_float,
        "operator=(float*, float) -> float",
        llvm::Type::getFloatTy(*context),
        new filc::ast::LambdaType({ptr_float, float_type}, float_type)
    )
    ASSIGNATION_FUNCTION(
        char_char,
        "operator=(char*, char) -> char",
        llvm::Type::getInt8Ty(*context),
        new filc::ast::LambdaType({ptr_char, char_type}, char_type)
    )
    ASSIGNATION_FUNCTION(
        bool_bool,
        "operator=(bool*, bool) -> bool",
        llvm::Type::getInt1Ty(*context),
        new filc::ast::LambdaType({ptr_bool, bool_type}, bool_type)
    )
}
