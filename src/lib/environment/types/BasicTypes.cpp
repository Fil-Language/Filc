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
#include "Identifier.h"

using namespace filc::environment;

auto Environment::addBasicTypes(std::shared_ptr<Environment> global) -> BasicTypes {
    BasicTypes basic_types;
    basic_types._int_type    = std::make_shared<ast::Type>(std::make_shared<ast::Identifier>("int"));
    basic_types._double_type = std::make_shared<ast::Type>(std::make_shared<ast::Identifier>("double"));
    basic_types._float_type  = std::make_shared<ast::Type>(std::make_shared<ast::Identifier>("float"));
    basic_types._char_type   = std::make_shared<ast::Type>(std::make_shared<ast::Identifier>("char"));
    basic_types._bool_type   = std::make_shared<ast::Type>(std::make_shared<ast::Identifier>("bool"));

    auto is_ok = global->addType(basic_types._int_type) && global->addType(basic_types._double_type)
              && global->addType(basic_types._float_type) && global->addType(basic_types._char_type)
              && global->addType(basic_types._bool_type);
    if (!is_ok) {
        throw std::logic_error("Fail to add base types to global environment");
    }

    return basic_types;
}
