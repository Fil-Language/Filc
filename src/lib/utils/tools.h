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
#ifndef FILC_TOOLS_H
#define FILC_TOOLS_H

#include <string>
#include <vector>

namespace filc::utils {
    auto parseEscapedChar(const std::string &escaped_char) -> char;

    auto parseEscapedString(const std::string &escaped_string) -> std::string;

    auto fileExists(const std::string &filename) -> bool;

    auto strStartsWith(const std::string &source, const std::string &needle) -> bool;

    auto splitString(const std::string &source, char delimiter) -> std::vector<std::string>;

    auto joinString(const std::vector<std::string> &source, const std::string &delimiter) -> std::string;

    auto trim(const std::string &input) -> std::string;

    auto computeVersionNumber(const std::string &version) -> unsigned int;

    auto getFilenameFromModule(const std::string &module) -> std::string;
}// namespace filc::utils

#endif//FILC_TOOLS_H
