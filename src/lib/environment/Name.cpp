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
#include "Name.h"
#include <utility>

namespace filc::environment {
    Name::Name(std::string name, const std::shared_ptr<filc::ast::AbstractType> &type)
            : _name(std::move(name)), _type(type), _value(nullptr), _function(nullptr) {}

    auto Name::getName() const -> const std::string & {
        return _name;
    }

    auto Name::getType() const -> std::shared_ptr<filc::ast::AbstractType> {
        return _type;
    }

    auto Name::getValue() const -> llvm::Value * {
        return _value;
    }

    auto Name::setValue(llvm::Value *value) -> void {
        if (value == nullptr) {
            throw std::logic_error("Tried to set nullptr to a Name value");
        }
        _value = value;
    }

    auto Name::getFunction() const -> llvm::Function * {
        return _function;
    }

    auto Name::setFunction(llvm::Function *function) -> void {
        if (function == nullptr) {
            throw std::logic_error("Tried to set nullptr to a Name function");
        }
        _function = function;
    }
}
