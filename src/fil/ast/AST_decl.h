/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
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
