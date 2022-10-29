/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionParam::FunctionParam() = default;

FunctionParam::FunctionParam(const std::string &name) : _name(name) {}

IndentPrinter *FunctionParam::print(IndentPrinter *printer) const {
    return printer->write(_name);
}
