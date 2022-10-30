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

Class::Class(const string &modifier,
             ClassIdentifier *name,
             vector<ClassParam *> &params,
             vector<ClassExtend *> &extends)
        : _modifier(modifier), _name(name), _params(params), _extends(extends) {}

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

ClassIdentifier::ClassIdentifier(const string &name, vector<Type *> &generics)
        : _generics(generics) {
    _name = name;
}

IndentPrinter *ClassIdentifier::print(IndentPrinter *printer) const {
    printer->write(_name);

    if (!_generics.empty()) {
        printer->write("<");
        for (auto it = _generics.begin(); it != _generics.end(); ++it) {
            (*it)->print(printer);
            if (it != _generics.end() - 1)
                printer->write(", ");
        }
        printer->write(">");
    }

    return printer;
}

// ====================

ClassParam::ClassParam()
        : _isDecl(false), _decl(nullptr), _name(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(AbstractExpr *decl)
        : _isDecl(true), _decl(decl), _name(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(Identifier *name, Type *type, AbstractLiteral *defaultValue)
        : _isDecl(false), _decl(nullptr), _name(name), _type(type), _defaultValue(defaultValue) {}

IndentPrinter *ClassParam::print(IndentPrinter *printer) const {
    if (_isDecl) {
        _decl->print(printer);
    } else {
        _name->print(printer);
        if (_type)
            _type->print(printer);
        if (_defaultValue)
            _defaultValue->print(printer);
    }

    return printer;
}

// ====================

ClassExtend::ClassExtend() : _identifier(nullptr) {}

ClassExtend::ClassExtend(ClassIdentifier *identifier)
        : _identifier(identifier) {}

IndentPrinter *ClassExtend::print(IndentPrinter *printer) const {
    _identifier->print(printer);

    return printer;
}
