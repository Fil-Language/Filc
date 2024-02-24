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
#include "FilCompiler.h"
#include "Config.h"
#include "Error.h"
#include "MessageCollector.h"
#include "tools.h"
#include <filesystem>

using namespace std;
using namespace filc;

FilCompiler::FilCompiler(grammar::Parser<ast::Program> *parser)
    : _parser(unique_ptr<grammar::Parser<ast::Program>>(parser)) {}

auto FilCompiler::compile() -> int {
    auto *collector = message::MessageCollector::getCollector(message::ERROR);

    collector->addMessage(new message::Message(message::SYSTEM, "Begin compilation"));

    /*
     * TODO:
     * - [x] get entrypoint
     * - [x] antlr parse it and its includes
     * - [ ] create dependency tree
     * - [ ] checks pass with visitors on tree
     * - [ ] llvm pass with visitors on tree
     * - [ ] return 0;
     */
    const auto entrypoint = getEntrypoint();
    if (collector->hasErrors()) {
        collector->printAll();
        // Assert that MessageCollector will not be used anymore after this line
        delete collector;
        return 1;
    }
    collector->printAll();

    _parser->parse(entrypoint, collector);
    auto *program = _parser->getResult();
    delete program;

    collector->addError(new message::BasicError(message::FATAL_ERROR, "Compiler not implemented yet!"));
    //collector->addMessage(new filc::message::Message(filc::message::SYSTEM, "Compilation finished"));
    collector->printAll();

    // Assert that MessageCollector will not be used anymore after this line
    delete collector;
    return 2;
}

auto FilCompiler::getEntrypoint() -> std::string {
    auto *collector       = message::MessageCollector::getCollector();
    const auto *config    = utils::config::Config::get();
    const auto entrypoint = config->getEntrypoint();

    if (entrypoint.empty() || !filesystem::exists(entrypoint) || !filesystem::is_regular_file(entrypoint)) {
        collector->addError(new message::BasicError(message::FATAL_ERROR, "Entrypoint cannot be found, or is not readable"));
    }

    return entrypoint;
}
