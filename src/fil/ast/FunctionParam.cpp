/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionParam::FunctionParam() : _name(nullptr), _type(nullptr) {}

FunctionParam::FunctionParam(Identifier *name, Type *type) : _name(name), _type(type) {}
