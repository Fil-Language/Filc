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
#include "test_tools.h"

/**
 * This test file aims to check memory usage of commands at the end
 * We should try to reduce it to the minimum (if zero is too hard to achieve)
 */

using namespace ::testing;

#ifdef __linux__

#define VALGRIND_OUTPUT_ZERO "in use at exit: 0 bytes in 0 blocks"

#define valgrind_run_input(input, args) exec_output("echo '" input "' | valgrind " FILC_BIN " " args " 2>&1")

#define valgrind_run(args) valgrind_run_input("", args)

TEST(Memory, version_command) {
    const auto result = valgrind_run("version");
    ASSERT_THAT(result, HasSubstr(VALGRIND_OUTPUT_ZERO));
}

TEST(Memory, help_command) {
    const auto result = valgrind_run("help");
    ASSERT_THAT(result, HasSubstr(VALGRIND_OUTPUT_ZERO));

    const auto result2 = valgrind_run("");
    ASSERT_THAT(result2, HasSubstr(VALGRIND_OUTPUT_ZERO));
}

TEST(Memory, init_command) {
    const auto result = valgrind_run_input("test\n", "init");
    ASSERT_THAT(result, HasSubstr(VALGRIND_OUTPUT_ZERO));
}

#endif
