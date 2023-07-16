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
#include "MessageCollector.h"
#include <gtest/gtest.h>

TEST(MessageCollector, getCollector) {
    auto *collector1 = filc::message::MessageCollector::getCollector();
    auto *collector2 = filc::message::MessageCollector::getCollector();
    ASSERT_EQ(collector1, collector2);

    collector1->addMessage(new filc::message::Message(filc::message::INFO, "Hello"));

    ASSERT_TRUE(collector1->hasMessages());
    ASSERT_TRUE(collector2->hasMessages());
}

TEST(MessageCollector, hasMessages) {
    auto *collector = filc::message::MessageCollector::getCollector();

    ASSERT_FALSE(collector->hasMessages());
    ASSERT_FALSE(collector->hasErrors());
    collector->addMessage(new filc::message::Message(filc::message::INFO, "Hello"));
    ASSERT_TRUE(collector->hasMessages());
    ASSERT_FALSE(collector->hasErrors());
}

TEST(MessageCollector, hasErrors) {
    auto *collector = filc::message::MessageCollector::getCollector();

    ASSERT_FALSE(collector->hasMessages());
    ASSERT_FALSE(collector->hasErrors());
    collector->addError(new filc::message::Message(filc::message::INFO, "Hello"));
    ASSERT_FALSE(collector->hasMessages());
    ASSERT_TRUE(collector->hasErrors());
}

TEST(MessageCollector, printMessages) {
    auto *collector = filc::message::MessageCollector::getCollector();
    collector->addMessage(new filc::message::Message(filc::message::INFO, "Hello"));
    collector->printMessages();

    ASSERT_FALSE(collector->hasMessages());
}

TEST(MessageCollector, printErrors) {
    auto *collector = filc::message::MessageCollector::getCollector();
    collector->addError(new filc::message::Message(filc::message::INFO, "Hello"));
    collector->printErrors();

    ASSERT_FALSE(collector->hasErrors());
}