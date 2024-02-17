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
#include "BuildCommand.h"
#include "Config.h"
#include "test_tools.h"
#include <filesystem>

using namespace std;
using namespace filc::utils::command;
using namespace filc::utils::config;

TEST(BuildCommand, help) {
    BuildCommand bc1(new CompilerStub(0));

    ASSERT_STREQ("Build your project following settings of local module.yml", bc1.help().c_str());
}

TEST(BuildCommand, run) {
    BuildCommand bc1(new CompilerStub(0));
    ASSERT_EQ(1, bc1.run(0, {}));
    Config::clear();

    BuildCommand bc2(new CompilerStub(0));
    Config::init("module.yml");
    ASSERT_EQ(0, bc2.run(0, {}));
    Config::clear();
    filesystem::remove("module.yml");

    BuildCommand bc3(new CompilerStub(1));
    Config::init("module.yml");
    ASSERT_EQ(1, bc3.run(0, {}));
    Config::clear();
    filesystem::remove("module.yml");
}
