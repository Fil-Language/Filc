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
#include "Environment.h"
#include "AST.h"
#include <algorithm>

namespace filc::environment {
    Environment::Environment(const std::string &module, const Environment *parent)
            : _module(module), _parent(parent) {}

    auto Environment::getModule() const -> const std::string & {
        return _module;
    }

    auto Environment::getParent() const -> const Environment * {
        return _parent;
    }

    auto Environment::hasName(const std::string &name, filc::ast::AbstractType *type) const -> bool {
        return std::any_of(_names.begin(), _names.end(), [name, type](auto *item) -> bool {
            return item->getName() == name && (type == nullptr || *item->getType() == *type);
        }) || (_parent != nullptr && _parent->hasName(name));
    }

    auto Environment::addName(const std::string &name, filc::ast::AbstractType *type) -> bool {
        if (hasName(name, type)) {
            return false;
        }

        _names.push_back(new Name(name, type));

        return true;
    }

    auto Environment::getName(const std::string &name, filc::ast::AbstractType *type) const -> Name * {
        if (hasName(name, type)) {
            auto result = std::find_if(_names.begin(), _names.end(), [name, type](auto *item) -> bool {
                return item->getName() == name && (type == nullptr || *item->getType() == *type);
            });

            if (result == _names.end()) {
                if (_parent != nullptr) {
                    return _parent->getName(name, type);
                }

                return nullptr;
            }

            return *result;
        }

        return nullptr;
    }

    auto Environment::hasType(const std::string &type) const -> bool {
        return std::any_of(_types.begin(), _types.end(), [type](auto *item) -> bool {
            return item->dump() == type;
        }) || (_parent != nullptr && _parent->hasType(type));
    }

    auto Environment::addType(filc::ast::AbstractType *type) -> bool {
        if (hasType(type->dump())) {
            return false;
        }

        _types.push_back(type);

        return true;
    }

    auto Environment::getType(const std::string &type) const -> filc::ast::AbstractType * {
        if (hasType(type)) {
            auto result = std::find_if(_types.begin(), _types.end(), [type](auto *item) -> bool {
                return item->dump() == type;
            });
            if (result == _types.end()) {
                if (_parent != nullptr) {
                    return _parent->getType(type);
                }

                return nullptr;
            }

            return *result;
        }

        return nullptr;
    }

    auto Environment::getGlobalEnvironment() -> const Environment * {
        static Environment *global = nullptr;
        if (global != nullptr) {
            return global;
        }

        global = new Environment("__global__");

        auto basic_types = addBasicTypes(global);
        addConstants(global, basic_types);
        addAssignations(global, basic_types);
        addPrefixUnary(global, basic_types);
        addPostfixUnary(global, basic_types);
        addBinary(global, basic_types);

        return global;
    }

    auto Environment::addBasicTypes(Environment *global) -> BasicTypes {
        BasicTypes basic_types;
        basic_types._int_type = new ast::Type(new ast::Identifier("int"));
        basic_types._double_type = new ast::Type(new ast::Identifier("double"));
        basic_types._float_type = new ast::Type(new ast::Identifier("float"));
        basic_types._char_type = new ast::Type(new ast::Identifier("char"));
        basic_types._bool_type = new ast::Type(new ast::Identifier("bool"));

        auto is_ok = global->addType(basic_types._int_type)
                     && global->addType(basic_types._double_type)
                     && global->addType(basic_types._float_type)
                     && global->addType(basic_types._char_type)
                     && global->addType(basic_types._bool_type);
        if (!is_ok) {
            throw std::logic_error("Fail to add base types to global environment");
        }

        return basic_types;
    }

    auto Environment::addConstants(Environment *global, BasicTypes &basic_types) -> void {
        auto is_ok = global->addName("true", basic_types._bool_type)
                     && global->addName("false", basic_types._bool_type);
        if (!is_ok) {
            throw std::logic_error("Fail to add base names to global environment");
        }
    }

    auto Environment::addAssignations(Environment *global, BasicTypes &basic_types) -> void {
        auto iok = global->addName(
                "operator=",
                new ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator=",
                new ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator=",
                new ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator=",
                new ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator=",
                new ast::LambdaType({basic_types._bool_type, basic_types._bool_type}, basic_types._bool_type)
        );
        if (!iok) {
            throw std::logic_error("Fail to add base assignations to global environment");
        }
    }

