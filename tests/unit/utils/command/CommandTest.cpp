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
#include "test_tools.h"

using namespace filc::utils::command;

TEST(Command, constructor) {
    IncompleteCommand ic1;

    ASSERT_STREQ("name", ic1.getName().c_str());
    ASSERT_STREQ("description", ic1.getDescription().c_str());
    ASSERT_THAT(ic1.getAliases(), IsEmpty());
    ASSERT_TRUE(ic1.matchName("name"));
    ASSERT_FALSE(ic1.matchName("n"));
    ASSERT_FALSE(ic1.matchName("name2"));
    ASSERT_THROW(ic1.help(), std::logic_error);
    ASSERT_EQ(2, ic1.run(0, nullptr));
}

TEST(Command, childClass) {
    CustomCommand cc1;

    ASSERT_STREQ("custom", cc1.getName().c_str());
    ASSERT_STREQ("My custom command", cc1.getDescription().c_str());
    ASSERT_THAT(cc1.getAliases(), ElementsAre("c", "custom-command"));
    ASSERT_TRUE(cc1.matchName("custom"));
    ASSERT_TRUE(cc1.matchName("c"));
    ASSERT_TRUE(cc1.matchName("custom-command"));
    ASSERT_FALSE(cc1.matchName("help"));
    ASSERT_STREQ("Help of custom command", cc1.help().c_str());
    ASSERT_EQ(0, cc1.run(0, nullptr));
}
