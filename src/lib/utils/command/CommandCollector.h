/**
 * MIT License
 *
 * Copyright (c) 2024-Present Kevin Traini
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
#ifndef FILC_COMMANDCOLLECTOR_H
#define FILC_COMMANDCOLLECTOR_H

#include "Command.h"
#include <vector>
#include <memory>

namespace filc::utils::command {
    class CommandCollector {
    public:
        CommandCollector();

        ~CommandCollector();

        [[nodiscard]] auto getCommands() const -> const std::vector<std::unique_ptr<Command>> &;

        auto addCommand(Command *command) -> bool;

        [[nodiscard]] auto run(int argc, char **argv) -> int;

    private:
        std::vector<std::unique_ptr<Command>> _commands;

        auto runHelpCommand(int argc, char **argv) const -> int;
    };
}

#endif //FILC_COMMANDCOLLECTOR_H
