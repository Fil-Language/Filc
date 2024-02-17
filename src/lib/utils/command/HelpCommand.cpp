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
#include "HelpCommand.h"
#include "tools.h"

#include <iostream>

using namespace std;
using namespace filc::utils::command;

HelpCommand::HelpCommand(const CommandCollector *collector)
    : Command("help", "Display this help message", {}), _collector(collector) {}

auto HelpCommand::help() const -> string {
    string result = "Fil compiler\n";
    result += "Version: " FILC_VERSION "\n";
    result += "License: "
              "MIT"
              "\n";
    result += "Usage: `filc <command>`\n";
    result += "\n";

    for (const auto &command: _collector->getCommands()) {
        result += "\t" + command->getName() + "\t" + command->getDescription() + "\n";
    }
    result += "\t" + getName() + "\t" + getDescription() + "\n";
    result += "\n";

    result += "Use `filc help <command>` to see specific help of command\n";

    return result;
}

auto HelpCommand::run(int argc, char **argv) -> int {
    if (argc >= 1) {
        const string command_name = argv[0];
        for (const auto &command: _collector->getCommands()) {
            if (command->matchName(command_name)) {
                cout << command->help();

                return 0;
            }
        }

        cout << "\033[31m"
             << "Command "
             << "\033[1m" << command_name
             << "\033[0m\033[31m"
             << " not found"
             << "\033[0m" << '\n';
        cout << help();

        return 1;
    }

    cout << help();

    return 0;
}
