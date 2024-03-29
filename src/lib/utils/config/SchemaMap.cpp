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

using namespace std;
using namespace filc::utils::config;

SchemaMap::SchemaMap()
    : AbstractSchema() {}

SchemaMap::~SchemaMap() {
    for (auto &node: _nodes) {
        delete node.second;
    }
}

auto SchemaMap::has(const std::string &key) const -> bool {
    return _nodes.find(key) != _nodes.end();
}

auto SchemaMap::get(const string &key) const -> AbstractSchema * {
    auto it = _nodes.find(key);
    if (it != _nodes.end()) {
        return it->second;
    }

    return nullptr;
}

auto SchemaMap::set(const string &key, AbstractSchema *value) -> void {
    _nodes[key] = value;
}

auto SchemaMap::keys() const -> vector<string> {
    vector<string> result;

    result.reserve(_nodes.size());
    for (const auto &node: _nodes) {
        result.push_back(node.first);
    }

    return result;
}
