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
#include "Body.h"
#include "Identifier.h"
#include "Loop.h"
#include "test_tools.h"

TEST(ForIter, constructor) {
    filc::ast::ForIter fi1(
        true,
        std::make_shared<filc::ast::Identifier>("item"),
        std::make_shared<filc::ast::Identifier>("my_array"),
        std::shared_ptr<filc::ast::BlockBody>(new filc::ast::BlockBody({})) // NOLINT(*-make-shared)
    );
    ASSERT_TRUE(fi1.isConstant());
    ASSERT_IDENTIFIER("item", fi1.getIdentifier());
    ASSERT_IDENTIFIER("my_array", fi1.getArray());
    ASSERT_THAT(fi1.getBody()->getExpressions(), IsEmpty());
}
