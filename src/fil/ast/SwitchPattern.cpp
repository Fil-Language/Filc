/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

SwitchPattern::SwitchPattern()
        : _isDefault(true), _literal(nullptr) {}

SwitchPattern::SwitchPattern(AbstractLiteral *literal)
        : _isDefault(false), _literal(literal) {}

SwitchPattern::~SwitchPattern() {
    delete _literal;
}

string SwitchPattern::decompile(int indent) const {
    return _isDefault ? "default" : _literal->decompile(indent);
}

AbstractLiteral *SwitchPattern::getLiteral() const {
    return _literal;
}
