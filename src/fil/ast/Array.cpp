/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Array::Array() = default;

Array::Array(vector<AbstractExpr *> &values) : _values(values) {}

Array::~Array() {
    for (auto &value: _values) {
        delete value;
    }
}

string Array::decompile(int indent) const {
    string res = "{\n";

    for (auto it = _values.begin(); it != _values.end(); it++) {
        res += (*it)->decompile(indent + 1);
        if (it != _values.end() - 1) {
            res += ",\n";
        }
    }

    return res + "}";
}
