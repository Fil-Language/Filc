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
#include <algorithm>

namespace filc::message {
    MessageCollector::MessageCollector(LEVEL level)
            : _level(level) {}

    MessageCollector::~MessageCollector() {
        std::for_each(_messages.begin(), _messages.end(), [](Message *message) {
            delete message;
        });
        std::for_each(_errors.begin(), _errors.end(), [](Message *error) {
            delete error;
        });
    }

    auto MessageCollector::addMessage(Message *message) -> MessageCollector & {
        _messages.push_back(message);

        return *this;
    }

    auto MessageCollector::addError(Message *error) -> MessageCollector & {
        _errors.push_back(error);

        return *this;
    }

    auto MessageCollector::hasMessages() -> bool {
        return !_messages.empty();
    }

    auto MessageCollector::printMessages() -> MessageCollector & {
        std::for_each(_messages.begin(), _messages.end(), [this](Message *message) {
            if (message->getLevel() <= _level) {
                std::cout << *message << std::endl;
            }
        });

        _messages.clear();

        return *this;
    }

    auto MessageCollector::hasErrors() -> bool {
        return !_errors.empty();
    }

    auto MessageCollector::printErrors() -> MessageCollector & {
        std::for_each(_errors.begin(), _errors.end(), [this](Message *error) {
            if (error->getLevel() <= _level) {
                std::cerr << *error << std::endl;
            }
        });

        _errors.clear();

        return *this;
    }

    auto MessageCollector::getCollector(LEVEL level) -> MessageCollector * {
        static auto *collector = new MessageCollector(level);

        return collector;
    }
}
