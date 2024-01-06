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
#ifndef FILC_COMMAND_H
#define FILC_COMMAND_H

#include <string>
#include <vector>

namespace filc::utils::command {
    class Command {
    public:
        [[nodiscard]] auto getName() const -> const std::string &;

        [[nodiscard]] auto getDescription() const -> const std::string &;

        [[nodiscard]] auto getAliases() const -> const std::vector<std::string> &;

        [[nodiscard]] auto matchName(const std::string &name) const -> bool;

        [[nodiscard]] virtual auto help() const -> std::string;

        [[nodiscard]] virtual auto run() -> int;

    protected:
        Command(std::string name, std::string description, const std::vector<std::string> &aliases);

    private:
        const std::string _name;
        const std::string _description;
        const std::vector<std::string> _aliases;
    };
}

#endif //FILC_COMMAND_H
