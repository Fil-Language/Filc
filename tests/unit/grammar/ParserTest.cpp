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
#include "Parser.h"
#include <string>
#include "test_tools.h"

using namespace ::testing;

#define FIXTURES_PATH_GRAMMAR FIXTURES_PATH "/grammar"

TEST(Parser, filename) {
    filc::grammar::Parser parser(FIXTURES_PATH_GRAMMAR "/module1.fil", COLLECTOR);
    auto *program = parser.getProgram();
    ASSERT_STREQ(FIXTURES_PATH_GRAMMAR "/module1.fil", program->getFilename().c_str());
}

TEST(Parser, exported) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/not-exported.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_FALSE(expression1->isExported());

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/exported.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_TRUE(expression2->isExported());
}

TEST(Parser, position) {
    filc::grammar::Parser parser(FIXTURES_PATH_GRAMMAR "/int1.fil", COLLECTOR);
    auto *program = parser.getProgram();
    ASSERT_THAT(program->getExpressions(), SizeIs(1));
    auto *expression = program->getExpressions()[0];
    ASSERT_NE(nullptr, expression);
    auto *position = expression->getPosition();
    ASSERT_STREQ(FIXTURES_PATH_GRAMMAR "/int1.fil", position->getFilename().c_str());
    ASSERT_EQ(3, position->getLine());
    ASSERT_EQ(0, position->getColumn());
    ASSERT_STREQ("42", position->getContent().c_str());
}

TEST(Parser, module) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/module1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_STREQ("a.module1", program1->getModule().c_str());

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/module2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_STREQ("a.b.module2", program2->getModule().c_str());

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/module3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_STREQ("an.example.with.many.dots.module3", program3->getModule().c_str());
}

TEST(Parser, use) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/use1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getImports(), SizeIs(1));
    ASSERT_THAT(program1->getImports(), Contains("a"));

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/use2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getImports(), SizeIs(1));
    ASSERT_THAT(program2->getImports(), Contains("a.b"));

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/use3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getImports(), SizeIs(1));
    ASSERT_THAT(program3->getImports(), Contains("an.example.with.many.dots"));

    filc::grammar::Parser parser4(FIXTURES_PATH_GRAMMAR "/use4.fil", COLLECTOR);
    auto *program4 = parser4.getProgram();
    ASSERT_THAT(program4->getImports(), SizeIs(3));
    ASSERT_THAT(program4->getImports(), Contains("a.b"));
    ASSERT_THAT(program4->getImports(), Contains("c.d"));
    ASSERT_THAT(program4->getImports(), Contains("e.f"));
}

TEST(Parser, BooleanLiteral) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/bool1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL(true, BooleanLiteral, expression1);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/bool2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_LITERAL(false, BooleanLiteral, expression2);
}

TEST(Parser, IntegerLiteral) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/int1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL(42, IntegerLiteral, expression1);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/int2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_LITERAL(-5, IntegerLiteral, expression2);

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/int3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    auto *expression3 = program3->getExpressions()[0];
    ASSERT_NE(nullptr, expression3);
    ASSERT_LITERAL(25, IntegerLiteral, expression3);
}

TEST(Parser, FloatLiteral) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/float1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL(42.0, FloatLiteral, expression1);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/float2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_LITERAL(-2.5, FloatLiteral, expression2);

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/float3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    auto *expression3 = program3->getExpressions()[0];
    ASSERT_NE(nullptr, expression3);
    ASSERT_LITERAL(4.45, FloatLiteral, expression3);

    filc::grammar::Parser parser4(FIXTURES_PATH_GRAMMAR "/float4.fil", COLLECTOR);
    auto *program4 = parser4.getProgram();
    ASSERT_THAT(program4->getExpressions(), SizeIs(1));
    auto *expression4 = program4->getExpressions()[0];
    ASSERT_NE(nullptr, expression4);
    ASSERT_LITERAL(3.14159265359, FloatLiteral, expression4);
}

TEST(Parser, CharacterLiteral) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/char1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL('a', CharacterLiteral, expression1);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/char2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_LITERAL('2', CharacterLiteral, expression2);

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/char3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    auto *expression3 = program3->getExpressions()[0];
    ASSERT_NE(nullptr, expression3);
    ASSERT_LITERAL('\t', CharacterLiteral, expression3);
}

