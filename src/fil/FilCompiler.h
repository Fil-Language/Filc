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
#include <string>
#include "antlr4-runtime.h"

class FilCompiler {
public:
    explicit FilCompiler(std::string filename);

    int compile(int flag, bool debug, const std::string &output);

    static std::string import(const std::string &moduleName, antlr4::Token *tkn);

    static ast::Program *getModule(const std::string &moduleName);

private:
    static ast::Program *getSystemProgram();

private:
    std::string _filename;
    static std::string _currentDir;
    static std::map<std::string, ast::Program *> _modules;
};

typedef enum FLAGS {
    NONE,

    DECOMPILE,
    AST,
} FLAGS;


#endif //FILC_FILCOMPILER_H
