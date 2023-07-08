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
#include "ErrorsRegister.h"

ErrorsRegister *ErrorsRegister::_instance = nullptr;

ErrorsRegister::ErrorsRegister() {}

void ErrorsRegister::init() {
    if (_instance == nullptr) {
        _instance = new ErrorsRegister();
    }
}

void ErrorsRegister::clean() {
    if (_instance != nullptr) {
        _instance->_messages.clear();
    }
}

auto ErrorsRegister::containsError() -> bool {
    return _instance != nullptr && _instance->_contains_error;
}

auto ErrorsRegister::containsWarning() -> bool {
    return _instance != nullptr && _instance->_contains_warning;
}

void ErrorsRegister::addWarning(Message *message) {
    if (_instance != nullptr) {
        _instance->_messages.push_back(message);
        _instance->_contains_warning = true;
    }
}

void ErrorsRegister::addError(Message *message) {
    if (_instance != nullptr) {
        _instance->_messages.push_back(message);
        _instance->_contains_error = true;
    }
}

void ErrorsRegister::dump(std::ostream &out) {
    if (_instance != nullptr) {
        for (auto &message: _instance->_messages) {
            out << message->dump() << std::endl;
        }
    }
}
