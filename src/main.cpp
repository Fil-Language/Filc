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
#include "BuildCommand.h"
#include "CommandCollector.h"
#include "FilCompiler.h"
#include "InitCommand.h"
#include "VersionCommand.h"
#include "tools.h"

using namespace std;
using namespace filc;

auto main(int argc, char **argv) -> int {
    utils::command::CommandCollector command_collector;
    command_collector.addCommand(new utils::command::BuildCommand(new FilCompiler));
    command_collector.addCommand(new utils::command::InitCommand);
    command_collector.addCommand(new utils::command::VersionCommand(FILC_VERSION, utils::computeVersionNumber(FILC_VERSION), "MIT"));

    return command_collector.run(argc, argv);
}
