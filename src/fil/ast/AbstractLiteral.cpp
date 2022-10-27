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

IndentPrinter *AbstractLiteral::print(IndentPrinter *printer) const {
    return printer->writeIndent("AbstractLiteral\n");
}

// ====================

Integer::Integer() : _value(0) {}

Integer::Integer(int value) : _value(value) {}

IndentPrinter *Integer::print(IndentPrinter *printer) const {
    return printer->writeIndent("Integer: ")->write(to_string(_value))->write("\n");
}

// ====================

Float::Float() : _value(0) {}

Float::Float(float value) : _value(value) {}

IndentPrinter *Float::print(IndentPrinter *printer) const {
    return printer->writeIndent("Float: ")->write(to_string(_value))->write("\n");
}

// ====================

Double::Double() : _value(0) {}

Double::Double(double value) : _value(value) {}

IndentPrinter *Double::print(IndentPrinter *printer) const {
    return printer->writeIndent("Double: ")->write(to_string(_value))->write("\n");
}

// ====================

String::String() = default;

String::String(const string &value) : _value(value) {}

IndentPrinter *String::print(IndentPrinter *printer) const {
    return printer->writeIndent("String: ")->write(_value)->write("\n");
}

// ====================

FString::FString(const std::string &value) {
    _value = value;
}

IndentPrinter *FString::print(IndentPrinter *printer) const {
    return printer->writeIndent("FString: ")->write(_value)->write("\n");
}

// ====================

Char::Char() : _value('\0') {}

Char::Char(char value) : _value(value) {}

IndentPrinter *Char::print(IndentPrinter *printer) const {
    return printer->writeIndent("Char: ")->write(to_string(_value))->write("\n");
}

// ====================

AbstractBool::AbstractBool() = default;

IndentPrinter *AbstractBool::print(IndentPrinter *printer) const {
    return printer->writeIndent("AbstractBool\n");
}

// ====================

True::True() = default;

IndentPrinter *True::print(IndentPrinter *printer) const {
    return printer->writeIndent("True\n");
}

// ====================

False::False() = default;

IndentPrinter *False::print(IndentPrinter *printer) const {
    return printer->writeIndent("False\n");
}

// ====================

Null::Null() = default;

IndentPrinter *Null::print(IndentPrinter *printer) const {
    return printer->writeIndent("Null\n");
}
