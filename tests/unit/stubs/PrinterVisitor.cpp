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
#include "PrinterVisitor.h"
#include "Body.h"
#include "Calcul.h"
#include "Identifier.h"
#include "Literal.h"
#include "Operator.h"
#include <stdexcept>

auto PrinterVisitor::getResult() const -> std::string {
    return _result;
}

auto PrinterVisitor::clear() -> void {
    _result = "";
}

auto PrinterVisitor::visitAbstractExpression(filc::ast::AbstractExpression *abstract_expression) -> void {
    throw std::logic_error("Should not go here");
}

auto PrinterVisitor::visitBooleanLiteral(filc::ast::BooleanLiteral *boolean_literal) -> void {
    _result += boolean_literal->getValue() ? "true" : "false";
}

auto PrinterVisitor::visitIntegerLiteral(filc::ast::IntegerLiteral *integer_literal) -> void {
    _result += std::to_string(integer_literal->getValue());
}

auto PrinterVisitor::visitFloatLiteral(filc::ast::FloatLiteral *float_literal) -> void {
    _result += std::to_string(float_literal->getValue());
}

auto PrinterVisitor::visitCharacterLiteral(filc::ast::CharacterLiteral *character_literal) -> void {
    _result += "'" + std::string(1, character_literal->getValue()) + "'";
}

auto PrinterVisitor::visitStringLiteral(filc::ast::StringLiteral *string_literal) -> void {
    _result += "\"" + string_literal->getValue() + "\"";
}

auto PrinterVisitor::visitBinaryCalcul(filc::ast::BinaryCalcul *binary_calcul) -> void {
    _result += "(";
    binary_calcul->getLeftExpression()->accept(this);
    _result += " ";
    binary_calcul->getOperator()->accept(this);
    _result += " ";
    binary_calcul->getRightExpression()->accept(this);
    _result += ")";
}

auto PrinterVisitor::visitClassicOperator(filc::ast::ClassicOperator *classic_operator) -> void {
    _result += classic_operator->dump();
}

auto PrinterVisitor::visitArrayOperator(filc::ast::ArrayOperator *array_operator) -> void {
    _result += "[";
    array_operator->getExpression()->accept(this);
    _result += "]";
}

auto PrinterVisitor::visitFunctionOperator(filc::ast::FunctionOperator *function_operator) -> void {
    _result += "(";

    auto expressions = function_operator->getExpressions();
    for (auto it = expressions.begin(); it != expressions.end(); it++) {
        (*it)->accept(this);
        if (it + 1 != expressions.end()) {
            _result + ", ";
        }
    }

    _result += ")";
}

auto PrinterVisitor::visitIdentifier(filc::ast::Identifier *identifier) -> void {
    _result += identifier->getName();
}

auto PrinterVisitor::visitAssignationOperator(filc::ast::AssignationOperator *assignation_operator) -> void {
    auto inner_operator = assignation_operator->getInnerOperator();
    if (inner_operator != nullptr) {
        inner_operator->accept(this);
    }
    _result += "=";
}

auto PrinterVisitor::visitBlockBody(filc::ast::BlockBody *block_body) -> void {
    if (block_body->getExpressions().size() == 1) {
        _result += "(";
        block_body->getExpressions()[0]->accept(this);
        _result += ")";
    } else {
        _result += "{\n";
        for (const auto &expression: block_body->getExpressions()) {
            expression->accept(this);
            _result += "\n";
        }
        _result += "}";
    }
}
