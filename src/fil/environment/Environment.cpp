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

    // TODO : add builtins types

    return globalEnvironment;
}

bool Environment::addFunction(const std::string &name, Position *position) {
    return _functions->addSymbol(name, position);
}

bool Environment::addVariable(const std::string &name, Position *position) {
    return _variables->addSymbol(name, position);
}

bool Environment::addType(const std::string &name, Position *position) {
    return _types->addSymbol(name, position);
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

void Environment::merge(Environment *environment) {
    _functions->merge(environment->_functions);
    _variables->merge(environment->_variables);
    _types->merge(environment->_types);
}
