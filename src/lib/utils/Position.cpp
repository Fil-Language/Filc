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
#include "Position.h"
#include "MessageCollector.h"
#include "Error.h"
#include <utility>
#include <fstream>

namespace filc::utils {
    Position::Position(std::string filename, unsigned int line, unsigned int column)
            : _filename(std::move(filename)), _line(line), _column(column) {}

    Position::Position(const antlr4::Token *token)
            : _filename(token->getTokenSource()->getSourceName()), _line(token->getLine()),
              _column(token->getCharPositionInLine()) {}

    auto Position::getFilename() const -> const std::string & {
        return _filename;
    }

    auto Position::getLine() const -> unsigned int {
        return _line;
    }

    auto Position::getColumn() const -> unsigned int {
        return _column;
    }

    auto Position::getContent() const -> std::string {
        std::ifstream file(_filename);
        if (!file.is_open() || !file.good()) {
            filc::message::MessageCollector::getCollector()->addError(
                    new filc::message::BasicError(filc::message::ERROR,
                                                  "File " + _filename + " cannot be open or read")
            );

            return "";
        }
        std::string line;

        for (unsigned int i = 0; i < _line; i++) {
            std::getline(file, line);
        }

        file.close();

        return line;
    }

    auto Position::dump(const std::string &color) const -> std::string {
        std::string nth = " " + std::to_string(_line) + " ";
        std::string res = std::string(nth.length() + 1, ' ') + _filename + "\n";

        res += nth + "|" + getContent() + "\n";
        res += std::string(nth.length(), ' ') + "|";
        std::string spaces = _column > 0 ? std::string(_column - 1, ' ') : "";
        res += spaces + color + "^" + "\033[0m" + "\n";

        return res;
    }
}