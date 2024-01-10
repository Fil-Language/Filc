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
#include "test_tools.h"

using namespace filc::utils::command;

TEST(VersionCommand, help) {
    VersionCommand vc1("", 0, "");

    ASSERT_STREQ("Display version of compiler\n", vc1.help().c_str());
}

TEST(VersionCommand, run) {
    VersionCommand vc1("1.3.2", 54, "My License");

    ASSERT_OUTPUT("     _______ __    \n"
                  "    / ____(_) /____\n"
                  "   / /_  / / / ___/\n"
                  "  / __/ / / / /__  \n"
                  " /_/   /_/_/\\___/  \n"
                  "                   \n"
                  "Filc version 1.3.2 - 54\n"
                  "License: My License\n", ASSERT_EQ(0, vc1.run(0, {})));
}
