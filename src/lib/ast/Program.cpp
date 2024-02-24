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
#include <utility>
#include <algorithm>

auto getFileName(const std::string &filename) -> std::string {
    auto slash = filename.find_last_of('/');
    auto dot = filename.find_last_of('.');

    return filename.substr(slash + 1, dot - slash - 1);
}

namespace filc::ast {
    Program::Program(std::string module, const std::vector<std::string> &imports,
                     const std::vector<AbstractExpression *> &expressions)
            : _module(std::move(module)), _imports(imports), _expressions(expressions), _environment(nullptr),
              _public_environment(nullptr) {}

    Program::~Program() {
        for (const auto &expression: _expressions) {
            delete expression;
        }
    }

    auto Program::getModule() const -> const std::string & {
        return _module;
    }

    auto Program::getImports() const -> const std::vector<std::string> & {
        return _imports;
    }

    auto Program::getExpressions() const -> const std::vector<AbstractExpression *> & {
        return _expressions;
    }

    auto Program::getFilename() const -> const std::string & {
        return _filename;
    }

    auto Program::setFilename(const std::string &filename) -> void {
        _filename = filename;

        auto file = getFileName(_filename);
        if (file != "index" || file != "main") {
            _module += "." + file;
        }
    }
}
