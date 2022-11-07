/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AbstractLiteral::AbstractLiteral() = default;

// ====================

Integer::Integer() : _value(0) {}

Integer::Integer(int value) : _value(value) {}

// ====================

Float::Float() : _value(0) {}

Float::Float(float value) : _value(value) {}

// ====================

Double::Double() : _value(0) {}

Double::Double(double value) : _value(value) {}

// ====================

String::String() = default;

String::String(const string &value) : _value(value) {}

// ====================

FString::FString(const std::string &value) {
    _value = value;
}

// ====================

Char::Char() : _value('\0') {}

Char::Char(char value) : _value(value) {}

// ====================

AbstractBool::AbstractBool() = default;

// ====================

True::True() = default;

// ====================

False::False() = default;

// ====================

Null::Null() = default;
