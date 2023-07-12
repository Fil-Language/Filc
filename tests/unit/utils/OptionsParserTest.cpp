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
#include "OptionsParser.h"
#include <gtest/gtest.h>

TEST(OptionParser, constructor) {
    auto parser = filc::utils::OptionsParser();

    ASSERT_EQ(0, parser.getFilenames().size());
    ASSERT_EQ(0, parser.getVerbose());
    ASSERT_FALSE(parser.isDebug());
    ASSERT_STREQ("a.out", parser.getOut().c_str());
}

TEST(OptionParser, parse) {
    auto parser = filc::utils::OptionsParser();

    std::vector<const char *> argv = {"filc"};
    ASSERT_FALSE(parser.parse(1, argv.data()));

    argv = {"filc", "--help"};
    ASSERT_TRUE(parser.parse(2, argv.data()));

    argv = {"filc", "--version"};
    ASSERT_TRUE(parser.parse(2, argv.data()));

    argv = {"filc", "wrong_file"};
    ASSERT_FALSE(parser.parse(2, argv.data()));

    argv = {"filc", "file1.fil"};
    ASSERT_TRUE(parser.parse(2, argv.data()));

    argv = {"filc", "file1.fil", "file2.fil"};
    ASSERT_TRUE(parser.parse(3, argv.data()));

    argv = {"filc", "-d", "file1.fil"};
    ASSERT_TRUE(parser.parse(3, argv.data()));

    argv = {"filc", "--verbose", "file1.fil"};
    ASSERT_TRUE(parser.parse(3, argv.data()));

    argv = {"filc", "-o", "executable", "file1.fil"};
    ASSERT_TRUE(parser.parse(4, argv.data()));
}

TEST(OptionParser, getOptions) {
    auto parser = filc::utils::OptionsParser();

    ASSERT_NO_THROW({ parser.getOptions(); });
}

TEST(OptionParser, getFilenames) {
    auto parser = filc::utils::OptionsParser();

    std::vector<const char *> argv = {"filc", "file1.fil", "file2.fil"};
    parser.parse(3, argv.data());

    auto filenames = parser.getFilenames();

    ASSERT_EQ(2, parser.getFilenames().size());
    const auto *filename1 = "file1.fil";
    ASSERT_STREQ(filename1, filenames[0].c_str());
    const auto *filename2 = "file2.fil";
    ASSERT_STREQ(filename2, filenames[1].c_str());
}

TEST(OptionParser, getVerbose) {
    auto parser = filc::utils::OptionsParser();

    std::vector<const char *> argv = {"filc", "--verbose=2", "file2.fil"};
    parser.parse(3, argv.data());
    ASSERT_EQ(2, parser.getVerbose());

    argv = {"filc", "--verbose=0", "file2.fil"};
    parser.parse(3, argv.data());
    ASSERT_EQ(0, parser.getVerbose());

    argv = {"filc", "--verbose=10", "file2.fil"};
    parser.parse(3, argv.data());
    ASSERT_EQ(5, parser.getVerbose());

    argv = {"filc", "--verbose=-2", "file2.fil"};
    ASSERT_FALSE(parser.parse(3, argv.data()));
}

TEST(OptionParser, isDebug) {
    auto parser = filc::utils::OptionsParser();

    std::vector<const char *> argv = {"filc", "file2.fil"};
    parser.parse(2, argv.data());
    ASSERT_FALSE(parser.isDebug());

    argv = {"filc", "--debug", "file2.fil"};
    parser.parse(3, argv.data());
    ASSERT_TRUE(parser.isDebug());

    argv = {"filc", "-d", "file2.fil"};
    parser.parse(3, argv.data());
    ASSERT_TRUE(parser.isDebug());
}

TEST(OptionParser, getOut) {
    auto parser = filc::utils::OptionsParser();

    std::vector<const char *> argv = {"filc", "file2.fil"};
    parser.parse(2, argv.data());
    const auto *expected = "a.out";
    ASSERT_STREQ(expected, parser.getOut().c_str());

    argv = {"filc", "--out=myExec", "file2.fil"};
    parser.parse(3, argv.data());
    expected = "myExec";
    ASSERT_STREQ(expected, parser.getOut().c_str());

    argv = {"filc", "-o", "myExec2", "file2.fil"};
    parser.parse(4, argv.data());
    expected = "myExec2";
    ASSERT_STREQ(expected, parser.getOut().c_str());
}

TEST(OptionParser, extension) {
    std::string expected = "fil";
    ASSERT_STREQ(expected.c_str(), filc::utils::OptionsParser::extension("file.fil").c_str());

    expected = "";
    ASSERT_STREQ(expected.c_str(), filc::utils::OptionsParser::extension("fil").c_str());

    expected = "txt";
    ASSERT_STREQ(expected.c_str(), filc::utils::OptionsParser::extension("some file with spaces.txt").c_str());

    expected = "teng";
    ASSERT_STREQ(expected.c_str(), filc::utils::OptionsParser::extension("homepage.html.teng").c_str());
}
