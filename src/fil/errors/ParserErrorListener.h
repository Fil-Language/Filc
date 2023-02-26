/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#ifndef FILC_PARSERERRORLISTENER_H
#define FILC_PARSERERRORLISTENER_H

#include "antlr4-runtime.h"

class ParserErrorListener : public antlr4::BaseErrorListener {
    void syntaxError(antlr4::Recognizer *recognizer,
                     antlr4::Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string &msg,
                     std::exception_ptr e) override;
};


#endif //FILC_PARSERERRORLISTENER_H
