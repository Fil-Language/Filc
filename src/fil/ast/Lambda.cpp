/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Lambda::Lambda() : _body(nullptr) {}

Lambda::Lambda(std::vector<FunctionParam *> &params, ast::AbstractExpr *body) : _params(params), _body(body) {}

Lambda::~Lambda() {
    for (auto &param: _params) {
        delete param;
    }
    delete _body;
}
