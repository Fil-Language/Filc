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

    Symbol *addFunction(const std::string &name, Position *position);

    Symbol *addFunction(Symbol *symbol);

    Symbol *addVariable(const std::string &name, Position *position);

    Symbol *addVariable(Symbol *symbol);

    Symbol *addType(const std::string &name, Position *position);

    bool hasSymbol(const std::string &name) const;

    bool hasFunction(const std::string &name) const;

    bool hasVariable(const std::string &name) const;

    Symbol *getSymbol(const std::string &name) const;

    bool hasType(const std::string &name) const;

    void merge(Environment *environment);

private:
    Environment *_parent;

    SymbolTable *_functions;
    SymbolTable *_variables;
    SymbolTable *_types;
};


#endif //FILC_ENVIRONMENT_H
