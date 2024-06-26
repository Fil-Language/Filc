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
#include "test_tools.h"

using namespace std;

auto redirectCin(const function<void(stringstream &stream)> &function) -> void {
    stringstream input_stream;
    streambuf *old = cin.rdbuf(input_stream.rdbuf());
    function(input_stream);
    cin.rdbuf(old);
}

auto getMessageContent(filc::message::Message &message) -> string {
    stringstream stream;
    message.print(stream);
    string result(istreambuf_iterator<char>(stream), {});

    return result;
}

auto getOutput(const std::function<void()> &expression, const std::function<void(const std::string &)> &assertion)
    -> void {
    stringstream redirect_stream;
    streambuf *oldbuf = cout.rdbuf(redirect_stream.rdbuf());
    expression();
    string result, line;
    while (getline(redirect_stream, line)) {
        result += line + "\n";
    }
    assertion(result);
    cout.rdbuf(oldbuf);
}

auto getErrOutput(const std::function<void()> &expression, const std::function<void(const std::string &)> &assertion)
    -> void {
    stringstream redirect_stream;
    streambuf *oldbuf = cerr.rdbuf(redirect_stream.rdbuf());
    expression();
    string result, line;
    while (getline(redirect_stream, line)) {
        result += line + "\n";
    }
    assertion(result);
    cerr.rdbuf(oldbuf);
}

auto toStringArray(const vector<string> &data) -> vector<char *> {
    vector<char *> strings;
    strings.reserve(data.size());
    for (auto &item: data) {
        strings.push_back(const_cast<char *>(item.c_str()));
    }

    return strings;
}
