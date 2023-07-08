/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <utility>

#include "AST.hpp"
#include "FilCompiler.h"

using namespace std;
using namespace ast;

Program::Program(string module,
                 const vector<std::string> &imports,
                 const vector<AbstractExpr *> &exprs)
    : _module(std::move(module)), _imports(imports), _exprs(exprs), _environment(nullptr), _resolved(false) {}

auto Program::decompile(int indent) const -> string {
    string result = "module " + _module + "\n";

    if (!_imports.empty()) {
        result += "\n";
    }
    for (const auto &import: _imports) {
        result += "use " + import + "\n";
    }

    if (!_exprs.empty()) {
        result += "\n";
    }
    for (auto it = _exprs.begin(); it != _exprs.end(); it++) {
        result += ((*it)->isExported() ? "export " : "") + (*it)->decompile(indent) + "\n";

        if (it + 1 != _exprs.end()) {
            result += "\n";
        }
    }

    return result;
}

void Program::resolveEnvironment() {
    if (_resolved) {// Fix infinite loop of resolve
        return;
    }
    _resolved = true;

    // Remove duplicate imports
    sort(_imports.begin(), _imports.end());
    _imports.erase(unique(_imports.begin(), _imports.end()), _imports.end());

    // Resolve imports
    for (auto &import: _imports) {
        auto *module = FilCompiler::getModule(import);
        if (module == nullptr) {
            ErrorsRegister::addWarning(
                    new BasicWarning("\033[1mDev code 2\033[21m\nModule '" + import + "' not found"));
            continue;
        }

        module->resolveEnvironment();
        _imported_modules.push_back(module);
    }

    // TODO : merge imports env to _environment

    // TODO : resolve exprs
}

auto Program::dump(int indent) const -> string {
    string res = string(indent, '\t') + "[Program] <module:" + _module + ">\n";

    for (const auto &imp: _imported_modules) {
        res += imp->dump(indent + 1);
    }

    for (const auto &expr: _exprs) {
        res += expr->dump(indent + 1);
    }

    return res;
}

void Program::setEnvironment(Environment *environment) {
    _environment = environment;
}
