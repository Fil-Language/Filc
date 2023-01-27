/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Type::Type(Identifier *name)
        : _name(name), _isArray(false), _arraySize(0), _isPointer(false), _subType(nullptr) {}

Type::Type(int arraySize, AbstractType *subType)
        : _name(nullptr), _isArray(true), _arraySize(arraySize), _isPointer(false), _subType(subType) {}

Type::Type(AbstractType *subType)
        : _name(nullptr), _isArray(false), _arraySize(0), _isPointer(true), _subType(subType) {}

string Type::decompile(int indent) const {
    if (_isPointer) {
        return _subType->decompile(indent) + "*";
    } else if (_isArray) {
        return _subType->decompile(indent) + "[" + to_string(_arraySize) + "]";
    } else {
        return _name->decompile(indent);
    }
}

string Type::getName() const {
    if (_isPointer) {
        return _subType->getName() + "*";
    } else if (_isArray) {
        return _subType->getName() + "[" + to_string(_arraySize) + "]";
    } else {
        return _name->getName();
    }
}

bool Type::isIterable() const {
    return _isArray;
}

AbstractType *Type::getIterableType() {
    if (isIterable()) {
        return _subType;
    } else {
        return AbstractType::getIterableType();
    }
}
