/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Class::Class() : _name(nullptr) {};

Class::Class(const string &modifier, ClassIdentifier *name, vector<ClassParam *> &params)
        : _modifier(modifier), _name(name), _params(params) {}

IndentPrinter *Class::print(IndentPrinter *printer) const {
    printer->writeIndent("Class => [")
            ->write(_modifier)
            ->write("] ");

    if (_name) {
        _name->print(printer);
        printer->write(" ");
    }

    if (!_params.empty()) {
        printer->write("(");
        for (auto it = _params.begin(); it != _params.end(); ++it) {
            (*it)->print(printer);
            if (it != _params.end() - 1) {
                printer->write(", ");
            }
        }
        printer->write(")");
    }

    return printer->write("\n");
}

// ====================

ClassIdentifier::ClassIdentifier() = default;

ClassIdentifier::ClassIdentifier(const string &name, vector<string> &generics)
        : _name(name), _generics(generics) {}

IndentPrinter *ClassIdentifier::print(IndentPrinter *printer) const {
    printer->write(_name);

    if (!_generics.empty()) {
        printer->write("<");
        for (auto it = _generics.begin(); it != _generics.end(); ++it) {
            printer->write(*it);
            if (it != _generics.end() - 1)
                printer->write(", ");
        }
        printer->write(">");
    }

    return printer;
}

// ====================

ClassParam::ClassParam()
        : _isDecl(false), _decl(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(AbstractExpr *decl)
        : _isDecl(true), _decl(decl), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(const string &name, Type *type, AbstractLiteral *defaultValue)
        : _isDecl(false), _decl(nullptr), _name(name), _type(type), _defaultValue(defaultValue) {}

IndentPrinter *ClassParam::print(IndentPrinter *printer) const {
    if (_isDecl) {
        _decl->print(printer);
    } else {
        printer->write(_name);
        if (_type)
            _type->print(printer);
        if (_defaultValue)
            _defaultValue->print(printer);
    }

    return printer;
}
