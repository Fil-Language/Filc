/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Environment.h"

Environment::Environment(Environment *parent)
        : _parent(parent) {
    _functions = new SymbolTable();
    _variables = new SymbolTable();
    _types = new SymbolTable();
}

Environment::~Environment() {
    delete _parent;
    delete _functions;
    delete _variables;
    delete _types;
}

Environment *Environment::getGlobalEnvironment() {
    static auto *globalEnvironment = new Environment();

    // Add builtins types
    globalEnvironment->addType("int", new Position(0, 0, "builtin"));
    globalEnvironment->addType("float", new Position(0, 0, "builtin"));
    globalEnvironment->addType("char", new Position(0, 0, "builtin"));
    globalEnvironment->addType("bool", new Position(0, 0, "builtin"));

    return globalEnvironment;
}

Symbol *Environment::addFunction(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    return _functions->addSymbol(name, position);
}

Symbol *Environment::addVariable(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    return _variables->addSymbol(name, position);
}

Symbol *Environment::addType(const std::string &name, Position *position) {
    if (hasSymbol(name)) {
        return nullptr;
    }

    return _types->addSymbol(name, position);
}

bool Environment::hasSymbol(const std::string &name) const {
    return _functions->hasSymbol(name) || _variables->hasSymbol(name) || _types->hasSymbol(name);
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
        return _functions->getSymbol(name);
    } else if (_variables->hasSymbol(name)) {
        return _variables->getSymbol(name);
    } else if (_types->hasSymbol(name)) {
        return _types->getSymbol(name);
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
