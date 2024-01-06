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
#include "Position.h"
#include "test_tools.h"
#include <fstream>

#define POSITION_FILE FIXTURES_PATH "/utils/position.txt"

TEST(SimplePosition, constructor) {
    filc::utils::SimplePosition pos("filename", 20, 10);

    ASSERT_STREQ("filename", pos.getFilename().c_str());
    ASSERT_EQ(20, pos.getLine());
    ASSERT_EQ(10, pos.getColumn());
}

TEST(SimplePosition, getContent) {
    filc::utils::SimplePosition pos(POSITION_FILE, 12, 10);

    ASSERT_STREQ("12;abcd", pos.getContent().c_str());
}

TEST(SimplePosition, dump) {
    filc::utils::SimplePosition pos(POSITION_FILE, 12, 10);

    const auto *expected =
            "   \033[1;34m--> \033[0m../../../tests/unit/Fixtures/utils/position.txt:12:10\n"
            "\033[1;34m 12 | \033[0m12;abcd\n"
            "\033[1;34m    | \033[0m          \033[31m^\033[0m\n";

    ASSERT_STREQ(expected, pos.dump("\033[31m").c_str());
}

TEST(DoublePosition, constructor) {
    filc::utils::DoublePosition pos("filename", 20, 10, 30, 40);

    ASSERT_STREQ("filename", pos.getFilename().c_str());
    ASSERT_EQ(20, pos.getStartPosition().first);
    ASSERT_EQ(10, pos.getStartPosition().second);
    ASSERT_EQ(30, pos.getEndPosition().first);
    ASSERT_EQ(40, pos.getEndPosition().second);
    ASSERT_EQ(20, pos.getLine());
}

TEST(DoublePosition, getContent) {
    filc::utils::DoublePosition pos1(POSITION_FILE, 10, 0, 10, 10);
    ASSERT_THAT(pos1.getContent(), ElementsAre("10;abcd"));

    filc::utils::DoublePosition pos2(POSITION_FILE, 5, 0, 8, 0);
    ASSERT_THAT(pos2.getContent(), ElementsAre("05;abcd", "06;abcd", "07;abcd", "08;abcd"));
}

TEST(DoublePosition, dump) {
    filc::utils::DoublePosition pos1(POSITION_FILE, 15, 0, 15, 6);
    const auto *expected1 =
            "   \033[1;34m--> \033[0m../../../tests/unit/Fixtures/utils/position.txt:15:0\n"
            "\033[1;34m 15 | \033[0m15;abcd\n"
            "\033[1;34m    | \033[0m\033[31m^^^^^^^\033[0m\n";
    ASSERT_STREQ(expected1, pos1.dump("\033[31m").c_str());

    filc::utils::DoublePosition pos2(POSITION_FILE, 3, 1, 6, 5);
    const auto *expected2 =
            "  \033[1;34m--> \033[0m../../../tests/unit/Fixtures/utils/position.txt:3:1\n"
            "\033[1;34m   | \033[0m \033[31mv\033[0m\n"
            "\033[1;34m 3 | \033[0m03;abcd\n"
            "\033[1;34m 4 | \033[0m04;abcd\n"
            "\033[1;34m 5 | \033[0m05;abcd\n"
            "\033[1;34m 6 | \033[0m06;abcd\n"
            "\033[1;34m   | \033[0m     \033[31m^\033[0m\n";
    ASSERT_STREQ(expected2, pos2.dump("\033[31m").c_str());
}
