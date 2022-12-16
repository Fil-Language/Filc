/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Type::Type(const std::string &name)
        : _name(name), _isArray(false), _isPointer(false), _arraySize(0), _subType(nullptr) {}

Type::Type(int arraySize, Type *subType)
        : _isArray(true), _isPointer(false), _arraySize(arraySize), _subType(subType) {}

Type::Type(Type *subType)
        : _isArray(false), _isPointer(true), _arraySize(0), _subType(subType) {}

string Type::decompile(int indent) const {
    if (_isPointer) {
        return _subType->decompile(indent) + "*";
    } else if (_isArray) {
        return _subType->decompile(indent) + "[" + to_string(_arraySize) + "]";
    } else {
        return _name;
    }
}
