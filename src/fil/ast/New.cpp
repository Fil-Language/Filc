/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

New::New() : _identifier(nullptr) {}

New::New(ClassIdentifier *identifier, vector<AbstractExpr *> &args)
        : _identifier(identifier), _args(args) {}

New::~New() {
    delete _identifier;
    for (auto &arg: _args) {
        delete arg;
    }
}

string New::decompile(int indent) const {
    string res = "new " + _identifier->decompile(indent) + "(";

    for (auto it = _args.begin(); it != _args.end(); it++) {
        res += (*it)->decompile(indent);
        if (it != _args.end() - 1) {
            res += ", ";
        }
    }

    return res + ")";
}
