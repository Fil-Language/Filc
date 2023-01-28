/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_ENVIRONMENT_H
#define FILC_ENVIRONMENT_H

#include "Symbol.h"
#include <deque>

class Environment {
public:
    explicit Environment(Environment *parent = nullptr);

    ~Environment();

    static Environment *getGlobalEnvironment();

    Symbol *addSymbol(const std::string &name, Position *position, Symbol::SymbolType type);

    bool hasSymbol(const std::string &name, ast::AbstractType *signature = nullptr);

    Symbol *getSymbol(const std::string &name, ast::AbstractType *signature = nullptr);

    void setParent(Environment *parent);

private:
    Environment *_parent;
    std::deque<Symbol *> _symbols;
};


#endif //FILC_ENVIRONMENT_H
