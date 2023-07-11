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

constexpr uint FILC_VERSION_MAJOR = 0;
constexpr uint FILC_VERSION_MINOR = 2;
constexpr uint FILC_VERSION_PATCH = 1;

constexpr auto makeVersion(uint major, uint minor, uint patch) {
    const uint VERSION_SPAN = 1000;
    return ((major) * (VERSION_SPAN * VERSION_SPAN) + (minor) * VERSION_SPAN + (patch));
}

#define MAKE_VERSION_STRING(major, minor, patch) std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch)

#define FILC_VERSION makeVersion(FILC_VERSION_MAJOR, FILC_VERSION_MINOR, FILC_VERSION_PATCH)
#define FILC_VERSION_STRING MAKE_VERSION_STRING (FILC_VERSION_MAJOR, FILC_VERSION_MINOR, FILC_VERSION_PATCH)

constexpr const char *FILC_LICENSE = "MIT";

#endif//FILC_VERSION_H
