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
#include "Error.h"
#include "test_tools.h"

TEST(BasicError, constructor) {
    auto basic_error = filc::message::BasicError(filc::message::ERROR, "My error");
    ASSERT_EQ(filc::message::ERROR, basic_error.getLevel());
}

TEST(BasicError, print) {
    auto basic_error = filc::message::BasicError(filc::message::ERROR, "My error");
    ASSERT_MESSAGE_CONTENT("\033[1;31mERROR\033[0m\033[1m: My error\033[0m", basic_error);
    ASSERT_MESSAGE_CONTENT("", basic_error);
}

TEST(Error, constructor) {
    auto error = filc::message::Error(filc::message::ERROR, "My error",
                                      new filc::utils::SimplePosition(FIXTURES_PATH "/utils/position.txt", 5, 2));
    ASSERT_EQ(filc::message::ERROR, error.getLevel());
}

TEST(Error, print) {
    auto error = filc::message::Error(filc::message::ERROR, "My error",
                                      new filc::utils::SimplePosition(FIXTURES_PATH "/utils/position.txt", 5, 2));
    auto expected =
            "\033[1;31mERROR\033[0m\033[1m: My error\033[0m\n"
            "  \033[1;34m--> \033[0m../../tests/unit/Fixtures/utils/position.txt:5:2\n"
            "\033[1;34m 5 | \033[0m05;abcd\n"
            "\033[1;34m   | \033[0m  \033[1;31m^\033[0m\n";
    ASSERT_MESSAGE_CONTENT(expected, error);
    ASSERT_MESSAGE_CONTENT("", error);
}
