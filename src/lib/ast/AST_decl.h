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
#ifndef FILC_AST_DECL_H
#define FILC_AST_DECL_H

namespace filc::ast {
    class Program;

    class AbstractExpression;

    class Identifier;

    template<typename T> class AbstractLiteral;

    class BooleanLiteral;

    class IntegerLiteral;

    class FloatLiteral;

    class CharacterLiteral;

    class StringLiteral;

    class VariableDeclaration;

    class AbstractType;

    class Type;

    class ArrayType;

    class PointerType;

    class LambdaType;

    class UnaryCalcul;

    class PreUnaryCalcul;

    class PostUnaryCalcul;

    class BinaryCalcul;

    class Operator;

    class ClassicOperator;

    class ArrayOperator;

    class FunctionOperator;

    class AssignationOperator;

    class Lambda;

    class Function;

    class FunctionParameter;

    class If;

    class Match;

    class MatchCase;

    class ForI;

    class ForIter;

    class While;

    class BlockBody;
} // namespace filc::ast

auto operator==(const filc::ast::AbstractType &type1, const filc::ast::AbstractType &type2) -> bool;

auto operator!=(const filc::ast::AbstractType &type1, const filc::ast::AbstractType &type2) -> bool;

#endif // FILC_AST_DECL_H
