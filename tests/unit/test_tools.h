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
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MessageCollector.h"
#include <sstream>
#include "AST.h"

using namespace ::testing;

#define FIXTURES_PATH "../../../tests/unit/Fixtures"

#define COLLECTOR filc::message::MessageCollector::getCollector()

#define ASSERT_TYPE(expected, type) ASSERT_STREQ(expected, type->dump().c_str())

#define ASSERT_IDENTIFIER(expected, identifier) ASSERT_STREQ(expected, dynamic_cast<filc::ast::Identifier *>(identifier)->getName().c_str())

#define ASSERT_CLASSIC_OPERATOR(expected, op) ASSERT_EQ(filc::ast::ClassicOperator::expected, dynamic_cast<filc::ast::ClassicOperator *>(op)->getOperator())

#define ASSERT_ASSIGNATION_OPERATOR(expected, op) ASSERT_CLASSIC_OPERATOR(expected, dynamic_cast<filc::ast::AssignationOperator *>(op)->getInnerOperator())

#define ASSERT_LITERAL(expected, type, literal) ASSERT_EQ(expected, dynamic_cast<filc::ast::type *>(literal)->getValue())

#define ASSERT_VARIABLE_DECLARATION(constant, name, type, value, literal, variable) \
    auto *var_##variable = dynamic_cast<filc::ast::VariableDeclaration *>(variable);\
    ASSERT_NE(nullptr, var_##variable); \
    ASSERT_EQ(constant, var_##variable->isConstant()); \
    ASSERT_IDENTIFIER(name, var_##variable->getIdentifier()); \
    ASSERT_TYPE(type, var_##variable->getType()); \
    ASSERT_LITERAL(value, literal, var_##variable->getAssignation())

#define ASSERT_MESSAGE_CONTENT(expected, message) { \
    std::stringstream stream; \
    message.print(stream); \
    std::string result(std::istreambuf_iterator<char>(stream), {}); \
    ASSERT_STREQ(expected, result.c_str()); \
    }

class TestExpression : public filc::ast::AbstractExpression {
public:
    TestExpression();

    auto withExpressionType(const std::shared_ptr<filc::ast::AbstractType> &expression_type) -> TestExpression &;

    auto resolveType(filc::environment::Environment *environment,
                     filc::message::MessageCollector *collector,
                     const std::shared_ptr<filc::ast::AbstractType> &preferred_type) -> void override;

    auto addNameToEnvironment(filc::environment::Environment *environment) const -> void override;

    auto generateIR(filc::message::MessageCollector *collector,
                    filc::environment::Environment *environment,
                    llvm::LLVMContext *context,
                    llvm::Module *module,
                    llvm::IRBuilder<> *builder) const -> llvm::Value * override;
};
