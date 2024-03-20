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
#include "type/Type.h"
#include "identifier/Identifier.h"
#include "Error.h"
#include <algorithm>
#include <memory>
#include <utility>
#include "llvm/IR/Verifier.h"

namespace filc::environment {
    Environment::Environment(std::string module, const Environment *parent)
            : _module(std::move(module)), _parent(parent) {
        if (parent == this) {
            throw std::logic_error("Environment cannot be its own parent");
        }
    }

    Environment::~Environment() {
        for (auto &name: _names) {
            delete name;
        }
    }

    auto Environment::getModule() const -> const std::string & {
        return _module;
    }

    auto Environment::getParent() const -> const Environment * {
        return _parent;
    }

    auto Environment::hasName(const std::string &name,
                              const std::shared_ptr<filc::ast::AbstractType> &type) const -> bool {
        return std::any_of(_names.begin(), _names.end(), [name, type](auto *item) -> bool {
            return item->getName() == name && (type == nullptr || *item->getType() == *type);
        }) || (_parent != nullptr && _parent->hasName(name, nullptr));
    }

    auto Environment::hasName(const std::string &name, filc::ast::AbstractType *type) const -> bool {
        return hasName(name, std::shared_ptr<filc::ast::AbstractType>(type));
    }

    auto Environment::addName(const std::string &name, const std::shared_ptr<filc::ast::AbstractType> &type) -> bool {
        if (hasName(name, type)) {
            return false;
        }

        _names.push_back(new Name(name, type));

        return true;
    }

    auto Environment::addName(const std::string &name, filc::ast::AbstractType *type) -> bool {
        return addName(name, std::shared_ptr<filc::ast::AbstractType>(type));
    }

