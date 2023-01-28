/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionParam::FunctionParam(Identifier *name, AbstractType *type)
        : _name(name), _type(type) {}

string FunctionParam::decompile(int indent) const {
    string result = _name->decompile(indent);

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}

Symbol *FunctionParam::resolveSymbol(Environment *function) {
    return _name->resolveVar(function);
}

AbstractType *FunctionParam::inferType(Environment *function) const {
    function->getSymbol(_name->getName())->setSignature(_type);

    return _type;
}

string FunctionParam::dump(int indent) const {
    return string(indent, '\t') + "[FunctionParam] <name:" + _name->getName() + "> <type:" + _type->getName() + ">\n";
}
