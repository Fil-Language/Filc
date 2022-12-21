/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "AST.hpp"

using namespace std;
using namespace ast;

Operator::Operator(Op op)
        : _op(op), _index(nullptr) {}

Operator::Operator(AbstractExpr *index)
        : _op(ARRAY), _index(index) {}

Operator::~Operator() {
    delete _index;
}

string to_string(Operator::Op op) {
    switch (op) {
        case Operator::STAR:
            return "*";
        case Operator::PLUSPLUS:
            return "++";
        case Operator::MINUSMINUS:
            return "--";
        case Operator::REF:
            return "&";
        case Operator::NOT:
            return "!";
        case Operator::AND:
            return "&&";
        case Operator::OR:
            return "||";
        case Operator::LESS:
            return "<";
        case Operator::GREATER:
            return ">";
        case Operator::EQEQ:
            return "==";
        case Operator::LEQ:
            return "<=";
        case Operator::GEQ:
            return ">=";
        case Operator::NEQ:
            return "!=";
        case Operator::FLEFT:
            return "<<";
        case Operator::FRIGHT:
            return ">>";
        case Operator::PLUS:
            return "+";
        case Operator::MINUS:
            return "-";
        case Operator::DIV:
            return "/";
        case Operator::MOD:
            return "%";
        case Operator::ARRAY:
        default:
            return "";
    }
}

string Operator::decompile(int indent) const {
    if (_op == ARRAY) {
        return "[" + _index->decompile(indent) + "]";
    } else {
        return to_string(_op);
    }
}

Operator::Op Operator::getOp() const {
    return _op;
}
