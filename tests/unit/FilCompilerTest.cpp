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
#include "FilCompiler.h"
#include "Config.h"
#include "test_tools.h"
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filc;

auto createProject() -> void {
    utils::config::Config::init("my_project");
    filesystem::create_directory("my_project");
    filesystem::current_path(filesystem::current_path().string() + "/my_project");
    filesystem::create_directory("src");
    ofstream file("src/main.fil");
    file << "module my_project" << '\n'
         << '\n'
         << "fun main(): int = 0" << '\n';
    file.flush();
    file.close();
}

auto deleteProject() -> void {
    filesystem::current_path(filesystem::current_path().string() + "/..");
    filesystem::remove_all("my_project");
    utils::config::Config::clear();
}

TEST(FilCompiler_compile, entrypoint_error) {
    createProject();
    auto *config = utils::config::Config::get();
    config->setEntrypoint("non-existing-file.fil");

    FilCompiler compiler(new ParserStub);
    ASSERT_ERR_OUTPUT_MATCH(".*Entrypoint cannot be found, or is not readable.*", ASSERT_EQ(1, compiler.compile()));

    deleteProject();
}

TEST(FilCompiler_compile, good) {
    createProject();

    FilCompiler compiler(new ParserStub);
    ASSERT_ERR_OUTPUT_MATCH(".*Compiler not implemented yet!.*", ASSERT_EQ(2, compiler.compile()));

    deleteProject();
}
