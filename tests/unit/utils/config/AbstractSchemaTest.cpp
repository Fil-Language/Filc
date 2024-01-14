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
#include "Schema.h"

#include "CustomSchema.h"
#include "test_tools.h"

using namespace std;
using namespace filc::utils::config;

TEST(AbstractSchema, as) {
    AbstractSchema *schema = new CustomSchema1(12);
    ASSERT_NE(nullptr, schema->as<CustomSchema1>());
    ASSERT_EQ(12, schema->as<CustomSchema1>()->_value);
    ASSERT_EQ(nullptr, schema->as<CustomSchema2>());

    AbstractSchema *schema2 = new CustomSchema2("hello");
    ASSERT_NE(nullptr, schema2->as<CustomSchema2>());
    ASSERT_STREQ("hello", schema2->as<CustomSchema2>()->_value.c_str());
    ASSERT_EQ(nullptr, schema2->as<CustomSchema1>());
}
