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
#include <fstream>
#include <iostream>

using namespace std;
using namespace filc::utils::config;
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
    if (!filesystem::create_directory(project_name)) {
        cout << "\033[31mFailed to create project\033[0m\n";
        return 1;
    }

    // Create config file
    Config::init(project_name);
    Config::save(project_name + "/module.yml");
    const auto config = Config::get();

    // Create entry point
    const auto source_dir = project_name + "/src";
    if (!filesystem::create_directory(source_dir)) {
        cout << "\033[31mFailed to create project\033[0m\n";
        return 1;
    }
    const auto filename = source_dir + "/main.fil";
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "\033[31mFailed to create project\033[0m\n";
        return 1;
    }

    file << "module " << config->getNamespace("src") << '\n'
         << '\n'
         << "fun main() = 0" << '\n';
    file.flush();
    file.close();

    return 0;
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
