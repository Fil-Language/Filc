/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

SwitchCase::SwitchCase(SwitchPattern *pattern, AbstractExpr *body)
        : _pattern(pattern), _body(body) {}

string SwitchCase::decompile(int indent) const {
    return _pattern->decompile(indent) + " -> " + _body->decompile(indent) + "\n";
}

AbstractType *SwitchCase::inferType(Environment *parent) {
    _exprType = _body->inferType(parent);

    return _exprType;
}

AbstractType *SwitchCase::inferPatternType(Environment *parent) const {
    if (!_pattern->isDefault()) {
        return _pattern->getLiteral()->inferType(parent);
    }

    return nullptr;
}

string SwitchCase::dump(int indent) const {
    string res = string(indent, '\t') + "[SwitchCase]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _pattern->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
