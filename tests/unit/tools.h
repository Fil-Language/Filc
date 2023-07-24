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
#ifndef FILC_TOOLS_H
#define FILC_TOOLS_H

#include <gtest/gtest.h>
#include <algorithm>

template<typename T>
auto assertCount(unsigned int count, const std::vector<T> &array) -> ::testing::AssertionResult {
    if (array.size() == count) {
        return ::testing::AssertionSuccess();
    }
    return ::testing::AssertionFailure() << "Array size is " << array.size() << ", " << count << " expected";
}

template<typename T>
auto assertContains(T value, const std::vector<T> &array) -> ::testing::AssertionResult {
    if (std::find(array.begin(), array.end(), value) != array.end()) {
        return ::testing::AssertionSuccess();
    }
    return ::testing::AssertionFailure() << "Array does not contain " << value;
}

#define ASSERT_COUNT(count, array) ASSERT_TRUE(assertCount(count, array))

#define ASSERT_CONTAINS(value, array) ASSERT_TRUE(assertContains(value, array))

#endif //FILC_TOOLS_H
