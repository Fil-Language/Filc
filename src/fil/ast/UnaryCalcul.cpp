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

std::string UnaryCalcul::decompile(int indent) const {
    if (_isPrefix) {
        return _op->decompile(indent) + _identifier->decompile(indent);
    } else {
        return _identifier->decompile(indent) + _op->decompile(indent);
    }
}

Symbol *UnaryCalcul::resolveSymbols(Environment *parent) {
    return _identifier->resolveSymbols(parent);
}

AbstractType *UnaryCalcul::inferType(Environment *parent) {
    auto type = _identifier->inferType(parent);

    if (_op->getOp() == Operator::ARRAY && !type->isIterable()) {
        auto operators = parent->getSymbols("operator[]");
        bool found = false;
        for (auto op: operators) {
            auto opType = (LambdaType *) op->getSignature();
            if (*opType->getArgsTypes()[0] == *type) {
                found = true;
                _exprType = opType->getReturnType();
                break;
            }
        }
        if (!found) {
            ErrorsRegister::addError(new Error("Type " + type->getName() + " has no overload for operator []", _pos));
        }
    } else {
        auto operators = parent->getSymbols("operator" + _op->decompile(0));
        bool found = false;
        for (auto op: operators) {
            auto opType = (LambdaType *) op->getSignature();
            if (*opType->getArgsTypes()[0] == *type) {
                found = true;
                _exprType = opType->getReturnType();
                break;
            }
        }
        if (!found) {
            ErrorsRegister::addError(
                    new Error("Type " + type->getName() + " has no overload for operator " + _op->decompile(0), _pos)
            );
        }
    }

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
