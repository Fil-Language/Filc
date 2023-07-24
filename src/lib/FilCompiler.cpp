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
#include "MessageCollector.h"
#include "Error.h"
#include "Parser.h"
#include <utility>
#include <future>

namespace filc {
    FilCompiler::FilCompiler(utils::OptionsParser options)
            : _options(std::move(options)) {
        message::MessageCollector::getCollector((filc::message::LEVEL) _options.getVerbose());
    }

    auto FilCompiler::compile() -> int {
        auto *collector = filc::message::MessageCollector::getCollector();

        std::vector<std::future<filc::ast::Program *>> futures;
        for (const auto &filename: _options.getFilenames()) {
            auto fut = std::async([collector](const std::string &filename) {
                try {
                    filc::grammar::Parser parser(filename);

                    return parser.getProgram();
                } catch (std::exception &e) {
                    collector->addError(new filc::message::BasicError(filc::message::FATAL_ERROR, e.what()));

                    return (filc::ast::Program *) nullptr;
                }
            }, filename);
            futures.push_back(std::move(fut));
        }

        if (collector->hasErrors()) {
            collector->printAll();

            return 1;
        }

        std::for_each(futures.begin(), futures.end(), [collector, this](std::future<filc::ast::Program *> &fut) {
            fut.wait();
            filc::ast::Program *program = fut.get();
            auto module_name = program->getModule();

            if (_modules.find(module_name) != _modules.end()) {
                collector->addError(
                        new filc::message::BasicError(filc::message::ERROR, "Module " + module_name + " already exists")
                );
            } else {
                _modules.emplace(module_name, program);
                collector->addMessage(
                        new filc::message::Message(filc::message::DEBUG, "Getting module: " + module_name)
                );
            }
        });

        if (collector->hasErrors()) {
            collector->printAll();

            return 1;
        }
        collector->printAll();

        return 0;
    }
}
