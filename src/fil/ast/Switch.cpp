/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Switch::Switch(AbstractExpr *condition, const vector<SwitchCase *> &cases)
        : _condition(condition), _cases(cases) {}

string Switch::decompile(int indent) const {
    string res = "switch (" + _condition->decompile(indent) + ") {\n";

    for (auto &c: _cases) {
        res += string(indent + 1, '\t') + c->decompile(indent);
    }

    res += "}";

    return res;
}

Symbol *Switch::resolveSymbols(Environment *parent) {
    _condition->resolveSymbols(parent);
    for (auto &c: _cases) {
        c->resolveSymbols(parent);
    }

    return nullptr;
}

AbstractType *Switch::inferType(Environment *parent) {
    auto condType = _condition->inferType(parent);

    AbstractType *prevType = nullptr;
    for (auto &c: _cases) {
        auto patternType = c->inferPatternType(parent);
        if (patternType && *patternType != *condType) {
            ErrorsRegister::addError(
                    new Error("Type mismatch : pattern type is " + patternType->getName() +
                              " but condition type is " + condType->getName(), c->getPosition())
            );
        }

        auto caseType = c->inferType(parent);
        if (prevType == nullptr) {
            prevType = caseType;
        } else if (*caseType != *prevType) {
            ErrorsRegister::addError(
                    new Error("Type mismatch : cas type is " + caseType->getName() + ", but " +
                              prevType->getName() + " was expected", c->getPosition())
            );
        }
    }

    _exprType = prevType;

    return _exprType;
}

string Switch::dump(int indent) const {
    string res = string(indent, '\t') + "[Switch]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);

    for (auto &c: _cases) {
        res += c->dump(indent + 1);
    }

    return res;
}
