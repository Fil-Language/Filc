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
    SimplePosition::SimplePosition(std::string filename, unsigned int line, unsigned int column)
            : _filename(std::move(filename)), _line(line), _column(column) {}

    SimplePosition::SimplePosition(const antlr4::Token *token)
            : _filename(token->getTokenSource()->getSourceName()), _line(token->getLine()),
              _column(token->getCharPositionInLine()) {}

    auto SimplePosition::getFilename() const -> const std::string & {
        return _filename;
    }

    auto SimplePosition::getLine() const -> unsigned int {
        return _line;
    }

    auto SimplePosition::getColumn() const -> unsigned int {
        return _column;
    }

    auto SimplePosition::getContent() const -> std::string {
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

    auto SimplePosition::dump(const std::string &color) const -> std::string {
        std::string nth = " " + std::to_string(_line) + " ";
        std::string res = std::string(nth.length() + 1, ' ') + _filename + "\n";

        res += nth + "|" + getContent() + "\n";
        res += std::string(nth.length(), ' ') + "|";
        std::string spaces = _column > 0 ? std::string(_column, ' ') : "";
        res += spaces + color + "^" + "\033[0m" + "\n";

        return res;
    }

    DoublePosition::DoublePosition(std::string filename, unsigned int start_line, unsigned int start_column,
                                   unsigned int end_line, unsigned int end_column)
            : _filename(std::move(filename)), _start_position(std::make_pair(start_line, start_column)),
              _end_position(std::make_pair(end_line, end_column)) {}

    DoublePosition::DoublePosition(const antlr4::Token *start_token, const antlr4::Token *end_token)
            : _filename(start_token->getTokenSource()->getSourceName()) {
        if (end_token->getTokenSource()->getSourceName() != _filename) {
            filc::message::MessageCollector::getCollector()->addError(
                    new filc::message::BasicError(filc::message::FATAL_ERROR,
                                                  "Tried to create a double position from two different sources: " +
                                                  _filename + " and " + end_token->getTokenSource()->getSourceName())
            );
        }

        _start_position = std::make_pair(
                start_token->getLine(),
                start_token->getCharPositionInLine()
        );
        _end_position = std::make_pair(
                end_token->getLine(),
                end_token->getCharPositionInLine()
        );
    }

    auto DoublePosition::getFilename() const -> const std::string & {
        return _filename;
    }

    auto DoublePosition::getStartPosition() const -> std::pair<unsigned int, unsigned int> {
        return _start_position;
    }

    auto DoublePosition::getEndPosition() const -> std::pair<unsigned int, unsigned int> {
        return _end_position;
    }

    auto DoublePosition::getLine() const -> unsigned int {
        return getStartPosition().first;
    }

    auto DoublePosition::getContent() const -> std::vector<std::string> {
        std::ifstream file(_filename);
        if (!file.is_open() || !file.good()) {
            filc::message::MessageCollector::getCollector()->addError(
                    new filc::message::BasicError(filc::message::ERROR,
                                                  "File " + _filename + " cannot be open or read")
            );

            return {};
        }
        std::vector<std::string> content;

        auto start_line = _start_position.first;
        unsigned int idx = 0;
        std::string line;
        for (; idx < start_line; idx++) {
            std::getline(file, line);
        }
        content.push_back(line);

        auto end_line = _end_position.first;
        if (end_line > start_line) {
            for (; idx < end_line; idx++) {
                std::getline(file, line);
                content.push_back(line);
            }
        }

        file.close();

        return content;
    }

    auto DoublePosition::dump(const std::string &color) const -> std::string {
        auto start_line = _start_position.first;
        auto start_column = _start_position.second;
        auto end_line = _end_position.first;
        auto end_column = _end_position.second;
        auto content = getContent();

        if (start_line == end_line && content.size() == 1) { // Single line
            auto nth = " " + std::to_string(start_line) + " ";
            auto res = std::string(nth.length() + 1, ' ') + _filename + "\n";

            auto line = content[0];

            res += nth + "|" + line + "\n";
            res += std::string(nth.length(), ' ') + "|";
            auto spaces = start_column > 0 ? std::string(start_column, ' ') : "";
            res += spaces + color + std::string(end_column - start_column, '^') + "\033[0m" + "\n";

            return res;
        }
        if (content.size() > 1) { // Multi line
            std::vector<std::string> nths;
            auto nth_end = " " + std::to_string(end_line) + " ";
            for (unsigned int i = start_line; i <= end_line; i++) {
                auto line = " " + std::to_string(i) + " ";

                nths.push_back(line + std::string(nth_end.length() - line.length(), ' '));
            }
            auto nth_space = std::string(nth_end.length(), ' ') + "|";

            auto res = std::string(nth_end.length() + 1, ' ') + _filename + "\n";

            auto spaces = start_column > 0 ? std::string(start_column, ' ') : "";
            res += nth_space + spaces + color + "v" + "\033[0m" + "\n";

            for (unsigned int i = 0; i < nths.size(); i++) {
                res += nths[i] + "|" + content[i] + "\n";
            }

            spaces = end_column > 0 ? std::string(end_column, ' ') : "";
            res += nth_space + spaces + color + "^" + "\033[0m" + "\n";

            return res;
        }

        filc::message::MessageCollector::getCollector()->addError(
                new filc::message::BasicError(filc::message::WARNING,
                                              "Cannot get position content")
        );

        return "";

    }
}