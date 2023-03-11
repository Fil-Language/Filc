/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#ifndef FILC_LEXERERRORLISTENER_H
#define FILC_LEXERERRORLISTENER_H

#include "antlr4-runtime.h"

class LexerErrorListener : public antlr4::BaseErrorListener {
    void syntaxError(antlr4::Recognizer *recognizer,
                     antlr4::Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string &msg,
                     std::exception_ptr e) override;
};


#endif //FILC_LEXERERRORLISTENER_H
