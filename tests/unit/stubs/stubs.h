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

#include "AST.h"
#include "Command.h"
#include "Schema.h"
#include <string>
#include <utility>

class TestExpression : public filc::ast::AbstractExpression {
public:
    TestExpression();

    auto withExpressionType(const std::shared_ptr<filc::ast::AbstractType> &expression_type) -> TestExpression &;

    auto resolveType(filc::environment::Environment *environment,
                     filc::message::MessageCollector *collector,
                     const std::shared_ptr<filc::ast::AbstractType> &preferred_type) -> void override;

    [[nodiscard]] auto isResolveTypeCalled() const -> bool;

    auto addNameToEnvironment(filc::environment::Environment *environment) const -> void override;

    auto generateIR(filc::message::MessageCollector *collector,
                    filc::environment::Environment *environment,
                    llvm::LLVMContext *context,
                    llvm::Module *module,
                    llvm::IRBuilder<> *builder) const -> llvm::Value * override;

private:
    bool _resolveType_called;
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

#endif//FILC_STUBS_H
