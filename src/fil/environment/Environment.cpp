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
}

Environment::~Environment() {
    delete _parent;
    delete _functions;
    delete _variables;
}

Environment *Environment::getGlobalEnvironment() {
    static auto *globalEnvironment = new Environment();

    return globalEnvironment;
}

bool Environment::addFunction(const std::string &name, Position *position) {
    return _functions->addSymbol(name, position);
}

bool Environment::addVariable(const std::string &name, Position *position) {
    return _variables->addSymbol(name, position);
}

bool Environment::hasFunction(const std::string &name) const {
    return _functions->hasSymbol(name);
}

bool Environment::hasVariable(const std::string &name) const {
    return _variables->hasSymbol(name);
}

void Environment::merge(Environment *environment) {
    _functions->merge(environment->_functions);
    _variables->merge(environment->_variables);
}
