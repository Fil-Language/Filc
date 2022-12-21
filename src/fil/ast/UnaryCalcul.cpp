/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

UnaryCalcul::UnaryCalcul(Identifier *identifier, Operator *op)
        : _op(op), _identifier(identifier), _isPrefix(false) {}

UnaryCalcul::UnaryCalcul(Operator *op, Identifier *identifier)
        : _op(op), _identifier(identifier), _isPrefix(true) {}

UnaryCalcul::~UnaryCalcul() {
    delete _op;
    delete _identifier;
}

std::string UnaryCalcul::decompile(int indent) const {
    if (_isPrefix) {
        return _op->decompile(indent) + _identifier->decompile(indent);
    } else {
        return _identifier->decompile(indent) + _op->decompile(indent);
    }
}

void UnaryCalcul::resolveEnvironment(Environment *parent) {
    // Nothing to do
}

AbstractType *UnaryCalcul::inferType(Environment *env) {
    _exprType = _identifier->inferType(env);

    return _exprType;
}

string UnaryCalcul::dump(int indent) const {
    string res = string(indent, '\t') + "[UnaryCalcul]"
                 + (_isExported ? " <exported> " : " ")
                 + (_isPrefix ? "<prefix>" : "<postfix>")
                 + " <operator:" + _op->decompile(indent) + ">"
                 + " <type:" + _exprType->getName() + ">\n";

    res += _identifier->dump(indent + 1);

    return res;
}
