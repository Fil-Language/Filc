/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Program::Program(const std::string &module, const std::vector<Program *> &imports)
        : _module(module), _imports(imports) {}

Program::~Program() {
    for (auto &import: _imports) {
        delete import;
    }
}

std::string Program::decompile(int indent) const {
    string result = "module " + _module + "\n\n";

    for (auto &import: _imports) {
        result += "import " + import->_module + "\n";
    }

    return result;
}
