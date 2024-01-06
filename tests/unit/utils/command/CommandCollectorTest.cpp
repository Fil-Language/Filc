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
#include "test_tools.h"

using namespace filc::utils::command;

class CustomCommand : public Command {
public:
    CustomCommand() : Command("custom", "My custom command", {"c", "custom-command"}) {}

    [[nodiscard]] auto help() const -> std::string override {
        return "Help of custom command";
    }

    auto run(int argc, char **argv) -> int override {
        return 0;
    }
};

TEST(CommandCollector, constructor) {
    CommandCollector cc1;

    ASSERT_THAT(cc1.getCommands(), IsEmpty());
    ASSERT_TRUE(cc1.addCommand(new CustomCommand()));
    ASSERT_FALSE(cc1.addCommand(new CustomCommand()));
    ASSERT_THAT(cc1.getCommands(), SizeIs(1));

    char *argv0[] = {"filc"};
    ASSERT_EQ(2, cc1.run(1, argv0));
    char *argv1[] = {"filc", "custom"};
    ASSERT_EQ(0, cc1.run(2, argv1));
    char *argv2[] = {"filc", "c"};
    ASSERT_EQ(0, cc1.run(2, argv2));
    char *argv3[] = {"filc", "custom-command"};
    ASSERT_EQ(0, cc1.run(2, argv3));
    char *argv4[] = {"filc", "non-existing-command"};
    ASSERT_EQ(2, cc1.run(2, argv4));
}