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
#include "LLVMFunction.h"
#include "Type.h"

using namespace filc::environment;

auto Environment::generatePostFixUnary(
    const std::shared_ptr<message::MessageCollector> &collector,
    llvm::LLVMContext *context,
    llvm::Module *module,
    llvm::IRBuilder<> *builder
) const -> void {
    auto int_type    = getType("int");
    auto double_type = getType("double");
    auto float_type  = getType("float");
    auto char_type   = getType("char");
    auto bool_type   = getType("bool");
    auto ptr_int     = std::make_shared<filc::ast::PointerType>(int_type);
    auto ptr_double  = std::make_shared<filc::ast::PointerType>(double_type);
    auto ptr_float   = std::make_shared<filc::ast::PointerType>(float_type);
    auto ptr_char    = std::make_shared<filc::ast::PointerType>(char_type);

    // region int
    DEFINE_FUNCTION(
        "operator++(int*) -> int",
        {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context))},
        llvm::Type::getInt64Ty(*context),
        {
            auto *variable_plusplus_int
                = builder->CreateLoad(function_plusplus_int->getArg(0)->getType(), function_plusplus_int);
            auto *result_plusplus_int
                = builder->CreateAdd(variable_plusplus_int, llvm::ConstantInt::get(*context, llvm::APInt(64, 1, true)));
            builder->CreateStore(result_plusplus_int, variable_plusplus_int);
            builder->CreateRet(variable_plusplus_int);
        },
        plusplus_int,
        "operator++",
        new filc::ast::LambdaType({ptr_int}, int_type)
    )
    DEFINE_FUNCTION(
        "operator--(int*) -> int",
        {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context))},
        llvm::Type::getInt64Ty(*context),
        {
            auto *variable_minusminus_int
                = builder->CreateLoad(function_minusminus_int->getArg(0)->getType(), function_minusminus_int);
            auto *result_minusminus_int = builder->CreateSub(
                variable_minusminus_int, llvm::ConstantInt::get(*context, llvm::APInt(64, 1, true))
            );
            builder->CreateStore(result_minusminus_int, variable_minusminus_int);
            builder->CreateRet(variable_minusminus_int);
        },
        minusminus_int,
        "operator--",
        new filc::ast::LambdaType({ptr_int}, int_type)
    )
    // endregion

    // region double
    DEFINE_FUNCTION(
        "operator++(double*) -> double",
        {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context))},
        llvm::Type::getDoubleTy(*context),
        {
            auto *variable_plusplus_double
                = builder->CreateLoad(function_plusplus_double->getArg(0)->getType(), function_plusplus_double);
            auto *result_plusplus_double
                = builder->CreateFAdd(variable_plusplus_double, llvm::ConstantFP::get(*context, llvm::APFloat(1.0)));
            builder->CreateStore(result_plusplus_double, variable_plusplus_double);
            builder->CreateRet(variable_plusplus_double);
        },
        plusplus_double,
        "operator++",
        new filc::ast::LambdaType({ptr_double}, double_type)
    )
    DEFINE_FUNCTION(
        "operator--(double*) -> double",
        {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context))},
        llvm::Type::getDoubleTy(*context),
        {
            auto *variable_minusminus_double
                = builder->CreateLoad(function_minusminus_double->getArg(0)->getType(), function_minusminus_double);
            auto *result_minusminus_double
                = builder->CreateFSub(variable_minusminus_double, llvm::ConstantFP::get(*context, llvm::APFloat(1.0)));
            builder->CreateStore(result_minusminus_double, variable_minusminus_double);
            builder->CreateRet(variable_minusminus_double);
        },
        minusminus_double,
        "operator--",
        new filc::ast::LambdaType({ptr_double}, double_type)
    )
    // endregion

    // region float
    DEFINE_FUNCTION(
        "operator++(float*) -> float",
        {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context))},
        llvm::Type::getFloatTy(*context),
        {
            auto *variable_plusplus_float
                = builder->CreateLoad(function_plusplus_float->getArg(0)->getType(), function_plusplus_float);
            auto *result_plusplus_float
                = builder->CreateFAdd(variable_plusplus_float, llvm::ConstantFP::get(*context, llvm::APFloat(1.0F)));
            builder->CreateStore(result_plusplus_float, variable_plusplus_float);
            builder->CreateRet(variable_plusplus_float);
        },
        plusplus_float,
        "operator++",
        new filc::ast::LambdaType({ptr_float}, float_type)
    )
    DEFINE_FUNCTION(
        "operator--(float*) -> float",
        {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context))},
        llvm::Type::getFloatTy(*context),
        {
            auto *variable_minusminus_float
                = builder->CreateLoad(function_minusminus_float->getArg(0)->getType(), function_minusminus_float);
            auto *result_minusminus_float
                = builder->CreateFSub(variable_minusminus_float, llvm::ConstantFP::get(*context, llvm::APFloat(1.0F)));
            builder->CreateStore(result_minusminus_float, variable_minusminus_float);
            builder->CreateRet(variable_minusminus_float);
        },
        minusminus_float,
        "operator--",
        new filc::ast::LambdaType({ptr_float}, float_type)
    )
    // endregion

    // region char
    DEFINE_FUNCTION(
        "operator++(char*) -> char",
        {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context))},
        llvm::Type::getInt8Ty(*context),
        {
            auto *variable_plusplus_char
                = builder->CreateLoad(function_plusplus_char->getArg(0)->getType(), function_plusplus_char);
            auto *result_plusplus_char
                = builder->CreateAdd(variable_plusplus_char, llvm::ConstantInt::get(*context, llvm::APInt(8, 1, true)));
            builder->CreateStore(result_plusplus_char, variable_plusplus_char);
            builder->CreateRet(variable_plusplus_char);
        },
        plusplus_char,
        "operator++",
        new filc::ast::LambdaType({ptr_char}, char_type)
    )
    DEFINE_FUNCTION(
        "operator--(char*) -> char",
        {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context))},
        llvm::Type::getInt8Ty(*context),
        {
            auto *variable_minusminus_char
                = builder->CreateLoad(function_minusminus_char->getArg(0)->getType(), function_minusminus_char);
            auto *result_minusminus_char = builder->CreateSub(
                variable_minusminus_char, llvm::ConstantInt::get(*context, llvm::APInt(8, 1, true))
            );
            builder->CreateStore(result_minusminus_char, variable_minusminus_char);
            builder->CreateRet(variable_minusminus_char);
        },
        minusminus_char,
        "operator--",
        new filc::ast::LambdaType({ptr_char}, char_type)
    )
    // endregion
}
