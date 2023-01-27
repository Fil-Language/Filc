/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "FilCompiler.h"
#include "antlr4-runtime.h"
#include "FilLexer.h"
#include "FilParser.h"
#include "ErrorsRegister.h"

#include <utility>
#include <iostream>

using namespace std;
using namespace antlr4;
using namespace antlrcppfil;

string FilCompiler::_currentDir;

FilCompiler::FilCompiler(string filename) : _filename(std::move(filename)) {
    _currentDir = _filename.substr(0, _filename.find_last_of("/\\"));
}

int FilCompiler::compile(int flag, bool debug, const string &output) {
    ifstream file(_filename);
    if (!file.is_open()) {
        cout << "File " << _filename << " not found" << endl;
        file.close();
        return 1;
    }

    try {
        ErrorsRegister::init();

        ANTLRInputStream input(file);
        FilLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        Program *program = parser.parseTree();

        ErrorsRegister::dump(cerr);
        if (ErrorsRegister::containsError()) {
            file.close();

            return 1;
        }
        ErrorsRegister::clean();

        if (file.is_open()) {
            file.close();
        }

        if (flag == DECOMPILE) {
            cout << program->decompile(0) << endl;

            return 0;
        }

        // Generate symbols tables (environment)
        //program->resolveGlobalEnvironment();

        // Type inference and checking
        //program->inferTypes();

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
    } catch (exception &e) {
        cout << e.what() << endl;
        return 1;
    }

    if (file.is_open()) {
        file.close();
    }

    return 0;
}

Program *FilCompiler::import(const string &moduleName, antlr4::Token *tkn) {
#ifdef _WIN32
    char sep = '\\';
    string ssep = "\\";
#else
    char sep = '/';
    string ssep = "/";
#endif
    // Lambda to parse the file and return the AST
    auto getProgram = [](ifstream &file) {
        ANTLRInputStream input(file);
        FilLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        Program *program = parser.parseTree();

        file.close();

        // Generate symbols tables (environment)
        //program->resolveGlobalEnvironment();

        // Type inference and checking
        //program->inferTypes();

        return program;
    };

    // Looking for the module in the current directory
    auto filename = _currentDir + ssep + replace(moduleName, '.', sep) + ".fil";
    ifstream file(filename);
    if (file.is_open()) {
        return getProgram(file);
    }
    // ----
    filename = _currentDir + ssep + replace(moduleName, '.', sep) + ssep +
               *(split(moduleName, '.').end() - 1) + ".fil";
    file = ifstream(filename);
    if (file.is_open()) {
        return getProgram(file);
    }

    // Looking for the module in the include path $FIL_PATH
    auto filPath = to_string(getenv("FIL_PATH"));
    auto paths = split(filPath, ':');
    for (auto &path: paths) {
        filename = path + ssep + replace(moduleName, '.', sep) + ".fil";
        file = ifstream(filename);
        if (file.is_open()) {
            return getProgram(file);
        }
        // ----
        filename = path + ssep + replace(moduleName, '.', sep) + ssep +
                   *(split(moduleName, '.').end() - 1) + ".fil";
        file = ifstream(filename);
        if (file.is_open()) {
            return getProgram(file);
        }
    }

    // Module not found
    ErrorsRegister::addError(
            "Module " + moduleName + " not found",
            new Position((int) tkn->getLine(),
                         (int) tkn->getCharPositionInLine(),
                         tkn->getTokenSource()->getSourceName())
    );

    return nullptr;
}
