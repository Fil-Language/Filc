/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_SYMBOL_H
#define FILC_SYMBOL_H

#include <string>
#include "utils.h"
#include "AST_decl.h"

class Symbol {
public:
    enum SymbolType {
        FUNCTION,
        VARIABLE,
        TYPE
    };

public:
    Symbol(const std::string &name, Position *position, SymbolType type);

    ~Symbol();

    std::string getName() const;

    Position *getPosition() const;

    SymbolType getType() const;

    ast::AbstractType *getSignature() const;

    void setSignature(ast::AbstractType *signature);

    bool operator==(const Symbol &b) const;

    bool operator!=(const Symbol &b) const;

private:
    std::string _name;
    Position *_position;
    SymbolType _type;
    ast::AbstractType *_signature;
};

#endif //FILC_SYMBOL_H
