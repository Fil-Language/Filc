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

using namespace filc::utils::config;

TEST(SchemaMap, get) {
    SchemaMap map;
    map.set("my_key", new CustomSchema1(5));
    ASSERT_FALSE(map.has("non-existing-key"));
    ASSERT_EQ(nullptr, map.get("non-existing-key"));
    ASSERT_TRUE(map.has("my_key"));
    auto value = map.get("my_key");
    ASSERT_NE(nullptr, value);
    ASSERT_NE(nullptr, value->as<CustomSchema1>());
    ASSERT_EQ(5, value->as<CustomSchema1>()->_value);
    ASSERT_THAT(map.keys(), SizeIs(1));
    ASSERT_STREQ("my_key", map.keys()[0].c_str());
}
