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
#ifndef FILC_FILCOMPILER_H
#define FILC_FILCOMPILER_H

#include "AST.h"
#include "Compiler.h"
#include "MessageCollector.h"
#include <future>
#include <map>

namespace filc {
    class FilCompiler final : public Compiler {
    public:
        FilCompiler();

        ~FilCompiler() override = default;

        auto compile() -> int override;

    private:
        std::map<const std::string, ast::Program *> _modules;

        static auto checkCollector(message::MessageCollector *collector) -> bool;

        auto parseFiles(message::MessageCollector *collector) -> std::vector<std::future<ast::Program *>>;

        auto collectModules(std::vector<std::future<ast::Program *>> &futures,
                            message::MessageCollector *collector) -> void;

        auto checkModules(message::MessageCollector *collector) -> void;

        auto resolveEnvironment(message::MessageCollector *collector) -> void;

        auto generateLLVMIR(message::MessageCollector *collector) -> void;

        static auto getModuleFilename(const std::string &module_name, const std::string &std_path) -> std::string;
    };
}// namespace filc

#endif//FILC_FILCOMPILER_H
