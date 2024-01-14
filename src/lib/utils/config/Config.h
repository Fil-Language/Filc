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
#ifndef FILC_CONFIG_H
#define FILC_CONFIG_H

#include "Schema.h"
#include <memory>

namespace filc::utils::config {
    class Config final {
    public:
        static auto init(const std::string &name) -> void;

        static auto get() -> Config *;

        static auto save(const std::string &filename) -> void;

        [[nodiscard]] auto getName() const -> const std::string &;

        auto setName(const std::string &name) -> void;

        [[nodiscard]] auto getDescription() const -> const std::string &;

        auto setDescription(const std::string &description) -> void;

        [[nodiscard]] auto getVersion() const -> const std::string &;

        auto setVersion(const std::string &version) -> void;

        [[nodiscard]] auto getEntrypoint() const -> const std::string &;

        auto setEntrypoint(const std::string &entrypoint) -> void;

        [[nodiscard]] auto getNamespaces() const -> std::map<std::string, std::string>;

        [[nodiscard]] auto getNamespace(const std::string &name) const -> std::string;

        auto setNamespace(const std::string &name, const std::string &path) -> void;

    private:
        static Config *_instance;
        SchemaMap *_root;

        Config();

        Config(Config &b);
    };
}// namespace filc::utils::config

#endif//FILC_CONFIG_H
