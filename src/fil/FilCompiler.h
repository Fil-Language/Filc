/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
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

    static ast::Program *import(const std::string &moduleName, antlr4::Token *tkn);

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
