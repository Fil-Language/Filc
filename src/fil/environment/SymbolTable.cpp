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

bool SymbolTable::addSymbol(const std::string &name, Position *position) {
    if (_symbols.find(name) != _symbols.end()) {
        return false;
    }

    _symbols[name] = new Symbol(name, position);

    return true;
}

bool SymbolTable::hasSymbol(const std::string &name) const {
    return _symbols.find(name) != _symbols.end();
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

Symbol::Symbol(const std::string &name, Position *position)
        : _name(name), _position(position) {}

Symbol::~Symbol() {
    delete _position;
}

std::string Symbol::getName() const {
    return _name;
}

Position *Symbol::getPosition() const {
    return _position;
}
