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
#include "CommandCollector.h"

#include <algorithm>
#include <iostream>

using namespace std;
using namespace filc::utils::command;

CommandCollector::CommandCollector() = default;

auto CommandCollector::getCommands() const -> const vector<unique_ptr<Command>> & {
    return _commands;
}

auto CommandCollector::addCommand(Command *command_added) -> bool {
    if (!any_of(_commands.begin(), _commands.end(), [&command_added](const unique_ptr<Command> &command) -> bool {
        return command->getName() == command_added->getName();
    })) {
        _commands.push_back(unique_ptr<Command>(command_added));

        return true;
    }

    return false;
}

auto CommandCollector::run(int argc, char **argv) -> int {
    argc--; // Remove name of executable
    argv++;

    if (argc == 0) {
        return runHelpCommand();
    }

    const string command_name = argv[0];
    auto command = find_if(
            _commands.begin(), _commands.end(),
            [&command_name](const unique_ptr<Command> &command) -> bool {
                return command->matchName(command_name);
            }
    );
    if (command == _commands.end()) {
        return runHelpCommand();
    }

    argc--; // Remove name of command
    argv++;

    return (*command)->run(argc, argv);
}

auto CommandCollector::runHelpCommand() const -> int {
    cout << "\033[31m" << "Help command not implemented" << "\033[0m" << '\n';

    return 2;
}
