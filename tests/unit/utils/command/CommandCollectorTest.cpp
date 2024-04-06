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

TEST(CommandCollector, constructor) {
    CommandCollector cc1;

    ASSERT_THAT(cc1.getCommands(), IsEmpty());
    ASSERT_TRUE(cc1.addCommand(new CustomCommand()));
    ASSERT_FALSE(cc1.addCommand(new CustomCommand()));
    ASSERT_THAT(cc1.getCommands(), SizeIs(1));

    ASSERT_EQ(0, cc1.run(1, toStringArray({"filc"}).data()));
    ASSERT_EQ(0, cc1.run(2, toStringArray({"filc", "custom"}).data()));
    ASSERT_EQ(0, cc1.run(2, toStringArray({"filc", "c"}).data()));
    ASSERT_EQ(0, cc1.run(2, toStringArray({"filc", "custom-command"}).data()));
    ASSERT_EQ(1, cc1.run(2, toStringArray({"filc", "non-existing-command"}).data()));
    ASSERT_EQ(0, cc1.run(2, toStringArray({"filc", "help"}).data()));
    ASSERT_EQ(0, cc1.run(3, toStringArray({"filc", "help", "custom"}).data()));
    ASSERT_EQ(0, cc1.run(3, toStringArray({"filc", "help", "c"}).data()));
    ASSERT_EQ(1, cc1.run(3, toStringArray({"filc", "help", "non-existing-command"}).data()));
}
