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
    Environment::Environment(const Environment *parent)
            : _parent(parent) {}

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

        global = new Environment;

        // Types
        auto *int_type = new filc::ast::Type(new filc::ast::Identifier("int"));
        auto *double_type = new filc::ast::Type(new filc::ast::Identifier("double"));
        auto *float_type = new filc::ast::Type(new filc::ast::Identifier("float"));
        auto *char_type = new filc::ast::Type(new filc::ast::Identifier("char"));
        auto *char_pointer_type = new filc::ast::PointerType(new filc::ast::Type(new filc::ast::Identifier("char")));
        auto *bool_type = new filc::ast::Type(new filc::ast::Identifier("bool"));
        auto *void_type = new filc::ast::Type(new filc::ast::Identifier("void"));
        auto iok = global->addType(int_type)
                   && global->addType(double_type)
                   && global->addType(float_type)
                   && global->addType(char_type)
                   && global->addType(char_pointer_type)
                   && global->addType(bool_type)
                   && global->addType(void_type);
        if (!iok) {
            throw std::logic_error("Fail to add base types to global environment");
        }

        // Names
        iok = global->addName("true", bool_type)
              && global->addName("false", bool_type);
        if (!iok) {
            throw std::logic_error("Fail to add base names to global environment");
        }

        // NOLINTBEGIN
        // Operators
        // - Assignations
        iok = global->addName("operator=", new filc::ast::LambdaType({int_type, int_type}, int_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({int_type, double_type}, int_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({int_type, float_type}, int_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({int_type, char_type}, int_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({int_type, bool_type}, int_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({double_type, int_type}, double_type, void_type))
              && global->addName("operator=",new filc::ast::LambdaType({double_type, double_type}, double_type, void_type))
              && global->addName("operator=",new filc::ast::LambdaType({double_type, float_type}, double_type, void_type))
              && global->addName("operator=",new filc::ast::LambdaType({double_type, char_type}, double_type, void_type))
              && global->addName("operator=",new filc::ast::LambdaType({double_type, bool_type}, double_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({float_type, int_type}, float_type, void_type))
              && global->addName("operator=",new filc::ast::LambdaType({float_type, double_type}, float_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({float_type, float_type}, float_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({float_type, char_type}, float_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({float_type, bool_type}, float_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({char_type, int_type}, char_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({char_type, double_type}, char_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({char_type, float_type}, char_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({char_type, char_type}, char_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({char_type, bool_type}, char_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({bool_type, int_type}, bool_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({bool_type, double_type}, bool_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({bool_type, float_type}, bool_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({bool_type, char_type}, bool_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({bool_type, bool_type}, bool_type, void_type))
              && global->addName("operator=", new filc::ast::LambdaType({char_pointer_type, char_pointer_type},char_pointer_type, void_type));
        if (!iok) {
            throw std::logic_error("Fail to add base assignations to global environment");
        }
        // - Prefix unary
        iok = global->addName("operator++", new filc::ast::LambdaType({}, int_type, int_type))
              && global->addName("operator--", new filc::ast::LambdaType({}, int_type, int_type))
              && global->addName("operator+", new filc::ast::LambdaType({}, int_type, int_type))
              && global->addName("operator-", new filc::ast::LambdaType({}, int_type, int_type))
              && global->addName("operator&", new filc::ast::LambdaType({}, new filc::ast::PointerType(int_type),int_type))
              && global->addName("operator++", new filc::ast::LambdaType({}, double_type, double_type))
              && global->addName("operator--", new filc::ast::LambdaType({}, double_type, double_type))
              && global->addName("operator+", new filc::ast::LambdaType({}, double_type, double_type))
              && global->addName("operator-", new filc::ast::LambdaType({}, double_type, double_type))
              && global->addName("operator&", new filc::ast::LambdaType({}, new filc::ast::PointerType(double_type),double_type))
              && global->addName("operator++", new filc::ast::LambdaType({}, float_type, float_type))
              && global->addName("operator--", new filc::ast::LambdaType({}, float_type, float_type))
              && global->addName("operator+", new filc::ast::LambdaType({}, float_type, float_type))
              && global->addName("operator-", new filc::ast::LambdaType({}, float_type, float_type))
              && global->addName("operator&", new filc::ast::LambdaType({}, new filc::ast::PointerType(float_type),float_type))
              && global->addName("operator++", new filc::ast::LambdaType({}, char_type, char_type))
              && global->addName("operator--", new filc::ast::LambdaType({}, char_type, char_type))
              && global->addName("operator&", new filc::ast::LambdaType({}, char_pointer_type, char_type))
              && global->addName("operator!", new filc::ast::LambdaType({}, bool_type, bool_type))
              && global->addName("operator&", new filc::ast::LambdaType({}, new filc::ast::PointerType(bool_type),bool_type))
              && global->addName("operator++", new filc::ast::LambdaType({}, char_pointer_type, char_pointer_type))
              && global->addName("operator--", new filc::ast::LambdaType({}, char_pointer_type, char_pointer_type))
              && global->addName("operator&", new filc::ast::LambdaType({},new filc::ast::PointerType(char_pointer_type),char_pointer_type))
              && global->addName("operator*", new filc::ast::LambdaType({}, char_type, char_pointer_type));
        if (!iok) {
            throw std::logic_error("Fail to add base prefix unary calcul to global environment");
        }
        // - Postfix unary
        iok = global->addName("operator++", new filc::ast::LambdaType({void_type}, int_type, int_type))
              && global->addName("operator--", new filc::ast::LambdaType({void_type}, int_type, int_type))
              && global->addName("operator++", new filc::ast::LambdaType({void_type}, double_type, double_type))
              && global->addName("operator--", new filc::ast::LambdaType({void_type}, double_type, double_type))
              && global->addName("operator++", new filc::ast::LambdaType({void_type}, float_type, float_type))
              && global->addName("operator--", new filc::ast::LambdaType({void_type}, float_type, float_type))
              && global->addName("operator++", new filc::ast::LambdaType({void_type}, char_type, char_type))
              && global->addName("operator--", new filc::ast::LambdaType({void_type}, char_type, char_type))
              && global->addName("operator++", new filc::ast::LambdaType({void_type}, char_pointer_type,char_pointer_type))
              && global->addName("operator--", new filc::ast::LambdaType({void_type}, char_pointer_type,char_pointer_type))
              && global->addName("operator[]", new filc::ast::LambdaType({int_type}, char_type, char_pointer_type));
        if (!iok) {
            throw std::logic_error("Fail to add base postfix unary calcul to global environment");
        }
        // - Binary
        iok = global->addName("operator*", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator*", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator*", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator*", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator/", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator/", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator/", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator/", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator%", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator%", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator%", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator%", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator+", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator+", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator+", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator+", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator-", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator-", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator-", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator-", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator<", new filc::ast::LambdaType({int_type, int_type}, bool_type, int_type))
              && global->addName("operator<", new filc::ast::LambdaType({int_type, double_type}, bool_type, int_type))
              && global->addName("operator<", new filc::ast::LambdaType({int_type, float_type}, bool_type, int_type))
              && global->addName("operator<", new filc::ast::LambdaType({int_type, char_type}, bool_type, int_type))
              && global->addName("operator>", new filc::ast::LambdaType({int_type, int_type}, bool_type, int_type))
              && global->addName("operator>", new filc::ast::LambdaType({int_type, double_type}, bool_type, int_type))
              && global->addName("operator>", new filc::ast::LambdaType({int_type, float_type}, bool_type, int_type))
              && global->addName("operator>", new filc::ast::LambdaType({int_type, char_type}, bool_type, int_type))
              && global->addName("operator==", new filc::ast::LambdaType({int_type, int_type}, bool_type, int_type))
              && global->addName("operator==", new filc::ast::LambdaType({int_type, double_type}, bool_type, int_type))
              && global->addName("operator==", new filc::ast::LambdaType({int_type, float_type}, bool_type, int_type))
              && global->addName("operator==", new filc::ast::LambdaType({int_type, char_type}, bool_type, int_type))
              && global->addName("operator<=", new filc::ast::LambdaType({int_type, int_type}, bool_type, int_type))
              && global->addName("operator<=", new filc::ast::LambdaType({int_type, double_type}, bool_type, int_type))
              && global->addName("operator<=", new filc::ast::LambdaType({int_type, float_type}, bool_type, int_type))
              && global->addName("operator<=", new filc::ast::LambdaType({int_type, char_type}, bool_type, int_type))
              && global->addName("operator>=", new filc::ast::LambdaType({int_type, int_type}, bool_type, int_type))
              && global->addName("operator>=", new filc::ast::LambdaType({int_type, double_type}, bool_type, int_type))
              && global->addName("operator>=", new filc::ast::LambdaType({int_type, float_type}, bool_type, int_type))
              && global->addName("operator>=", new filc::ast::LambdaType({int_type, char_type}, bool_type, int_type))
              && global->addName("operator!=", new filc::ast::LambdaType({int_type, int_type}, bool_type, int_type))
              && global->addName("operator!=", new filc::ast::LambdaType({int_type, double_type}, bool_type, int_type))
              && global->addName("operator!=", new filc::ast::LambdaType({int_type, float_type}, bool_type, int_type))
              && global->addName("operator!=", new filc::ast::LambdaType({int_type, char_type}, bool_type, int_type))
              && global->addName("operator*=", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator*=", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator*=", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator*=", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator/=", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator/=", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator/=", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator/=", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator%=", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator%=", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator%=", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator%=", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator+=", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator+=", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator+=", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator+=", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))
              && global->addName("operator-=", new filc::ast::LambdaType({int_type, int_type}, int_type, int_type))
              && global->addName("operator-=", new filc::ast::LambdaType({int_type, double_type}, int_type, int_type))
              && global->addName("operator-=", new filc::ast::LambdaType({int_type, float_type}, int_type, int_type))
              && global->addName("operator-=", new filc::ast::LambdaType({int_type, char_type}, int_type, int_type))

              && global->addName("operator*", new filc::ast::LambdaType({double_type, int_type}, double_type,double_type))
              && global->addName("operator*", new filc::ast::LambdaType({double_type, double_type}, double_type,double_type))
              && global->addName("operator*", new filc::ast::LambdaType({double_type, float_type}, double_type,double_type))
              && global->addName("operator*", new filc::ast::LambdaType({double_type, char_type}, double_type,double_type))
              && global->addName("operator/", new filc::ast::LambdaType({double_type, int_type}, double_type,double_type))
              && global->addName("operator/", new filc::ast::LambdaType({double_type, double_type}, double_type,double_type))
              && global->addName("operator/", new filc::ast::LambdaType({double_type, float_type}, double_type,double_type))
              && global->addName("operator/", new filc::ast::LambdaType({double_type, char_type}, double_type,double_type))
              && global->addName("operator%", new filc::ast::LambdaType({double_type, int_type}, double_type,double_type))
              && global->addName("operator%", new filc::ast::LambdaType({double_type, double_type}, double_type,double_type))
              && global->addName("operator%", new filc::ast::LambdaType({double_type, float_type}, double_type,double_type))
              && global->addName("operator%", new filc::ast::LambdaType({double_type, char_type}, double_type,double_type))
              && global->addName("operator+", new filc::ast::LambdaType({double_type, int_type}, double_type,double_type))
              && global->addName("operator+", new filc::ast::LambdaType({double_type, double_type}, double_type,double_type))
              && global->addName("operator+", new filc::ast::LambdaType({double_type, float_type}, double_type,double_type))
              && global->addName("operator+", new filc::ast::LambdaType({double_type, char_type}, double_type,double_type))
              && global->addName("operator-", new filc::ast::LambdaType({double_type, int_type}, double_type,double_type))
              && global->addName("operator-", new filc::ast::LambdaType({double_type, double_type}, double_type,double_type))
              && global->addName("operator-", new filc::ast::LambdaType({double_type, float_type}, double_type,double_type))
              && global->addName("operator-", new filc::ast::LambdaType({double_type, char_type}, double_type,double_type))
              && global->addName("operator<", new filc::ast::LambdaType({double_type, int_type}, bool_type,double_type))
              && global->addName("operator<", new filc::ast::LambdaType({double_type, double_type}, bool_type,double_type))
              && global->addName("operator<", new filc::ast::LambdaType({double_type, float_type}, bool_type,double_type))
              && global->addName("operator<", new filc::ast::LambdaType({double_type, char_type}, bool_type,double_type))
              && global->addName("operator>", new filc::ast::LambdaType({double_type, int_type}, bool_type,double_type))
              && global->addName("operator>", new filc::ast::LambdaType({double_type, double_type}, bool_type,double_type))
              && global->addName("operator>", new filc::ast::LambdaType({double_type, float_type}, bool_type,double_type))
              && global->addName("operator>", new filc::ast::LambdaType({double_type, char_type}, bool_type,double_type))
              && global->addName("operator==", new filc::ast::LambdaType({double_type, int_type}, bool_type,double_type))
              && global->addName("operator==", new filc::ast::LambdaType({double_type, double_type}, bool_type,double_type))
              && global->addName("operator==", new filc::ast::LambdaType({double_type, float_type}, bool_type,double_type))
              && global->addName("operator==", new filc::ast::LambdaType({double_type, char_type}, bool_type,double_type))
              && global->addName("operator<=", new filc::ast::LambdaType({double_type, int_type}, bool_type,double_type))
              && global->addName("operator<=", new filc::ast::LambdaType({double_type, double_type}, bool_type,double_type))
              && global->addName("operator<=", new filc::ast::LambdaType({double_type, float_type}, bool_type,double_type))
              && global->addName("operator<=", new filc::ast::LambdaType({double_type, char_type}, bool_type,double_type))
              && global->addName("operator>=", new filc::ast::LambdaType({double_type, int_type}, bool_type,double_type))
              && global->addName("operator>=", new filc::ast::LambdaType({double_type, double_type}, bool_type,double_type))
              && global->addName("operator>=", new filc::ast::LambdaType({double_type, float_type}, bool_type,double_type))
              && global->addName("operator>=", new filc::ast::LambdaType({double_type, char_type}, bool_type,double_type))
              && global->addName("operator!=", new filc::ast::LambdaType({double_type, int_type}, bool_type,double_type))
              && global->addName("operator!=", new filc::ast::LambdaType({double_type, double_type}, bool_type,double_type))
              && global->addName("operator!=", new filc::ast::LambdaType({double_type, float_type}, bool_type,double_type))
              && global->addName("operator!=", new filc::ast::LambdaType({double_type, char_type}, bool_type,double_type))
              && global->addName("operator*=", new filc::ast::LambdaType({double_type, int_type}, int_type,double_type))
              && global->addName("operator*=", new filc::ast::LambdaType({double_type, double_type}, int_type,double_type))
              && global->addName("operator*=", new filc::ast::LambdaType({double_type, float_type}, int_type,double_type))
              && global->addName("operator*=", new filc::ast::LambdaType({double_type, char_type}, int_type,double_type))
              && global->addName("operator/=", new filc::ast::LambdaType({double_type, int_type}, int_type,double_type))
              && global->addName("operator/=", new filc::ast::LambdaType({double_type, double_type}, int_type,double_type))
              && global->addName("operator/=", new filc::ast::LambdaType({double_type, float_type}, int_type,double_type))
              && global->addName("operator/=", new filc::ast::LambdaType({double_type, char_type}, int_type,double_type))
              && global->addName("operator%=", new filc::ast::LambdaType({double_type, int_type}, int_type,double_type))
              && global->addName("operator%=", new filc::ast::LambdaType({double_type, double_type}, int_type,double_type))
              && global->addName("operator%=", new filc::ast::LambdaType({double_type, float_type}, int_type,double_type))
              && global->addName("operator%=", new filc::ast::LambdaType({double_type, char_type}, int_type,double_type))
              && global->addName("operator+=", new filc::ast::LambdaType({double_type, int_type}, int_type,double_type))
              && global->addName("operator+=", new filc::ast::LambdaType({double_type, double_type}, int_type,double_type))
              && global->addName("operator+=", new filc::ast::LambdaType({double_type, float_type}, int_type,double_type))
              && global->addName("operator+=", new filc::ast::LambdaType({double_type, char_type}, int_type,double_type))
              && global->addName("operator-=", new filc::ast::LambdaType({double_type, int_type}, int_type,double_type))
              && global->addName("operator-=", new filc::ast::LambdaType({double_type, double_type}, int_type,double_type))
              && global->addName("operator-=", new filc::ast::LambdaType({double_type, float_type}, int_type,double_type))
              && global->addName("operator-=", new filc::ast::LambdaType({double_type, char_type}, int_type,double_type))

              && global->addName("operator*", new filc::ast::LambdaType({float_type, int_type}, float_type, float_type))
              && global->addName("operator*", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator*", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator*", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator/", new filc::ast::LambdaType({float_type, int_type}, float_type, float_type))
              && global->addName("operator/", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator/", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator/", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator%", new filc::ast::LambdaType({float_type, int_type}, float_type, float_type))
              && global->addName("operator%", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator%", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator%", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator+", new filc::ast::LambdaType({float_type, int_type}, float_type, float_type))
              && global->addName("operator+", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator+", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator+", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator-", new filc::ast::LambdaType({float_type, int_type}, float_type, float_type))
              && global->addName("operator-", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator-", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator-", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator<", new filc::ast::LambdaType({float_type, int_type}, bool_type, float_type))
              && global->addName("operator<", new filc::ast::LambdaType({float_type, double_type}, bool_type,float_type))
              && global->addName("operator<", new filc::ast::LambdaType({float_type, float_type}, bool_type,float_type))
              && global->addName("operator<", new filc::ast::LambdaType({float_type, char_type}, bool_type, float_type))
              && global->addName("operator>", new filc::ast::LambdaType({float_type, int_type}, bool_type, float_type))
              && global->addName("operator>", new filc::ast::LambdaType({float_type, double_type}, bool_type,float_type))
              && global->addName("operator>", new filc::ast::LambdaType({float_type, float_type}, bool_type,float_type))
              && global->addName("operator>", new filc::ast::LambdaType({float_type, char_type}, bool_type, float_type))
              && global->addName("operator==", new filc::ast::LambdaType({float_type, int_type}, bool_type,float_type))
              && global->addName("operator==", new filc::ast::LambdaType({float_type, double_type}, bool_type,float_type))
              && global->addName("operator==", new filc::ast::LambdaType({float_type, float_type}, bool_type,float_type))
              && global->addName("operator==", new filc::ast::LambdaType({float_type, char_type}, bool_type,float_type))
              && global->addName("operator<=", new filc::ast::LambdaType({float_type, int_type}, bool_type,float_type))
              && global->addName("operator<=", new filc::ast::LambdaType({float_type, double_type}, bool_type,float_type))
              && global->addName("operator<=", new filc::ast::LambdaType({float_type, float_type}, bool_type,float_type))
              && global->addName("operator<=", new filc::ast::LambdaType({float_type, char_type}, bool_type,float_type))
              && global->addName("operator>=", new filc::ast::LambdaType({float_type, int_type}, bool_type,float_type))
              && global->addName("operator>=", new filc::ast::LambdaType({float_type, double_type}, bool_type,float_type))
              && global->addName("operator>=", new filc::ast::LambdaType({float_type, float_type}, bool_type,float_type))
              && global->addName("operator>=", new filc::ast::LambdaType({float_type, char_type}, bool_type,float_type))
              && global->addName("operator!=", new filc::ast::LambdaType({float_type, int_type}, bool_type,float_type))
              && global->addName("operator!=", new filc::ast::LambdaType({float_type, double_type}, bool_type,float_type))
              && global->addName("operator!=", new filc::ast::LambdaType({float_type, float_type}, bool_type,float_type))
              && global->addName("operator!=", new filc::ast::LambdaType({float_type, char_type}, bool_type,float_type))
              && global->addName("operator&&", new filc::ast::LambdaType({float_type, int_type}, bool_type,float_type))
              && global->addName("operator&&", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator&&", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator&&", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator||", new filc::ast::LambdaType({float_type, int_type}, float_type,float_type))
              && global->addName("operator||", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator||", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator||", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator*=", new filc::ast::LambdaType({float_type, int_type}, float_type,float_type))
              && global->addName("operator*=", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator*=", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator*=", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator/=", new filc::ast::LambdaType({float_type, int_type}, float_type,float_type))
              && global->addName("operator/=", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator/=", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator/=", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator%=", new filc::ast::LambdaType({float_type, int_type}, float_type,float_type))
              && global->addName("operator%=", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator%=", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator%=", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator+=", new filc::ast::LambdaType({float_type, int_type}, float_type,float_type))
              && global->addName("operator+=", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator+=", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator+=", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))
              && global->addName("operator-=", new filc::ast::LambdaType({float_type, int_type}, float_type,float_type))
              && global->addName("operator-=", new filc::ast::LambdaType({float_type, double_type}, float_type,float_type))
              && global->addName("operator-=", new filc::ast::LambdaType({float_type, float_type}, float_type,float_type))
              && global->addName("operator-=", new filc::ast::LambdaType({float_type, char_type}, float_type,float_type))

              && global->addName("operator*", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator*", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator*", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator*", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator/", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator/", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator/", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator/", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator%", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator%", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator%", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator%", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator+", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator+", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator+", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator+", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator-", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator-", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator-", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator-", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator<", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator<", new filc::ast::LambdaType({char_type, double_type}, bool_type, char_type))
              && global->addName("operator<", new filc::ast::LambdaType({char_type, float_type}, bool_type, char_type))
              && global->addName("operator<", new filc::ast::LambdaType({char_type, char_type}, bool_type, char_type))
              && global->addName("operator>", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator>", new filc::ast::LambdaType({char_type, double_type}, bool_type, char_type))
              && global->addName("operator>", new filc::ast::LambdaType({char_type, float_type}, bool_type, char_type))
              && global->addName("operator>", new filc::ast::LambdaType({char_type, char_type}, bool_type, char_type))
              && global->addName("operator==", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator==", new filc::ast::LambdaType({char_type, double_type}, bool_type, char_type))
              && global->addName("operator==", new filc::ast::LambdaType({char_type, float_type}, bool_type, char_type))
              && global->addName("operator==", new filc::ast::LambdaType({char_type, char_type}, bool_type, char_type))
              && global->addName("operator<=", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator<=", new filc::ast::LambdaType({char_type, double_type}, bool_type, char_type))
              && global->addName("operator<=", new filc::ast::LambdaType({char_type, float_type}, bool_type, char_type))
              && global->addName("operator<=", new filc::ast::LambdaType({char_type, char_type}, bool_type, char_type))
              && global->addName("operator>=", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator>=", new filc::ast::LambdaType({char_type, double_type}, bool_type, char_type))
              && global->addName("operator>=", new filc::ast::LambdaType({char_type, float_type}, bool_type, char_type))
              && global->addName("operator>=", new filc::ast::LambdaType({char_type, char_type}, bool_type, char_type))
              && global->addName("operator!=", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator!=", new filc::ast::LambdaType({char_type, double_type}, bool_type, char_type))
              && global->addName("operator!=", new filc::ast::LambdaType({char_type, float_type}, bool_type, char_type))
              && global->addName("operator!=", new filc::ast::LambdaType({char_type, char_type}, bool_type, char_type))
              && global->addName("operator&&", new filc::ast::LambdaType({char_type, int_type}, bool_type, char_type))
              && global->addName("operator&&", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator&&", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator&&", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator||", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator||", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator||", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator||", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator*=", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator*=", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator*=", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator*=", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator/=", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator/=", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator/=", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator/=", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator%=", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator%=", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator%=", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator%=", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator+=", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator+=", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator+=", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator+=", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))
              && global->addName("operator-=", new filc::ast::LambdaType({char_type, int_type}, char_type, char_type))
              && global->addName("operator-=", new filc::ast::LambdaType({char_type, double_type}, char_type, char_type))
              && global->addName("operator-=", new filc::ast::LambdaType({char_type, float_type}, char_type, char_type))
              && global->addName("operator-=", new filc::ast::LambdaType({char_type, char_type}, char_type, char_type))

              && global->addName("operator==", new filc::ast::LambdaType({bool_type, bool_type}, bool_type, bool_type))
              && global->addName("operator!=", new filc::ast::LambdaType({bool_type, bool_type}, bool_type, bool_type))
              && global->addName("operator&&", new filc::ast::LambdaType({bool_type, bool_type}, bool_type, bool_type))
              && global->addName("operator||", new filc::ast::LambdaType({bool_type, bool_type}, bool_type, bool_type));
        if (!iok) {
            throw std::logic_error("Fail to add base binary calcul to global environment");
        }
        // NOLINTEND

        return global;
    }
}
