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
#include "test_tools.h"

using namespace filc::utils::command;

TEST(HelpCommand, help) {
    CommandCollector cc1;
    HelpCommand hc1(&cc1);

    ASSERT_STREQ(
        "Fil compiler\n"
        "Version: 0.2.1\n"
        "License: MIT\n"
        "Usage: `filc <command>`\n"
        "\n"
        "\thelp\tDisplay this help message\n"
        "\n"
        "Use `filc help <command>` to see specific help of command\n",
        hc1.help().c_str()
    );

    cc1.addCommand(new CustomCommand());
    ASSERT_STREQ(
        "Fil compiler\n"
        "Version: 0.2.1\n"
        "License: MIT\n"
        "Usage: `filc <command>`\n"
        "\n"
        "\tcustom\tMy custom command\n"
        "\thelp\tDisplay this help message\n"
        "\n"
        "Use `filc help <command>` to see specific help of command\n",
        hc1.help().c_str()
    );
}

TEST(HelpCommand, run) {
    CommandCollector cc1;
    HelpCommand hc1(&cc1);
    auto *custom1 = new CustomCommand;
    cc1.addCommand(custom1);

    getOutput(
        [&hc1]() {
            ASSERT_EQ(0, hc1.run(0, {}));
        },
        [&hc1](const std::string &result) {
            ASSERT_EQ(hc1.help(), result);
        }
    );
    getOutput(
        [&hc1]() {
            ASSERT_EQ(1, hc1.run(1, toStringArray({"non-existing-command"}).data()));
        },
        [&hc1](const std::string &result) {
            ASSERT_EQ(
                "\033[31mCommand \033[1mnon-existing-command\033[0m\033[31m not found\033[0m\n" + hc1.help(), result
            );
        }
    );
    const auto custom_help = custom1->help() + '\n';
    getOutput(
        [&hc1]() {
            ASSERT_EQ(0, hc1.run(1, toStringArray({"custom"}).data()));
        },
        [&custom_help](const std::string &result) {
            ASSERT_EQ(custom_help, result);
        }
    );
    getOutput(
        [&hc1]() {
            ASSERT_EQ(0, hc1.run(1, toStringArray({"c"}).data()));
        },
        [&custom_help](const std::string &result) {
            ASSERT_EQ(custom_help, result);
        }
    );
    getOutput(
        [&hc1]() {
            ASSERT_EQ(0, hc1.run(1, toStringArray({"custom-command"}).data()));
        },
        [&custom_help](const std::string &result) {
            ASSERT_EQ(custom_help, result);
        }
    );
}
