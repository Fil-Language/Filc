/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

While::While(AbstractExpr *condition, AbstractExpr *body)
        : _condition(condition), _body(body), _environment(nullptr) {}

string While::decompile(int indent) const {
    return "while (" + _condition->decompile(indent) + ") "
           + _body->decompile(indent);
}

string While::dump(int indent) const {
    string res = string(indent, '\t') + "[While]" + (_isExported ? " <exported> " : " ") +
                 "<type:" + _exprType->getName() + ">\n";

    res += _condition->dump(indent + 1);
    res += _body->dump(indent + 1);

    return res;
}
