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
#include "Condition.h"

using namespace filc::ast;

If::If(const std::shared_ptr<AbstractExpression> &condition, const std::shared_ptr<BlockBody> &body)
    : _condition(condition), _body(body), _else(nullptr) {}

auto If::getCondition() const -> std::shared_ptr<AbstractExpression> {
    return _condition;
}

auto If::getBody() const -> std::shared_ptr<BlockBody> {
    return _body;
}

auto If::getElse() const -> std::shared_ptr<BlockBody> {
    return _else;
}

auto If::setElse(const std::shared_ptr<BlockBody> &p_else) -> void {
    _else = p_else;
}

If::~If() = default;
