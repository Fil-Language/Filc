/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDecl::FunctionDecl() : _name(nullptr), _returnType(nullptr) {}

FunctionDecl::FunctionDecl(Identifier *name, vector<FunctionParam *> &params, Type *returnType)
        : _name(name), _params(params), _returnType(returnType) {}
