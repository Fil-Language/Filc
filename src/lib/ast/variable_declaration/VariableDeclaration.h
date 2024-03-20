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
#ifndef FILC_VARIABLEDECLARATION_H
#define FILC_VARIABLEDECLARATION_H

#include "AbstractExpression.h"
#include "AST_decl.h"

namespace filc::ast {
    class VariableDeclaration : public AbstractExpression {
    public:
        VariableDeclaration(
            bool is_constant, const std::shared_ptr<Identifier> &identifier, std::shared_ptr<AbstractType> type
        );

        ~VariableDeclaration() override;

        [[nodiscard]] auto isConstant() const -> bool;

        [[nodiscard]] auto getIdentifier() const -> std::shared_ptr<Identifier>;

        [[nodiscard]] auto getType() const -> std::shared_ptr<AbstractType>;

        [[nodiscard]] auto getAssignation() const -> std::shared_ptr<AbstractExpression>;

        auto setAssignation(const std::shared_ptr<AbstractExpression> &assignation) -> void;

    private:
        bool _constant;
        std::shared_ptr<Identifier> _identifier;
        std::shared_ptr<AbstractType> _type;
        std::shared_ptr<AbstractExpression> _assignation;
    };
} // namespace filc::ast

#endif // FILC_VARIABLEDECLARATION_H
