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
#include "utils.h"

#include <fstream>
#include <sstream>

std::string &ltrim(std::string &input) {
    return input.erase(0, input.find_first_not_of(' '));
}

Position::Position(int line, int column, const std::string &filename)
        : _line(line), _column(column), _filename(filename) {}

int Position::getLine() const {
    return _line;
}

int Position::getColumn() const {
    return _column;
}

std::string Position::getFilename() const {
    return _filename;
}

std::string Position::getLineContent() const {
    std::ifstream file(_filename);
    std::string line;

    for (int i = 0; i < _line; i++) {
        std::getline(file, line);
    }

    file.close();

    return line;
}

std::string Position::dump() const {
    return _filename + ":" + std::to_string(_line) + ":" + std::to_string(_column);
}

std::string replace(const std::string &str, char from, char to) {
    auto cpy = str;
    for (char &c: cpy) {
        if (c == from) {
            c = to;
        }
    }

    return cpy;
}

std::string to_string(char *str) {
    std::stringstream ss;
    ss << str;

    return ss.str();
}

std::vector<std::string> split(const std::string &str, char delim) {
    std::vector<std::string> result;

    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

std::string extension(const std::string &filename) {
    auto dot = filename.find_last_of('.');
    return filename.substr(dot + 1);
}
