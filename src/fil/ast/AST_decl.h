/**
 * MIT License
 *
 * Copyright (c) 2022-Present Kevin Traini
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

/**
 * Pre-declaration of all AST classes
 */
namespace ast {
    class AST;

    class AbstractExpr;

    class Program;

    class Identifier;

    class AbstractType;

    class Type;

    class LambdaType;

    class BlockBody;

    class ParenthesisBody;

    class AbstractLiteral;

    class BooleanLiteral;

    class IntegerLiteral;

    class FloatLiteral;

    class CharLiteral;

    class StringLiteral;

    class Assignation;

    class VariableDeclaration;

    class Operator;

    class UnaryCalcul;

    class BinaryCalcul;

    class FunctionParam;

    class FunctionDeclaration;

    class Function;

    class Lambda;

    class If;

    class SwitchPattern;

    class SwitchCase;

    class Switch;

    class ForICondition;

    class ForI;

    class ForIterCondition;

    class ForIter;

    class While;

    class FunctionCall;
}

#endif //FILC_AST_DECL_H
