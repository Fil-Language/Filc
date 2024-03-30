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

using namespace filc::environment;

auto Environment::addPrefixUnary(std::shared_ptr<Environment> global, BasicTypes &basic_types) -> void {
    auto ptr_int    = std::make_shared<ast::PointerType>(basic_types._int_type);
    auto ptr_double = std::make_shared<ast::PointerType>(basic_types._double_type);
    auto ptr_float  = std::make_shared<ast::PointerType>(basic_types._float_type);
    auto ptr_char   = std::make_shared<ast::PointerType>(basic_types._char_type);
    auto is_ok      = global->addName("operator++", new ast::LambdaType({ptr_int}, ptr_int))
              && global->addName("operator--", new ast::LambdaType({ptr_int}, ptr_int))
              && global->addName("operator+", new ast::LambdaType({basic_types._int_type}, basic_types._int_type))
              && global->addName("operator-", new ast::LambdaType({basic_types._int_type}, basic_types._int_type))
              && global->addName("operator++", new ast::LambdaType({ptr_double}, ptr_double))
              && global->addName("operator--", new ast::LambdaType({ptr_double}, ptr_double))
              && global->addName("operator+", new ast::LambdaType({basic_types._double_type}, basic_types._double_type))
              && global->addName("operator-", new ast::LambdaType({basic_types._double_type}, basic_types._double_type))
              && global->addName("operator++", new ast::LambdaType({ptr_float}, ptr_float))
              && global->addName("operator--", new ast::LambdaType({ptr_float}, ptr_float))
              && global->addName("operator+", new ast::LambdaType({basic_types._float_type}, basic_types._float_type))
              && global->addName("operator-", new ast::LambdaType({basic_types._float_type}, basic_types._float_type))
              && global->addName("operator++", new ast::LambdaType({ptr_char}, ptr_char))
              && global->addName("operator--", new ast::LambdaType({ptr_char}, ptr_char))
              && global->addName("operator!", new ast::LambdaType({basic_types._bool_type}, basic_types._bool_type));
    if (!is_ok) {
        throw std::logic_error("Fail to add base prefix unary calcul to global environment");
    }
}
