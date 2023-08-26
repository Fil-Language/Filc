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
    VariableDeclaration::VariableDeclaration(bool is_constant, Identifier *identifier, AbstractType *type)
            : _constant(is_constant), _identifier(identifier), _type(type), _assignation(nullptr) {}

    VariableDeclaration::~VariableDeclaration() {
        delete _identifier;
        delete _type;
        delete _assignation;
    }

    auto VariableDeclaration::isConstant() const -> bool {
        return _constant;
    }

    auto VariableDeclaration::getIdentifier() const -> Identifier * {
        return _identifier;
    }

    auto VariableDeclaration::getType() const -> AbstractType * {
        return _type;
    }

    auto VariableDeclaration::getAssignation() const -> AbstractExpression * {
        return _assignation;
    }

    auto VariableDeclaration::setAssignation(filc::ast::AbstractExpression *assignation) -> void {
        _assignation = assignation;
    }

    auto VariableDeclaration::resolveType(filc::environment::Environment *environment,
                                          filc::message::MessageCollector *collector) -> void {
        if (environment->hasName(_identifier->getName())) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR,
                                             "Variable " + _identifier->getName() + " already defined",
                                             _identifier->getPosition())
            );
            return;
        }

        _assignation->resolveType(environment, collector);
        auto *assignation_type = _assignation->getExpressionType();
        if (assignation_type == nullptr) {
            return;
        }

        if (!environment->hasName("operator=", new filc::ast::LambdaType({_type, assignation_type},
                                                                         environment->getType("void")))) {
            collector->addError(
                    new filc::message::Error(filc::message::ERROR,
                                             "Cannot assign " + assignation_type->dump() + " to " + _type->dump(),
                                             _assignation->getPosition())
            );
            return;
        }

        environment->addName(_identifier->getName(), _type);
        setExpressionType(_type);
    }
}
