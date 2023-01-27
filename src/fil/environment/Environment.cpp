/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Environment.h"
#include "AST.hpp"

Environment::Environment(Environment *parent)
        : _parent(parent) {
    _symbols = std::deque<Symbol *>();
}

Environment::~Environment() = default;

Environment *Environment::getGlobalEnvironment() {
    auto *globalEnvironment = new Environment();

    // Add builtins types
    globalEnvironment->addSymbol("int", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new ast::Type(new ast::Identifier("int")));
    globalEnvironment->addSymbol("float", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new ast::Type(new ast::Identifier("float")));
    globalEnvironment->addSymbol("char", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new ast::Type(new ast::Identifier("char")));
    globalEnvironment->addSymbol("bool", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new ast::Type(new ast::Identifier("bool")));
    // FIXME : temporary, to be removed later as string is part of stl
    globalEnvironment->addSymbol("string", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new ast::Type(new ast::Identifier("string")));
    globalEnvironment->addSymbol("void", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new ast::Type(new ast::Identifier("void")));

    return globalEnvironment;
}

Symbol *Environment::addSymbol(const std::string &name, Position *position, Symbol::SymbolType type) {
    auto *symbol = new Symbol(name, position, type);
    _symbols.push_back(symbol);

    return symbol;
}

bool Environment::hasSymbol(const std::string &name, ast::AbstractType *signature) {
    if (std::any_of(_symbols.begin(), _symbols.end(), [name, signature](Symbol *symbol) {
        if (signature == nullptr)
            return symbol->getName() == name;
        else
            return symbol->getName() == name && symbol->getSignature() == signature;
    })) {
        return true;
    }

    if (_parent != nullptr) {
        return _parent->hasSymbol(name, signature);
    }

    return false;
}

Symbol *Environment::getSymbol(const std::string &name, ast::AbstractType *signature) {
    auto it = std::find_if(_symbols.begin(), _symbols.end(), [name, signature](Symbol *symbol) {
        if (signature == nullptr)
            return symbol->getName() == name;
        else
            return symbol->getName() == name && symbol->getSignature() == signature;
    });

    if (it != _symbols.end()) {
        return *it;
    }

    if (_parent != nullptr) {
        return _parent->getSymbol(name, signature);
    }

    return nullptr;
}

void Environment::merge(Environment *environment) {
    exit(42); // TODO : implement
}
