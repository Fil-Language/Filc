/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_FILCOMPILER_H
#define FILC_FILCOMPILER_H

#include "AST.hpp"
#include <string>
#include "antlr4-runtime.h"

class FilCompiler {
public:
    explicit FilCompiler(std::string filename);

    int compile(int flag, bool debug, const std::string& output);

    static ast::Program *import(const std::string &moduleName, antlr4::Token *tkn);

private:
    std::string _filename;
    static std::string _currentDir;
};

typedef enum FLAGS {
    NONE,

    DECOMPILE,
    AST,
} FLAGS;


#endif //FILC_FILCOMPILER_H
