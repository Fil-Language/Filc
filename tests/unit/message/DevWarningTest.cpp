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
#include "DevWarning.h"
#include "test_tools.h"

TEST(DevWarning, constructor) {
    auto dev_warning = filc::message::DevWarning(
        5, std::make_shared<filc::utils::SimplePosition>(FIXTURES_PATH "/utils/position.txt", 12, 3), "My dev warning"
    );
    ASSERT_EQ(5, dev_warning.getCode());
}

TEST(DevWarning, print) {
    auto dev_warning = filc::message::DevWarning(
        5, std::make_shared<filc::utils::SimplePosition>(FIXTURES_PATH "/utils/position.txt", 12, 3), "My dev warning"
    );
    auto expected = "\033[1;36mDEV WARNING[5]\033[0m\033[1m: My dev warning\n"
                    "   \033[1;34m--> \033[0m../../../tests/unit/Fixtures/utils/position.txt:12:3\n"
                    "\033[1;34m 12 | \033[0m12;abcd\n"
                    "\033[1;34m    | \033[0m   \033[1;36m^\033[0m\n";
    ASSERT_MESSAGE_CONTENT(expected, dev_warning);
}
