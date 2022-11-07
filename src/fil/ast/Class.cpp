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

// ====================

ClassVariable::ClassVariable() : _decl(nullptr) {}

ClassVariable::ClassVariable(const string &visibility, VariableDecl *decl)
        : _visibility(visibility), _decl(decl) {}

ClassVariable::~ClassVariable() {
    delete _decl;
}

// ====================

ClassFunction::ClassFunction() : _function(nullptr) {}

ClassFunction::ClassFunction(const std::string &modifier, const std::string &visibility, ast::AST *function)
        : _modifier(modifier), _visibility(visibility), _function(function) {}

ClassFunction::~ClassFunction() {
    delete _function;
}
