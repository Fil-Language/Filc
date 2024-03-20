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
#include "VariableDeclaration.h"
#include "Error.h"
#include <utility>

using namespace filc::ast;

VariableDeclaration::VariableDeclaration(
    bool is_constant, const std::shared_ptr<Identifier> &identifier, std::shared_ptr<AbstractType> type
)
    : _constant(is_constant), _identifier(identifier), _type(std::move(type)), _assignation(nullptr) {}

VariableDeclaration::~VariableDeclaration() = default;

auto VariableDeclaration::isConstant() const -> bool {
    return _constant;
}

auto VariableDeclaration::getIdentifier() const -> std::shared_ptr<Identifier> {
    return _identifier;
}

auto VariableDeclaration::getType() const -> std::shared_ptr<AbstractType> {
    return _type;
}

auto VariableDeclaration::getAssignation() const -> std::shared_ptr<AbstractExpression> {
    return _assignation;
}

auto VariableDeclaration::setAssignation(const std::shared_ptr<AbstractExpression> &assignation) -> void {
    _assignation = assignation;
}
