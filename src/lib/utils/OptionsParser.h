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

#ifndef FILC_OPTIONSPARSER_H
#define FILC_OPTIONSPARSER_H

#include "cxxopts.hpp"

namespace filc::utils {
    class OptionsParser final {
    public:
        OptionsParser();

        auto parse(int argc, const char **argv) -> bool;

        auto getOptions() const -> const cxxopts::Options &;

        auto getFilenames() const -> const std::vector<std::string> &;

        auto getVerbose() const -> uint;

        auto isDebug() const -> bool;

        auto getOut() const -> const std::string &;

        static auto extension(const std::string &filename) -> std::string;

    private:
        cxxopts::Options _options;
        std::vector<std::string> _filenames;
        uint _verbose;
        bool _debug;
        std::string _out;

        auto help() -> void;

        static auto version() -> void;
    };
}

#endif//FILC_OPTIONSPARSER_H
