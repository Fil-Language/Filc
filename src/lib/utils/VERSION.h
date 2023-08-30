/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
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
#ifndef FILC_VERSION_H
#define FILC_VERSION_H

#include <string>

#define FILC_VERSION_MAJOR 0
#define FILC_VERSION_MINOR 3
#define FILC_VERSION_PATCH 0
#define FILC_VERSION_PRE std::string("")

#define MAKE_VERSION(major, minor, patch) ((major) * 1000000 + (minor) * 1000 + (patch))
#define MAKE_VERSION_STRING(major, minor, patch, pre) std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch) + (pre.empty() ? "" : ("-" + pre))

#define FILC_VERSION MAKE_VERSION(FILC_VERSION_MAJOR, FILC_VERSION_MINOR, FILC_VERSION_PATCH)
#define FILC_VERSION_STRING MAKE_VERSION_STRING(FILC_VERSION_MAJOR, FILC_VERSION_MINOR, FILC_VERSION_PATCH, FILC_VERSION_PRE)

#define FILC_LICENSE "MIT"

#endif//FILC_VERSION_H
