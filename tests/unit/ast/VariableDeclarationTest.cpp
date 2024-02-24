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
#include "Parser.h"
#include "test_tools.h"

TEST(VariableDeclaration, constructor) {
    auto tp1 = std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int"));
    filc::ast::VariableDeclaration vd1(false, new filc::ast::Identifier("my_var"), tp1);
    ASSERT_FALSE(vd1.isConstant());
    ASSERT_IDENTIFIER("my_var", vd1.getIdentifier());
    ASSERT_TYPE("int", vd1.getType());

    auto tp2 = std::make_shared<filc::ast::Type>(new filc::ast::Identifier("float"));
    filc::ast::VariableDeclaration vd2(true, new filc::ast::Identifier("my_val"), tp2);
    ASSERT_TRUE(vd2.isConstant());
    ASSERT_IDENTIFIER("my_val", vd2.getIdentifier());
    ASSERT_TYPE("float", vd2.getType());
}

TEST(VariableDeclaration, assignation) {
    auto tp1 = std::make_shared<filc::ast::Type>(new filc::ast::Identifier("int"));
    filc::ast::VariableDeclaration vd1(false, new filc::ast::Identifier("my_var"), tp1);
    auto *exp1 = new filc::ast::IntegerLiteral(12);
    vd1.setAssignation(exp1);
    ASSERT_EQ(exp1, vd1.getAssignation());
}