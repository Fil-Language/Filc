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
#include "tools.h"
#include "Config.h"
#include <algorithm>
#include <filesystem>
#include <fstream>

namespace filc::utils {
    auto parseEscapedChar(const std::string &escaped_char) -> char {
        if (escaped_char.length() == 2 && escaped_char[0] == '\\') {
            // An escaped char \\ + ['"?abfnrtv\\]
            switch (escaped_char[1]) {
                case '\'':
                    return '\'';
                case '"':
                    return '"';
                case '?':
                    return '\?';
                case 'a':
                    return '\a';
                case 'b':
                    return '\b';
                case 'f':
                    return '\f';
                case 'n':
                    return '\n';
                case 'r':
                    return '\r';
                case 't':
                    return '\t';
                case 'v':
                    return '\v';
                case '\\':
                    return '\\';
                default:
                    break;
            }
        }

        return escaped_char[0];
    }

    auto parseEscapedString(const std::string &escaped_string) -> std::string {
        std::string result;

        for (unsigned int i = 0; i < escaped_string.length(); i++) {
            if (escaped_string[i] == '\\' && i + 1 < escaped_string.length()) {
                result += parseEscapedChar(escaped_string.substr(i, 2));
                i++;
            } else {
                result += escaped_string[i];
            }
        }

        return result;
    }

    auto fileExists(const std::string &filename) -> bool {
        std::ifstream file(filename);
        auto result = file.good() && file.is_open();
        file.close();

        return result;
    }

    auto strStartsWith(const std::string &source, const std::string &needle) -> bool {
        return source.find(needle) == 0;
    }

    auto splitString(const std::string &source, char delimiter) -> std::vector<std::string> {
        auto str = source;
        std::vector<std::string> result;

        while (!str.empty()) {
            auto position = str.find(delimiter);
            if (position == std::string::npos) {
                result.push_back(str);
                break;
            }
            result.push_back(str.substr(0, position));
            str.erase(0, position + 1);
        }

        return result;
    }

    auto joinString(const std::vector<std::string> &source, const std::string &delimiter) -> std::string {
        std::string result;

        for (const auto &item: source) {
            result += item + delimiter;
        }

        return result.substr(0, result.length() - delimiter.length());
    }

    auto trim(const std::string &input) -> std::string {
        static const std::string WHITESPACE = " \n\r\t\f\v";
        const auto begin                    = input.find_first_not_of(WHITESPACE);
        const auto copy                     = input.substr(begin);
        const auto end                      = copy.find_last_not_of(WHITESPACE);

        return copy.substr(0, end + 1);
    }

    auto computeVersionNumber(const std::string &version) -> unsigned int {
        auto parts = splitString(version, '.');
        if (parts.size() != 3) {
            return 0;
        }

        int major      = std::stoi(parts[0]);
        int minor      = std::stoi(parts[1]);
        auto sub_parts = splitString(parts[2], '-');
        int patch      = std::stoi(sub_parts[0]);

        return ((major) * 1000000 + (minor) * 1000 + (patch));
    }

    auto getFilePathForModule(const std::string &base_path, const std::vector<std::string> &module_parts) -> std::string {
        const auto &last_part = module_parts.back();
        std::vector<std::string> sub_parts(module_parts.begin(), module_parts.end() - 1);
        const auto path = base_path + "/" + (sub_parts.empty() ? "" : (joinString(sub_parts, "/") + "/"));

        if (std::filesystem::exists(path + last_part + ".fil")) {
            return path + last_part + ".fil";
        }
        if (std::filesystem::exists(path + last_part + "/main.fil")) {
            return path + last_part + "/main.fil";
        }
        if (std::filesystem::exists(path + last_part + "/index.fil")) {
            return path + last_part + "/index.fil";
        }

        return "";
    }

    auto getFilenameFromModule(const std::string &module) -> std::string {
        auto parts = splitString(module, '.');
        if (parts.empty()) {
            throw std::logic_error("Module name should not be empty");
        }

        const auto config = utils::config::Config::get();
        std::string current_module;
        std::string found;
        while (!parts.empty()) {
            current_module += current_module.empty() ? parts.front() : "." + parts.front();
            parts.erase(parts.begin(), parts.begin() + 1);
            auto path = config->getNamespace(current_module);
            if (!path.empty()) {
                auto potential_path = getFilePathForModule(path, parts);
                if (!potential_path.empty()) {
                    found = potential_path;
                    break;
                }
            }
        }

        if (found.empty()) {
            throw std::logic_error("Module " + module + " not found");
        }

        return found;
    }
}// namespace filc::utils
