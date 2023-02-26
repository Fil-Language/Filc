/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "ParserErrorListener.h"
#include "ErrorsRegister.h"

using namespace std;

void ParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                      size_t charPositionInLine, const string &msg, exception_ptr e) {
    ErrorsRegister::addError(new Error(
            msg,
            new Position((int) line, (int) charPositionInLine,
                         recognizer->getInputStream()->getSourceName())
    ));
}
