/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

New::New() : _identifier(nullptr), _isPointer(true) {}

New::New(ClassIdentifier *identifier, vector<AbstractExpr *> &args)
        : _identifier(identifier), _args(args), _isPointer(true) {}

New::New(ClassIdentifier *identifier, vector<AbstractExpr *> &args, bool isPointer)
        : _identifier(identifier), _args(args), _isPointer(isPointer) {}

New::~New() {
    delete _identifier;
    for (auto &arg: _args) {
        delete arg;
    }
}

string New::decompile(int indent) const {
    string res = (_isPointer ? "new " : "");
    res += _identifier->decompile(indent) + "(";

    for (auto it = _args.begin(); it != _args.end(); it++) {
        res += (*it)->decompile(indent);
        if (it != _args.end() - 1) {
            res += ", ";
        }
    }

    return res + ")";
}
