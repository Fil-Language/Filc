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
#ifndef FILC_MESSAGE_H
#define FILC_MESSAGE_H

#include <string>
#include <iostream>

namespace filc::message {
    using LEVEL = enum LEVEL {
        /**
         * Information on the system (# of thread, compilation time, ...)
         */
        SYSTEM = 5,
        /**
         * Some additional information on the state of the compiler
         */
        INFO = 4,
        /**
         * Some additional information on the state of the compiler and the code parsed
         */
        DEBUG = 3,
        /**
         * Something is wrong, but not really important
         */
        WARNING = 2,
        /**
         * Something is wrong and compiler must terminate
         */
        ERROR = 1,
        /**
         * Always shown and terminate compiler
         */
        FATAL_ERROR = 0,
    };

    class Message {
    public:
        Message(LEVEL level, std::string content);

        virtual ~Message() = default;

        virtual auto print(std::ostream &out) -> std::ostream &;

        [[nodiscard]] auto getLevel() const -> LEVEL;

    protected:
        LEVEL _level;
        std::string _content;
        bool _printed;
    };
}

auto operator<<(std::ostream &out, filc::message::Message &message) -> std::ostream &;

#endif //FILC_MESSAGE_H
