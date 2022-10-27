/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

#include <utility>
#include <sstream>

using namespace std;
using namespace ast;

Program::Program() : _imports(vector<Program>()) {}

Program::Program(string moduleName) : _moduleName(std::move(moduleName)), _imports(vector<Program>()) {}

Program::Program(string moduleName, vector<Program> &imports) : _moduleName(std::move(moduleName)), _imports(imports) {}

std::string Program::toString() const {
    string res;
    res += "Program: " + _moduleName + "\n";

    for (const auto &import: _imports) {
        res += "\t" + import.toString() + "\n";
    }

    return res;
}
