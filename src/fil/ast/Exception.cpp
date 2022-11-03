/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Try::Try() : _body(nullptr) {}

Try::Try(AbstractExpr *body, vector<Catch *> &catches)
        : _body(body), _catches(catches) {}

IndentPrinter *Try::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}

// ====================

Catch::Catch() : _param(nullptr), _body(nullptr) {}

Catch::Catch(FunctionParam *param, AbstractExpr *body)
        : _param(param), _body(body) {}

IndentPrinter *Catch::print(IndentPrinter *printer) const {
    // TODO : implement

    return printer;
}
