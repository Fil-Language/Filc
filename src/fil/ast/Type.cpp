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
        : _name(name), _isArray(false), _isPointer(false), _arraySize(0), _subType(nullptr) {}

Type::Type(int arraySize, AbstractType *subType)
        : _name(nullptr), _isArray(true), _isPointer(false), _arraySize(arraySize), _subType(subType) {}

Type::Type(AbstractType *subType)
        : _name(nullptr), _isArray(false), _isPointer(true), _arraySize(0), _subType(subType) {}

Type::~Type() {
    delete _name;
    delete _subType;
}

string Type::decompile(int indent) const {
    if (_isPointer) {
        return _subType->decompile(indent) + "*";
    } else if (_isArray) {
        return _subType->decompile(indent) + "[" + to_string(_arraySize) + "]";
    } else {
        return _name->decompile(indent);
    }
}
