/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_AST_HPP
#define FILC_AST_HPP

#include <string>
#include <vector>

#include "utils.h"

namespace ast {
    class AST {
    public:
        AST();

        ~AST();

        virtual std::string decompile(int indent) const = 0;
    };

    class AbstractExpr : public AST {
    public:
        std::string decompile(int indent) const override;

        void isExported(bool exported);

    protected:
        AbstractExpr();

    protected:
        bool _isExported;
    };

    class Type : public AST {
    public:
        explicit Type(const std::string &name); // IDENTIFIER

        Type(int arraySize, Type *subType); // IDENTIFIER '[' INTEGER ']'

        explicit Type(Type *subType); // IDENTIFIER '*'

        std::string decompile(int indent) const override;

    private:
        std::string _name;

        bool _isArray;
        int _arraySize;

        bool _isPointer;
        Type *_subType;
    };

    class Program : public AST {
    public:
        Program(const std::string &module,
                const std::vector<Program *> &imports,
                const std::vector<AbstractExpr *> &exprs);

        ~Program();

        std::string decompile(int indent) const override;

    private:
        std::string _module;
        std::vector<Program *> _imports;
        std::vector<AbstractExpr *> _exprs;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class AbstractLiteral : public AbstractExpr {
    };

    class BooleanLiteral : public AbstractLiteral {
    public:
        explicit BooleanLiteral(bool value);

        std::string decompile(int indent) const override;

    private:
        bool _value;
    };

    class IntegerLiteral : public AbstractLiteral {
    public:
        explicit IntegerLiteral(int value);

        std::string decompile(int indent) const override;

    private:
        int _value;
    };

    class FloatLiteral : public AbstractLiteral {
    public:
        explicit FloatLiteral(float value);

        std::string decompile(int indent) const override;

    private:
        float _value;
    };

    class CharLiteral : public AbstractLiteral {
    public:
        explicit CharLiteral(const std::string &value);

        std::string decompile(int indent) const override;

    private:
        char _value;
    };

    class StringLiteral : public AbstractLiteral {
    public:
        explicit StringLiteral(const std::string &value);

        std::string decompile(int indent) const override;

    protected:
        std::string _value;
    };

    class FStringLiteral : public StringLiteral {
    public:
        explicit FStringLiteral(const std::string &value);

        std::string decompile(int indent) const override;
    };

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

    class VariableDeclaration : public AbstractExpr {
    public:
        VariableDeclaration(bool isVal, const std::string &name, Type *type);

        std::string decompile(int indent) const override;

    private:
        bool _isVal;
        std::string _name;
        Type *_type;
    };
}

#endif //FILC_AST_HPP
