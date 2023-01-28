/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForIterCondition::ForIterCondition(bool isVal, Identifier *iterator, Identifier *iterable)
        : _isVal(isVal), _iterator(iterator), _iterable(iterable), _iteratorSymbol(nullptr) {}

string ForIterCondition::decompile(int indent) const {
    return (_isVal ? "val " : "var ")
           + _iterator->decompile(indent)
           + ": "
           + _iterable->decompile(indent);
}

void ForIterCondition::resolveSymbols(Environment *loop) {
    _iteratorSymbol = _iterator->resolveVar(loop);
}

void ForIterCondition::inferTypes(Environment *loop) {
    auto iterableType = _iterable->inferType(loop);

    if (!iterableType->isIterable()) {
        auto operators = loop->getSymbols("operator[]");
        bool found = false;
        for (auto &op: operators) {
            auto opType = (LambdaType *) op->getSignature();
            if (*opType->getArgsTypes()[0] == *iterableType) {
                _iteratorSymbol->setSignature(opType->getReturnType());
                found = true;
                break;
            }
        }
        if (!found) {
            ErrorsRegister::addError(
                    new Error("Type " + iterableType->getName() + " is not iterable", _iterable->getPosition())
            );
        }
    } else {
        _iteratorSymbol->setSignature(iterableType->getIterableType());
    }
}

string ForIterCondition::dump(int indent) const {
    string res = string(indent, '\t') + "[ForIterCondition] " + (_isVal ? "<val>" : "<var>") + "\n";

    res += _iterator->dump(indent + 1);
    res += _iterable->dump(indent + 1);

    return res;
}
