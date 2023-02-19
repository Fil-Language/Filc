/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#ifndef FILC_SYMBOL_H
#define FILC_SYMBOL_H

#include <string>
#include "utils.h"
#include "AST_decl.h"

class Symbol {
public:
    enum SymbolKind {
        FUNCTION,
        VARIABLE,
        TYPE
    };

public:
    Symbol(const std::string &name, Position *position, SymbolKind kind);

    ~Symbol();

    std::string getName() const;

    Position *getPosition() const;

    SymbolKind getKind() const;

    ast::AbstractType *getSignature() const;

    ast::AbstractType *setSignature(ast::AbstractType *signature);

    bool operator==(const Symbol &b) const;

    bool operator!=(const Symbol &b) const;

private:
    std::string _name;
    Position *_position;
    SymbolKind _kind;
    ast::AbstractType *_signature;
};

#endif //FILC_SYMBOL_H
