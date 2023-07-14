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
#include <utility>

constexpr uint MAX_LEVEL = 5;

namespace filc::message {
    Message::Message(uint level, std::string content)
            : _level(level <= MAX_LEVEL ? level : MAX_LEVEL), _content(std::move(content)), _printed(false) {}

    auto Message::print(std::ostream &out) -> std::ostream & {
        if (_printed) {
            return out;
        }

        out << _content;
        _printed = true;

        return out;
    }

    auto Message::getLevel() const -> uint {
        return _level;
    }
}

auto operator<<(std::ostream &out, filc::message::Message &message) -> std::ostream & {
    return message.print(out);
}