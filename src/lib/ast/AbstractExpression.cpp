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
#include "tools.h"

namespace filc::ast {
    AbstractExpression::~AbstractExpression() {
        delete _position;
    }

    auto AbstractExpression::isExported() const -> bool {
        return _exported;
    }

    auto AbstractExpression::setExported(bool exported) -> void {
        _exported = exported;
    }

    auto AbstractExpression::getPosition() const -> filc::utils::Position * {
        return _position;
    }

    auto AbstractExpression::setPosition(filc::utils::Position *position) -> void {
        _position = position;
    }

    auto AbstractExpression::getExpressionType() const -> AbstractType * {
        return _expression_type;
    }

    auto AbstractExpression::setExpressionType(AbstractType *expression_type) -> void {
        _expression_type = expression_type;
    }

    auto AbstractExpression::resolveType(filc::environment::Environment *environment,
                                         filc::message::MessageCollector *collector,
                                         AbstractType *preferred_type) -> void {
        collector->addError(
                new filc::message::Error(filc::message::FATAL_ERROR,
                                         "resolveType not implemented",
                                         getPosition())
        );
    }

    auto AbstractExpression::addNameToEnvironment(filc::environment::Environment *environment) const -> void {
        auto name = filc::utils::joinString(filc::utils::splitString(environment->getModule(), '.'), "_")
                    + "_" + std::to_string(getPosition()->getLine());
        environment->addName(name, getExpressionType());
    }

    auto AbstractExpression::generateIR(filc::message::MessageCollector *collector,
                                        filc::environment::Environment *environment,
                                        llvm::LLVMContext *context, llvm::Module *module,
                                        llvm::IRBuilder<> *builder) const -> llvm::Value * {
        collector->addError(
                new filc::message::Error(filc::message::FATAL_ERROR,
                                         "generateIR not implemented",
                                         getPosition())
        );

        return nullptr;
    }
}
