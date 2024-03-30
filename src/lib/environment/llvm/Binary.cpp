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

auto Environment::generateBinary(
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

    // region int operators
    DEFINE_FUNCTION(
        "operator*(int, int) -> int",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt64Ty(*context),
        { builder->CreateRet(builder->CreateMul(function_times_int->getArg(0), function_times_int->getArg(1))); },
        times_int,
        "operator*",
        new filc::ast::LambdaType({int_type, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator/(int, int) -> int",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt64Ty(*context),
        { builder->CreateRet(builder->CreateSDiv(function_div_int->getArg(0), function_div_int->getArg(1))); },
        div_int,
        "operator/",
        new filc::ast::LambdaType({int_type, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator%(int, int) -> int",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt64Ty(*context),
        { builder->CreateRet(builder->CreateSRem(function_mod_int->getArg(0), function_mod_int->getArg(1))); },
        mod_int,
        "operator%",
        new filc::ast::LambdaType({int_type, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator+(int, int) -> int",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt64Ty(*context),
        { builder->CreateRet(builder->CreateAdd(function_plus_int->getArg(0), function_plus_int->getArg(1))); },
        plus_int,
        "operator+",
        new filc::ast::LambdaType({int_type, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator-(int, int) -> int",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt64Ty(*context),
        { builder->CreateRet(builder->CreateSub(function_sub_int->getArg(0), function_sub_int->getArg(1))); },
        sub_int,
        "operator-",
        new filc::ast::LambdaType({int_type, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator<(int, int) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpSLT(function_lt_int->getArg(0), function_lt_int->getArg(1))); },
        lt_int,
        "operator<",
        new filc::ast::LambdaType({int_type, int_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>(int, int) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpSGT(function_gt_int->getArg(0), function_gt_int->getArg(1))); },
        gt_int,
        "operator>",
        new filc::ast::LambdaType({int_type, int_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator==(int, int) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpEQ(function_eqeq_int->getArg(0), function_eqeq_int->getArg(1))); },
        eqeq_int,
        "operator==",
        new filc::ast::LambdaType({int_type, int_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator<=(int, int) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpSLE(function_leq_int->getArg(0), function_leq_int->getArg(1))); },
        leq_int,
        "operator<=",
        new filc::ast::LambdaType({int_type, int_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>=(int, int) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpSGE(function_geq_int->getArg(0), function_geq_int->getArg(1))); },
        geq_int,
        "operator>=",
        new filc::ast::LambdaType({int_type, int_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator!=(int, int) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpNE(function_ne_int->getArg(0), function_ne_int->getArg(1))); },
        ne_int,
        "operator!=",
        new filc::ast::LambdaType({int_type, int_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator*=(int*, int) -> int",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)), llvm::Type::getInt64Ty(*context)}
        ),
        llvm::Type::getInt64Ty(*context),
        {
            auto *result = builder->CreateMul(function_times_eq_int->getArg(0), function_times_eq_int->getArg(1));
            builder->CreateStore(result, function_times_eq_int->getArg(0));
            builder->CreateRet(result);
        },
        times_eq_int,
        "operator*=",
        new filc::ast::LambdaType({ptr_int, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator/=(int*, int) -> int",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)), llvm::Type::getInt64Ty(*context)}
        ),
        llvm::Type::getInt64Ty(*context),
        {
            auto *result = builder->CreateSDiv(function_div_eq_int->getArg(0), function_div_eq_int->getArg(1));
            builder->CreateStore(result, function_div_eq_int->getArg(0));
            builder->CreateRet(result);
        },
        div_eq_int,
        "operator/=",
        new filc::ast::LambdaType({ptr_int, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator%=(int*, int) -> int",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)), llvm::Type::getInt64Ty(*context)}
        ),
        llvm::Type::getInt64Ty(*context),
        {
            auto *result = builder->CreateSRem(function_mod_eq_int->getArg(0), function_mod_eq_int->getArg(1));
            builder->CreateStore(result, function_mod_eq_int->getArg(0));
            builder->CreateRet(result);
        },
        mod_eq_int,
        "operator%=",
        new filc::ast::LambdaType({ptr_int, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator+=(int*, int) -> int",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)), llvm::Type::getInt64Ty(*context)}
        ),
        llvm::Type::getInt64Ty(*context),
        {
            auto *result = builder->CreateAdd(function_add_eq_int->getArg(0), function_add_eq_int->getArg(1));
            builder->CreateStore(result, function_add_eq_int->getArg(0));
            builder->CreateRet(result);
        },
        add_eq_int,
        "operator+=",
        new filc::ast::LambdaType({ptr_int, int_type}, int_type)
    )
    DEFINE_FUNCTION(
        "operator-=(int*, int) -> int",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)), llvm::Type::getInt64Ty(*context)}
        ),
        llvm::Type::getInt64Ty(*context),
        {
            auto *result = builder->CreateSub(function_sub_eq_int->getArg(0), function_sub_eq_int->getArg(1));
            builder->CreateStore(result, function_sub_eq_int->getArg(0));
            builder->CreateRet(result);
        },
        sub_eq_int,
        "operator-=",
        new filc::ast::LambdaType({ptr_int, int_type}, int_type)
    )
    // endregion

    // region double operators
    DEFINE_FUNCTION(
        "operator*(double, double) -> double",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getDoubleTy(*context),
        {
            builder->CreateRet(builder->CreateFMul(function_times_double->getArg(0), function_times_double->getArg(1)));
        },
        times_double,
        "operator*",
        new filc::ast::LambdaType({double_type, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator/(double, double) -> double",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getDoubleTy(*context),
        { builder->CreateRet(builder->CreateFDiv(function_div_double->getArg(0), function_div_double->getArg(1))); },
        div_double,
        "operator/",
        new filc::ast::LambdaType({double_type, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator%(double, double) -> double",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getDoubleTy(*context),
        { builder->CreateRet(builder->CreateFRem(function_mod_double->getArg(0), function_mod_double->getArg(1))); },
        mod_double,
        "operator%",
        new filc::ast::LambdaType({double_type, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator+(double, double) -> double",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getDoubleTy(*context),
        { builder->CreateRet(builder->CreateFAdd(function_plus_double->getArg(0), function_plus_double->getArg(1))); },
        plus_double,
        "operator+",
        new filc::ast::LambdaType({double_type, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator-(double, double) -> double",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getDoubleTy(*context),
        { builder->CreateRet(builder->CreateFSub(function_sub_double->getArg(0), function_sub_double->getArg(1))); },
        sub_double,
        "operator-",
        new filc::ast::LambdaType({double_type, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator<(double, double) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOLT(function_lt_double->getArg(0), function_lt_double->getArg(1))); },
        lt_double,
        "operator<",
        new filc::ast::LambdaType({double_type, double_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>(double, double) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOGT(function_gt_double->getArg(0), function_gt_double->getArg(1))); },
        gt_double,
        "operator>",
        new filc::ast::LambdaType({double_type, double_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator==(double, double) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        {
            builder->CreateRet(builder->CreateFCmpOEQ(function_eqeq_double->getArg(0), function_eqeq_double->getArg(1))
            );
        },
        eqeq_double,
        "operator==",
        new filc::ast::LambdaType({double_type, double_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator<=(double, double) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOLE(function_leq_double->getArg(0), function_leq_double->getArg(1))); },
        leq_double,
        "operator<=",
        new filc::ast::LambdaType({double_type, double_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>=(double, double) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOGE(function_geq_double->getArg(0), function_geq_double->getArg(1))); },
        geq_double,
        "operator>=",
        new filc::ast::LambdaType({double_type, double_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator!=(double, double) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpONE(function_ne_double->getArg(0), function_ne_double->getArg(1))); },
        ne_double,
        "operator!=",
        new filc::ast::LambdaType({double_type, double_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator*=(double*, double) -> double",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)), llvm::Type::getDoubleTy(*context)}
        ),
        llvm::Type::getDoubleTy(*context),
        {
            auto *result
                = builder->CreateFMul(function_times_eq_double->getArg(0), function_times_eq_double->getArg(1));
            builder->CreateStore(result, function_times_eq_double->getArg(0));
            builder->CreateRet(result);
        },
        times_eq_double,
        "operator*=",
        new filc::ast::LambdaType({ptr_double, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator/=(double*, double) -> double",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)), llvm::Type::getDoubleTy(*context)}
        ),
        llvm::Type::getDoubleTy(*context),
        {
            auto *result = builder->CreateFDiv(function_div_eq_double->getArg(0), function_div_eq_double->getArg(1));
            builder->CreateStore(result, function_div_eq_double->getArg(0));
            builder->CreateRet(result);
        },
        div_eq_double,
        "operator/=",
        new filc::ast::LambdaType({ptr_double, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator%=(double*, double) -> double",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)), llvm::Type::getDoubleTy(*context)}
        ),
        llvm::Type::getDoubleTy(*context),
        {
            auto *result = builder->CreateFRem(function_mod_eq_double->getArg(0), function_mod_eq_double->getArg(1));
            builder->CreateStore(result, function_mod_eq_double->getArg(0));
            builder->CreateRet(result);
        },
        mod_eq_double,
        "operator%=",
        new filc::ast::LambdaType({ptr_double, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator+=(double*, double) -> double",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)), llvm::Type::getDoubleTy(*context)}
        ),
        llvm::Type::getDoubleTy(*context),
        {
            auto *result = builder->CreateFAdd(function_add_eq_double->getArg(0), function_add_eq_double->getArg(1));
            builder->CreateStore(result, function_add_eq_double->getArg(0));
            builder->CreateRet(result);
        },
        add_eq_double,
        "operator+=",
        new filc::ast::LambdaType({ptr_double, double_type}, double_type)
    )
    DEFINE_FUNCTION(
        "operator-=(double*, double) -> double",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)), llvm::Type::getDoubleTy(*context)}
        ),
        llvm::Type::getDoubleTy(*context),
        {
            auto *result = builder->CreateFSub(function_sub_eq_double->getArg(0), function_sub_eq_double->getArg(1));
            builder->CreateStore(result, function_sub_eq_double->getArg(0));
            builder->CreateRet(result);
        },
        sub_eq_double,
        "operator-=",
        new filc::ast::LambdaType({ptr_double, double_type}, double_type)
    )
    // endregion

    // region float operators
    DEFINE_FUNCTION(
        "operator*(float, float) -> float",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getFloatTy(*context),
        { builder->CreateRet(builder->CreateFMul(function_times_float->getArg(0), function_times_float->getArg(1))); },
        times_float,
        "operator*",
        new filc::ast::LambdaType({float_type, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator/(float, float) -> float",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getFloatTy(*context),
        { builder->CreateRet(builder->CreateFDiv(function_div_float->getArg(0), function_div_float->getArg(1))); },
        div_float,
        "operator/",
        new filc::ast::LambdaType({float_type, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator%(float, float) -> float",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getFloatTy(*context),
        { builder->CreateRet(builder->CreateFRem(function_mod_float->getArg(0), function_mod_float->getArg(1))); },
        mod_float,
        "operator%",
        new filc::ast::LambdaType({float_type, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator+(float, float) -> float",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getFloatTy(*context),
        { builder->CreateRet(builder->CreateFAdd(function_plus_float->getArg(0), function_plus_float->getArg(1))); },
        plus_float,
        "operator+",
        new filc::ast::LambdaType({float_type, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator-(float, float) -> float",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getFloatTy(*context),
        { builder->CreateRet(builder->CreateFSub(function_sub_float->getArg(0), function_sub_float->getArg(1))); },
        sub_float,
        "operator-",
        new filc::ast::LambdaType({float_type, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator<(float, float) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOLT(function_lt_float->getArg(0), function_lt_float->getArg(1))); },
        lt_float,
        "operator<",
        new filc::ast::LambdaType({float_type, float_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>(float, float) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOGT(function_gt_float->getArg(0), function_gt_float->getArg(1))); },
        gt_float,
        "operator>",
        new filc::ast::LambdaType({float_type, float_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator==(float, float) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOEQ(function_eqeq_float->getArg(0), function_eqeq_float->getArg(1))); },
        eqeq_float,
        "operator==",
        new filc::ast::LambdaType({float_type, float_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator<=(float, float) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOLE(function_leq_float->getArg(0), function_leq_float->getArg(1))); },
        leq_float,
        "operator<=",
        new filc::ast::LambdaType({float_type, float_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>=(float, float) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpOGE(function_geq_float->getArg(0), function_geq_float->getArg(1))); },
        geq_float,
        "operator>=",
        new filc::ast::LambdaType({float_type, float_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator!=(float, float) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateFCmpONE(function_ne_float->getArg(0), function_ne_float->getArg(1))); },
        ne_float,
        "operator!=",
        new filc::ast::LambdaType({float_type, float_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator*=(float*, float) -> float",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)), llvm::Type::getFloatTy(*context)}
        ),
        llvm::Type::getFloatTy(*context),
        {
            auto *result = builder->CreateFMul(function_times_eq_float->getArg(0), function_times_eq_float->getArg(1));
            builder->CreateStore(result, function_times_eq_float->getArg(0));
            builder->CreateRet(result);
        },
        times_eq_float,
        "operator*=",
        new filc::ast::LambdaType({ptr_float, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator/=(float*, float) -> float",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)), llvm::Type::getFloatTy(*context)}
        ),
        llvm::Type::getFloatTy(*context),
        {
            auto *result = builder->CreateFDiv(function_div_eq_float->getArg(0), function_div_eq_float->getArg(1));
            builder->CreateStore(result, function_div_eq_float->getArg(0));
            builder->CreateRet(result);
        },
        div_eq_float,
        "operator/=",
        new filc::ast::LambdaType({ptr_float, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator%=(float*, float) -> float",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)), llvm::Type::getFloatTy(*context)}
        ),
        llvm::Type::getFloatTy(*context),
        {
            auto *result = builder->CreateFRem(function_mod_eq_float->getArg(0), function_mod_eq_float->getArg(1));
            builder->CreateStore(result, function_mod_eq_float->getArg(0));
            builder->CreateRet(result);
        },
        mod_eq_float,
        "operator%=",
        new filc::ast::LambdaType({ptr_float, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator+=(float*, float) -> float",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)), llvm::Type::getFloatTy(*context)}
        ),
        llvm::Type::getFloatTy(*context),
        {
            auto *result = builder->CreateFAdd(function_add_eq_float->getArg(0), function_add_eq_float->getArg(1));
            builder->CreateStore(result, function_add_eq_float->getArg(0));
            builder->CreateRet(result);
        },
        add_eq_float,
        "operator+=",
        new filc::ast::LambdaType({ptr_float, float_type}, float_type)
    )
    DEFINE_FUNCTION(
        "operator-=(float*, float) -> float",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)), llvm::Type::getFloatTy(*context)}
        ),
        llvm::Type::getFloatTy(*context),
        {
            auto *result = builder->CreateFSub(function_sub_eq_float->getArg(0), function_sub_eq_float->getArg(1));
            builder->CreateStore(result, function_sub_eq_float->getArg(0));
            builder->CreateRet(result);
        },
        sub_eq_float,
        "operator-=",
        new filc::ast::LambdaType({ptr_float, float_type}, float_type)
    )
    // endregion

    // region char operators
    DEFINE_FUNCTION(
        "operator*(char, char) -> char",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt8Ty(*context),
        { builder->CreateRet(builder->CreateMul(function_times_char->getArg(0), function_times_char->getArg(1))); },
        times_char,
        "operator*",
        new filc::ast::LambdaType({char_type, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator/(char, char) -> char",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt8Ty(*context),
        { builder->CreateRet(builder->CreateSDiv(function_div_char->getArg(0), function_div_char->getArg(1))); },
        div_char,
        "operator/",
        new filc::ast::LambdaType({char_type, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator%(char, char) -> char",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt8Ty(*context),
        { builder->CreateRet(builder->CreateSRem(function_mod_char->getArg(0), function_mod_char->getArg(1))); },
        mod_char,
        "operator%",
        new filc::ast::LambdaType({char_type, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator+(char, char) -> char",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt8Ty(*context),
        { builder->CreateRet(builder->CreateAdd(function_plus_char->getArg(0), function_plus_char->getArg(1))); },
        plus_char,
        "operator+",
        new filc::ast::LambdaType({char_type, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator-(char, char) -> char",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt8Ty(*context),
        { builder->CreateRet(builder->CreateSub(function_sub_char->getArg(0), function_sub_char->getArg(1))); },
        sub_char,
        "operator-",
        new filc::ast::LambdaType({char_type, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator<(char, char) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpULT(function_lt_char->getArg(0), function_lt_char->getArg(1))); },
        lt_char,
        "operator<",
        new filc::ast::LambdaType({char_type, char_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>(char, char) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpUGT(function_gt_char->getArg(0), function_gt_char->getArg(1))); },
        gt_char,
        "operator>",
        new filc::ast::LambdaType({char_type, char_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator==(char, char) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpEQ(function_eqeq_char->getArg(0), function_eqeq_char->getArg(1))); },
        eqeq_char,
        "operator==",
        new filc::ast::LambdaType({char_type, char_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator<=(char, char) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpULE(function_leq_char->getArg(0), function_leq_char->getArg(1))); },
        leq_char,
        "operator<=",
        new filc::ast::LambdaType({char_type, char_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator>=(char, char) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpUGE(function_geq_char->getArg(0), function_geq_char->getArg(1))); },
        geq_char,
        "operator>=",
        new filc::ast::LambdaType({char_type, char_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator!=(char, char) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpNE(function_ne_char->getArg(0), function_ne_char->getArg(1))); },
        ne_char,
        "operator!=",
        new filc::ast::LambdaType({char_type, char_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator*=(char*, char) -> char",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)), llvm::Type::getInt8Ty(*context)}
        ),
        llvm::Type::getInt8Ty(*context),
        {
            auto *result = builder->CreateMul(function_times_eq_char->getArg(0), function_times_eq_char->getArg(1));
            builder->CreateStore(result, function_times_eq_char->getArg(0));
            builder->CreateRet(result);
        },
        times_eq_char,
        "operator*=",
        new filc::ast::LambdaType({ptr_char, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator/=(char*, char) -> char",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)), llvm::Type::getInt8Ty(*context)}
        ),
        llvm::Type::getInt8Ty(*context),
        {
            auto *result = builder->CreateSDiv(function_div_eq_char->getArg(0), function_div_eq_char->getArg(1));
            builder->CreateStore(result, function_div_eq_char->getArg(0));
            builder->CreateRet(result);
        },
        div_eq_char,
        "operator/=",
        new filc::ast::LambdaType({ptr_char, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator%=(char*, char) -> char",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)), llvm::Type::getInt8Ty(*context)}
        ),
        llvm::Type::getInt8Ty(*context),
        {
            auto *result = builder->CreateSRem(function_mod_eq_char->getArg(0), function_mod_eq_char->getArg(1));
            builder->CreateStore(result, function_mod_eq_char->getArg(0));
            builder->CreateRet(result);
        },
        mod_eq_char,
        "operator%=",
        new filc::ast::LambdaType({ptr_char, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator+=(char*, char) -> char",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)), llvm::Type::getInt8Ty(*context)}
        ),
        llvm::Type::getInt8Ty(*context),
        {
            auto *result = builder->CreateAdd(function_add_eq_char->getArg(0), function_add_eq_char->getArg(1));
            builder->CreateStore(result, function_add_eq_char->getArg(0));
            builder->CreateRet(result);
        },
        add_eq_char,
        "operator+=",
        new filc::ast::LambdaType({ptr_char, char_type}, char_type)
    )
    DEFINE_FUNCTION(
        "operator-=(char*, char) -> char",
        std::vector<llvm::Type *>(
            {llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)), llvm::Type::getInt8Ty(*context)}
        ),
        llvm::Type::getInt8Ty(*context),
        {
            auto *result = builder->CreateSub(function_sub_eq_char->getArg(0), function_sub_eq_char->getArg(1));
            builder->CreateStore(result, function_sub_eq_char->getArg(0));
            builder->CreateRet(result);
        },
        sub_eq_char,
        "operator-=",
        new filc::ast::LambdaType({ptr_char, char_type}, char_type)
    )
    // endregion

    // region bool operators
    DEFINE_FUNCTION(
        "operator==(bool, bool) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpEQ(function_eqeq_bool->getArg(0), function_eqeq_bool->getArg(1))); },
        eqeq_bool,
        "operator==",
        new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator!=(bool, bool) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateICmpNE(function_ne_bool->getArg(0), function_ne_bool->getArg(1))); },
        ne_bool,
        "operator!=",
        new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator&&(bool, bool) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateAnd(function_and_bool->getArg(0), function_and_bool->getArg(1))); },
        and_bool,
        "operator&&",
        new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
    )
    DEFINE_FUNCTION(
        "operator||(bool, bool) -> bool",
        std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
        llvm::Type::getInt1Ty(*context),
        { builder->CreateRet(builder->CreateOr(function_or_bool->getArg(0), function_or_bool->getArg(1))); },
        or_bool,
        "operator||",
        new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
    )
    // endregion
}
