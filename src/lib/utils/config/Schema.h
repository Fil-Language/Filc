/**
 * MIT License
 *
 * Copyright (c) 2024-Present Kevin Traini
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
#ifndef FILC_SCHEMA_H
#define FILC_SCHEMA_H

#include <map>
#include <string>

namespace filc::utils::config {
    class AbstractSchema {
    public:
        template<typename T>
        auto as() -> T * {
            return dynamic_cast<T *>(this);
        }

        virtual ~AbstractSchema() = default;

    protected:
        AbstractSchema() = default;
    };

    class SchemaMap : public AbstractSchema {
    public:
        SchemaMap();

        ~SchemaMap() override;

        [[nodiscard]] auto get(const std::string &key) const -> AbstractSchema *;

        auto set(const std::string &key, AbstractSchema *value) -> void;

    private:
        std::map<std::string, AbstractSchema *> _nodes;
    };

    class SchemaString : public AbstractSchema {
    public:
        explicit SchemaString(std::string value);

        ~SchemaString() override;

        [[nodiscard]] auto get() const -> const std::string &;

        auto set(const std::string &value) -> void;

    private:
        std::string _value;
    };
}// namespace filc::utils::config

#endif//FILC_SCHEMA_H
