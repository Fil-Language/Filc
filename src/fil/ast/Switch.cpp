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

Switch::~Switch() {
    delete _condition;
    for (auto &c: _cases) {
        delete c;
    }
}

string Switch::decompile(int indent) const {
    string res = "switch (" + _condition->decompile(indent) + ") {\n";

    for (auto &c: _cases) {
        res += c->decompile(indent);
    }

    res += "}";

    return res;
}

void Switch::resolveEnvironment(Environment *parent) {
    _condition->resolveEnvironment(parent);
    for (auto &c: _cases) {
        c->resolveEnvironment(parent);
    }
}

AbstractType *Switch::inferType(Environment *env) {
    auto conditionType = _condition->inferType(env);

    bool hasDefault = false;
    for (auto &_case: _cases) {
        auto currentType = _case->inferType(env);

        if (_exprType == nullptr) {
            _exprType = currentType;
        } else if (_exprType != currentType) {
            ErrorsRegister::addError(
                    "Type mismatch in switch cases, expected " + _exprType->getName() +
                    " but got " + currentType->getName(),
                    _case->getPosition()
            );
        }

        auto patternType = _case->inferPatternType(env);
        if (patternType) {
            if (patternType != conditionType) {
                ErrorsRegister::addError(
                        "Type mismatch in switch case pattern, expected " + conditionType->getName() +
                        " but got " + patternType->getName(),
                        _case->getPosition()
                );
            }
        } else {
            if (hasDefault) {
                ErrorsRegister::addError(
                        "Multiple default cases in switch",
                        _case->getPosition()
                );
            }
            hasDefault = true;
        }
    }

    if (!hasDefault) {
        ErrorsRegister::addWarning(
                "Switch without default case",
                _pos
        );
    }

    return _exprType;
}
