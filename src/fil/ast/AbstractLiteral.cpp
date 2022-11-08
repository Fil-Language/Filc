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

string AbstractLiteral::decompile(int indent) const {
    throw;
}

// ====================

Integer::Integer() : _value(0) {}

Integer::Integer(int value) : _value(value) {}

string Integer::decompile(int indent) const {
    return to_string(_value);
}

// ====================

Float::Float() : _value(0) {}

Float::Float(float value) : _value(value) {}

string Float::decompile(int indent) const {
    return to_string(_value);
}

// ====================

Double::Double() : _value(0) {}

Double::Double(double value) : _value(value) {}

string Double::decompile(int indent) const {
    return to_string(_value);
}

// ====================

String::String() = default;

String::String(const string &value) : _value(value) {}

string String::decompile(int indent) const {
    return "\"" + _value + "\"";
}

// ====================

FString::FString(const std::string &value) {
    _value = value;
}

string FString::decompile(int indent) const {
    return "f\"" + _value + "\n";
}

// ====================

Char::Char() : _value('\0') {}

Char::Char(char value) : _value(value) {}

string Char::decompile(int indent) const {
    return "'" + string(1, _value) + "'";
}

// ====================

AbstractBool::AbstractBool() = default;

string AbstractBool::decompile(int indent) const {
    throw;
}

// ====================

True::True() = default;

string True::decompile(int indent) const {
    return "true";
}

// ====================

False::False() = default;

string False::decompile(int indent) const {
    return "false";
}

// ====================

Null::Null() = default;

string Null::decompile(int indent) const {
    return "null";
}
