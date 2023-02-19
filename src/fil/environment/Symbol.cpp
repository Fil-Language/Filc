/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Symbol.h"

using namespace std;
using namespace ast;

Symbol::Symbol(const string &name, Position *position, SymbolKind kind)
        : _name(name), _position(position), _kind(kind), _signature(nullptr) {}

Symbol::~Symbol() {
    delete _position;
}

std::string Symbol::getName() const {
    return _name;
}

Position *Symbol::getPosition() const {
    return _position;
}

Symbol::SymbolKind Symbol::getKind() const {
    return _kind;
}

ast::AbstractType *Symbol::getSignature() const {
    return _signature;
}

AbstractType *Symbol::setSignature(AbstractType *signature) {
    _signature = signature;

    return _signature;
}

bool Symbol::operator==(const Symbol &b) const {
    return _name == b._name &&
           _kind == b._kind &&
           _signature == b._signature;
}

bool Symbol::operator!=(const Symbol &b) const {
    return !(b == *this);
}
