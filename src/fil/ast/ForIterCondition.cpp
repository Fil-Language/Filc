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
        : _isVal(isVal), _iterator(iterator), _iterable(iterable) {}

string ForIterCondition::decompile(int indent) const {
    return (_isVal ? "val " : "var ")
           + _iterator->decompile(indent)
           + ": "
           + _iterable->decompile(indent);
}

void ForIterCondition::resolveSymbols(Environment *loop) {
    _iterator->resolveVar(loop);
}

//void ForIterCondition::resolveCondition(Environment *loop) {
//    _iterator->resolveVar(loop);
//
//    if (!loop->hasVariable(_iterable->getName())) {
//        ErrorsRegister::addError(
//                "Unknown variable " + _iterable->getName(),
//                _iterable->getPosition()
//        );
//    }
//}
//
//void ForIterCondition::inferCondition(Environment *env, Environment *loop) {
//    auto type = _iterable->inferType(env);
//    if (!type->isIterable()) {
//        ErrorsRegister::addError(
//                "Cannot iterate over " + type->getName(),
//                _iterable->getPosition()
//        );
//    }
//
//    loop->getSymbol(_iterable->getName())->setSignature(type->getIterableType());
//}

string ForIterCondition::dump(int indent) const {
    string res = string(indent, '\t') + "[ForIterCondition] " + (_isVal ? "<val>" : "<var>") + "\n";

    res += _iterator->dump(indent + 1);
    res += _iterable->dump(indent + 1);

    return res;
}
