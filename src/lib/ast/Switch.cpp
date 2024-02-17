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
#include <algorithm>

namespace filc::ast {
    Switch::Switch(filc::ast::AbstractExpression *condition, const std::vector<SwitchCase *> &cases)
            : _condition(condition), _cases(cases) {}

    auto Switch::getCondition() const -> AbstractExpression * {
        return _condition;
    }

    auto Switch::getCases() const -> const std::vector<SwitchCase *> & {
        return _cases;
    }

    Switch::~Switch() {
        delete _condition;
        for (const auto &item: _cases) {
            delete item;
        }
    }

    auto Switch::resolveType(filc::environment::Environment *environment,
                             filc::message::MessageCollector *collector,
                             const std::shared_ptr<AbstractType> &preferred_type) -> void {
        _condition->resolveType(environment, collector, nullptr);
        auto condition_type = _condition->getExpressionType();
        if (condition_type == nullptr) {
            return;
        }

        auto count = std::count_if(_cases.begin(), _cases.end(), [](const auto *item) -> bool {
            return item->isDefault();
        });
        if (count > 1) {
            collector->addError(new filc::message::Error(
                    filc::message::ERROR,
                    "Switch can have only 1 default case, " + std::to_string(count) + " found",
                    getPosition()
            ));
            return;
        }

        std::shared_ptr<AbstractType> return_type = preferred_type;
        for (auto *item: _cases) {
            item->resolveType(environment, collector, return_type);
            auto item_type = item->getExpressionType();
            auto pattern_type = item->getPattern()->getExpressionType();
            if (item_type == nullptr) {
                return;
            }

            if (!item->isDefault() && *pattern_type != *condition_type) {
                collector->addError(new filc::message::Error(
                        filc::message::ERROR,
                        "Pattern type is not the same as condition type. Expected " + condition_type->dump()
                        + ", found " + pattern_type->dump(),
                        item->getPosition()
                ));
                return;
            }

            if (return_type == nullptr) {
                return_type = item_type;
            } else {
                if (*return_type != *item_type &&
                    !environment->hasName("operator=",
                                          new filc::ast::LambdaType({return_type, item_type}, return_type))) {
                    collector->addError(new filc::message::Error(
                            filc::message::ERROR,
                            "Switch case return wrong type. Expected " + return_type->dump()
                            + ", found " + item_type->dump(),
                            item->getPosition()
                    ));
                    return;
                }
            }
        }

        setExpressionType(return_type);
    }
}
