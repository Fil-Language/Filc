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

#include <utility>
#include <iostream>

using namespace std;
using namespace antlr4;
using namespace antlrcppfil;

FilCompiler::FilCompiler(string filename) : _filename(std::move(filename)) {}

int FilCompiler::compile(int flag) {
    ifstream file(_filename);
    if (!file.is_open()) {
        cout << "File " << _filename << " not found" << endl;
        file.close();
        return 1;
    }

    try {
        ANTLRInputStream input(file);
        FilLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        tokens.fill();

        FilParser parser(&tokens);
        Program *program = parser.parseTree();

        if (file.is_open()) {
            file.close();
        }

        if (flag == DECOMPILE) {
            cout << program->decompile(0) << endl;

            delete program;
            return 0;
        }

        // TODO : generate symbols tables

        // TODO : type inference and checking

        // TODO : code structure checking

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

Program *FilCompiler::import(const string &moduleName) {
    return new Program(moduleName, {});
    // TODO: look for the file in the current directory, then in the include path $FIL_PATH
}
