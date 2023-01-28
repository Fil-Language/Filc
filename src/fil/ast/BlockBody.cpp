/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

BlockBody::BlockBody(const vector<AbstractExpr *> &exprs)
        : _exprs(exprs), _environment(nullptr) {}

string BlockBody::decompile(int indent) const {
    string result = "{\n";

    for (auto expr: _exprs) {
        result += string(indent + 1, '\t') + expr->decompile(indent + 1) + "\n";
    }

    result += string(indent, '\t') + "}";

    return result;
}

Symbol *BlockBody::resolveSymbols(Environment *parent) {
    _environment = new Environment(parent);

    for (auto expr: _exprs) {
        expr->resolveSymbols(_environment);
    }

    return nullptr;
}

AbstractType *BlockBody::inferType(Environment *parent) {
    if (_exprs.empty()) {
        _exprType = parent->getSymbol("void")->getSignature();
    } else {
        for (auto it = _exprs.begin(); it != _exprs.end(); it++) {
            if ((*it)->isReturn()) {
                _exprType = (*it)->inferType(parent);
            } else {
                auto type = (*it)->inferType(parent);

                if (it + 1 == _exprs.end()) {
                    _exprType = type;
                }
            }
        }
    }

    return _exprType;
}

string BlockBody::dump(int indent) const {
    string res = string(indent, '\t') + "[BlockBody]" + (_isExported ? " <exported>" : "") +
                 " <type:" + _exprType->getName() + ">\n";

    for (auto expr: _exprs) {
        res += expr->dump(indent + 1);
    }

    return res;
}
