/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_SYMBOLTABLE_H
#define FILC_SYMBOLTABLE_H

#include <string>
#include <map>
#include "utils.h"

class Symbol {
public:
    Symbol(const std::string &name, Position *position);

    ~Symbol();

    std::string getName() const;

    Position *getPosition() const;

private:
    std::string _name;
    Position *_position;
};

class SymbolTable {
public:
    SymbolTable();

    ~SymbolTable();

    bool addSymbol(const std::string &name, Position *position);

    bool hasSymbol(const std::string &name) const;

private:
    std::map<std::string, Symbol *> _symbols;
};

#endif //FILC_SYMBOLTABLE_H
