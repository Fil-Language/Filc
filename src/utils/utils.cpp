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
#include <utility>

auto ltrim(std::string &input) -> std::string & {
    return input.erase(0, input.find_first_not_of(' '));
}

Position::Position(int line, int column, std::string filename)
    : _line(line), _column(column), _filename(std::move(filename)) {}

auto Position::getLine() const -> int {
    return _line;
}

auto Position::getColumn() const -> int {
    return _column;
}

auto Position::getFilename() const -> std::string {
    return _filename;
}

auto Position::getLineContent() const -> std::string {
    std::ifstream file(_filename);
    std::string line;

    for (int i = 0; i < _line; i++) {
        std::getline(file, line);
    }

    file.close();

    return line;
}

auto Position::dump() const -> std::string {
    return _filename + ":" + std::to_string(_line) + ":" + std::to_string(_column);
}

auto replace(const std::string &str, char from, char target) -> std::string {
    auto copy = str;
    for (char &current: copy) {
        if (current == from) {
            current = target;
        }
    }

    return copy;
}

auto toString(char *str) -> std::string {
    std::stringstream stream;
    stream << str;

    return stream.str();
}

auto split(const std::string &str, char delim) -> std::vector<std::string> {
    std::vector<std::string> result;

    std::stringstream stream(str);
    std::string item;
    while (std::getline(stream, item, delim)) {
        result.push_back(item);
    }

    return result;
}

auto extension(const std::string &filename) -> std::string {
    auto dot = filename.find_last_of('.');
    return filename.substr(dot + 1);
}
