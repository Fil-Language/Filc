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
#include "Calcul.h"
#include "Identifier.h"
#include "Operator.h"
#include "test_tools.h"

TEST(BinaryCalcul, constructor) {
    filc::ast::BinaryCalcul bc1(
        std::make_shared<filc::ast::Identifier>("a"),
        std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::PLUS),
        std::make_shared<filc::ast::Identifier>("b")
    );
    ASSERT_IDENTIFIER("a", bc1.getLeftExpression());
    ASSERT_IDENTIFIER("b", bc1.getRightExpression());
    ASSERT_CLASSIC_OPERATOR(PLUS, bc1.getOperator());
}
