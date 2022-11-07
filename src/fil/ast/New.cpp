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
