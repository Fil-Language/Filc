/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
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

//void ForICondition::resolveCondition(Environment *loop) {
//    _declaration->resolveEnvironment(loop);
//    _condition->resolveEnvironment(loop);
//    _increment->resolveEnvironment(loop);
//}
//
//void ForICondition::inferCondition(Environment *env, Environment *loop) {
//    if (_declaration)
//        _declaration->inferType(loop);
//    if (_condition)
//        _condition->inferType(loop);
//    if (_increment)
//        _increment->inferType(loop);
//}

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
