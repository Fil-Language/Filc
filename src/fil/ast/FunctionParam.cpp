/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

FunctionParam::FunctionParam() : _type(nullptr) {}

FunctionParam::FunctionParam(const std::string &name, Type *type) : _name(name), _type(type) {}

IndentPrinter *FunctionParam::print(IndentPrinter *printer) const {
    printer->write(_name)->write(": ");
    return _type->print(printer);
}
