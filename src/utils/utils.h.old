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
#ifndef FILC_UTILS_H
#define FILC_UTILS_H

#include <string>
#include <vector>

/**
 * Trim left
 *
 * @param input
 * @return
 */
auto ltrim(std::string &input) -> std::string &;

/**
 * Describe a position in a file
 */
class Position {
public:
    /**
     * Main constructor
     *
     * @param line
     * @param column
     * @param filename
     */
    Position(int line, int column, std::string filename);

    [[nodiscard]] auto getLine() const -> int;

    [[nodiscard]] auto getColumn() const -> int;

    [[nodiscard]] auto getFilename() const -> std::string;

    /**
     * @return The line in the file where the position is
     */
    [[nodiscard]] auto getLineContent() const -> std::string;

    [[nodiscard]] auto dump() const -> std::string;

private:
    int _line;
    int _column;
    std::string _filename;
};

auto replace(const std::string &str, char from, char target) -> std::string;

auto toString(char *str) -> std::string;

auto split(const std::string &str, char delim) -> std::vector<std::string>;

auto extension(const std::string &filename) -> std::string;

#endif //FILC_UTILS_H
