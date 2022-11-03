/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Class::Class() : _name(nullptr), _constructor(nullptr) {}

Class::Class(const string &modifier,
             ClassIdentifier *name,
             vector<ClassParam *> &params,
             vector<ClassExtend *> &extends,
             ExprBlock *constructor,
             vector<ClassVariable *> &variables,
             vector<ClassFunction *> &functions)
        : _modifier(modifier),
          _name(name),
          _params(params),
          _extends(extends),
          _constructor(constructor),
          _variables(variables),
          _functions(functions) {}

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
        printer->write(") ");
    }

    if (!_extends.empty()) {
        printer->write(": ");
        for (auto it = _extends.begin(); it != _extends.end(); it++) {
            (*it)->print(printer);
            if (it != _extends.end() - 1) {
                printer->write(", ");
            }
        }
    }

    printer->write("\n")
            ->indent();

    if (_constructor) {
        printer->writeIndent("Constructor =>\n")
                ->indent();
        _constructor->print(printer);
        printer->unindent();
    }

    if (!_variables.empty()) {
        printer->writeIndent("Variables =>\n")
                ->indent();
        for (auto _variable: _variables) {
            _variable->print(printer);
        }
        printer->unindent();
    }

    return printer->unindent()
            ->write("\n");
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

ClassParam::ClassParam(VariableDecl *decl)
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

ClassExtend::ClassExtend(ClassIdentifier *identifier, vector<AbstractExpr *> &args)
        : _identifier(identifier), _args(args) {}

IndentPrinter *ClassExtend::print(IndentPrinter *printer) const {
    _identifier->print(printer);

    return printer;
}

// ====================

ClassVariable::ClassVariable() : _decl(nullptr) {}

ClassVariable::ClassVariable(const string &visibility, VariableDecl *decl)
        : _visibility(visibility), _decl(decl) {}

IndentPrinter *ClassVariable::print(IndentPrinter *printer) const {
    printer->writeIndent(_visibility);

    return printer->write("\n");
}

// ====================

ClassFunction::ClassFunction() : _function(nullptr) {}

ClassFunction::ClassFunction(const std::string &modifier, const std::string &visibility, ast::AST *function)
        : _modifier(modifier), _visibility(visibility), _function(function) {}

IndentPrinter *ClassFunction::print(IndentPrinter *printer) const {
    printer->writeIndent(_modifier)
            ->write(" ")
            ->write(_visibility)
            ->write(" =>\n")
            ->indent();

    _function->print(printer);

    return printer->unindent();
}
