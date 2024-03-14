/**
 * MIT License
 *
 * Copyright (c) 2023-Present Kevin Traini
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
#include "Parser.h"

#include "Antlr4ErrorListener.h"
#include "FilLexer.h"
#include "FilParser.h"
#include "antlr4-runtime.h"
#include "tools.h"

using namespace filc::grammar;

auto FilParser::parse(const std::string &filename, std::shared_ptr<message::MessageCollector> collector) -> void {
    // Check if file was already parsed or not
    if (_program_cache.find(filename) != _program_cache.end()) {
        return;
    }

    auto *error_listener = new filc::message::Antlr4ErrorListener(collector);

    antlr4::ANTLRFileStream input;
    input.loadFromFile(filename);
    antlr::FilLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(error_listener);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();

    antlr::FilParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(error_listener);

    auto program = parser.program()->tree;
    program->setFilename(filename);

    // Add file in cache to avoid parsing it twice
    _program_cache[filename] = program;

    std::vector<ast::Program *> imports;
    for (const auto &import_module: program->getImports()) {
        try {
            auto import_filename = utils::getFilenameFromModule(import_module);
            parse(import_filename, collector);
            if (_program_cache.find(import_filename) == _program_cache.end()) {
                collector->addError(new filc::message::BasicError(filc::message::FATAL_ERROR, "Cannot find program attached to file " + import_filename));
            }
            imports.push_back(_program_cache[import_filename]);
        } catch (std::logic_error &e) {
            collector->addError(new filc::message::BasicError(filc::message::FATAL_ERROR, "Module " + import_module + " not found"));
        }
    }
    program->setImports(imports);

    setResult(program);
}
