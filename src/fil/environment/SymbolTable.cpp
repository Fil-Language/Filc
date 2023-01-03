/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    _symbols = std::map<std::string, Symbol *>();
}

SymbolTable::~SymbolTable() {
    for (auto &symbol: _symbols) {
        delete symbol.second;
    }
}

Symbol *SymbolTable::addSymbol(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    auto symbol = new Symbol(name, position);
    _symbols[name] = symbol;

    return symbol;
}

Symbol *SymbolTable::addSymbol(Symbol *symbol) {
    if (hasSymbol(symbol->getName())) {
        return nullptr;
    }

    _symbols[symbol->getName()] = symbol;

    return symbol;
}

bool SymbolTable::hasSymbol(const std::string &name) const {
    return _symbols.find(name) != _symbols.end();
}

Symbol *SymbolTable::getSymbol(const std::string &name) const {
    return _symbols.at(name);
}

void SymbolTable::merge(SymbolTable *symbolTable) {
    for (auto &symbol: symbolTable->_symbols) {
        _symbols[symbol.first] = symbol.second;
    }
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

Symbol::Symbol(const std::string &name, Position *position)
        : _name(name), _position(position), _type(nullptr) {}

Symbol::~Symbol() {
    delete _position;
}

std::string Symbol::getName() const {
    return _name;
}

Position *Symbol::getPosition() const {
    return _position;
}

ast::AbstractType *Symbol::getType() const {
    return _type;
}

void Symbol::setType(ast::AbstractType *type) {
    _type = type;
}
