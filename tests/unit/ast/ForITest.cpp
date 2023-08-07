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
#include "tools.h"

TEST(ForI, constructor) {
    auto *declaration = new filc::ast::VariableDeclaration(false, new filc::ast::Identifier("i"),
                                                           new filc::ast::Type(new filc::ast::Identifier("int")));
    declaration->setAssignation(new filc::ast::IntegerLiteral(0));
    filc::ast::ForI fi1(
            declaration,
            new filc::ast::BinaryCalcul(
                    new filc::ast::Identifier("i"),
                    new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LESS),
                    new filc::ast::IntegerLiteral(10)
            ),
            new filc::ast::PostUnaryCalcul(
                    new filc::ast::Identifier("i"),
                    new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUSPLUS)
            ),
            {}
    );
    ASSERT_IDENTIFIER("i", fi1.getDeclaration()->getIdentifier());
    ASSERT_TYPE("int", fi1.getDeclaration()->getType());
    ASSERT_LITERAL(0, IntegerLiteral, fi1.getDeclaration()->getAssignation());
    auto *condition = static_cast<filc::ast::BinaryCalcul *>(fi1.getCondition());
    ASSERT_IDENTIFIER("i", condition->getLeftExpression());
    ASSERT_CLASSIC_OPERATOR(LESS, condition->getOperator());
    ASSERT_LITERAL(10, IntegerLiteral, condition->getRightExpression());
    auto *iteration = static_cast<filc::ast::PostUnaryCalcul *>(fi1.getIteration());
    ASSERT_IDENTIFIER("i", iteration->getVariable());
    ASSERT_CLASSIC_OPERATOR(PLUSPLUS, iteration->getOperator());
    ASSERT_THAT(fi1.getBody(), IsEmpty());
}