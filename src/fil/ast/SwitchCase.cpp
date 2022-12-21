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

SwitchCase::~SwitchCase() {
    delete _pattern;
    delete _body;
}

string SwitchCase::decompile(int indent) const {
    return _pattern->decompile(indent) + " -> " + _body->decompile(indent) + "\n";
}

void SwitchCase::resolveEnvironment(Environment *parent) {
    _body->resolveEnvironment(parent);
}

AbstractType *SwitchCase::inferType(Environment *env) {
    _exprType = _body->inferType(env);

    return _exprType;
}

AbstractType *SwitchCase::inferPatternType(Environment *env) {
    if (!_pattern->isDefault()) {
        return _pattern->getLiteral()->inferType(env);
    }

    return nullptr;
}

string SwitchCase::dump(int indent) const {
    string res = string(indent, '\t') + "[SwitchCase] <type:" + _exprType->getName() + ">\n";

    res += _pattern->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
