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

Class::~Class() {
    delete _name;
    delete _constructor;
    for (auto &param: _params) {
        delete param;
    }
    for (auto &extend: _extends) {
        delete extend;
    }
    for (auto &variable: _variables) {
        delete variable;
    }
    for (auto &function: _functions) {
        delete function;
    }
}

string Class::decompile(int indent) const {
    string res = _modifier + " class " + _name->decompile(indent);

    // Params
    res += "(";
    if (!_params.empty()) {
        for (auto it = _params.begin(); it != _params.end(); it++) {
            res += (*it)->decompile(indent);
            if (it != _params.end() - 1) {
                res += ", ";
            }
        }
    }
    res += ")";

    // Extends
    if (!_extends.empty()) {
        res += " : ";
        for (auto it = _extends.begin(); it != _extends.end(); it++) {
            res += (*it)->decompile(indent);
            if (it != _extends.end() - 1) {
                res += ", ";
            }
        }
    }

    if (_constructor || !_variables.empty() || !_functions.empty()) {
        res += " {\n";
        if (_constructor) {
            res += _constructor->decompile(indent + 1);
        }
        for (auto &variable: _variables) {
            res += variable->decompile(indent + 1);
        }
        for (auto &function: _functions) {
            res += function->decompile(indent + 1);
        }
        res += "}";
    }

    return res;
}

// ====================

ClassIdentifier::ClassIdentifier() = default;

ClassIdentifier::ClassIdentifier(const string &name, vector<Type *> &generics)
        : _generics(generics) {
    _name = name;
}

ClassIdentifier::~ClassIdentifier() {
    for (auto &generic: _generics) {
        delete generic;
    }
}

string ClassIdentifier::decompile(int indent) const {
    string res = _name;
    if (!_generics.empty()) {
        res += "<";
        for (auto it = _generics.begin(); it != _generics.end(); it++) {
            res += (*it)->decompile(indent);
            if (it != _generics.end() - 1) {
                res += ", ";
            }
        }
        res += ">";
    }

    return res;
}

// ====================

ClassParam::ClassParam()
        : _isDecl(false), _decl(nullptr), _name(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(VariableDecl *decl)
        : _isDecl(true), _decl(decl), _name(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(Identifier *name, Type *type, AbstractLiteral *defaultValue)
        : _isDecl(false), _decl(nullptr), _name(name), _type(type), _defaultValue(defaultValue) {}

ClassParam::~ClassParam() {
    if (_isDecl) {
        delete _decl;
    } else {
        delete _name;
        delete _type;
        delete _defaultValue;
    }
}

string ClassParam::decompile(int indent) const {
    if (_isDecl) {
        return _decl->decompile(indent);
    } else {
        return _name->decompile(indent) + ": " + _type->decompile(indent) +
               (_defaultValue ? " = " + _defaultValue->decompile(indent) : "");
    }
}

// ====================

ClassExtend::ClassExtend() : _identifier(nullptr) {}

ClassExtend::ClassExtend(ClassIdentifier *identifier, vector<AbstractExpr *> &args)
        : _identifier(identifier), _args(args) {}

ClassExtend::~ClassExtend() {
    delete _identifier;
    for (auto &arg: _args) {
        delete arg;
    }
}

string ClassExtend::decompile(int indent) const {
    string res = _identifier->decompile(indent);
    if (!_args.empty()) {
        res += "(";
        for (auto it = _args.begin(); it != _args.end(); it++) {
            res += (*it)->decompile(indent);
            if (it != _args.end() - 1) {
                res += ", ";
            }
        }
        res += ")";
    }

    return res;
}

// ====================

ClassVariable::ClassVariable() : _decl(nullptr) {}

ClassVariable::ClassVariable(const string &visibility, VariableDecl *decl)
        : _visibility(visibility), _decl(decl) {}

ClassVariable::~ClassVariable() {
    delete _decl;
}

string ClassVariable::decompile(int indent) const {
    return _visibility + " " + _decl->decompile(indent) + ";\n";
}

// ====================

ClassFunction::ClassFunction() : _function(nullptr) {}

ClassFunction::ClassFunction(const std::string &modifier, const std::string &visibility, ast::AST *function)
        : _modifier(modifier), _visibility(visibility), _function(function) {}

ClassFunction::~ClassFunction() {
    delete _function;
}

string ClassFunction::decompile(int indent) const {
    string res;
    if (!_modifier.empty()) {
        res += _modifier + " ";
    }
    if (!_visibility.empty()) {
        res += _visibility + " ";
    }

    return res + _function->decompile(indent);
}
