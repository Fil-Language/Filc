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
#ifndef FILC_ENVIRONMENT_H
#define FILC_ENVIRONMENT_H

#include "Name.h"
#include <vector>

namespace filc::environment {
    class Environment {
    public:
        [[nodiscard]] auto hasName(const std::string &name) const -> bool;

        auto addName(const std::string &name, filc::ast::AbstractType *type) -> bool;

        [[nodiscard]] auto getName(const std::string &name) const -> Name *;

        [[nodiscard]] auto hasType(const std::string &type) const -> bool;

        auto addType(filc::ast::AbstractType *type) -> bool;

        [[nodiscard]] auto getType(const std::string &type) const -> filc::ast::AbstractType *;

    private:
        std::vector<Name *> _names;
        std::vector<filc::ast::AbstractType *> _types;
    };
}

#endif //FILC_ENVIRONMENT_H
