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
#include "FilCompiler.h"
#include "ErrorsRegister.h"
#include "FilLexer.h"
#include "FilParser.h"
#include "LexerErrorListener.h"
#include "ParserErrorListener.h"
#include "antlr4-runtime.h"

#include <iostream>
#include <utility>

using namespace std;
using namespace antlr4;
using namespace antlrcppfil;

string FilCompiler::_current_dir;
map<string, Program *> FilCompiler::_modules;

FilCompiler::FilCompiler(string filename) : _filename(std::move(filename)) {
    _current_dir = _filename.substr(0, _filename.find_last_of("/\\"));
}

auto FilCompiler::compile(int flag, bool debug, const string &output) -> int {
    ifstream file(_filename);
    if (!file.is_open()) {
        cout << "File " << _filename << " not found" << endl;
        file.close();
        return 1;
    }
    file.close();

    try {
        ErrorsRegister::init();

        ANTLRFileStream input;
        input.loadFromFile(_filename);
        FilLexer lexer(&input);
        lexer.removeErrorListeners();
        lexer.addErrorListener(new LexerErrorListener());
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(new ParserErrorListener());
        Program *program = parser.parseTree();

        ErrorsRegister::dump(cerr);
        if (ErrorsRegister::containsError()) {
            return 1;
        }
        ErrorsRegister::clean();

        if (flag == DECOMPILE) {
            cout << program->decompile(0);

            return 0;
        }

        // Resolve environment
        program->resolveEnvironment();

        ErrorsRegister::dump(cerr);
        if (ErrorsRegister::containsError()) {
            return 1;
        }
        ErrorsRegister::clean();

        if (flag == FLAGS::AST) {
            cout << program->dump(0) << endl;

            return 0;
        }

        // TODO : LLVM IR generation
        (void) debug;
        (void) output;
    } catch (exception &e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}

auto FilCompiler::import(const string &module_name, antlr4::Token *tkn) -> string {
    // Check if the module is already imported
    if (_modules.find(module_name) != _modules.end()) {
        return module_name;
    }
    // It fixes the infinite loop of import
    // The nullptr is replaced by the Program pointer just after the parsing
    _modules[module_name] = nullptr;


#ifdef _WIN32
    char sep    = '\\';
    string ssep = "\\";
#else
    char sep    = '/';
    string ssep = "/";
#endif

    // Lambda to parse the file and return the AST
    auto get_program = [module_name](const string &filename) {
        ANTLRFileStream input;
        input.loadFromFile(filename);
        FilLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(new ParserErrorListener());
        Program *program      = parser.parseTree();
        _modules[module_name] = program;
    };

    // Looking for the module in the current directory
    auto filename = _current_dir + ssep + replace(module_name, '.', sep) + ".fil";
    ifstream file(filename);
    if (file.is_open()) {
        file.close();
        get_program(filename);
        return module_name;
    }
    // ----
    filename = _current_dir + ssep + replace(module_name, '.', sep) + ssep +
               *(split(module_name, '.').end() - 1) + ".fil";
    file = ifstream(filename);
    if (file.is_open()) {
        file.close();
        get_program(filename);
        return module_name;
    }

    // Special case for the standard library
    if (module_name == "fil.system") {
        auto *prog            = getSystemProgram();
        _modules[module_name] = prog;
        return module_name;
    }

    // Looking for the module in the include path $FIL_PATH
    auto fil_path = toString(getenv("FIL_PATH"));
    auto paths    = split(fil_path, ':');
    for (auto &path: paths) {
        filename = path + ssep + replace(module_name, '.', sep) + ".fil";
        file     = ifstream(filename);
        if (file.is_open()) {
            file.close();
            get_program(filename);
            return module_name;
        }
        // ----
        filename = path + ssep;
        filename += replace(module_name, '.', sep) + ssep;
        filename += *(split(module_name, '.').end() - 1) + ".fil";
        file = ifstream(filename);
        if (file.is_open()) {
            file.close();
            get_program(filename);
            return module_name;
        }
    }

    // Module not found
    ErrorsRegister::addError(new Error(
            "Module " + module_name + " not found",
            new Position((int) tkn->getLine(),
                         (int) tkn->getCharPositionInLine(),
                         tkn->getTokenSource()->getSourceName())));

    return "";
}

auto FilCompiler::getModule(const std::string &module_name) -> ast::Program * {
    return _modules[module_name];
}

auto FilCompiler::getSystemProgram() -> Program * {
    static auto *system_program = new Program("fil.system", {}, {});
    static bool initialized     = false;

    if (initialized) {
        return system_program;
    }

    initialized = true;

    auto *env = Environment::getGlobalEnvironment();

    // Add system functions
    // TODO

    system_program->setEnvironment(env);

    return system_program;
}
