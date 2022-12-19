/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_ENVIRONMENT_H
#define FILC_ENVIRONMENT_H

#include "SymbolTable.h"

class Environment {
public:
    explicit Environment(Environment *parent = nullptr);

    ~Environment();

    static Environment *getGlobalEnvironment();

    bool addFunction(const std::string &name, Position *position);

    bool addVariable(const std::string &name, Position *position);

    bool hasFunction(const std::string &name) const;

    bool hasVariable(const std::string &name) const;

private:
    Environment *_parent;

    SymbolTable *_functions;
    SymbolTable *_variables;
};


#endif //FILC_ENVIRONMENT_H
