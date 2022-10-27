/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

#include <utility>

using namespace std;
using namespace ast;

Program::Program(string moduleName) : _moduleName(std::move(moduleName)) {}

std::string Program::toString() const {
    return "Program: " + _moduleName;
}

Program::Program() = default;
