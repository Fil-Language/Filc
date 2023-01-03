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
    _functions = new SymbolTable();
    _variables = new SymbolTable();
    _types = new SymbolTable();
}

Environment::~Environment() {
    delete _functions;
    delete _variables;
    delete _types;
}

Environment *Environment::getGlobalEnvironment() {
    auto *globalEnvironment = new Environment();

    // Add builtins types
    globalEnvironment->addType("int", new Position(0, 0, "builtin"));
    globalEnvironment->getSymbol("int")->setType(new ast::Type(new ast::Identifier("int")));
    globalEnvironment->addType("float", new Position(0, 0, "builtin"));
    globalEnvironment->getSymbol("float")->setType(new ast::Type(new ast::Identifier("float")));
    globalEnvironment->addType("char", new Position(0, 0, "builtin"));
    globalEnvironment->getSymbol("char")->setType(new ast::Type(new ast::Identifier("char")));
    globalEnvironment->addType("bool", new Position(0, 0, "builtin"));
    globalEnvironment->getSymbol("bool")->setType(new ast::Type(new ast::Identifier("bool")));
    globalEnvironment->addType("string", new Position(0, 0,
                                                      "builtin")); // FIXME : temporary, to be removed later as string is part of stl
    globalEnvironment->getSymbol("string")->setType(new ast::Type(new ast::Identifier("string")));

    return globalEnvironment;
}

Symbol *Environment::addFunction(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    return _functions->addSymbol(name, position);
}

Symbol *Environment::addFunction(Symbol *symbol) {
    if (hasSymbol(symbol->getName())) {
        return nullptr;
    }

    return _functions->addSymbol(symbol);
}

Symbol *Environment::addVariable(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    return _variables->addSymbol(name, position);
}

Symbol *Environment::addVariable(Symbol *symbol) {
    if (hasSymbol(symbol->getName())) {
        return nullptr;
    }

    return _variables->addSymbol(symbol);
}

Symbol *Environment::addType(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    return _types->addSymbol(name, position);
}

bool Environment::hasSymbol(const std::string &name) const {
    return _functions->hasSymbol(name)
           || _variables->hasSymbol(name)
           || _types->hasSymbol(name)
           || (_parent && _parent->hasSymbol(name));
}

bool Environment::hasFunction(const std::string &name) const {
    return _functions->hasSymbol(name) || (_parent && _parent->hasFunction(name));
}

bool Environment::hasVariable(const std::string &name) const {
    return _variables->hasSymbol(name) || (_parent && _parent->hasVariable(name));
}

bool Environment::hasType(const std::string &name) const {
    return _types->hasSymbol(name) || (_parent && _parent->hasType(name));
}

Symbol *Environment::getSymbol(const std::string &name) const {
    if (_functions->hasSymbol(name)) {
        auto s = _functions->getSymbol(name);
        return s != nullptr ? s : _parent->getSymbol(name);
    } else if (_variables->hasSymbol(name)) {
        auto s = _variables->getSymbol(name);
        return s != nullptr ? s : _parent->getSymbol(name);
    } else if (_types->hasSymbol(name)) {
        auto s = _types->getSymbol(name);
        return s != nullptr ? s : _parent->getSymbol(name);
    } else if (_parent) {
        return _parent->getSymbol(name);
    }

    return nullptr;
}

void Environment::merge(Environment *environment) {
    _functions->merge(environment->_functions);
    _variables->merge(environment->_variables);
    _types->merge(environment->_types);
}
