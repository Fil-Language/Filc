/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Type::Type() : _isPointer(false), _isArray(false), _arraySize(0) {}

Type::Type(const std::string &name)
        : _name(name), _isPointer(false), _isArray(false), _arraySize(0) {}

Type::Type(const std::string &name, bool isPointer)
        : _name(name), _isPointer(isPointer), _isArray(false), _arraySize(0) {}

Type::Type(const std::string &name, int arraySize)
        : _name(name), _isPointer(false), _isArray(true), _arraySize(arraySize) {}

string Type::decompile(int indent) const {
    if (_isPointer) {
        return _name + "*";
    } else if (_isArray) {
        return _name + "[" + to_string(_arraySize) + "]";
    } else {
        return _name;
    }
}
