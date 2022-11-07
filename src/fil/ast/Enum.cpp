/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Enum::Enum() : _name(nullptr) {}

Enum::Enum(Identifier *name, vector<Identifier *> &values)
        : _name(name), _values(values) {}
