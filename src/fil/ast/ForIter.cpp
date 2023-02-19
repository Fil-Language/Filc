/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForIter::ForIter(ForIterCondition *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

string ForIter::decompile(int indent) const {
    return "for (" + _condition->decompile(indent) + ") " + _body->decompile(indent);
}

string ForIter::dump(int indent) const {
    string res = string(indent, '\t') + "[ForIter]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
