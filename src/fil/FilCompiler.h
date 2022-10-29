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

class FilCompiler {
public:
    explicit FilCompiler(std::string filename);

    int compile(int flag);

    static ast::Program *import(const std::string &moduleName);

private:
    std::string _filename;
};

typedef enum FLAGS {
    AST,
} FLAGS;


#endif //FILC_FILCOMPILER_H
