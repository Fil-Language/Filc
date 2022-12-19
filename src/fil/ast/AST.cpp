/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

AST::AST() : _pos(nullptr) {}

AST::~AST() {
    delete _pos;
}

string AST::decompile(int indent) const {
    throw;
}

void AST::setPosition(antlr4::Token *token) {
    _pos = new Position((int) token->getLine(),
                        (int) token->getCharPositionInLine(),
                        token->getTokenSource()->getSourceName());
}
