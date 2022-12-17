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

ForIterCondition::~ForIterCondition() {
    delete _iterator;
    delete _iterable;
}

string ForIterCondition::decompile(int indent) const {
    return (_isVal ? "val " : "var ")
           + _iterator->decompile(indent)
           + ": "
           + _iterable->decompile(indent);
}
