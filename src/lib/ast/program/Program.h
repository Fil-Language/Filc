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
#ifndef FILC_PROGRAM_H
#define FILC_PROGRAM_H

#include "AST_decl.h"
#include "Environment.h"
#include <memory>
#include <string>
#include <vector>

namespace filc::ast {
    class Program {
    public:
        explicit Program(
            std::string module,
            const std::vector<std::string> &imports,
            const std::vector<std::shared_ptr<AbstractExpression>> &expressions
        );

        ~Program();

        [[nodiscard]] auto getModule() const -> const std::string &;

        [[nodiscard]] auto getImports() const -> const std::vector<std::string> &;

        auto setImports(const std::vector<std::shared_ptr<Program>> &imports) -> void;

        [[nodiscard]] auto getExpressions() const -> const std::vector<std::shared_ptr<AbstractExpression>> &;

        [[nodiscard]] auto getFilename() const -> const std::string &;

        auto setFilename(const std::string &filename) -> void;

    private:
        std::string _module;
        std::vector<std::string> _import_modules;
        std::vector<std::shared_ptr<Program>> _imports;
        std::vector<std::shared_ptr<AbstractExpression>> _expressions;
        std::string _filename;
        std::shared_ptr<environment::Environment> _environment;
        std::shared_ptr<environment::Environment> _public_environment;
    };
} // namespace filc::ast

#endif // FILC_PROGRAM_H
