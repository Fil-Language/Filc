/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

ForICondition::ForICondition(VariableDeclaration *declaration, AbstractExpr *condition, AbstractExpr *increment)
        : _declaration(declaration), _condition(condition), _increment(increment) {}

string ForICondition::decompile(int indent) const {
    return _declaration->decompile(indent) + "; "
           + _condition->decompile(indent) + "; "
           + _increment->decompile(indent);
}

string ForICondition::dump(int indent) const {
    string res = string(indent, '\t') + "[ForICondition]\n";

    if (_declaration)
        res += _declaration->dump(indent + 1);
    else
        res += string(indent + 1, '\t') + "_\n";

    if (_condition)
        res += _condition->dump(indent + 1);
    else
        res += string(indent + 1, '\t') + "_\n";

    if (_increment)
        res += _increment->dump(indent + 1);
    else
        res += string(indent + 1, '\t') + "_\n";

    return res;
}
