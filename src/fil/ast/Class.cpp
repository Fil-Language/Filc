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

// ====================

ClassIdentifier::ClassIdentifier() = default;

ClassIdentifier::ClassIdentifier(const string &name, vector<Type *> &generics)
        : _generics(generics) {
    _name = name;
}

// ====================

ClassParam::ClassParam()
        : _isDecl(false), _decl(nullptr), _name(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(VariableDecl *decl)
        : _isDecl(true), _decl(decl), _name(nullptr), _type(nullptr), _defaultValue(nullptr) {}

ClassParam::ClassParam(Identifier *name, Type *type, AbstractLiteral *defaultValue)
        : _isDecl(false), _decl(nullptr), _name(name), _type(type), _defaultValue(defaultValue) {}

// ====================

ClassExtend::ClassExtend() : _identifier(nullptr) {}

ClassExtend::ClassExtend(ClassIdentifier *identifier, vector<AbstractExpr *> &args)
        : _identifier(identifier), _args(args) {}

// ====================

ClassVariable::ClassVariable() : _decl(nullptr) {}

ClassVariable::ClassVariable(const string &visibility, VariableDecl *decl)
        : _visibility(visibility), _decl(decl) {}

// ====================

ClassFunction::ClassFunction() : _function(nullptr) {}

ClassFunction::ClassFunction(const std::string &modifier, const std::string &visibility, ast::AST *function)
        : _modifier(modifier), _visibility(visibility), _function(function) {}
