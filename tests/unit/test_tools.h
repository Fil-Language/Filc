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
#include "AST_decl.h"
#include "MessageCollector.h"
#include "stubs.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <sstream>

using namespace ::testing;

#define FIXTURES_PATH "../../../tests/unit/Fixtures"

#define COLLECTOR filc::message::MessageCollector::getCollector()

#define ASSERT_TYPE(expected, type) ASSERT_STREQ(expected, type->dump().c_str())

#define ASSERT_IDENTIFIER(expected, identifier) \
    ASSERT_STREQ(expected, std::dynamic_pointer_cast<filc::ast::Identifier>(identifier)->getName().c_str())

#define ASSERT_CLASSIC_OPERATOR(expected, op)                                                                          \
    ASSERT_EQ(                                                                                                         \
        filc::ast::ClassicOperator::expected, std::dynamic_pointer_cast<filc::ast::ClassicOperator>(op)->getOperator() \
    )

#define ASSERT_LITERAL(expected, type, literal) \
    ASSERT_EQ(expected, std::dynamic_pointer_cast<filc::ast::type>(literal)->getValue())

#define ASSERT_VARIABLE_DECLARATION(constant, name, type, value, literal, variable)            \
    auto var_##variable = std::dynamic_pointer_cast<filc::ast::VariableDeclaration>(variable); \
    ASSERT_NE(nullptr, var_##variable);                                                        \
    ASSERT_EQ(constant, var_##variable->isConstant());                                         \
    ASSERT_IDENTIFIER(name, var_##variable->getIdentifier());                                  \
    ASSERT_TYPE(type, var_##variable->getType());                                              \
    ASSERT_LITERAL(value, literal, var_##variable->getAssignation())

auto getMessageContent(filc::message::Message &message) -> std::string;

#define ASSERT_MESSAGE_CONTENT(expected, message) ASSERT_STREQ(expected, getMessageContent(message).c_str())

auto getOutput(const std::function<void()> &expression, const std::function<void(const std::string &)> &assertion)
    -> void;

auto getErrOutput(const std::function<void()> &expression, const std::function<void(const std::string &)> &assertion)
    -> void;

auto redirectCin(const std::function<void(std::stringstream &stream)> &function) -> void;

auto toStringArray(const std::vector<std::string> &data) -> std::vector<char *>;
