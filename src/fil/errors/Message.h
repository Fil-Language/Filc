/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
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

#include "utils.h"
#include <string>

class Message {
protected:
    Message(std::string message, Position *position);

public:
    virtual ~Message() = default;

    [[nodiscard]] virtual auto dump() const -> std::string = 0;

protected:
    std::string _message;
    Position *_position;
};

class BasicWarning : public Message {
public:
    explicit BasicWarning(const std::string &message);

    [[nodiscard]] auto dump() const -> std::string override;
};

class Warning : public Message {
public:
    Warning(const std::string &message, Position *position);

    [[nodiscard]] auto dump() const -> std::string override;
};

class BasicError : public Message {
public:
    explicit BasicError(const std::string &message);

    [[nodiscard]] auto dump() const -> std::string override;
};

class Error : public Message {
public:
    Error(const std::string &message, Position *position);

    [[nodiscard]] auto dump() const -> std::string override;
};

#endif//FILC_MESSAGE_H
