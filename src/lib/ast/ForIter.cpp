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
    ForIter::ForIter(bool constant, Identifier *identifier, AbstractExpression *array, BlockBody *body)
            : _constant(constant), _identifier(identifier), _array(array), _body(body), _body_environment(nullptr) {}

    auto ForIter::isConstant() const -> bool {
        return _constant;
    }

    auto ForIter::getIdentifier() const -> Identifier * {
        return _identifier;
    }

    auto ForIter::getArray() const -> AbstractExpression * {
        return _array;
    }

    auto ForIter::getBody() const -> BlockBody * {
        return _body;
    }

    ForIter::~ForIter() {
        delete _identifier;
        delete _array;
        delete _body;
    }

    auto ForIter::resolveType(filc::environment::Environment *environment,
                              filc::message::MessageCollector *collector,
                              const std::shared_ptr<AbstractType> &preferred_type) -> void {
        _body_environment = new filc::environment::Environment("", environment);

        _array->resolveType(environment, collector, nullptr);
        auto array_type = _array->getExpressionType();
        if (dynamic_cast<PointerType *>(array_type.get()) == nullptr) {
            auto *array_operator = environment->getName(
                    "operator[]",
                    new filc::ast::LambdaType({environment->getType("int")}, array_type->getInnerType())
            );
            if (array_operator == nullptr) {
                collector->addError(new filc::message::Error(
                        filc::message::ERROR,
                        "Value is not iterable",
                        _array->getPosition()
                ));
                return;
            }
        }

        if (environment->hasName(_identifier->getName(), nullptr)) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    _identifier->getName() + " is already defined",
                    _identifier->getPosition()
            ));
            return;
        }
        _body_environment->addName(_identifier->getName(), array_type->getInnerType());

        _body->resolveType(_body_environment, collector, nullptr);
        std::shared_ptr<AbstractType> body_type = _body->getExpressionType();
        if (body_type == nullptr) {
            return;
        }

        setExpressionType(std::make_shared<PointerType>(body_type));
    }
}