    auto Environment::getName(const std::string &name,
                              const std::shared_ptr<filc::ast::AbstractType> &type) const -> Name * {
        if (hasName(name, type)) {
            auto result = std::find_if(_names.begin(), _names.end(), [name, type](const auto *item) -> bool {
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

    auto Environment::getName(const std::string &name, filc::ast::AbstractType *type) const -> Name * {
        return getName(name, std::shared_ptr<filc::ast::AbstractType>(type));
    }

    auto Environment::hasType(const std::string &type) const -> bool {
        return std::any_of(_types.begin(), _types.end(), [type](const auto &item) -> bool {
            return item->dump() == type;
        }) || (_parent != nullptr && _parent->hasType(type));
    }

    auto Environment::addType(const std::shared_ptr<filc::ast::AbstractType> &type) -> bool {
        if (hasType(type->dump())) {
            return false;
        }

        _types.push_back(type);

        return true;
    }

    auto Environment::getType(const std::string &type) const -> std::shared_ptr<filc::ast::AbstractType> {
        if (hasType(type)) {
            auto result = std::find_if(_types.begin(), _types.end(), [type](const auto &item) -> bool {
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
        basic_types._int_type = std::make_shared<filc::ast::Type>(std::make_shared<ast::Identifier>("int"));
        basic_types._double_type = std::make_shared<filc::ast::Type>(std::make_shared<ast::Identifier>("double"));
        basic_types._float_type = std::make_shared<filc::ast::Type>(std::make_shared<ast::Identifier>("float"));
        basic_types._char_type = std::make_shared<filc::ast::Type>(std::make_shared<ast::Identifier>("char"));
        basic_types._bool_type = std::make_shared<filc::ast::Type>(std::make_shared<ast::Identifier>("bool"));

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
        auto ptr_int = std::make_shared<filc::ast::PointerType>(basic_types._int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(basic_types._double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(basic_types._float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(basic_types._char_type);
        auto ptr_bool = std::make_shared<filc::ast::PointerType>(basic_types._bool_type);
        auto iok = global->addName(
                "operator=",
                std::make_shared<filc::ast::LambdaType>(
                        std::vector<std::shared_ptr<filc::ast::AbstractType>>({ptr_int, basic_types._int_type}),
                        basic_types._int_type)
        ) && global->addName(
                "operator=",
                std::make_shared<filc::ast::LambdaType>(
                        std::vector<std::shared_ptr<filc::ast::AbstractType>>({ptr_double, basic_types._double_type}),
                        basic_types._double_type)
        ) && global->addName(
                "operator=",
                std::make_shared<filc::ast::LambdaType>(
                        std::vector<std::shared_ptr<filc::ast::AbstractType>>({ptr_float, basic_types._float_type}),
                        basic_types._float_type)
        ) && global->addName(
                "operator=",
                std::make_shared<filc::ast::LambdaType>(
                        std::vector<std::shared_ptr<filc::ast::AbstractType>>({ptr_char, basic_types._char_type}),
                        basic_types._char_type)
        ) && global->addName(
                "operator=",
                std::make_shared<filc::ast::LambdaType>(
                        std::vector<std::shared_ptr<filc::ast::AbstractType>>({ptr_bool, basic_types._bool_type}),
                        basic_types._bool_type)
        );
        if (!iok) {
            throw std::logic_error("Fail to add base assignations to global environment");
        }
    }

    auto Environment::addPrefixUnary(Environment *global, BasicTypes &basic_types) -> void {
        auto ptr_int = std::make_shared<filc::ast::PointerType>(basic_types._int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(basic_types._double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(basic_types._float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(basic_types._char_type);
        auto is_ok = global->addName(
                "operator++",
                new ast::LambdaType({ptr_int}, ptr_int)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_int}, ptr_int)
        ) && global->addName(
                "operator+",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator-",
                new ast::LambdaType({basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({ptr_double}, ptr_double)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_double}, ptr_double)
        ) && global->addName(
                "operator+",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator-",
                new ast::LambdaType({basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({ptr_float}, ptr_float)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_float}, ptr_float)
        ) && global->addName(
                "operator+",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator-",
                new ast::LambdaType({basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({ptr_char}, ptr_char)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_char}, ptr_char)
        ) && global->addName(
                "operator!",
                new ast::LambdaType({basic_types._bool_type}, basic_types._bool_type)
        );
        if (!is_ok) {
            throw std::logic_error("Fail to add base prefix unary calcul to global environment");
        }
    }

    auto Environment::addPostfixUnary(Environment *global, BasicTypes &basic_types) -> void {
        auto ptr_int = std::make_shared<filc::ast::PointerType>(basic_types._int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(basic_types._double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(basic_types._float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(basic_types._char_type);
        auto is_ok = global->addName(
                "operator++",
                new ast::LambdaType({ptr_int}, basic_types._int_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_int}, basic_types._int_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({ptr_double}, basic_types._double_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_double}, basic_types._double_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({ptr_float}, basic_types._float_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_float}, basic_types._float_type)
        ) && global->addName(
                "operator++",
                new ast::LambdaType({ptr_char}, basic_types._char_type)
        ) && global->addName(
                "operator--",
                new ast::LambdaType({ptr_char}, basic_types._char_type)
        );
        if (!is_ok) {
            throw std::logic_error("Fail to add base postfix unary calcul to global environment");
        }
    }

    auto Environment::addBinary(Environment *global, BasicTypes &basic_types) -> void {
        auto ptr_int = std::make_shared<filc::ast::PointerType>(basic_types._int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(basic_types._double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(basic_types._float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(basic_types._char_type);
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
                new filc::ast::LambdaType({ptr_int, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({ptr_int, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({ptr_int, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({ptr_int, basic_types._int_type}, basic_types._int_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({ptr_int, basic_types._int_type}, basic_types._int_type)
        );

        is_ok = is_ok && global->addName(
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
                new filc::ast::LambdaType({ptr_double, basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({ptr_double, basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({ptr_double, basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({ptr_double, basic_types._double_type}, basic_types._double_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({ptr_double, basic_types._double_type}, basic_types._double_type)
        );

        is_ok = is_ok && global->addName(
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
                new filc::ast::LambdaType({ptr_float, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({ptr_float, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({ptr_float, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({ptr_float, basic_types._float_type}, basic_types._float_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({ptr_float, basic_types._float_type}, basic_types._float_type)
        );

        is_ok = is_ok && global->addName(
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
                new filc::ast::LambdaType({ptr_char, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator/=",
                new filc::ast::LambdaType({ptr_char, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator%=",
                new filc::ast::LambdaType({ptr_char, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator+=",
                new filc::ast::LambdaType({ptr_char, basic_types._char_type}, basic_types._char_type)
        ) && global->addName(
                "operator-=",
                new filc::ast::LambdaType({ptr_char, basic_types._char_type}, basic_types._char_type)
        );

        is_ok = is_ok && global->addName(
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

    auto Environment::generateIR(std::shared_ptr<filc::message::MessageCollector> collector,
                                 llvm::LLVMContext *context,
                                 llvm::Module *module,
                                 llvm::IRBuilder<> *builder) const -> void {
        if (_parent != nullptr) {
            // Generate only for global environment
            _parent->generateIR(collector, context, module, builder);
            return;
        }

        static auto generated = false;
        if (generated) {
            // Generate only once
            return;
        }

        getType("int")->setLLVMType(llvm::Type::getInt64Ty(*context));
        getType("double")->setLLVMType(llvm::Type::getDoubleTy(*context));
        getType("float")->setLLVMType(llvm::Type::getFloatTy(*context));
        getType("char")->setLLVMType(llvm::Type::getInt8Ty(*context));
        getType("bool")->setLLVMType(llvm::Type::getInt1Ty(*context));

        generateAssignations(collector, context, module, builder);
        generatePrefixUnary(collector, context, module, builder);
        generatePostFixUnary(collector, context, module, builder);
        generateBinary(collector, context, module, builder);

        generated = true;
    }

#define ASSIGNATION_FUNCTION(var, name, type, operator_type) {\
    std::vector<llvm::Type *> types_##var = {llvm::PointerType::getUnqual(type), type}; \
    auto *type_##var = llvm::FunctionType::get(type, types_##var, false); \
    auto *function_##var = llvm::Function::Create(type_##var, llvm::Function::ExternalLinkage, name, *module); \
    function_##var->getArg(0)->setName("a"); \
    function_##var->getArg(1)->setName("b"); \
    if (!function_##var->empty()) { \
        collector->addError(new filc::message::BasicError( \
            filc::message::ERROR, \
            "Tried to redefine " name \
        )); \
        return; \
    } \
    llvm::BasicBlock *basic_block_##var = llvm::BasicBlock::Create(*context, "entry", function_##var); \
    builder->SetInsertPoint(basic_block_##var); \
    auto *variable_##var = builder->CreateLoad(function_##var->getArg(0)->getType(), function_##var); \
    builder->CreateStore(function_##var->getArg(1), variable_##var); \
    builder->CreateRet(variable_##var); \
    llvm::verifyFunction(*function_##var); \
    getName("operator=", operator_type)->setFunction(function_##var); \
    }

    auto Environment::generateAssignations(std::shared_ptr<filc::message::MessageCollector> collector,
                                           llvm::LLVMContext *context,
                                           llvm::Module *module,
                                           llvm::IRBuilder<> *builder) const -> void {
        auto int_type = getType("int");
        auto double_type = getType("double");
        auto float_type = getType("float");
        auto char_type = getType("char");
        auto bool_type = getType("bool");
        auto ptr_int = std::make_shared<filc::ast::PointerType>(int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(char_type);
        auto ptr_bool = std::make_shared<filc::ast::PointerType>(bool_type);
        ASSIGNATION_FUNCTION(
                int_int, "operator=(int*, int) -> int", llvm::Type::getInt64Ty(*context),
                new filc::ast::LambdaType({ptr_int, int_type}, int_type)
        )
        ASSIGNATION_FUNCTION(
                double_double, "operator=(double*, double) -> double", llvm::Type::getDoubleTy(*context),
                new filc::ast::LambdaType({ptr_double, double_type}, double_type)
        )
        ASSIGNATION_FUNCTION(
                float_float, "operator=(float*, float) -> float", llvm::Type::getFloatTy(*context),
                new filc::ast::LambdaType({ptr_float, float_type}, float_type)
        )
        ASSIGNATION_FUNCTION(
                char_char, "operator=(char*, char) -> char", llvm::Type::getInt8Ty(*context),
                new filc::ast::LambdaType({ptr_char, char_type}, char_type)
        )
        ASSIGNATION_FUNCTION(
                bool_bool, "operator=(bool*, bool) -> bool", llvm::Type::getInt1Ty(*context),
                new filc::ast::LambdaType({ptr_bool, bool_type}, bool_type)
        )
    }

#define DEFINE_FUNCTION(name, params, rtype, body, var, operator_name, operator_type) { \
    std::vector<llvm::Type *> types_##var = params; \
    auto *type_##var = llvm::FunctionType::get( \
            rtype, \
            types_##var, \
            false \
    ); \
    auto *function_##var = llvm::Function::Create(type_##var, llvm::Function::ExternalLinkage, name, *module); \
    if (!function_##var->empty()) { \
        collector->addError(new filc::message::BasicError( \
                filc::message::ERROR, \
                "Tried to redefine " name \
        )); \
        return; \
    } \
    llvm::BasicBlock *basic_block_##var = llvm::BasicBlock::Create(*context, "entry", function_##var); \
    builder->SetInsertPoint(basic_block_##var); \
    body \
    llvm::verifyFunction(*function_##var); \
    getName(operator_name, operator_type)->setFunction(function_##var); \
    }

    auto Environment::generatePrefixUnary(std::shared_ptr<filc::message::MessageCollector> collector,
                                          llvm::LLVMContext *context,
                                          llvm::Module *module,
                                          llvm::IRBuilder<> *builder) const -> void {
        auto int_type = getType("int");
        auto double_type = getType("double");
        auto float_type = getType("float");
        auto char_type = getType("char");
        auto bool_type = getType("bool");
        auto ptr_int = std::make_shared<filc::ast::PointerType>(int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(char_type);

        //region int
        DEFINE_FUNCTION(
                "operator++(int*) -> int*",
                { llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                {
                    auto *variable_plusplus_int = builder->CreateLoad(
                            function_plusplus_int->getArg(0)->getType(),
                            function_plusplus_int);
                    auto *result_plusplus_int = builder->CreateAdd(
                            variable_plusplus_int,
                            llvm::ConstantInt::get(*context, llvm::APInt(64, 1, true))
                    );
                    builder->CreateStore(result_plusplus_int, variable_plusplus_int);
                    builder->CreateRet(function_plusplus_int->getArg(0));
                },
                plusplus_int,
                "operator++",
                new filc::ast::LambdaType({ptr_int}, ptr_int)
        )
        DEFINE_FUNCTION(
                "operator--(int*) -> int*",
                { llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                {
                    auto *variable_minusminus_int = builder->CreateLoad(
                            function_minusminus_int->getArg(0)->getType(),
                            function_minusminus_int);
                    auto *result_minusminus_int = builder->CreateSub(
                            variable_minusminus_int,
                            llvm::ConstantInt::get(*context, llvm::APInt(64, 1, true))
                    );
                    builder->CreateStore(result_minusminus_int, variable_minusminus_int);
                    builder->CreateRet(function_minusminus_int->getArg(0));
                },
                minusminus_int,
                "operator--",
                new filc::ast::LambdaType({ptr_int}, ptr_int)
        )
        DEFINE_FUNCTION(
                "operator+(int) -> int",
                { llvm::Type::getInt64Ty(*context) },
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateAdd(
                            llvm::ConstantInt::get(*context, llvm::APInt::getZero(64)),
                            function_plus_int->getArg(0)
                    ));
                },
                plus_int,
                "operator+",
                new filc::ast::LambdaType({int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator-(int) -> int",
                { llvm::Type::getInt64Ty(*context) },
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateSub(
                            llvm::ConstantInt::get(*context, llvm::APInt::getZero(64)),
                            function_minus_int->getArg(0)
                    ));
                },
                minus_int,
                "operator-",
                new filc::ast::LambdaType({int_type}, int_type)
        )
        //endregion

        //region double
        DEFINE_FUNCTION(
                "operator++(double*) -> double*",
                { llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                {
                    auto *variable_plusplus_double = builder->CreateLoad(
                            function_plusplus_double->getArg(0)->getType(),
                            function_plusplus_double);
                    auto *result_plusplus_double = builder->CreateFAdd(
                            variable_plusplus_double,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0))
                    );
                    builder->CreateStore(result_plusplus_double, variable_plusplus_double);
                    builder->CreateRet(function_plusplus_double->getArg(0));
                },
                plusplus_double,
                "operator++",
                new filc::ast::LambdaType({ptr_double}, ptr_double)
        )
        DEFINE_FUNCTION(
                "operator--(double*) -> double*",
                { llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                {
                    auto *variable_minusminus_double = builder->CreateLoad(
                            function_minusminus_double->getArg(0)->getType(),
                            function_minusminus_double);
                    auto *result_minusminus_double = builder->CreateFSub(
                            variable_minusminus_double,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0))
                    );
                    builder->CreateStore(result_minusminus_double, variable_minusminus_double);
                    builder->CreateRet(function_minusminus_double->getArg(0));
                },
                minusminus_double,
                "operator--",
                new filc::ast::LambdaType({ptr_double}, ptr_double)
        )
        DEFINE_FUNCTION(
                "operator+(double) -> double",
                { llvm::Type::getDoubleTy(*context) },
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFAdd(
                            llvm::ConstantFP::get(*context, llvm::APFloat(0.0)),
                            function_plus_double->getArg(0)
                    ));
                },
                plus_double,
                "operator+",
                new filc::ast::LambdaType({double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator-(double) -> double",
                { llvm::Type::getDoubleTy(*context) },
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFSub(
                            llvm::ConstantFP::get(*context, llvm::APFloat(0.0)),
                            function_minus_double->getArg(0)
                    ));
                },
                minus_double,
                "operator-",
                new filc::ast::LambdaType({double_type}, double_type)
        )
        //endregion

        //region float
        DEFINE_FUNCTION(
                "operator++(float*) -> float*",
                { llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                {
                    auto *variable_plusplus_float = builder->CreateLoad(
                            function_plusplus_float->getArg(0)->getType(),
                            function_plusplus_float);
                    auto *result_plusplus_float = builder->CreateFAdd(
                            variable_plusplus_float,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0F))
                    );
                    builder->CreateStore(result_plusplus_float, variable_plusplus_float);
                    builder->CreateRet(function_plusplus_float->getArg(0));
                },
                plusplus_float,
                "operator++",
                new filc::ast::LambdaType({ptr_float}, ptr_float)
        )
        DEFINE_FUNCTION(
                "operator--(float*) -> float*",
                { llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                {
                    auto *variable_minusminus_float = builder->CreateLoad(
                            function_minusminus_float->getArg(0)->getType(),
                            function_minusminus_float);
                    auto *result_minusminus_float = builder->CreateFSub(
                            variable_minusminus_float,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0F))
                    );
                    builder->CreateStore(result_minusminus_float, variable_minusminus_float);
                    builder->CreateRet(function_minusminus_float->getArg(0));
                },
                minusminus_float,
                "operator--",
                new filc::ast::LambdaType({ptr_float}, ptr_float)
        )
        DEFINE_FUNCTION(
                "operator+(float) -> float",
                { llvm::Type::getFloatTy(*context) },
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFAdd(
                            llvm::ConstantFP::get(*context, llvm::APFloat(0.0F)),
                            function_plus_float->getArg(0)
                    ));
                },
                plus_float,
                "operator+",
                new filc::ast::LambdaType({float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator-(float) -> float",
                { llvm::Type::getFloatTy(*context) },
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFSub(
                            llvm::ConstantFP::get(*context, llvm::APFloat(0.0F)),
                            function_minus_float->getArg(0)
                    ));
                },
                minus_float,
                "operator-",
                new filc::ast::LambdaType({float_type}, float_type)
        )
        //endregion

        //region char
        DEFINE_FUNCTION(
                "operator++(char*) -> char*",
                { llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                {
                    auto *variable_plusplus_char = builder->CreateLoad(
                            function_plusplus_char->getArg(0)->getType(),
                            function_plusplus_char);
                    auto *result_plusplus_char = builder->CreateAdd(
                            variable_plusplus_char,
                            llvm::ConstantInt::get(*context, llvm::APInt(8, 1, false))
                    );
                    builder->CreateStore(result_plusplus_char, variable_plusplus_char);
                    builder->CreateRet(function_plusplus_char->getArg(0));
                },
                plusplus_char,
                "operator++",
                new filc::ast::LambdaType({ptr_char}, ptr_char)
        )
        DEFINE_FUNCTION(
                "operator--(char*) -> char*",
                { llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)) },
                llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                {
                    auto *variable_minusminus_char = builder->CreateLoad(
                            function_minusminus_char->getArg(0)->getType(),
                            function_minusminus_char);
                    auto *result_minusminus_char = builder->CreateSub(
                            variable_minusminus_char,
                            llvm::ConstantInt::get(*context, llvm::APInt(8, 1, false))
                    );
                    builder->CreateStore(result_minusminus_char, variable_minusminus_char);
                    builder->CreateRet(function_minusminus_char->getArg(0));
                },
                minusminus_char,
                "operator--",
                new filc::ast::LambdaType({ptr_char}, ptr_char)
        )
        //endregion

        //region bool
        DEFINE_FUNCTION(
                "operator!(bool) -> bool",
                { llvm::Type::getInt1Ty(*context) },
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateSub(
                            llvm::ConstantInt::get(*context, llvm::APInt(1, 1, false)),
                            function_not_bool->getArg(0)
                    ));
                },
                not_bool,
                "operator!",
                new filc::ast::LambdaType({bool_type}, bool_type)
        )
        //endregion
    }

    auto Environment::generatePostFixUnary(std::shared_ptr<filc::message::MessageCollector> collector,
                                           llvm::LLVMContext *context,
                                           llvm::Module *module,
                                           llvm::IRBuilder<> *builder) const -> void {
        auto int_type = getType("int");
        auto double_type = getType("double");
        auto float_type = getType("float");
        auto char_type = getType("char");
        auto bool_type = getType("bool");
        auto ptr_int = std::make_shared<filc::ast::PointerType>(int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(char_type);

        //region int
        DEFINE_FUNCTION(
                "operator++(int*) -> int",
                { llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)) },
                llvm::Type::getInt64Ty(*context),
                {
                    auto *variable_plusplus_int = builder->CreateLoad(
                            function_plusplus_int->getArg(0)->getType(),
                            function_plusplus_int
                    );
                    auto *result_plusplus_int = builder->CreateAdd(
                            variable_plusplus_int,
                            llvm::ConstantInt::get(*context, llvm::APInt(64, 1, true))
                    );
                    builder->CreateStore(result_plusplus_int, variable_plusplus_int);
                    builder->CreateRet(variable_plusplus_int);
                },
                plusplus_int,
                "operator++",
                new filc::ast::LambdaType({ptr_int}, int_type)
        )
        DEFINE_FUNCTION(
                "operator--(int*) -> int",
                { llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)) },
                llvm::Type::getInt64Ty(*context),
                {
                    auto *variable_minusminus_int = builder->CreateLoad(
                            function_minusminus_int->getArg(0)->getType(),
                            function_minusminus_int
                    );
                    auto *result_minusminus_int = builder->CreateSub(
                            variable_minusminus_int,
                            llvm::ConstantInt::get(*context, llvm::APInt(64, 1, true))
                    );
                    builder->CreateStore(result_minusminus_int, variable_minusminus_int);
                    builder->CreateRet(variable_minusminus_int);
                },
                minusminus_int,
                "operator--",
                new filc::ast::LambdaType({ptr_int}, int_type)
        )
        //endregion

        //region double
        DEFINE_FUNCTION(
                "operator++(double*) -> double",
                { llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)) },
                llvm::Type::getDoubleTy(*context),
                {
                    auto *variable_plusplus_double = builder->CreateLoad(
                            function_plusplus_double->getArg(0)->getType(),
                            function_plusplus_double
                    );
                    auto *result_plusplus_double = builder->CreateFAdd(
                            variable_plusplus_double,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0))
                    );
                    builder->CreateStore(result_plusplus_double, variable_plusplus_double);
                    builder->CreateRet(variable_plusplus_double);
                },
                plusplus_double,
                "operator++",
                new filc::ast::LambdaType({ptr_double}, double_type)
        )
        DEFINE_FUNCTION(
                "operator--(double*) -> double",
                { llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)) },
                llvm::Type::getDoubleTy(*context),
                {
                    auto *variable_minusminus_double = builder->CreateLoad(
                            function_minusminus_double->getArg(0)->getType(),
                            function_minusminus_double
                    );
                    auto *result_minusminus_double = builder->CreateFSub(
                            variable_minusminus_double,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0))
                    );
                    builder->CreateStore(result_minusminus_double, variable_minusminus_double);
                    builder->CreateRet(variable_minusminus_double);
                },
                minusminus_double,
                "operator--",
                new filc::ast::LambdaType({ptr_double}, double_type)
        )
        //endregion

        //region float
        DEFINE_FUNCTION(
                "operator++(float*) -> float",
                { llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)) },
                llvm::Type::getFloatTy(*context),
                {
                    auto *variable_plusplus_float = builder->CreateLoad(
                            function_plusplus_float->getArg(0)->getType(),
                            function_plusplus_float
                    );
                    auto *result_plusplus_float = builder->CreateFAdd(
                            variable_plusplus_float,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0F))
                    );
                    builder->CreateStore(result_plusplus_float, variable_plusplus_float);
                    builder->CreateRet(variable_plusplus_float);
                },
                plusplus_float,
                "operator++",
                new filc::ast::LambdaType({ptr_float}, float_type)
        )
        DEFINE_FUNCTION(
                "operator--(float*) -> float",
                { llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)) },
                llvm::Type::getFloatTy(*context),
                {
                    auto *variable_minusminus_float = builder->CreateLoad(
                            function_minusminus_float->getArg(0)->getType(),
                            function_minusminus_float
                    );
                    auto *result_minusminus_float = builder->CreateFSub(
                            variable_minusminus_float,
                            llvm::ConstantFP::get(*context, llvm::APFloat(1.0F))
                    );
                    builder->CreateStore(result_minusminus_float, variable_minusminus_float);
                    builder->CreateRet(variable_minusminus_float);
                },
                minusminus_float,
                "operator--",
                new filc::ast::LambdaType({ptr_float}, float_type)
        )
        //endregion

        //region char
        DEFINE_FUNCTION(
                "operator++(char*) -> char",
                { llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)) },
                llvm::Type::getInt8Ty(*context),
                {
                    auto *variable_plusplus_char = builder->CreateLoad(
                            function_plusplus_char->getArg(0)->getType(),
                            function_plusplus_char
                    );
                    auto *result_plusplus_char = builder->CreateAdd(
                            variable_plusplus_char,
                            llvm::ConstantInt::get(*context, llvm::APInt(8, 1, true))
                    );
                    builder->CreateStore(result_plusplus_char, variable_plusplus_char);
                    builder->CreateRet(variable_plusplus_char);
                },
                plusplus_char,
                "operator++",
                new filc::ast::LambdaType({ptr_char}, char_type)
        )
        DEFINE_FUNCTION(
                "operator--(char*) -> char",
                { llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)) },
                llvm::Type::getInt8Ty(*context),
                {
                    auto *variable_minusminus_char = builder->CreateLoad(
                            function_minusminus_char->getArg(0)->getType(),
                            function_minusminus_char
                    );
                    auto *result_minusminus_char = builder->CreateSub(
                            variable_minusminus_char,
                            llvm::ConstantInt::get(*context, llvm::APInt(8, 1, true))
                    );
                    builder->CreateStore(result_minusminus_char, variable_minusminus_char);
                    builder->CreateRet(variable_minusminus_char);
                },
                minusminus_char,
                "operator--",
                new filc::ast::LambdaType({ptr_char}, char_type)
        )
        //endregion
    }

    auto Environment::generateBinary(std::shared_ptr<filc::message::MessageCollector> collector,
                                     llvm::LLVMContext *context,
                                     llvm::Module *module,
                                     llvm::IRBuilder<> *builder) const -> void {
        auto int_type = getType("int");
        auto double_type = getType("double");
        auto float_type = getType("float");
        auto char_type = getType("char");
        auto bool_type = getType("bool");
        auto ptr_int = std::make_shared<filc::ast::PointerType>(int_type);
        auto ptr_double = std::make_shared<filc::ast::PointerType>(double_type);
        auto ptr_float = std::make_shared<filc::ast::PointerType>(float_type);
        auto ptr_char = std::make_shared<filc::ast::PointerType>(char_type);

        //region int operators
        DEFINE_FUNCTION(
                "operator*(int, int) -> int",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateMul(
                            function_times_int->getArg(0),
                            function_times_int->getArg(1)
                    ));
                },
                times_int,
                "operator*",
                new filc::ast::LambdaType({int_type, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator/(int, int) -> int",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateSDiv(
                            function_div_int->getArg(0),
                            function_div_int->getArg(1)
                    ));
                },
                div_int,
                "operator/",
                new filc::ast::LambdaType({int_type, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator%(int, int) -> int",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateSRem(
                            function_mod_int->getArg(0),
                            function_mod_int->getArg(1)
                    ));
                },
                mod_int,
                "operator%",
                new filc::ast::LambdaType({int_type, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator+(int, int) -> int",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateAdd(
                            function_plus_int->getArg(0),
                            function_plus_int->getArg(1)
                    ));
                },
                plus_int,
                "operator+",
                new filc::ast::LambdaType({int_type, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator-(int, int) -> int",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    builder->CreateRet(builder->CreateSub(
                            function_sub_int->getArg(0),
                            function_sub_int->getArg(1)
                    ));
                },
                sub_int,
                "operator-",
                new filc::ast::LambdaType({int_type, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator<(int, int) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpSLT(
                            function_lt_int->getArg(0),
                            function_lt_int->getArg(1)
                    ));
                },
                lt_int,
                "operator<",
                new filc::ast::LambdaType({int_type, int_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>(int, int) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpSGT(
                            function_gt_int->getArg(0),
                            function_gt_int->getArg(1)
                    ));
                },
                gt_int,
                "operator>",
                new filc::ast::LambdaType({int_type, int_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator==(int, int) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpEQ(
                            function_eqeq_int->getArg(0),
                            function_eqeq_int->getArg(1)
                    ));
                },
                eqeq_int,
                "operator==",
                new filc::ast::LambdaType({int_type, int_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator<=(int, int) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpSLE(
                            function_leq_int->getArg(0),
                            function_leq_int->getArg(1)
                    ));
                },
                leq_int,
                "operator<=",
                new filc::ast::LambdaType({int_type, int_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>=(int, int) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpSGE(
                            function_geq_int->getArg(0),
                            function_geq_int->getArg(1)
                    ));
                },
                geq_int,
                "operator>=",
                new filc::ast::LambdaType({int_type, int_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator!=(int, int) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt64Ty(*context), llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpNE(
                            function_ne_int->getArg(0),
                            function_ne_int->getArg(1)
                    ));
                },
                ne_int,
                "operator!=",
                new filc::ast::LambdaType({int_type, int_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator*=(int*, int) -> int",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                                           llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    auto *result = builder->CreateMul(
                            function_times_eq_int->getArg(0),
                            function_times_eq_int->getArg(1)
                    );
                    builder->CreateStore(result, function_times_eq_int->getArg(0));
                    builder->CreateRet(result);
                },
                times_eq_int,
                "operator*=",
                new filc::ast::LambdaType({ptr_int, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator/=(int*, int) -> int",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                                           llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    auto *result = builder->CreateSDiv(
                            function_div_eq_int->getArg(0),
                            function_div_eq_int->getArg(1)
                    );
                    builder->CreateStore(result, function_div_eq_int->getArg(0));
                    builder->CreateRet(result);
                },
                div_eq_int,
                "operator/=",
                new filc::ast::LambdaType({ptr_int, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator%=(int*, int) -> int",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                                           llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    auto *result = builder->CreateSRem(
                            function_mod_eq_int->getArg(0),
                            function_mod_eq_int->getArg(1)
                    );
                    builder->CreateStore(result, function_mod_eq_int->getArg(0));
                    builder->CreateRet(result);
                },
                mod_eq_int,
                "operator%=",
                new filc::ast::LambdaType({ptr_int, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator+=(int*, int) -> int",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                                           llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    auto *result = builder->CreateAdd(
                            function_add_eq_int->getArg(0),
                            function_add_eq_int->getArg(1)
                    );
                    builder->CreateStore(result, function_add_eq_int->getArg(0));
                    builder->CreateRet(result);
                },
                add_eq_int,
                "operator+=",
                new filc::ast::LambdaType({ptr_int, int_type}, int_type)
        )
        DEFINE_FUNCTION(
                "operator-=(int*, int) -> int",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt64Ty(*context)),
                                           llvm::Type::getInt64Ty(*context)}),
                llvm::Type::getInt64Ty(*context),
                {
                    auto *result = builder->CreateSub(
                            function_sub_eq_int->getArg(0),
                            function_sub_eq_int->getArg(1)
                    );
                    builder->CreateStore(result, function_sub_eq_int->getArg(0));
                    builder->CreateRet(result);
                },
                sub_eq_int,
                "operator-=",
                new filc::ast::LambdaType({ptr_int, int_type}, int_type)
        )
        //endregion

        //region double operators
        DEFINE_FUNCTION(
                "operator*(double, double) -> double",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFMul(
                            function_times_double->getArg(0),
                            function_times_double->getArg(1)
                    ));
                },
                times_double,
                "operator*",
                new filc::ast::LambdaType({double_type, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator/(double, double) -> double",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFDiv(
                            function_div_double->getArg(0),
                            function_div_double->getArg(1)
                    ));
                },
                div_double,
                "operator/",
                new filc::ast::LambdaType({double_type, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator%(double, double) -> double",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFRem(
                            function_mod_double->getArg(0),
                            function_mod_double->getArg(1)
                    ));
                },
                mod_double,
                "operator%",
                new filc::ast::LambdaType({double_type, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator+(double, double) -> double",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFAdd(
                            function_plus_double->getArg(0),
                            function_plus_double->getArg(1)
                    ));
                },
                plus_double,
                "operator+",
                new filc::ast::LambdaType({double_type, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator-(double, double) -> double",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    builder->CreateRet(builder->CreateFSub(
                            function_sub_double->getArg(0),
                            function_sub_double->getArg(1)
                    ));
                },
                sub_double,
                "operator-",
                new filc::ast::LambdaType({double_type, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator<(double, double) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOLT(
                            function_lt_double->getArg(0),
                            function_lt_double->getArg(1)
                    ));
                },
                lt_double,
                "operator<",
                new filc::ast::LambdaType({double_type, double_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>(double, double) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOGT(
                            function_gt_double->getArg(0),
                            function_gt_double->getArg(1)
                    ));
                },
                gt_double,
                "operator>",
                new filc::ast::LambdaType({double_type, double_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator==(double, double) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOEQ(
                            function_eqeq_double->getArg(0),
                            function_eqeq_double->getArg(1)
                    ));
                },
                eqeq_double,
                "operator==",
                new filc::ast::LambdaType({double_type, double_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator<=(double, double) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOLE(
                            function_leq_double->getArg(0),
                            function_leq_double->getArg(1)
                    ));
                },
                leq_double,
                "operator<=",
                new filc::ast::LambdaType({double_type, double_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>=(double, double) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOGE(
                            function_geq_double->getArg(0),
                            function_geq_double->getArg(1)
                    ));
                },
                geq_double,
                "operator>=",
                new filc::ast::LambdaType({double_type, double_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator!=(double, double) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getDoubleTy(*context), llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpONE(
                            function_ne_double->getArg(0),
                            function_ne_double->getArg(1)
                    ));
                },
                ne_double,
                "operator!=",
                new filc::ast::LambdaType({double_type, double_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator*=(double*, double) -> double",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                                           llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    auto *result = builder->CreateFMul(
                            function_times_eq_double->getArg(0),
                            function_times_eq_double->getArg(1)
                    );
                    builder->CreateStore(result, function_times_eq_double->getArg(0));
                    builder->CreateRet(result);
                },
                times_eq_double,
                "operator*=",
                new filc::ast::LambdaType({ptr_double, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator/=(double*, double) -> double",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                                           llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    auto *result = builder->CreateFDiv(
                            function_div_eq_double->getArg(0),
                            function_div_eq_double->getArg(1)
                    );
                    builder->CreateStore(result, function_div_eq_double->getArg(0));
                    builder->CreateRet(result);
                },
                div_eq_double,
                "operator/=",
                new filc::ast::LambdaType({ptr_double, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator%=(double*, double) -> double",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                                           llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    auto *result = builder->CreateFRem(
                            function_mod_eq_double->getArg(0),
                            function_mod_eq_double->getArg(1)
                    );
                    builder->CreateStore(result, function_mod_eq_double->getArg(0));
                    builder->CreateRet(result);
                },
                mod_eq_double,
                "operator%=",
                new filc::ast::LambdaType({ptr_double, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator+=(double*, double) -> double",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                                           llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    auto *result = builder->CreateFAdd(
                            function_add_eq_double->getArg(0),
                            function_add_eq_double->getArg(1)
                    );
                    builder->CreateStore(result, function_add_eq_double->getArg(0));
                    builder->CreateRet(result);
                },
                add_eq_double,
                "operator+=",
                new filc::ast::LambdaType({ptr_double, double_type}, double_type)
        )
        DEFINE_FUNCTION(
                "operator-=(double*, double) -> double",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getDoubleTy(*context)),
                                           llvm::Type::getDoubleTy(*context)}),
                llvm::Type::getDoubleTy(*context),
                {
                    auto *result = builder->CreateFSub(
                            function_sub_eq_double->getArg(0),
                            function_sub_eq_double->getArg(1)
                    );
                    builder->CreateStore(result, function_sub_eq_double->getArg(0));
                    builder->CreateRet(result);
                },
                sub_eq_double,
                "operator-=",
                new filc::ast::LambdaType({ptr_double, double_type}, double_type)
        )
        //endregion

        //region float operators
        DEFINE_FUNCTION(
                "operator*(float, float) -> float",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFMul(
                            function_times_float->getArg(0),
                            function_times_float->getArg(1)
                    ));
                },
                times_float,
                "operator*",
                new filc::ast::LambdaType({float_type, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator/(float, float) -> float",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFDiv(
                            function_div_float->getArg(0),
                            function_div_float->getArg(1)
                    ));
                },
                div_float,
                "operator/",
                new filc::ast::LambdaType({float_type, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator%(float, float) -> float",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFRem(
                            function_mod_float->getArg(0),
                            function_mod_float->getArg(1)
                    ));
                },
                mod_float,
                "operator%",
                new filc::ast::LambdaType({float_type, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator+(float, float) -> float",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFAdd(
                            function_plus_float->getArg(0),
                            function_plus_float->getArg(1)
                    ));
                },
                plus_float,
                "operator+",
                new filc::ast::LambdaType({float_type, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator-(float, float) -> float",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    builder->CreateRet(builder->CreateFSub(
                            function_sub_float->getArg(0),
                            function_sub_float->getArg(1)
                    ));
                },
                sub_float,
                "operator-",
                new filc::ast::LambdaType({float_type, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator<(float, float) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOLT(
                            function_lt_float->getArg(0),
                            function_lt_float->getArg(1)
                    ));
                },
                lt_float,
                "operator<",
                new filc::ast::LambdaType({float_type, float_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>(float, float) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOGT(
                            function_gt_float->getArg(0),
                            function_gt_float->getArg(1)
                    ));
                },
                gt_float,
                "operator>",
                new filc::ast::LambdaType({float_type, float_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator==(float, float) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOEQ(
                            function_eqeq_float->getArg(0),
                            function_eqeq_float->getArg(1)
                    ));
                },
                eqeq_float,
                "operator==",
                new filc::ast::LambdaType({float_type, float_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator<=(float, float) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOLE(
                            function_leq_float->getArg(0),
                            function_leq_float->getArg(1)
                    ));
                },
                leq_float,
                "operator<=",
                new filc::ast::LambdaType({float_type, float_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>=(float, float) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpOGE(
                            function_geq_float->getArg(0),
                            function_geq_float->getArg(1)
                    ));
                },
                geq_float,
                "operator>=",
                new filc::ast::LambdaType({float_type, float_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator!=(float, float) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getFloatTy(*context), llvm::Type::getFloatTy(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateFCmpONE(
                            function_ne_float->getArg(0),
                            function_ne_float->getArg(1)
                    ));
                },
                ne_float,
                "operator!=",
                new filc::ast::LambdaType({float_type, float_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator*=(float*, float) -> float",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                                           llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    auto *result = builder->CreateFMul(
                            function_times_eq_float->getArg(0),
                            function_times_eq_float->getArg(1)
                    );
                    builder->CreateStore(result, function_times_eq_float->getArg(0));
                    builder->CreateRet(result);
                },
                times_eq_float,
                "operator*=",
                new filc::ast::LambdaType({ptr_float, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator/=(float*, float) -> float",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                                           llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    auto *result = builder->CreateFDiv(
                            function_div_eq_float->getArg(0),
                            function_div_eq_float->getArg(1)
                    );
                    builder->CreateStore(result, function_div_eq_float->getArg(0));
                    builder->CreateRet(result);
                },
                div_eq_float,
                "operator/=",
                new filc::ast::LambdaType({ptr_float, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator%=(float*, float) -> float",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                                           llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    auto *result = builder->CreateFRem(
                            function_mod_eq_float->getArg(0),
                            function_mod_eq_float->getArg(1)
                    );
                    builder->CreateStore(result, function_mod_eq_float->getArg(0));
                    builder->CreateRet(result);
                },
                mod_eq_float,
                "operator%=",
                new filc::ast::LambdaType({ptr_float, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator+=(float*, float) -> float",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                                           llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    auto *result = builder->CreateFAdd(
                            function_add_eq_float->getArg(0),
                            function_add_eq_float->getArg(1)
                    );
                    builder->CreateStore(result, function_add_eq_float->getArg(0));
                    builder->CreateRet(result);
                },
                add_eq_float,
                "operator+=",
                new filc::ast::LambdaType({ptr_float, float_type}, float_type)
        )
        DEFINE_FUNCTION(
                "operator-=(float*, float) -> float",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getFloatTy(*context)),
                                           llvm::Type::getFloatTy(*context)}),
                llvm::Type::getFloatTy(*context),
                {
                    auto *result = builder->CreateFSub(
                            function_sub_eq_float->getArg(0),
                            function_sub_eq_float->getArg(1)
                    );
                    builder->CreateStore(result, function_sub_eq_float->getArg(0));
                    builder->CreateRet(result);
                },
                sub_eq_float,
                "operator-=",
                new filc::ast::LambdaType({ptr_float, float_type}, float_type)
        )
        //endregion

        //region char operators
        DEFINE_FUNCTION(
                "operator*(char, char) -> char",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    builder->CreateRet(builder->CreateMul(
                            function_times_char->getArg(0),
                            function_times_char->getArg(1)
                    ));
                },
                times_char,
                "operator*",
                new filc::ast::LambdaType({char_type, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator/(char, char) -> char",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    builder->CreateRet(builder->CreateSDiv(
                            function_div_char->getArg(0),
                            function_div_char->getArg(1)
                    ));
                },
                div_char,
                "operator/",
                new filc::ast::LambdaType({char_type, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator%(char, char) -> char",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    builder->CreateRet(builder->CreateSRem(
                            function_mod_char->getArg(0),
                            function_mod_char->getArg(1)
                    ));
                },
                mod_char,
                "operator%",
                new filc::ast::LambdaType({char_type, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator+(char, char) -> char",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    builder->CreateRet(builder->CreateAdd(
                            function_plus_char->getArg(0),
                            function_plus_char->getArg(1)
                    ));
                },
                plus_char,
                "operator+",
                new filc::ast::LambdaType({char_type, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator-(char, char) -> char",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    builder->CreateRet(builder->CreateSub(
                            function_sub_char->getArg(0),
                            function_sub_char->getArg(1)
                    ));
                },
                sub_char,
                "operator-",
                new filc::ast::LambdaType({char_type, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator<(char, char) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpULT(
                            function_lt_char->getArg(0),
                            function_lt_char->getArg(1)
                    ));
                },
                lt_char,
                "operator<",
                new filc::ast::LambdaType({char_type, char_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>(char, char) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpUGT(
                            function_gt_char->getArg(0),
                            function_gt_char->getArg(1)
                    ));
                },
                gt_char,
                "operator>",
                new filc::ast::LambdaType({char_type, char_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator==(char, char) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpEQ(
                            function_eqeq_char->getArg(0),
                            function_eqeq_char->getArg(1)
                    ));
                },
                eqeq_char,
                "operator==",
                new filc::ast::LambdaType({char_type, char_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator<=(char, char) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpULE(
                            function_leq_char->getArg(0),
                            function_leq_char->getArg(1)
                    ));
                },
                leq_char,
                "operator<=",
                new filc::ast::LambdaType({char_type, char_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator>=(char, char) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpUGE(
                            function_geq_char->getArg(0),
                            function_geq_char->getArg(1)
                    ));
                },
                geq_char,
                "operator>=",
                new filc::ast::LambdaType({char_type, char_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator!=(char, char) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt8Ty(*context), llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpNE(
                            function_ne_char->getArg(0),
                            function_ne_char->getArg(1)
                    ));
                },
                ne_char,
                "operator!=",
                new filc::ast::LambdaType({char_type, char_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator*=(char*, char) -> char",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                                           llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    auto *result = builder->CreateMul(
                            function_times_eq_char->getArg(0),
                            function_times_eq_char->getArg(1)
                    );
                    builder->CreateStore(result, function_times_eq_char->getArg(0));
                    builder->CreateRet(result);
                },
                times_eq_char,
                "operator*=",
                new filc::ast::LambdaType({ptr_char, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator/=(char*, char) -> char",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                                           llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    auto *result = builder->CreateSDiv(
                            function_div_eq_char->getArg(0),
                            function_div_eq_char->getArg(1)
                    );
                    builder->CreateStore(result, function_div_eq_char->getArg(0));
                    builder->CreateRet(result);
                },
                div_eq_char,
                "operator/=",
                new filc::ast::LambdaType({ptr_char, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator%=(char*, char) -> char",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                                           llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    auto *result = builder->CreateSRem(
                            function_mod_eq_char->getArg(0),
                            function_mod_eq_char->getArg(1)
                    );
                    builder->CreateStore(result, function_mod_eq_char->getArg(0));
                    builder->CreateRet(result);
                },
                mod_eq_char,
                "operator%=",
                new filc::ast::LambdaType({ptr_char, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator+=(char*, char) -> char",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                                           llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    auto *result = builder->CreateAdd(
                            function_add_eq_char->getArg(0),
                            function_add_eq_char->getArg(1)
                    );
                    builder->CreateStore(result, function_add_eq_char->getArg(0));
                    builder->CreateRet(result);
                },
                add_eq_char,
                "operator+=",
                new filc::ast::LambdaType({ptr_char, char_type}, char_type)
        )
        DEFINE_FUNCTION(
                "operator-=(char*, char) -> char",
                std::vector<llvm::Type *>({llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                                           llvm::Type::getInt8Ty(*context)}),
                llvm::Type::getInt8Ty(*context),
                {
                    auto *result = builder->CreateSub(
                            function_sub_eq_char->getArg(0),
                            function_sub_eq_char->getArg(1)
                    );
                    builder->CreateStore(result, function_sub_eq_char->getArg(0));
                    builder->CreateRet(result);
                },
                sub_eq_char,
                "operator-=",
                new filc::ast::LambdaType({ptr_char, char_type}, char_type)
        )
        //endregion

        //region bool operators
        DEFINE_FUNCTION(
                "operator==(bool, bool) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpEQ(
                            function_eqeq_bool->getArg(0),
                            function_eqeq_bool->getArg(1)
                    ));
                },
                eqeq_bool,
                "operator==",
                new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator!=(bool, bool) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateICmpNE(
                            function_ne_bool->getArg(0),
                            function_ne_bool->getArg(1)
                    ));
                },
                ne_bool,
                "operator!=",
                new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator&&(bool, bool) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateAnd(
                            function_and_bool->getArg(0),
                            function_and_bool->getArg(1)
                    ));
                },
                and_bool,
                "operator&&",
                new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
        )
        DEFINE_FUNCTION(
                "operator||(bool, bool) -> bool",
                std::vector<llvm::Type *>({llvm::Type::getInt1Ty(*context), llvm::Type::getInt1Ty(*context)}),
                llvm::Type::getInt1Ty(*context),
                {
                    builder->CreateRet(builder->CreateOr(
                            function_or_bool->getArg(0),
                            function_or_bool->getArg(1)
                    ));
                },
                or_bool,
                "operator||",
                new filc::ast::LambdaType({bool_type, bool_type}, bool_type)
        )
        //endregion
    }
}
