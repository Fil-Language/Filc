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
#ifndef FILC_STUBS_H
#define FILC_STUBS_H

#include "AbstractExpression.h"
#include "Command.h"
#include "Compiler.h"
#include "Parser.h"
#include "Schema.h"
#include <string>
#include <utility>

class TestExpression : public filc::ast::AbstractExpression {
public:
    TestExpression() = default;
};

class CustomSchema1 : public filc::utils::config::AbstractSchema {
public:
    explicit CustomSchema1(int value)
        : AbstractSchema(), _value(value) {}

    ~CustomSchema1() override = default;

    int _value;
};

class CustomSchema2 : public filc::utils::config::AbstractSchema {
public:
    explicit CustomSchema2(std::string value)
        : AbstractSchema(), _value(std::move(value)) {}

    ~CustomSchema2() override = default;

    std::string _value;
};

class IncompleteCommand : public filc::utils::command::Command {
public:
    IncompleteCommand() : Command("name", "description", {}) {}
};

class CustomCommand : public filc::utils::command::Command {
public:
    CustomCommand() : Command("custom", "My custom command", {"c", "custom-command"}) {}

    [[nodiscard]] auto help() const -> std::string override {
        return "Help of custom command";
    }

    auto run(int argc, char **argv) -> int override {
        return 0;
    }
};

class CompilerStub : public filc::Compiler {
public:
    explicit CompilerStub(int return_value)
        : _return_value(return_value) {}

    ~CompilerStub() override = default;

    auto compile() -> int override {
        return _return_value;
    };

private:
    int _return_value;
};

class ParserStub final : public filc::grammar::Parser<filc::ast::Program> {
public:
    ParserStub() = default;

    auto parse(const std::string &filename, std::shared_ptr<filc::message::MessageCollector> collector) -> void override {
        setResult(std::shared_ptr<filc::ast::Program>(new filc::ast::Program(filename, {}, {}))); // NOLINT(*-make-shared)
    }
};

#endif//FILC_STUBS_H
