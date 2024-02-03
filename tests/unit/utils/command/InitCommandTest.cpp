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
#include "test_tools.h"
#include <filesystem>

using namespace filc::utils::command;
using namespace filc::utils::config;

TEST(InitCommand, formatProjectName) {
    ASSERT_STREQ("project", InitCommand::formatProjectName("project").c_str());
    ASSERT_STREQ("project", InitCommand::formatProjectName(" project   ").c_str());
    ASSERT_STREQ("my_project", InitCommand::formatProjectName(" my project   ").c_str());
    ASSERT_STREQ("my_project", InitCommand::formatProjectName(" my/project   ").c_str());
    ASSERT_STREQ("my-project", InitCommand::formatProjectName(" my-project   ").c_str());
}

TEST(InitCommand, help) {
    InitCommand ic1;
    ASSERT_STREQ("Init a new Fil project by creating a directory an populate it with a config file and an entry point\n"
                 "This command is interactive and wait for user input\n",
                 ic1.help().c_str());
}

TEST(InitCommand, run) {
    InitCommand ic1;
    ASSERT_EQ(nullptr, Config::get());
    redirectCin([&ic1](std::stringstream &stream) {
        stream << "my_project" << '\n';
        ASSERT_EQ(0, ic1.run(0, {}));
    });

    ASSERT_NE(nullptr, Config::get());
    ASSERT_TRUE(std::filesystem::exists("my_project/src/main.fil"));
    ASSERT_TRUE(std::filesystem::exists("my_project/module.yml"));

    std::filesystem::remove_all("my_project");
    Config::clear();
}
