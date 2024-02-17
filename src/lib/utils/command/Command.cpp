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
#include "Command.h"

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace filc::utils::command;

Command::Command(std::string name, std::string description, const std::vector<std::string> &aliases)
        : _name(std::move(name)), _description(std::move(description)), _aliases(aliases) {}

auto Command::getName() const -> const std::string & {
    return _name;
}

auto Command::getDescription() const -> const std::string & {
    return _description;
}

auto Command::getAliases() const -> const std::vector<std::string> & {
    return _aliases;
}

auto Command::matchName(const std::string &name) const -> bool {
    if (_name == name) {
        return true;
    }

    return any_of(_aliases.begin(), _aliases.end(), [&name](const auto &alias) -> bool {
        return alias == name;
    });
}

auto Command::help() const -> std::string {
    throw logic_error("Command::help not implemented. Should be override by child class");
}

auto Command::run(int argc, char **argv) -> int {
    cout << "\033[31m" << "Command::run not implemented. Should be override by child class" << "\033[0m" << '\n';

    return 2;
}
