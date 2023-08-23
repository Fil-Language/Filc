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
#include "tools.h"
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
        // Parse all files
        for (const auto &filename: _options.getFilenames()) {
            auto fut = std::async([collector](const std::string &filename) {
                try {
                    filc::grammar::Parser parser(filename, collector);

                    return parser.getProgram();
                } catch (std::exception &e) {
                    collector->addError(new filc::message::BasicError(filc::message::FATAL_ERROR, e.what()));

                    return (filc::ast::Program *) nullptr;
                }
            }, filename);
            futures.push_back(std::move(fut));
        }

        if (!checkCollector(collector)) {
            return 1;
        }

        // Collect all programs by modules
        for (auto &fut: futures) {
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
        }

        if (!checkCollector(collector)) {
            return 1;
        }

        checkModules(collector);

        // Resolve environment
        // TODO

        // LLVM
        // TODO

        // Free memory
        for (const auto &module: _modules) {
            delete module.second;
        }
        _modules.clear();

        return 0;
    }

    auto FilCompiler::checkCollector(filc::message::MessageCollector *collector) -> bool {
        if (collector->hasErrors()) {
            collector->printAll();

            return false;
        }
        collector->printAll();

        return true;
    }

    auto FilCompiler::checkModules(filc::message::MessageCollector *collector) -> void {
        auto has_change = true;
        while (has_change) {
            has_change = false;
            for (const auto &module: _modules) {
                auto *program = module.second;
                for (const auto &module_name: program->getImports()) {
                    if (_modules.find(module_name) == _modules.end()) {
                        // Modules not found, check if standard module
                        auto filename = getModuleFilename(module_name, _options.getStdPath());
                        if (!filename.empty()) {
                            // It's a standard module, add it
                            filc::grammar::Parser parser(filename, collector);

                            _modules.emplace(module_name, parser.getProgram());
                            collector->addMessage(
                                    new filc::message::Message(filc::message::DEBUG, "Getting module: " + module_name)
                            );
                            has_change = true;
                        } else {
                            collector->addError(
                                    new filc::message::Error(filc::message::ERROR,
                                                             "Module " + module_name + " not found",
                                                             new filc::utils::Position(program->getFilename(), 0, 0))
                            );
                        }
                    }
                }
            }
        }
    }

    auto FilCompiler::getModuleFilename(const std::string &module_name, const std::string &std_path) -> std::string {
        if (!filc::utils::strStartsWith(module_name, "fil.")) {
            return "";
        }

        auto paths = filc::utils::splitString(std_path, ';');
        auto modules = filc::utils::splitString(module_name, '.');
        modules.erase(modules.begin()); // Remove 'fil'

        std::string short_filename;
        for (const auto &module: modules) {
            short_filename += "/" + module;
        }

        for (const auto &path: paths) {
            // Try module
            if (filc::utils::fileExists(path + short_filename + ".fil")) {
                return path + short_filename + ".fil";
            }

            // Try module index
            if (filc::utils::fileExists(path + short_filename + "/index.fil")) {
                return path + short_filename + "/index.fil";
            }

            // Try module main
            if (filc::utils::fileExists(path + short_filename + "/main.fil")) {
                return path + short_filename + "/main.fil";
            }
        }

        return "";
    }
}
