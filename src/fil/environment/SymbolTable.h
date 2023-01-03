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
#include "AST_decl.h"

class Symbol {
public:
    Symbol(const std::string &name, Position *position);

    ~Symbol();

    std::string getName() const;

    Position *getPosition() const;

    ast::AbstractType *getType() const;

    void setType(ast::AbstractType *type);

private:
    std::string _name;
    Position *_position;
    ast::AbstractType *_type;
};

class SymbolTable {
public:
    SymbolTable();

    ~SymbolTable();

    Symbol *addSymbol(const std::string &name, Position *position);

    Symbol *addSymbol(Symbol *symbol);

    bool hasSymbol(const std::string &name) const;

    Symbol *getSymbol(const std::string &name) const;

    void merge(SymbolTable *symbolTable);

private:
    std::map<std::string, Symbol *> _symbols;
};

#endif //FILC_SYMBOLTABLE_H
