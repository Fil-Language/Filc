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
#include "Message.h"
#include <gtest/gtest.h>
#include <sstream>

auto getMessageContent(filc::message::Message &message) -> std::string {
    std::stringstream stream;
    stream << message;

    std::string result(std::istreambuf_iterator<char>(stream), {});

    return result;
}

TEST(Message, constructor) {
    std::string expected = "My message";
    auto message = filc::message::Message(4, expected);
    ASSERT_EQ(4, message.getLevel());
    ASSERT_STREQ(expected.c_str(), getMessageContent(message).c_str());

    expected = "My message 2";
    message = filc::message::Message(9, expected);
    ASSERT_EQ(5, message.getLevel());
    ASSERT_STREQ(expected.c_str(), getMessageContent(message).c_str());
}

TEST(Message, print) {
    std::string expected = "My message";
    auto message = filc::message::Message(4, expected);
    ASSERT_STREQ(expected.c_str(), getMessageContent(message).c_str());
    ASSERT_STREQ("", getMessageContent(message).c_str());
}