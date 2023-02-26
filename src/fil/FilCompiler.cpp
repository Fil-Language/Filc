/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "FilCompiler.h"
#include "antlr4-runtime.h"
#include "FilLexer.h"
#include "FilParser.h"
#include "ErrorsRegister.h"
#include "ParserErrorListener.h"

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
    file.close();

    try {
        ErrorsRegister::init();

        ANTLRFileStream input;
        input.loadFromFile(_filename);
        FilLexer lexer(&input);
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
            cout << program->decompile(0) << endl;

            return 0;
        }

        // Resolve environement
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

Program *FilCompiler::import(const string &moduleName, antlr4::Token *tkn) {
    static auto imports = map<string, Program *>();

    // Check if the module is already imported
    if (imports.find(moduleName) != imports.end()) {
        return imports[moduleName];
    } else {
        // It fixes the infinite loop of import
        // When it will resolve the environment, it will look again for the module
        // and replace nullptr by the correct one
        imports[moduleName] = nullptr;
    }

#ifdef _WIN32
    char sep = '\\';
    string ssep = "\\";
#else
    char sep = '/';
    string ssep = "/";
#endif

    // Lambda to parse the file and return the AST
    auto getProgram = [moduleName](const string &filename) {
        ANTLRFileStream input;
        input.loadFromFile(filename);
        FilLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(new ParserErrorListener());
        Program *program = parser.parseTree();
        imports[moduleName] = program;

        return program;
    };

    // Looking for the module in the current directory
    auto filename = _currentDir + ssep + replace(moduleName, '.', sep) + ".fil";
    ifstream file(filename);
    if (file.is_open()) {
        file.close();
        return getProgram(filename);
    }
    // ----
    filename = _currentDir + ssep + replace(moduleName, '.', sep) + ssep +
               *(split(moduleName, '.').end() - 1) + ".fil";
    file = ifstream(filename);
    if (file.is_open()) {
        file.close();
        return getProgram(filename);
    }

    // Special case for the standard library
    if (moduleName == "fil.system") {
        auto prog = getSystemProgram();
        imports[moduleName] = prog;

        return prog;
    }

    // Looking for the module in the include path $FIL_PATH
    auto filPath = to_string(getenv("FIL_PATH"));
    auto paths = split(filPath, ':');
    for (auto &path: paths) {
        filename = path + ssep + replace(moduleName, '.', sep) + ".fil";
        file = ifstream(filename);
        if (file.is_open()) {
            file.close();
            return getProgram(filename);
        }
        // ----
        filename = path + ssep;
        filename += replace(moduleName, '.', sep) + ssep;
        filename += *(split(moduleName, '.').end() - 1) + ".fil";
        file = ifstream(filename);
        if (file.is_open()) {
            file.close();
            return getProgram(filename);
        }
    }

    // Module not found
    ErrorsRegister::addError(new Error(
            "Module " + moduleName + " not found",
            new Position((int) tkn->getLine(),
                         (int) tkn->getCharPositionInLine(),
                         tkn->getTokenSource()->getSourceName())
    ));

    return nullptr;
}

Program *FilCompiler::getSystemProgram() {
    static auto *systemProgram = new Program("fil.system", {}, {});
    static bool initialized = false;

    if (initialized) {
        return systemProgram;
    }

    initialized = true;

    auto env = Environment::getGlobalEnvironment();

    // Add system functions
    // TODO

    systemProgram->setEnvironment(env);

    return systemProgram;
}
