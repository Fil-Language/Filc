/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "LexerErrorListener.h"
#include "ErrorsRegister.h"

using namespace std;

void LexerErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                     size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
    ErrorsRegister::addError(new Error(
            msg,
            new Position((int) line, (int) charPositionInLine,
                         recognizer->getInputStream()->getSourceName())
    ));
}
