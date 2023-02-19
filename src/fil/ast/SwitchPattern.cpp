/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

SwitchPattern::SwitchPattern()
        : _isDefault(true), _literal(nullptr) {}

SwitchPattern::SwitchPattern(AbstractLiteral *literal)
        : _isDefault(false), _literal(literal) {}

string SwitchPattern::decompile(int indent) const {
    return _isDefault ? "default" : _literal->decompile(indent);
}

AbstractLiteral *SwitchPattern::getLiteral() const {
    return _literal;
}

string SwitchPattern::dump(int indent) const {
    if (_isDefault) {
        return string(indent, '\t') + "[SwitchPattern] <default>\n";
    } else {
        string res = string(indent, '\t') + "[SwitchPattern]\n";

        res += _literal->dump(indent + 1);

        return res;
    }
}

bool SwitchPattern::isDefault() const {
    return _isDefault;
}
