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
#include "InitCommand.h"

#include "Config.h"
#include "tools.h"
#include <enquirer.h>
#include <filesystem>
#include <iostream>
#include <sys/stat.h>

using namespace std;
using namespace filc::utils;
using namespace filc::utils::command;

InitCommand::InitCommand()
    : Command("init", "Init a new Fil project", {}) {}

auto InitCommand::help() const -> string {
    return "Init a new Fil project by creating a directory an populate it with a config file and an entry point\n"
           "This command is interactive and wait for user input\n";
}

auto InitCommand::run(int argc, char **argv) -> int {
    auto project_name = enquirer::input("Name of your project");
    if (project_name.empty()) {
        cout << "Operation cancelled" << '\n';
        return 1;
    }
    project_name = formatProjectName(project_name);
    cout << "\033[34mLet's begin creation of project \033[1m" << project_name << "\033[0m" << '\n';

    // Create dir
    mkdir(project_name.c_str(), 0755);
    // Create config file
    config::Config::init(project_name);
    config::Config::save(project_name + "/module.yml");
    // Create entry point
    // TODO

    // Not implemented, so rmdir
    filesystem::remove_all(project_name);

    return 2;
}

auto InitCommand::formatProjectName(const string &project_name) -> string {
    string result;
    for (const auto c: trim(project_name)) {
        if (c == ' ' || c == '/') {
            result += '_';
        } else {
            result += c;
        }
    }

    return result;
}
