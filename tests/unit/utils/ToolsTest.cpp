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
#include "tools.h"

TEST(tools, splitString) {
    auto result = filc::utils::splitString("", '.');
    ASSERT_THAT(result, SizeIs(0));

    result = filc::utils::splitString("a..b", '.');
    ASSERT_THAT(result, SizeIs(3));
    ASSERT_THAT(result, ElementsAre("a", "", "b"));

    result = filc::utils::splitString("a.b.", '.');
    ASSERT_THAT(result, SizeIs(2));
    ASSERT_THAT(result, ElementsAre("a", "b"));

    result = filc::utils::splitString(".a.b", '.');
    ASSERT_THAT(result, SizeIs(3));
    ASSERT_THAT(result, ElementsAre("", "a", "b"));

    result = filc::utils::splitString("abcd", '.');
    ASSERT_THAT(result, SizeIs(1));
    ASSERT_STREQ("abcd", result[0].c_str());
}

TEST(tools, strStartsWith) {
    auto result = filc::utils::strStartsWith("abcd", "a");
    ASSERT_TRUE(result);

    result = filc::utils::strStartsWith("abcd", "b");
    ASSERT_FALSE(result);

    result = filc::utils::strStartsWith("hello world!", "hello");
    ASSERT_TRUE(result);

    result = filc::utils::strStartsWith("hello world!", "world");
    ASSERT_FALSE(result);
}

TEST(tools, fileExists) {
    auto result = filc::utils::fileExists(FIXTURES_PATH "/utils/position.txt");
    ASSERT_TRUE(result);

    result = filc::utils::fileExists("non-existing-file.a_file_extension");
    ASSERT_FALSE(result);
}

TEST(tools, joinString) {
    std::vector<std::string> vect = {};
    auto result = filc::utils::joinString(vect, ", ");
    ASSERT_TRUE(result.empty());

    vect = {"a", "b"};
    result = filc::utils::joinString(vect, ".");
    ASSERT_STREQ("a.b", result.c_str());

    vect = {"hello"};
    result = filc::utils::joinString(vect, " ");
    ASSERT_STREQ("hello", result.c_str());

    vect = {"hello", "world"};
    result = filc::utils::joinString(vect, " ");
    ASSERT_STREQ("hello world", result.c_str());

    vect = {"hello ", "world"};
    result = filc::utils::joinString(vect, "");
    ASSERT_STREQ("hello world", result.c_str());

    vect = {"a", "list", "of", "word"};
    result = filc::utils::joinString(vect, ", ");
    ASSERT_STREQ("a, list, of, word", result.c_str());
}

TEST(tools, parseEscapedChar) {
    // Normal cases
    ASSERT_EQ('\'', filc::utils::parseEscapedChar("\\'"));
    ASSERT_EQ('\"', filc::utils::parseEscapedChar("\\\""));
    ASSERT_EQ('\?', filc::utils::parseEscapedChar("\\?"));
    ASSERT_EQ('\a', filc::utils::parseEscapedChar("\\a"));
    ASSERT_EQ('\b', filc::utils::parseEscapedChar("\\b"));
    ASSERT_EQ('\f', filc::utils::parseEscapedChar("\\f"));
    ASSERT_EQ('\n', filc::utils::parseEscapedChar("\\n"));
    ASSERT_EQ('\r', filc::utils::parseEscapedChar("\\r"));
    ASSERT_EQ('\t', filc::utils::parseEscapedChar("\\t"));
    ASSERT_EQ('\v', filc::utils::parseEscapedChar("\\v"));
    ASSERT_EQ('\\', filc::utils::parseEscapedChar("\\\\"));

    // Limit cases
    ASSERT_EQ('\0', filc::utils::parseEscapedChar(""));
    ASSERT_EQ('a', filc::utils::parseEscapedChar("a"));
    ASSERT_EQ('a', filc::utils::parseEscapedChar("ab"));
    ASSERT_EQ('a', filc::utils::parseEscapedChar("abcd"));
    ASSERT_EQ('\\', filc::utils::parseEscapedChar("\\c"));
}

TEST(tools, parseEscapedString) {
    ASSERT_STREQ("Hello\nWorld!", filc::utils::parseEscapedString("Hello\\nWorld!").c_str());
}