TEST(Parser, StringLiteral) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/string1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL("Hello World!", StringLiteral, expression1);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/string2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_LITERAL("", StringLiteral, expression2);

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/string3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    auto *expression3 = program3->getExpressions()[0];
    ASSERT_NE(nullptr, expression3);
    ASSERT_LITERAL("\t\n\r\a\\\"", StringLiteral, expression3);
}

TEST(Parser, VariableDeclaration) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/variable_declaration1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(2));
    auto *expression1_1 = program1->getExpressions()[0];
    auto *expression1_2 = program1->getExpressions()[1];
    ASSERT_NE(nullptr, expression1_1);
    ASSERT_NE(nullptr, expression1_2);
    ASSERT_VARIABLE_DECLARATION(true, "pi", "float", 3.14, FloatLiteral, expression1_1);
    ASSERT_VARIABLE_DECLARATION(false, "potatoes", "int", 2, IntegerLiteral, expression1_2);
}

TEST(Parser, Identifier) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/identifier1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = program1->getExpressions()[0];
    ASSERT_NE(nullptr, expression1);
    ASSERT_IDENTIFIER("abcd", expression1);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/identifier2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = program2->getExpressions()[0];
    ASSERT_NE(nullptr, expression2);
    ASSERT_IDENTIFIER("_name", expression2);

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/identifier3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    auto *expression3 = program3->getExpressions()[0];
    ASSERT_NE(nullptr, expression3);
    ASSERT_IDENTIFIER("is42", expression3);
}

TEST(Parser, UnaryCalcul) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/unary_calcul1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::PostUnaryCalcul *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_IDENTIFIER("a", expression1->getVariable());
    ASSERT_CLASSIC_OPERATOR(PLUSPLUS, expression1->getOperator());

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/unary_calcul2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = dynamic_cast<filc::ast::PreUnaryCalcul *>(program2->getExpressions()[0]);
    ASSERT_NE(nullptr, expression2);
    ASSERT_IDENTIFIER("b", expression2->getVariable());
    ASSERT_CLASSIC_OPERATOR(MINUSMINUS, expression2->getOperator());

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/unary_calcul3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(1));
    auto *expression3 = dynamic_cast<filc::ast::PostUnaryCalcul *>(program3->getExpressions()[0]);
    ASSERT_NE(nullptr, expression3);
    ASSERT_IDENTIFIER("multiply", expression3->getVariable());
    auto *operator3 = dynamic_cast<filc::ast::FunctionOperator *>(expression3->getOperator());
    ASSERT_THAT(operator3->getExpressions(), SizeIs(2));
    ASSERT_LITERAL(2, IntegerLiteral, operator3->getExpressions()[0]);
    ASSERT_LITERAL(3, IntegerLiteral, operator3->getExpressions()[1]);

    filc::grammar::Parser parser4(FIXTURES_PATH_GRAMMAR "/unary_calcul4.fil", COLLECTOR);
    auto *program4 = parser4.getProgram();
    ASSERT_THAT(program4->getExpressions(), SizeIs(1));
    auto *expression4 = dynamic_cast<filc::ast::PostUnaryCalcul *>(program4->getExpressions()[0]);
    ASSERT_NE(nullptr, expression4);
    ASSERT_IDENTIFIER("array", expression4->getVariable());
    auto *operator4 = dynamic_cast<filc::ast::ArrayOperator *>(expression4->getOperator());
    ASSERT_LITERAL(4, IntegerLiteral, operator4->getExpression());
}

