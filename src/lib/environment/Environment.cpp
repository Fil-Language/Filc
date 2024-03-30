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
#include "Type.h"
#include "llvm/IR/Verifier.h"
#include <algorithm>
#include <memory>

using namespace filc::environment;

Environment::Environment(const std::string &module, const std::shared_ptr<Environment> &parent)
    : _module(module), _parent(parent) {
    if (parent.get() == this) {
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

auto Environment::getParent() const -> std::shared_ptr<Environment> {
    return _parent;
}

auto Environment::hasName(const std::string &name, const std::shared_ptr<ast::AbstractType> &type) const -> bool {
    return std::any_of(
               _names.begin(),
               _names.end(),
               [name, type](auto *item) -> bool {
                   return item->getName() == name && (type == nullptr || *item->getType() == *type);
               }
           )
        || (_parent != nullptr && _parent->hasName(name, nullptr));
}

auto Environment::hasName(const std::string &name, ast::AbstractType *type) const -> bool {
    return hasName(name, std::shared_ptr<filc::ast::AbstractType>(type));
}

auto Environment::addName(const std::string &name, const std::shared_ptr<ast::AbstractType> &type) -> bool {
    if (hasName(name, type)) {
        return false;
    }

    _names.push_back(new Name(name, type));

    return true;
}

auto Environment::addName(const std::string &name, ast::AbstractType *type) -> bool {
    return addName(name, std::shared_ptr<filc::ast::AbstractType>(type));
}

auto Environment::getName(const std::string &name, const std::shared_ptr<ast::AbstractType> &type) const -> Name * {
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

auto Environment::getName(const std::string &name, ast::AbstractType *type) const -> Name * {
    return getName(name, std::shared_ptr<filc::ast::AbstractType>(type));
}

auto Environment::hasType(const std::string &type) const -> bool {
    return std::any_of(
               _types.begin(),
               _types.end(),
               [type](const auto &item) -> bool {
                   return item->dump() == type;
               }
           )
        || (_parent != nullptr && _parent->hasType(type));
}

auto Environment::addType(const std::shared_ptr<ast::AbstractType> &type) -> bool {
    if (hasType(type->dump())) {
        return false;
    }

    _types.push_back(type);

    return true;
}

auto Environment::getType(const std::string &type) const -> std::shared_ptr<ast::AbstractType> {
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

auto Environment::getGlobalEnvironment() -> std::shared_ptr<Environment> {
    static std::shared_ptr<Environment> global = nullptr;
    if (global != nullptr) {
        return global;
    }

    global = std::make_shared<Environment>("__global__");

    auto basic_types = addBasicTypes(global);
    addConstants(global, basic_types);
    addAssignations(global, basic_types);
    addPrefixUnary(global, basic_types);
    addPostfixUnary(global, basic_types);
    addBinary(global, basic_types);

    return global;
}

auto Environment::generateIR(
    const std::shared_ptr<filc::message::MessageCollector> &collector,
    llvm::LLVMContext *context,
    llvm::Module *module,
    llvm::IRBuilder<> *builder
) const -> void {
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
