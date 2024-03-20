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
#ifndef FILC_PARSER_H
#define FILC_PARSER_H

#include "program/Program.h"
#include "MessageCollector.h"
#include <string>
#include <map>

namespace filc::grammar {
    template<typename T>
    class Parser {
    public:
        virtual ~Parser() = default;

        virtual auto parse(const std::string &filename, std::shared_ptr<message::MessageCollector> collector) -> void = 0;

        [[nodiscard]] auto getResult() const -> std::shared_ptr<T> {
            return _result;
        }

    protected:
        Parser() = default;

        auto setResult(const std::shared_ptr<T> &result) -> void {
            _result = result;
        }

    private:
        std::shared_ptr<T> _result;
    };

    class FilParser final : public Parser<ast::Program> {
    public:
        FilParser() = default;

        ~FilParser() override = default;

        auto parse(const std::string &filename, std::shared_ptr<message::MessageCollector> collector) -> void override;

    private:
        std::map<std::string, std::shared_ptr<ast::Program>> _program_cache;
    };
}// namespace filc::grammar

#endif//FILC_PARSER_H
