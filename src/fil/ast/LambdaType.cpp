/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

LambdaType::LambdaType(const vector<AbstractType *> &args, AbstractType *ret)
        : _args(args), _ret(ret) {}

LambdaType::~LambdaType() {
    for (auto arg: _args) {
        delete arg;
    }
    delete _ret;
}

string LambdaType::decompile(int indent) const {
    string res = "(";
    for (auto it = _args.begin(); it != _args.end(); ++it) {
        res += (*it)->decompile(indent);
        if (it + 1 != _args.end()) {
            res += ", ";
        }
    }
    res += ") -> " + _ret->decompile(indent);

    return res;
}