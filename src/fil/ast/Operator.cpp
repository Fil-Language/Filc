/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Operator::Operator() : _expr(nullptr) {}

Operator::Operator(Operator::OP op)
        : _op(op), _expr(nullptr) {}

Operator::Operator(Operator::OP op, AbstractExpr *expr)
        : _op(op), _expr(expr) {}

Operator::~Operator() {
    if (_expr != nullptr)
        delete _expr;
}

string Operator::decompile(int indent) const {
    switch (_op) {
        case PLUS :
            return "+";
        case MINUS :
            return "-";
        case DIVIDE :
            return "/";
        case TIMES :
            return "*";
        case MOD :
            return "%";
        case FLEFT :
            return "<<";
        case FRIGHT :
            return ">>";
        case AND :
            return "&&";
        case OR :
            return "||";
        case LT :
            return "<";
        case GT :
            return ">";
        case EQEQ :
            return "==";
        case LEQ :
            return "<=";
        case GEQ :
            return ">=";
        case NEQ :
            return "!=";
        case BAND :
            return "&";
        case BOR :
            return "|";
        case BXOR :
            return "^";
        case PLUSPLUS :
            return "++";
        case MINMIN :
            return "--";
        case NOT :
            return "!";
        case ARRAY :
            return "[" + _expr->decompile(indent) + "]";
    }
}

// ====================

OperatorIdentifier::OperatorIdentifier() : _op(nullptr) {}

OperatorIdentifier::OperatorIdentifier(const string &name, Operator *op)
        : _op(op) {
    _name = name;
}

OperatorIdentifier::~OperatorIdentifier() {
    delete _op;
}

string OperatorIdentifier::decompile(int indent) const {
    return _name + _op->decompile(indent);
}
