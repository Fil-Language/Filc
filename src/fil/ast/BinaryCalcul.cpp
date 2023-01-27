/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

BinaryCalcul::BinaryCalcul(AbstractExpr *left, Operator *op, AbstractExpr *right)
        : _left(left), _op(op), _right(right) {}

string BinaryCalcul::decompile(int indent) const {
    return _left->decompile(indent) + " " + _op->decompile(indent) + " " + _right->decompile(indent);
}

//void BinaryCalcul::resolveEnvironment(Environment *parent) {
//    _left->resolveEnvironment(parent);
//    _right->resolveEnvironment(parent);
//}
//
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

string BinaryCalcul::dump(int indent) const {
    string res = string(indent, '\t') + "[BinaryCalcul]" + (_isExported ? " <exported>" : "")
                 + " <operator:" + _op->decompile(0) + "> "
                 + "<type:" + _exprType->getName() + ">\n";

    res += _left->dump(indent + 1);
    res += _right->dump(indent + 1);

    return res;
}
