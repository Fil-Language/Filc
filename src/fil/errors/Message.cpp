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
#include "Message.h"

std::string printMessage(const std::string &message,
                         Position *position,
                         const std::string &type,
                         const std::string &color) {
    static const std::string reset = "\033[0m";

    std::string res = color + type + ": " + reset + message + "\n  " + position->dump() + "\n\n";

    std::string n = " " + std::to_string(position->getLine()) + " ";

    res += n + "|" + position->getLineContent() + "\n";
    res += std::string(n.length(), ' ') + "|";
    std::string spaces = position->getColumn() > 0 ? std::string(position->getColumn() - 1, ' ') : "";
    res += spaces + color + "^" + reset + "\n";

    return res;
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

Message::Message(const std::string &message, Position *position)
        : _message(message), _position(position) {}

BasicWarning::BasicWarning(const std::string &message) : Message(message, nullptr) {}

std::string BasicWarning::dump() const {
    return "\033[1;33mWARNING: " + _message + "\033[0m\n";
}

Warning::Warning(const std::string &message, Position *position) : Message(message, position) {}

std::string Warning::dump() const {
    return printMessage(_message, _position, "WARNING", "\033[1;33m");
}

BasicError::BasicError(const std::string &message) : Message(message, nullptr) {}

std::string BasicError::dump() const {
    return "\033[1;31mERROR: " + _message + "\033[0m\n";
}

Error::Error(const std::string &message, Position *position) : Message(message, position) {}

std::string Error::dump() const {
    return printMessage(_message, _position, "ERROR", "\033[1;31m");
}
