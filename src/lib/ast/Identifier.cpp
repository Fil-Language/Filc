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
#include "AST.h"
#include "Error.h"
#include <utility>

namespace filc::ast {
    Identifier::Identifier(antlr4::Token *token)
            : _name(token->getText()) {
        setPosition(new filc::utils::Position(token));
    }

    Identifier::Identifier(std::string name)
            : _name(std::move(name)) {}

    auto Identifier::getName() const -> const std::string & {
        return _name;
    }

    auto Identifier::resolveType(filc::environment::Environment *environment,
                                 filc::message::MessageCollector *collector,
                                 const std::shared_ptr<AbstractType> &preferred_type) -> void {
        if (!environment->hasName(_name, preferred_type)) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR, _name + " is not defined", getPosition())
            );
        } else {
            auto *name = environment->getName(_name, nullptr);
            setExpressionType(name->getType());
        }
    }

    auto Identifier::addNameToEnvironment(filc::environment::Environment *environment) const -> void {
        environment->addName(_name, getExpressionType());
    }

    auto Identifier::generateIR(filc::message::MessageCollector *collector,
                                filc::environment::Environment *environment,
                                llvm::LLVMContext *context,
                                llvm::Module *module,
                                llvm::IRBuilder<> *builder) const -> llvm::Value * {
        auto *name = environment->getName(_name, getExpressionType());
        if (name == nullptr) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR, _name + " is not defined", getPosition())
            );

            return nullptr;
        }
        auto *value = name->getValue();
        if (value == nullptr) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR, _name + " is not defined", getPosition())
            );
        }

        return value;
    }
}