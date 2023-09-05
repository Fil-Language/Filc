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
#include "AST.h"
#include "Error.h"

namespace filc::ast {
    Function::Function(Identifier *name, const std::vector<FunctionParameter *> &parameters, AbstractType *return_type,
                       const std::vector<AbstractExpression *> &body)
            : Lambda(parameters, return_type, body), _name(name) {}

    auto Function::getName() const -> Identifier * {
        return _name;
    }

    Function::~Function() {
        delete _name;
    }

    auto Function::resolveType(filc::environment::Environment *environment,
                               filc::message::MessageCollector *collector,
                               AbstractType *preferred_type) -> void {
        Lambda::resolveType(environment, collector, preferred_type);

        if (environment->hasName(_name->getName(), getExpressionType())) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    "Function " + _name->getName()
                    + " is already defined with signature " + getExpressionType()->dump(),
                    getPosition()
            ));
            setExpressionType(nullptr);
            return;
        }

        environment->addName(_name->getName(), getExpressionType());
    }

    auto Function::addNameToEnvironment(filc::environment::Environment *environment) const -> void {
        environment->addName(_name->getName(), getExpressionType());
    }
}
