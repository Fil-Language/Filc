/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
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

#include "AST_decl.h"
#include "antlr4-runtime.h"
#include <string>

class FilCompiler {
public:
    explicit FilCompiler(std::string filename);

    auto compile(int flag, bool debug, const std::string &output) -> int;

    static auto import(const std::string &module_name, antlr4::Token *tkn) -> std::string;

    static auto getModule(const std::string &module_name) -> ast::Program *;

private:
    static auto getSystemProgram() -> ast::Program *;

    std::string _filename;
    static std::string _current_dir;
    static std::map<std::string, ast::Program *> _modules;
};

using FLAGS = enum FLAGS {
    NONE,

    DECOMPILE,
    AST,
};

#endif//FILC_FILCOMPILER_H
