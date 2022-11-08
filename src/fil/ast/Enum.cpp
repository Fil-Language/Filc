/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Enum::Enum() : _name(nullptr) {}

Enum::Enum(Identifier *name, vector<Identifier *> &values)
        : _name(name), _values(values) {}

Enum::~Enum() {
    delete _name;
    for (auto &value: _values) {
        delete value;
    }
}

string Enum::decompile(int indent) const {
    string res = "Enum " + _name->decompile(indent);

    if (!_values.empty()) {
        res += " {\n";
        for (auto it = _values.begin(); it != _values.end(); it++) {
            res += (*it)->decompile(indent + 1);
            if (it != _values.end() - 1) {
                res += ",";
            }
            res += "\n";
        }
        res += "}";
    }

    return res;
}
