/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionDeclaration::FunctionDeclaration(Identifier *name, const vector<FunctionParam *> &params, AbstractType *type)
        : _name(name), _params(params), _type(type) {}

string FunctionDeclaration::decompile(int indent) const {
    string result = _name->decompile(indent);

    result += "(";
    for (auto it = _params.begin(); it != _params.end(); ++it) {
        result += (*it)->decompile(indent);
        if (it + 1 != _params.end()) {
            result += ", ";
        }
    }
    result += ")";

    if (_type) {
        result += " : " + _type->decompile(indent);
    }

    return result;
}

void FunctionDeclaration::resolveParams(Environment *function) {
    for (auto param: _params) {
        param->resolveSymbol(function);
    }
}

void FunctionDeclaration::inferParamsTypes(Environment *function) {
    auto paramsTypes = vector<AbstractType *>();

    for (auto param: _params) {
        paramsTypes.push_back(param->inferType(function));
    }

    _exprType = new LambdaType(paramsTypes, _type);
}

string FunctionDeclaration::dump(int indent) const {
    string res = string(indent, '\t') + "[FunctionDeclaration]" + (_isExported ? " <exported> " : " ")
                 + "<name:" + _name->getName() + "> "
                 + "<type:" + _exprType->getName() + ">\n";

    for (auto param: _params) {
        res += param->dump(indent + 1);
    }

    return res;
}
