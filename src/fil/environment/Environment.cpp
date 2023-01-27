/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Environment.h"
#include "AST.hpp"

using namespace std;
using namespace ast;

Environment::Environment(Environment *parent)
        : _parent(parent) {
    _symbols = std::deque<Symbol *>();
}

Environment::~Environment() = default;

Environment *Environment::getGlobalEnvironment() {
    static auto *globalEnvironment = new Environment();
    static bool initialized = false;

    if (initialized)
        return globalEnvironment;
    initialized = true;

    // Add builtins types
    auto tInt = globalEnvironment->addSymbol("int", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new Type(new Identifier("int")));
    auto tFloat = globalEnvironment->addSymbol("float", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new Type(new Identifier("float")));
    auto tChar = globalEnvironment->addSymbol("char", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new Type(new Identifier("char")));
    auto tBool = globalEnvironment->addSymbol("bool", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new Type(new Identifier("bool")));
    globalEnvironment->addSymbol("void", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new Type(new Identifier("void")));

    // Add builtins operators
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tInt));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tChar));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tInt}, tFloat));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tInt));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tInt));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tChar}, tFloat));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tInt));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tChar));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tInt}, tFloat));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tInt));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tInt));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator-", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tChar}, tFloat));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tInt));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tChar));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tInt}, tFloat));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tInt));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tInt));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator*", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tChar}, tFloat));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tInt));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tChar));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tInt}, tFloat));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tInt));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tInt));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tFloat}, tFloat));
    globalEnvironment->addSymbol("operator/", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tChar}, tFloat));
    globalEnvironment->addSymbol("operator%", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tInt));
    globalEnvironment->addSymbol("operator%", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tInt}, tInt));
    globalEnvironment->addSymbol("operator%", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tInt));
    globalEnvironment->addSymbol("operator++", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt}, tInt));
    globalEnvironment->addSymbol("operator++", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat}, tFloat));
    globalEnvironment->addSymbol("operator++", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar}, tChar));
    globalEnvironment->addSymbol("operator--", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt}, tInt));
    globalEnvironment->addSymbol("operator--", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat}, tFloat));
    globalEnvironment->addSymbol("operator--", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar}, tChar));
    globalEnvironment->addSymbol("operator==", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tBool));
    globalEnvironment->addSymbol("operator==", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tBool));
    globalEnvironment->addSymbol("operator==", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tBool));
    globalEnvironment->addSymbol("operator==", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tBool, tBool}, tBool));
    globalEnvironment->addSymbol("operator==", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tBool));
    globalEnvironment->addSymbol("operator==", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tBool));
    globalEnvironment->addSymbol("operator!=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tBool));
    globalEnvironment->addSymbol("operator!=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tBool));
    globalEnvironment->addSymbol("operator!=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tBool));
    globalEnvironment->addSymbol("operator!=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tBool, tBool}, tBool));
    globalEnvironment->addSymbol("operator!=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tBool));
    globalEnvironment->addSymbol("operator!=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tBool));
    globalEnvironment->addSymbol("operator>", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tBool));
    globalEnvironment->addSymbol("operator>", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tBool));
    globalEnvironment->addSymbol("operator>", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tBool));
    globalEnvironment->addSymbol("operator>", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tBool));
    globalEnvironment->addSymbol("operator>", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tBool));
    globalEnvironment->addSymbol("operator>=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tBool));
    globalEnvironment->addSymbol("operator>=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tBool));
    globalEnvironment->addSymbol("operator>=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tBool));
    globalEnvironment->addSymbol("operator>=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tBool));
    globalEnvironment->addSymbol("operator>=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tBool));
    globalEnvironment->addSymbol("operator<", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tBool));
    globalEnvironment->addSymbol("operator<", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tBool));
    globalEnvironment->addSymbol("operator<", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tBool));
    globalEnvironment->addSymbol("operator<", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tBool));
    globalEnvironment->addSymbol("operator<", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tBool));
    globalEnvironment->addSymbol("operator<=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tInt}, tBool));
    globalEnvironment->addSymbol("operator<=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tFloat, tFloat}, tBool));
    globalEnvironment->addSymbol("operator<=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tChar}, tBool));
    globalEnvironment->addSymbol("operator<=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tChar, tInt}, tBool));
    globalEnvironment->addSymbol("operator<=", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tInt, tChar}, tBool));
    globalEnvironment->addSymbol("operator!", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tBool}, tBool));
    globalEnvironment->addSymbol("operator&&", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tBool, tBool}, tBool));
    globalEnvironment->addSymbol("operator||", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tBool, tBool}, tBool));

    // FIXME : temporary, to be removed later as string is part of stl
    auto tString = globalEnvironment->addSymbol("string", new Position(0, 0, "builtin"), Symbol::SymbolType::TYPE)
            ->setSignature(new Type(new Identifier("string")));
    globalEnvironment->addSymbol("operator+", new Position(0, 0, "builtin"), Symbol::SymbolType::FUNCTION)
            ->setSignature(new LambdaType({tString, tString}, tString));
    // FIXME : end of fixme

    return globalEnvironment;
}

Symbol *Environment::addSymbol(const std::string &name, Position *position, Symbol::SymbolType type) {
    auto *symbol = new Symbol(name, position, type);
    _symbols.push_back(symbol);

    return symbol;
}

bool Environment::hasSymbol(const std::string &name, ast::AbstractType *signature) {
    if (std::any_of(_symbols.begin(), _symbols.end(), [name, signature](Symbol *symbol) {
        if (signature == nullptr)
            return symbol->getName() == name;
        else
            return symbol->getName() == name && symbol->getSignature() == signature;
    })) {
        return true;
    }

    if (_parent != nullptr) {
        return _parent->hasSymbol(name, signature);
    }

    return false;
}

Symbol *Environment::getSymbol(const std::string &name, ast::AbstractType *signature) {
    auto it = std::find_if(_symbols.begin(), _symbols.end(), [name, signature](Symbol *symbol) {
        if (signature == nullptr)
            return symbol->getName() == name;
        else
            return symbol->getName() == name && symbol->getSignature() == signature;
    });

    if (it != _symbols.end()) {
        return *it;
    }

    if (_parent != nullptr) {
        return _parent->getSymbol(name, signature);
    }

    return nullptr;
}

void Environment::merge(Environment *environment) {
    exit(42); // TODO : implement
}
