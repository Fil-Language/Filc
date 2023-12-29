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

using namespace ::testing;

#define HELP_MESSAGE "Fil compiler\n" \
                     "Version: 0.3.0\n" \
                     "License: MIT\n" \
                     "Usage:\n" \
                     "  filc [options...] <source files>\n" \
                     "\n" \
                     "  -h, --help                Display help message\n" \
                     "  -v, --version             Display version of compiler\n" \
                     "      --verbose [=arg(=3)]  Verbose level (0-5) (default: 2)\n" \
                     "  -d, --debug               Compile with debug information\n" \
                     "  -o, --out arg             Executable output filename (default: a.out)\n" \
                     "      --stdlib arg          Paths to standard library (separated by ;) \n" \
                     "                            (default: \"\")\n" \
                     "\n"

#define VERSION_MESSAGE "     _______ __    \n" \
                        "    / ____(_) /____\n" \
                        "   / /_  / / / ___/\n" \
                        "  / __/ / / / /__  \n" \
                        " /_/   /_/_/\\___/  \n" \
                        "                   \n" \
                        "Filc version 0.3.0 - 3000\n" \
                        "License: MIT\n"

TEST(Options, nothing) {
    const auto result = run_with_args();
    ASSERT_STREQ(HELP_MESSAGE, result.c_str());
}

TEST(Options, help) {
    const auto result1 = run_with_args("-h");
    ASSERT_STREQ(HELP_MESSAGE, result1.c_str());

    const auto result2 = run_with_args("--help");
    ASSERT_STREQ(HELP_MESSAGE, result2.c_str());
}

TEST(Options, version) {
    const auto result1 = run_with_args("-v");
    ASSERT_STREQ(VERSION_MESSAGE, result1.c_str());

    const auto result2 = run_with_args("--version");
    ASSERT_STREQ(VERSION_MESSAGE, result2.c_str());
}
