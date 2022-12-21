/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

bool AbstractType::equals(const AbstractType &other) const {
    return getName() == other.getName();
}

bool AbstractType::isIterable() const {
    return false;
}

AbstractType *AbstractType::getIterableType() {
    return this;
}

bool operator==(const AbstractType &a, const AbstractType &b) {
    return a.equals(b);
}

bool operator!=(const AbstractType &a, const AbstractType &b) {
    return !a.equals(b);
}
