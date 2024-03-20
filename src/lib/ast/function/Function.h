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
#ifndef FILC_FUNCTION_H
#define FILC_FUNCTION_H

#include "AbstractExpression.h"
#include "AST_decl.h"
#include "Environment.h"

namespace filc::ast {
    class Lambda : public AbstractExpression {
    public:
        Lambda(
            const std::vector<std::shared_ptr<FunctionParameter>> &parameters,
            const std::shared_ptr<AbstractType> &return_type,
            const std::shared_ptr<BlockBody> &body
        );

        ~Lambda() override;

        [[nodiscard]] auto getParameters() const -> const std::vector<std::shared_ptr<FunctionParameter>> &;

        [[nodiscard]] auto getReturnType() const -> std::shared_ptr<AbstractType>;

        [[nodiscard]] auto getBody() const -> std::shared_ptr<BlockBody>;

        [[nodiscard]] auto getBodyEnvironment() const -> std::shared_ptr<environment::Environment>;

    private:
        std::vector<std::shared_ptr<FunctionParameter>> _parameters;
        std::shared_ptr<AbstractType> _return_type;
        std::shared_ptr<BlockBody> _body;
        std::shared_ptr<environment::Environment> _body_environment;
        static int name_index;
    };

    class Function : public Lambda {
    public:
        Function(
            const std::shared_ptr<Identifier> &name,
            const std::vector<std::shared_ptr<FunctionParameter>> &parameters,
            const std::shared_ptr<AbstractType> &return_type,
            const std::shared_ptr<BlockBody> &body
        );

        ~Function() override;

        [[nodiscard]] auto getName() const -> std::shared_ptr<Identifier>;

    private:
        std::shared_ptr<Identifier> _name;
    };

    class FunctionParameter {
    public:
        FunctionParameter(const std::shared_ptr<Identifier> &name, const std::shared_ptr<AbstractType> &type);

        ~FunctionParameter();

        [[nodiscard]] auto getName() const -> std::shared_ptr<Identifier>;

        [[nodiscard]] auto getType() const -> std::shared_ptr<AbstractType>;

    private:
        std::shared_ptr<Identifier> _name;
        std::shared_ptr<AbstractType> _type;
    };
} // namespace filc::ast

#endif // FILC_FUNCTION_H
