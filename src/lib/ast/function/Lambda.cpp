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
#include "Function.h"
#include "llvm/IR/Verifier.h"

using namespace filc::ast;

int Lambda::name_index = 0;

Lambda::Lambda(
    const std::vector<std::shared_ptr<FunctionParameter>> &parameters,
    const std::shared_ptr<AbstractType> &return_type,
    const std::shared_ptr<BlockBody> &body
)
    : _parameters(parameters), _return_type(return_type), _body(body), _body_environment(nullptr) {}

auto Lambda::getParameters() const -> const std::vector<std::shared_ptr<FunctionParameter>> & {
    return _parameters;
}

auto Lambda::getReturnType() const -> std::shared_ptr<AbstractType> {
    return _return_type;
}

auto Lambda::getBody() const -> std::shared_ptr<BlockBody> {
    return _body;
}

auto Lambda::getBodyEnvironment() const -> std::shared_ptr<environment::Environment> {
    return _body_environment;
}

Lambda::~Lambda() = default;
