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

int FilCompiler::compile(int flag) {
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
            delete program;

            return 1;
        }
        ErrorsRegister::clean();

        if (file.is_open()) {
            file.close();
        }

        if (flag == DECOMPILE) {
            cout << program->decompile(0) << endl;

            delete program;
            return 0;
        }

        // Generate symbols tables (environment)
        program->resolveGlobalEnvironment();

        // Type inference and checking
        program->inferTypes();

        ErrorsRegister::dump(cerr);
        if (ErrorsRegister::containsError()) {
            delete program;

            return 1;
        }
        ErrorsRegister::clean();

        if (flag == FLAGS::AST) {
            cout << program->dump(0) << endl;

            delete program;
            return 0;
        }

        // TODO : LLVM IR generation

        // Free memory
        delete program;
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
    // Look for the module in the current directory
    auto filename = _currentDir + "/" + replace(moduleName, '.', '/') + ".fil";
    ifstream file(filename);
    if (file.is_open()) {
        ANTLRInputStream input(file);
        FilLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        Program *program = parser.parseTree();

        file.close();

        // Generate symbols tables (environment)
        program->resolveGlobalEnvironment();

        // Type inference and checking
        program->inferTypes();

        return program;
    }

    // Look for the module in the include path $FIL_PATH
    auto filPath = to_string(getenv("FIL_PATH"));
    auto paths = split(filPath, ':');
    for (auto &path: paths) {
        filename = path + "/" + replace(moduleName, '.', '/') + ".fil";
        file = ifstream(filename);
        if (file.is_open()) {
            ANTLRInputStream input(file);
            FilLexer lexer(&input);
            CommonTokenStream tokens(&lexer);

            tokens.fill();

            FilParser parser(&tokens);
            Program *program = parser.parseTree();

            file.close();

            // Generate symbols tables (environment)
            program->resolveGlobalEnvironment();

            // Type inference and checking
            program->inferTypes();

            return program;
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
