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
#include "MessageCollector.h"
#include "DevWarning.h"
#include "tools.h"
#include "llvm/IR/Constants.h"

namespace filc::ast {
    CharacterLiteral::CharacterLiteral(char value)
            : AbstractLiteral<char>(value) {}

    auto CharacterLiteral::stringToChar(const std::string &snippet, antlr4::Token *token) -> char {
        auto value = snippet.substr(1, snippet.size() - 2);

        if (value.size() == 1) {
            // Just a simple char
            return value[0];
        }

        if (value.size() == 2) {
            // An escaped char \\ + ['"?abfnrtv\\]
            return filc::utils::parseEscapedChar(value);
        }

        // There is a problem with the lexer
        if (token != nullptr) {
            filc::message::MessageCollector::getCollector()->addError(new filc::message::DevWarning(
                    2,
                    new filc::utils::Position(token),
                    "Lexer found a character that is not regular: " + snippet
            ));
        }

        return '\0';
    }

    auto CharacterLiteral::resolveType(filc::environment::Environment *environment,
                                       filc::message::MessageCollector *collector,
                                       const std::shared_ptr<AbstractType> &preferred_type) -> void {
        if (!environment->hasType("char")) {
            environment->addType(std::make_shared<Type>(new Identifier("char")));
        }

        setExpressionType(environment->getType("char"));
    }

    auto CharacterLiteral::generateIR(filc::message::MessageCollector *collector,
                                      filc::environment::Environment *environment,
                                      llvm::LLVMContext *context,
                                      llvm::Module *module,
                                      llvm::IRBuilder<> *builder) const -> llvm::Value * {
        return llvm::ConstantInt::get(*context, llvm::APInt(8, getValue()));
    }
}
