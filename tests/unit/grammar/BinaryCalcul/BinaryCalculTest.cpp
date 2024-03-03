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
#include "AST.h"
#include "PrinterVisitor.h"
#include "test_tools.h"

#define FIXTURES_PATH_GRAMMAR FIXTURES_PATH "/grammar"

TEST(Parser_BinaryCalcul, parse) {
    filc::grammar::FilParser parser;
    parser.parse(FIXTURES_PATH_GRAMMAR "/binary_calcul1.fil", COLLECTOR);
    auto *program = parser.getResult();
    ASSERT_THAT(program->getExpressions(), SizeIs(1));
    PrinterVisitor visitor;
    program->getExpressions()[0]->accept(&visitor);
    ASSERT_STREQ("(3 * 2)", visitor.getResult().c_str());
}

TEST(Parser_BinaryCalcul, permissions) {
    filc::grammar::FilParser parser;
    parser.parse(FIXTURES_PATH_GRAMMAR "/binary_calcul2.fil", COLLECTOR);
    auto *program = parser.getResult();
    ASSERT_THAT(program->getExpressions(), SizeIs(4));
    PrinterVisitor visitor;
    program->getExpressions()[0]->accept(&visitor);
    ASSERT_STREQ("((1 * 2) + 3)", visitor.getResult().c_str());
    visitor.clear();

    program->getExpressions()[1]->accept(&visitor);
    ASSERT_STREQ("(1 + (2 * 3))", visitor.getResult().c_str());
    visitor.clear();

    program->getExpressions()[2]->accept(&visitor);
    ASSERT_STREQ("(1 * ((2 + 3)))", visitor.getResult().c_str());
    visitor.clear();

    program->getExpressions()[3]->accept(&visitor);
    ASSERT_STREQ("(((1 + 2)) * 3)", visitor.getResult().c_str());
}

TEST(Parser_BinaryCalcul, assignation) {
    filc::grammar::FilParser parser;
    parser.parse(FIXTURES_PATH_GRAMMAR "/binary_calcul3.fil", COLLECTOR);
    auto *program = parser.getResult();
    ASSERT_THAT(program->getExpressions(), SizeIs(2));
    PrinterVisitor visitor;
    program->getExpressions()[0]->accept(&visitor);
    ASSERT_STREQ("(a = 2)", visitor.getResult().c_str());
    visitor.clear();
    program->getExpressions()[1]->accept(&visitor);
    ASSERT_STREQ("(b += a)", visitor.getResult().c_str());
}
