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
#include "Type.h"

using namespace filc::ast;

LambdaType::LambdaType(
    const std::vector<std::shared_ptr<AbstractType>> &argument_types, const std::shared_ptr<AbstractType> &return_type
)
    : _argument_types(argument_types), _return_type(return_type) {}

auto LambdaType::getArgumentTypes() const -> const std::vector<std::shared_ptr<AbstractType>> & {
    return _argument_types;
}

auto LambdaType::getReturnType() const -> std::shared_ptr<AbstractType> {
    return _return_type;
}

auto LambdaType::dump() const -> std::string {
    std::string result = "(";
    for (const auto &argument: _argument_types) {
        result += argument->dump() + ", ";
    }
    if (!_argument_types.empty()) {
        // Remove last ", "
        result.pop_back();
        result.pop_back();
    }
    result += ") -> ";

    result += _return_type->dump();

    return result;
}

auto LambdaType::getInnerType() const -> std::shared_ptr<AbstractType> {
    return nullptr;
}
