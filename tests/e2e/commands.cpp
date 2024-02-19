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
#include "test_tools.h"
#include <filesystem>

using namespace ::testing;

#define HELP_MESSAGE "Fil compiler\n"                           \
                     "Version: 0.2.1\n"                         \
                     "License: MIT\n"                           \
                     "Usage: `filc <command>`\n"                \
                     "\n"                                       \
                     "\tbuild\tBuild your project\n"            \
                     "\tinit\tInit a new Fil project\n"         \
                     "\tversion\tDisplay version of compiler\n" \
                     "\thelp\tDisplay this help message\n"      \
                     "\n"                                       \
                     "Use `filc help <command>` to see specific help of command\n"

TEST(Options, nothing) {
    const auto result = run_with_args();
    ASSERT_STREQ(HELP_MESSAGE, result.c_str());
}

TEST(Options, help) {
    const auto result1 = run_with_args("help");
    ASSERT_STREQ(HELP_MESSAGE, result1.c_str());
}

TEST(Options, version) {
    const auto result1 = run_with_args("help version");
    ASSERT_STREQ("Display version of compiler\n", result1.c_str());

    const auto result2 = run_with_args("version");
    ASSERT_THAT(result2, MatchesRegex(
                                 "     _______ __    \n"
                                 "    / ____\\(_\\) /____\n"
                                 "   / /_  / / / ___/\n"
                                 "  / __/ / / / /__  \n"
                                 " /_/   /_/_/\\\\___/  \n"
                                 "                   \n"
                                 "Filc version 0\\.2\\.1 - 2001\n"
                                 "Build time: [A-Za-z]{3} [0-9]{2} [0-9]{4} [0-9]{2}:[0-9]{2}:[0-9]{2}\n"
                                 "Build OS: (Windows 32-bit|Windows 64-bit|Mac OSX|Linux|FreeBSD|Unix|Other)\n"
                                 "License: MIT\n"));
}

TEST(Options, init) {
    run_with_args_and_input("init", "my_project\n");
    ASSERT_TRUE(std::filesystem::exists("my_project/src/main.fil"));
    ASSERT_TRUE(std::filesystem::exists("my_project/module.yml"));
    std::filesystem::remove_all("my_project");

    run_with_args_and_input("init", " my awesome project  \n");
    ASSERT_TRUE(std::filesystem::exists("my_awesome_project/src/main.fil"));
    ASSERT_TRUE(std::filesystem::exists("my_awesome_project/module.yml"));
    std::filesystem::remove_all("my_awesome_project");
}
