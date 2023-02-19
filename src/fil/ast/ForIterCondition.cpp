/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
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

string ForIterCondition::dump(int indent) const {
    string res = string(indent, '\t') + "[ForIterCondition] " + (_isVal ? "<val>" : "<var>") + "\n";

    res += _iterator->dump(indent + 1);
    res += _iterable->dump(indent + 1);

    return res;
}
