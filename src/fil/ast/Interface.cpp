/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Interface::Interface() : _name(nullptr) {}

Interface::Interface(Identifier *name, std::vector<ClassParam *> &params, std::vector<FunctionDecl *> &functions)
        : _name(name), _params(params), _functions(functions) {}