TEST(Parser, BinaryCalcul) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/binary_calcul1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::BinaryCalcul *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL(3, IntegerLiteral, expression1->getLeftExpression());
    ASSERT_LITERAL(2, IntegerLiteral, expression1->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(STAR, expression1->getOperator());

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/binary_calcul2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(4));
    auto *expression2_1 = dynamic_cast<filc::ast::BinaryCalcul *>(program2->getExpressions()[0]);
    auto *expression2_2 = dynamic_cast<filc::ast::BinaryCalcul *>(program2->getExpressions()[1]);
    auto *expression2_3 = dynamic_cast<filc::ast::BinaryCalcul *>(program2->getExpressions()[2]);
    auto *expression2_4 = dynamic_cast<filc::ast::BinaryCalcul *>(program2->getExpressions()[3]);
    ASSERT_NE(nullptr, expression2_1);
    ASSERT_NE(nullptr, expression2_2);
    ASSERT_NE(nullptr, expression2_3);
    ASSERT_NE(nullptr, expression2_4);
    auto *expression2_1_l = dynamic_cast<filc::ast::BinaryCalcul *>(expression2_1->getLeftExpression());
    ASSERT_LITERAL(1, IntegerLiteral, expression2_1_l->getLeftExpression());
    ASSERT_LITERAL(2, IntegerLiteral, expression2_1_l->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(STAR, expression2_1_l->getOperator());
    ASSERT_LITERAL(3, IntegerLiteral, expression2_1->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(PLUS, expression2_1->getOperator());
    auto *expression2_2_r = dynamic_cast<filc::ast::BinaryCalcul *>(expression2_2->getRightExpression());
    ASSERT_LITERAL(1, IntegerLiteral, expression2_2->getLeftExpression());
    ASSERT_CLASSIC_OPERATOR(PLUS, expression2_2->getOperator());
    ASSERT_LITERAL(2, IntegerLiteral, expression2_2_r->getLeftExpression());
    ASSERT_LITERAL(3, IntegerLiteral, expression2_2_r->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(STAR, expression2_2_r->getOperator());
    auto *expression2_3_r = dynamic_cast<filc::ast::BinaryCalcul *>(expression2_3->getRightExpression());
    ASSERT_LITERAL(1, IntegerLiteral, expression2_3->getLeftExpression());
    ASSERT_CLASSIC_OPERATOR(STAR, expression2_3->getOperator());
    ASSERT_LITERAL(2, IntegerLiteral, expression2_3_r->getLeftExpression());
    ASSERT_LITERAL(3, IntegerLiteral, expression2_3_r->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(PLUS, expression2_3_r->getOperator());
    auto *expression2_4_l = dynamic_cast<filc::ast::BinaryCalcul *>(expression2_4->getLeftExpression());
    ASSERT_LITERAL(1, IntegerLiteral, expression2_4_l->getLeftExpression());
    ASSERT_LITERAL(2, IntegerLiteral, expression2_4_l->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(PLUS, expression2_4_l->getOperator());
    ASSERT_LITERAL(3, IntegerLiteral, expression2_4->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(STAR, expression2_4->getOperator());

    filc::grammar::Parser parser3(FIXTURES_PATH_GRAMMAR "/binary_calcul3.fil", COLLECTOR);
    auto *program3 = parser3.getProgram();
    ASSERT_THAT(program3->getExpressions(), SizeIs(2));
    auto *expression3_1 = dynamic_cast<filc::ast::BinaryCalcul *>(program3->getExpressions()[0]);
    auto *expression3_2 = dynamic_cast<filc::ast::BinaryCalcul *>(program3->getExpressions()[1]);
    ASSERT_NE(nullptr, expression3_1);
    ASSERT_NE(nullptr, expression3_2);
    ASSERT_IDENTIFIER("a", expression3_1->getLeftExpression());
    ASSERT_LITERAL(2, IntegerLiteral, expression3_1->getRightExpression());
    ASSERT_EQ(nullptr,
              dynamic_cast<filc::ast::AssignationOperator *>(expression3_1->getOperator())->getInnerOperator());
    ASSERT_IDENTIFIER("b", expression3_2->getLeftExpression());
    ASSERT_IDENTIFIER("a", expression3_2->getRightExpression());
    ASSERT_ASSIGNATION_OPERATOR(PLUS, expression3_2->getOperator());
}

TEST(Parser, Function) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/function1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::Function *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_IDENTIFIER("minus", expression1->getName());
    ASSERT_TYPE("int", expression1->getReturnType());
    ASSERT_THAT(expression1->getParameters(), SizeIs(2));
    auto *parameter1_1 = expression1->getParameters()[0];
    auto *parameter1_2 = expression1->getParameters()[1];
    ASSERT_IDENTIFIER("a", parameter1_1->getName());
    ASSERT_IDENTIFIER("b", parameter1_2->getName());
    ASSERT_TYPE("int", parameter1_1->getType());
    ASSERT_TYPE("int", parameter1_2->getType());
    ASSERT_THAT(expression1->getBody(), SizeIs(1));
    auto *body1 = dynamic_cast<filc::ast::BinaryCalcul *>(expression1->getBody()[0]);
    ASSERT_IDENTIFIER("a", body1->getLeftExpression());
    ASSERT_IDENTIFIER("b", body1->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(MINUS, body1->getOperator());

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/function2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = dynamic_cast<filc::ast::Function *>(program2->getExpressions()[0]);
    ASSERT_NE(nullptr, expression2);
    ASSERT_IDENTIFIER("operator==", expression2->getName());
    ASSERT_TYPE("bool", expression2->getReturnType());
    ASSERT_THAT(expression1->getParameters(), SizeIs(2));
    auto *parameter2_1 = expression2->getParameters()[0];
    auto *parameter2_2 = expression2->getParameters()[1];
    ASSERT_IDENTIFIER("a", parameter2_1->getName());
    ASSERT_IDENTIFIER("b", parameter2_2->getName());
    ASSERT_TYPE("float", parameter2_1->getType());
    ASSERT_TYPE("float", parameter2_2->getType());
    ASSERT_THAT(expression2->getBody(), SizeIs(1));
    auto *body2 = dynamic_cast<filc::ast::BinaryCalcul *>(expression2->getBody()[0]);
    ASSERT_IDENTIFIER("a", body2->getLeftExpression());
    ASSERT_IDENTIFIER("b", body2->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(EQEQ, body2->getOperator());
}

TEST(Parser, Lambda) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/lambda1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::Lambda *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_THAT(expression1->getParameters(), SizeIs(1));
    ASSERT_IDENTIFIER("a", expression1->getParameters()[0]->getName());
    ASSERT_TYPE("int", expression1->getParameters()[0]->getType());
    ASSERT_TYPE("bool", expression1->getReturnType());
    ASSERT_THAT(expression1->getBody(), SizeIs(1));
    auto *body1 = dynamic_cast<filc::ast::BinaryCalcul *>(expression1->getBody()[0]);
    ASSERT_IDENTIFIER("a", body1->getLeftExpression());
    ASSERT_LITERAL(2, IntegerLiteral, body1->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(NEQ, body1->getOperator());
}

TEST(Parser, ParenthesisBody) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/parenthesis_body1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::BinaryCalcul *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_LITERAL(1, IntegerLiteral, expression1->getLeftExpression());
    ASSERT_LITERAL(2, IntegerLiteral, expression1->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(LESS, expression1->getOperator());
}

TEST(Parser, If) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/if1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::If *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_IDENTIFIER("a", expression1->getCondition());
    ASSERT_THAT(expression1->getBody(), SizeIs(1));
    ASSERT_IDENTIFIER("b", expression1->getBody()[0]);
    auto *else1 = expression1->getElse();
    ASSERT_NE(nullptr, else1);
    ASSERT_IDENTIFIER("true", else1->getCondition());
    ASSERT_THAT(else1->getBody(), SizeIs(1));
    ASSERT_IDENTIFIER("c", else1->getBody()[0]);

    filc::grammar::Parser parser2(FIXTURES_PATH_GRAMMAR "/if2.fil", COLLECTOR);
    auto *program2 = parser2.getProgram();
    ASSERT_THAT(program2->getExpressions(), SizeIs(1));
    auto *expression2 = dynamic_cast<filc::ast::If *>(program2->getExpressions()[0]);
    ASSERT_NE(nullptr, expression2);
    auto *condition2 = dynamic_cast<filc::ast::BinaryCalcul *>(expression2->getCondition());
    ASSERT_LITERAL(3, IntegerLiteral, condition2->getLeftExpression());
    ASSERT_LITERAL(0, IntegerLiteral, condition2->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(GREATER, condition2->getOperator());
    ASSERT_THAT(expression2->getBody(), SizeIs(1));
    auto *body2 = dynamic_cast<filc::ast::BinaryCalcul *>(expression2->getBody()[0]);
    ASSERT_IDENTIFIER("cout", body2->getLeftExpression());
    ASSERT_LITERAL("Hello World!", StringLiteral, body2->getRightExpression());
    ASSERT_CLASSIC_OPERATOR(FLEFT, body2->getOperator());
    ASSERT_EQ(nullptr, expression2->getElse());
}

TEST(Parser, Switch) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/switch1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::Switch *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_IDENTIFIER("value", expression1->getCondition());
    ASSERT_THAT(expression1->getCases(), SizeIs(3));
    auto *case1_1 = expression1->getCases()[0];
    auto *case1_2 = expression1->getCases()[1];
    auto *case1_3 = expression1->getCases()[2];
    ASSERT_LITERAL("b", StringLiteral, case1_1->getPattern());
    ASSERT_LITERAL("c", StringLiteral, case1_2->getPattern());
    ASSERT_IDENTIFIER("default", case1_3->getPattern());
    ASSERT_THAT(case1_1->getBody(), SizeIs(1));
    ASSERT_THAT(case1_2->getBody(), SizeIs(1));
    ASSERT_THAT(case1_3->getBody(), SizeIs(1));
    ASSERT_IDENTIFIER("b", case1_1->getBody()[0]);
    ASSERT_IDENTIFIER("c", case1_2->getBody()[0]);
    ASSERT_IDENTIFIER("a", case1_3->getBody()[0]);
}

TEST(Parser, ForI) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/for_i1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(2));
    auto *expression1_1 = dynamic_cast<filc::ast::VariableDeclaration *>(program1->getExpressions()[0]);
    auto *expression1_2 = dynamic_cast<filc::ast::ForI *>(program1->getExpressions()[1]);
    ASSERT_NE(nullptr, expression1_1);
    ASSERT_NE(nullptr, expression1_2);
    ASSERT_IDENTIFIER("i", expression1_1->getIdentifier());
    ASSERT_TYPE("int", expression1_1->getType());
    ASSERT_LITERAL(0, IntegerLiteral, expression1_1->getAssignation());
    ASSERT_EQ(nullptr, expression1_2->getDeclaration());
    ASSERT_NE(nullptr, expression1_2->getCondition());
    ASSERT_NE(nullptr, expression1_2->getIteration());
    auto *condition1 = dynamic_cast<filc::ast::BinaryCalcul *>(expression1_2->getCondition());
    auto *iteration1 = dynamic_cast<filc::ast::PreUnaryCalcul *>(expression1_2->getIteration());
    ASSERT_IDENTIFIER("i", condition1->getLeftExpression());
    ASSERT_CLASSIC_OPERATOR(LEQ, condition1->getOperator());
    ASSERT_LITERAL(10, IntegerLiteral, condition1->getRightExpression());
    ASSERT_IDENTIFIER("i", iteration1->getVariable());
    ASSERT_CLASSIC_OPERATOR(PLUSPLUS, iteration1->getOperator());
    ASSERT_THAT(expression1_2->getBody(), SizeIs(1));
    ASSERT_IDENTIFIER("i", expression1_2->getBody()[0]);
}

TEST(Parser, ForIter) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/for_iter1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::ForIter *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    ASSERT_TRUE(expression1->isConstant());
    ASSERT_IDENTIFIER("item", expression1->getIdentifier());
    ASSERT_IDENTIFIER("my_array", expression1->getArray());
    ASSERT_THAT(expression1->getBody(), SizeIs(1));
    auto *body1 = dynamic_cast<filc::ast::PreUnaryCalcul *>(expression1->getBody()[0]);
    ASSERT_NE(nullptr, body1);
    ASSERT_IDENTIFIER("item", body1->getVariable());
    ASSERT_CLASSIC_OPERATOR(REF, body1->getOperator());
}

TEST(Parser, While) {
    filc::grammar::Parser parser1(FIXTURES_PATH_GRAMMAR "/while1.fil", COLLECTOR);
    auto *program1 = parser1.getProgram();
    ASSERT_THAT(program1->getExpressions(), SizeIs(1));
    auto *expression1 = dynamic_cast<filc::ast::While *>(program1->getExpressions()[0]);
    ASSERT_NE(nullptr, expression1);
    auto *condition1 = dynamic_cast<filc::ast::BinaryCalcul *>(expression1->getCondition());
    ASSERT_IDENTIFIER("i", condition1->getLeftExpression());
    ASSERT_CLASSIC_OPERATOR(LESS, condition1->getOperator());
    ASSERT_LITERAL(10, IntegerLiteral, condition1->getRightExpression());
    ASSERT_THAT(expression1->getBody(), SizeIs(1));
    auto *body1 = dynamic_cast<filc::ast::PostUnaryCalcul *>(expression1->getBody()[0]);
    ASSERT_IDENTIFIER("i", body1->getVariable());
    ASSERT_CLASSIC_OPERATOR(PLUSPLUS, body1->getOperator());
}
