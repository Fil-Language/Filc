/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Symbol.h"

using namespace std;
using namespace ast;

Symbol::Symbol(const string &name, Position *position, SymbolType type)
        : _name(name), _position(position), _type(type), _signature(nullptr) {}

Symbol::~Symbol() {
    delete _position;
}

std::string Symbol::getName() const {
    return _name;
}

Position *Symbol::getPosition() const {
    return _position;
}

Symbol::SymbolType Symbol::getType() const {
    return _type;
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
           _type == b._type &&
           _signature == b._signature;
}

bool Symbol::operator!=(const Symbol &b) const {
    return !(b == *this);
}
