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
std::string &ltrim(std::string &input);

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
    Position(int line, int column, const std::string &filename);

    int getLine() const;

    int getColumn() const;

    std::string getFilename() const;

    /**
     * @return The line in the file where the position is
     */
    std::string getLineContent() const;

    std::string dump() const;

private:
    int _line;
    int _column;
    std::string _filename;
};

std::string replace(const std::string &str, char from, char to);

std::string to_string(char *str);

std::vector<std::string> split(const std::string &str, char delim);

std::string extension(const std::string &filename);

#endif //FILC_UTILS_H
