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
#include "VersionCommand.h"

#include <iostream>

using namespace std;
using namespace filc::utils::command;

VersionCommand::VersionCommand(const string &version, unsigned int version_numer, const std::string &license)
        : Command("version", "Display version of compiler", {}), _version(version), _version_number(version_numer),
          _license(license) {}

auto VersionCommand::help() const -> string {
    return getDescription() + '\n';
}

auto VersionCommand::run(int argc, char **argv) -> int {
    cout << "     _______ __    \n"
            "    / ____(_) /____\n"
            "   / /_  / / / ___/\n"
            "  / __/ / / / /__  \n"
            " /_/   /_/_/\\___/  \n"
            "                   "
         << '\n';
    cout << "Filc version " << _version << " - " << _version_number << '\n';
    cout << "License: " << _license << '\n';

    return 0;
}
