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
#ifndef FILC_PRINTERVISITOR_H
#define FILC_PRINTERVISITOR_H

#include "Visitor.h"
#include <string>

class PrinterVisitor final : public filc::Visitor {
public:
    [[nodiscard]] auto getResult() const -> std::string;

    auto clear() -> void;

    auto visitAbstractExpression(filc::ast::AbstractExpression *abstract_expression) -> void override;

    auto visitBooleanLiteral(filc::ast::BooleanLiteral *boolean_literal) -> void override;

    auto visitIntegerLiteral(filc::ast::IntegerLiteral *integer_literal) -> void override;

    auto visitFloatLiteral(filc::ast::FloatLiteral *float_literal) -> void override;

    auto visitCharacterLiteral(filc::ast::CharacterLiteral *character_literal) -> void override;

    auto visitStringLiteral(filc::ast::StringLiteral *string_literal) -> void override;

    auto visitBinaryCalcul(filc::ast::BinaryCalcul *binary_calcul) -> void override;

    auto visitClassicOperator(filc::ast::ClassicOperator *classic_operator) -> void override;

    auto visitArrayOperator(filc::ast::ArrayOperator *array_operator) -> void override;

    auto visitFunctionOperator(filc::ast::FunctionOperator *function_operator) -> void override;

    auto visitIdentifier(filc::ast::Identifier *identifier) -> void override;

    auto visitAssignationOperator(filc::ast::AssignationOperator *assignation_operator) -> void override;

    auto visitBlockBody(filc::ast::BlockBody *block_body) -> void override;

private:
    std::string _result;
};

#endif//FILC_PRINTERVISITOR_H
