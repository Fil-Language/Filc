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
#ifndef FILC_POSITION_H
#define FILC_POSITION_H

#include "antlr4-runtime.h"
#include <string>

namespace filc::utils {
    class AbstractPosition {
    public:
        [[nodiscard]] virtual auto dump(const std::string &color) const -> std::string = 0;

        virtual ~AbstractPosition() = default;

        [[nodiscard]] virtual auto getLine() const -> unsigned int = 0;

    protected:
        AbstractPosition() = default;
    };

    class SimplePosition final : public AbstractPosition {
    public:
        SimplePosition(std::string filename, unsigned int line, unsigned int column);

        explicit SimplePosition(const antlr4::Token *token);

        [[nodiscard]] auto getFilename() const -> const std::string &;

        [[nodiscard]] auto getLine() const -> unsigned int override;

        [[nodiscard]] auto getColumn() const -> unsigned int;

        [[nodiscard]] auto getContent() const -> std::string;

        [[nodiscard]] auto dump(const std::string &color) const -> std::string override;

    private:
        std::string _filename;
        unsigned int _line;
        unsigned int _column;
    };

    class DoublePosition final : public AbstractPosition {
    public:
        DoublePosition(std::string filename, unsigned int start_line, unsigned int start_column,
                       unsigned int end_line, unsigned int end_column);

        DoublePosition(const antlr4::Token *start_token, const antlr4::Token *end_token);

        [[nodiscard]] auto getFilename() const -> const std::string &;

        [[nodiscard]] auto getStartPosition() const -> std::pair<unsigned int, unsigned int>;

        [[nodiscard]] auto getEndPosition() const -> std::pair<unsigned int, unsigned int>;

        [[nodiscard]] auto getLine() const -> unsigned int override;

        [[nodiscard]] auto getContent() const -> std::vector<std::string>;

        [[nodiscard]] auto dump(const std::string &color) const -> std::string override;

    private:
        std::string _filename;
        std::pair<unsigned int, unsigned int> _start_position;
        std::pair<unsigned int, unsigned int> _end_position;
    };
}

#endif //FILC_POSITION_H
