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

namespace filc::ast {
    LambdaType::LambdaType(const std::vector<AbstractType *> &argument_types, AbstractType *return_type,
                           AbstractType *called_on)
            : _argument_types(argument_types), _return_type(return_type), _called_on(called_on) {}

    auto LambdaType::getArgumentTypes() const -> const std::vector<AbstractType *> & {
        return _argument_types;
    }

    auto LambdaType::getReturnType() const -> AbstractType * {
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

    LambdaType::~LambdaType() {
//        for (const auto &argument_type: _argument_types) {
//            delete argument_type;
//        }
//        delete _return_type;
    }

    auto LambdaType::getInnerType() const -> AbstractType * {
        return (AbstractType *) this;
    }

    auto LambdaType::getCalledOn() const -> AbstractType * {
        return _called_on;
    }

    auto LambdaType::equals(const AbstractType &other) const -> bool {
        if (dynamic_cast<const LambdaType *>(&other) == nullptr) {
            return false;
        }
        auto other_type = dynamic_cast<const LambdaType &>(other);

        if (_argument_types.size() != other_type._argument_types.size()) {
            return false;
        }

        for (unsigned int i = 0; i < _argument_types.size(); i++) {
            if (*_argument_types[i] != *other_type._argument_types[i]) {
                return false;
            }
        }

        return *_return_type == *other_type._return_type && *_called_on == *other_type._called_on;
    }
}
