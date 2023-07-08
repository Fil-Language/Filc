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
#include "AST.hpp"

using namespace std;
using namespace ast;

BinaryCalcul::BinaryCalcul(AbstractExpr *left, Operator *p_operator, AbstractExpr *right)
    : _left(left), _op(p_operator), _right(right) {}

auto BinaryCalcul::decompile(int indent) const -> string {
    return _left->decompile(indent) + " " + _op->decompile(indent) + " " + _right->decompile(indent);
}

//AbstractType *BinaryCalcul::inferType(Environment *env) {
//    auto leftType = _left->inferType(env);
//    auto rightType = _right->inferType(env);
//
//    if (leftType && rightType && *leftType != *rightType) {
//        ErrorsRegister::addError(
//                "Type mismatch: " + leftType->getName() + " and " + rightType->getName(),
//                _pos
//        );
//    }
//
//    switch (_op->getOp()) {
//        case Operator::AND:
//        case Operator::OR:
//        case Operator::LESS:
//        case Operator::GREATER:
//        case Operator::EQEQ:
//        case Operator::LEQ:
//        case Operator::GEQ:
//        case Operator::NEQ:
//            _exprType = env->getSymbol("bool")->getSignature();
//            break;
//
//        case Operator::FLEFT:
//        case Operator::FRIGHT:
//            _exprType = leftType; // FIXME : temporary, need to implement fil.io in stl to have corresponding types
//            break;
//
//        case Operator::PLUS:
//        case Operator::MINUS:
//        case Operator::DIV:
//        case Operator::MOD:
//        case Operator::STAR:
//            _exprType = leftType;
//            break;
//
//        default:
//            _exprType = leftType;
//            break;
//    }
//
//    return _exprType;
//}

auto BinaryCalcul::dump(int indent) const -> string {
    string res = string(indent, '\t') + "[BinaryCalcul]" + (_is_exported ? " <exported>" : "") + " <operator:" + _op->decompile(0) + "> " + "<type:" + _expr_type->getName() + ">\n";

    res += _left->dump(indent + 1);
    res += _right->dump(indent + 1);

    return res;
}
