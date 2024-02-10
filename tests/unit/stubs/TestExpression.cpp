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
#include "stubs.h"

using namespace std;
using namespace filc;

TestExpression::TestExpression()
    : _resolveType_called(false) {}

auto TestExpression::withExpressionType(
        const std::shared_ptr<ast::AbstractType> &expression_type) -> TestExpression & {
    setExpressionType(expression_type);

    return *this;
}

auto TestExpression::resolveType(environment::Environment *environment,
                                 message::MessageCollector *collector,
                                 const shared_ptr<ast::AbstractType> &preferred_type) -> void {
    (void) environment;
    (void) collector;
    (void) preferred_type;

    _resolveType_called = true;
}

auto TestExpression::addNameToEnvironment(environment::Environment *environment) const -> void {
    (void) environment;
}

auto TestExpression::generateIR(filc::message::MessageCollector *collector,
                                filc::environment::Environment *environment,
                                llvm::LLVMContext *context,
                                llvm::Module *module,
                                llvm::IRBuilder<> *builder) const -> llvm::Value * {
    return nullptr;
}

auto TestExpression::isResolveTypeCalled() const -> bool {
    return _resolveType_called;
}
