/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Environment.h"

Environment::Environment(Environment *parent)
        : _parent(parent) {}

Environment::~Environment() {
    delete _parent;
}

Environment *Environment::getGlobalEnvironment() {
    static auto *globalEnvironment = new Environment();

    return globalEnvironment;
}
