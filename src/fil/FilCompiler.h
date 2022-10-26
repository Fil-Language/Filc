/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_FILCOMPILER_H
#define FILC_FILCOMPILER_H

#include "AST.h"
#include <string>

class FilCompiler {
public:
    explicit FilCompiler(std::string filename);

    int compile();

    static ast::Program import(const std::string& moduleName);

private:
    std::string _filename;
};


#endif //FILC_FILCOMPILER_H
