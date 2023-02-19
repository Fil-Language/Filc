/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AST::AST() : _pos(nullptr) {}

string AST::decompile(int indent) const {
    throw;
}

std::string AST::dump(int indent) const {
    throw;
}

void AST::setPosition(antlr4::Token *token) {
    _pos = new Position((int) token->getLine(),
                        (int) token->getCharPositionInLine(),
                        token->getTokenSource()->getSourceName());
}

Position *AST::getPosition() const {
    return _pos;
}