    auto Environment::addPrefixUnary(Environment *global, BasicTypes &basic_types) -> void {
        auto *ptr_int = new filc::ast::PointerType(basic_types._int_type);
        auto *ptr_double = new filc::ast::PointerType(basic_types._double_type);
        auto *ptr_float = new filc::ast::PointerType(basic_types._float_type);
        auto *ptr_char = new filc::ast::PointerType(basic_types._char_type);
        auto is_ok = global->addName(
                "operator++",
                new ast::LambdaType({basic_types._int_type}, ptr_int)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._int_type}, ptr_int)
        ) && global->addName(
                "operator+",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator-",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator!",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({basic_types._double_type}, ptr_double)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._double_type}, ptr_double)
        ) && global->addName(
                "operator+",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator-",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator!",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({basic_types._float_type}, ptr_float)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._float_type}, ptr_float)
        ) && global->addName(
                "operator+",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator-",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator!",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({basic_types._char_type}, ptr_char)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._char_type}, ptr_char)
        ) && global->addName(
                "operator!",
                new ast::LambdaType({basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator!",
                new ast::LambdaType({basic_types._bool_type}, basic_types._bool_type)
        );
        if (!is_ok) {
            throw std::logic_error("Fail to add base prefix unary calcul to global environment");
        }
    }

    auto Environment::addPostfixUnary(Environment *global, BasicTypes &basic_types) -> void {
        auto is_ok = global->addName(
                "operator++",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({basic_types._char_type}, basic_types._char_type)
        );
        if (!is_ok) {
            throw std::logic_error("Fail to add base postfix unary calcul to global environment");
        }
    }

    auto Environment::addBinary(Environment *global, BasicTypes &basic_types) -> void {
        auto is_ok = global->addName(
                "operator*",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator/",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator%",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator+",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator-",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator<",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._bool_type)
        ) && global->addName(
                "operator==",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._bool_type)
        ) && global->addName(
                "operator<=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._bool_type)
        ) && global->addName(
                "operator!=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._bool_type)
        ) && global->addName(
                "operator*=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({basic_types._int_type, basic_types._int_type}, basic_types._int_type)
        )

                     && global->addName(
                "operator*",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type},
                                          basic_types._double_type)
        ) && global->addName(
                "operator/",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type},
                                          basic_types._double_type)
        ) && global->addName(
                "operator%",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type},
                                          basic_types._double_type)
        ) && global->addName(
                "operator+",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type},
                                          basic_types._double_type)
        ) && global->addName(
                "operator-",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type},
                                          basic_types._double_type)
        ) && global->addName(
                "operator<",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._bool_type)
        ) && global->addName(
                "operator==",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._bool_type)
        ) && global->addName(
                "operator<=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._bool_type)
        ) && global->addName(
                "operator!=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._bool_type)
        ) && global->addName(
                "operator*=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._int_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._int_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._int_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._int_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({basic_types._double_type, basic_types._double_type}, basic_types._int_type)
        )

                     && global->addName(
                "operator*",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator/",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator%",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator+",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator-",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator<",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._bool_type)
        ) && global->addName(
                "operator==",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._bool_type)
        ) && global->addName(
                "operator<=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._bool_type)
        ) && global->addName(
                "operator!=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._bool_type)
        ) && global->addName(
                "operator&&",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator||",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator*=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({basic_types._float_type, basic_types._float_type}, basic_types._float_type)
        )

                     && global->addName(
                "operator*",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator/",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator%",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator+",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator-",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator<",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._bool_type)
        ) && global->addName(
                "operator==",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._bool_type)
        ) && global->addName(
                "operator<=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._bool_type)
        ) && global->addName(
                "operator>=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._bool_type)
        ) && global->addName(
                "operator!=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._bool_type)
        ) && global->addName(
                "operator&&",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator||",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator*=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({basic_types._char_type, basic_types._char_type}, basic_types._char_type)
        )

                     && global->addName(
                "operator==",
                new filc::ast::LambdaType({basic_types._bool_type, basic_types._bool_type}, basic_types._bool_type)
        ) && global->addName(
                "operator!=",
                new filc::ast::LambdaType({basic_types._bool_type, basic_types._bool_type}, basic_types._bool_type)
        ) && global->addName(
                "operator&&",
                new filc::ast::LambdaType({basic_types._bool_type, basic_types._bool_type}, basic_types._bool_type)
        ) && global->addName(
                "operator||",
                new filc::ast::LambdaType({basic_types._bool_type, basic_types._bool_type}, basic_types._bool_type)
        );
        if (!is_ok) {
            throw std::logic_error("Fail to add base binary calcul to global environment");
        }
    }
}
