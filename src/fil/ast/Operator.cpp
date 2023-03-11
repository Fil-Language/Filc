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

Operator::Operator(Op op)
        : _op(op), _index(nullptr) {}

Operator::Operator(AbstractExpr *index)
        : _op(ARRAY), _index(index) {}

Operator::Operator(const vector<AbstractExpr *> &args)
        : _op(FUNCTION), _index(nullptr), _args(args) {}

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
            return "[]";
        case Operator::FUNCTION:
            return "()";
        default:
            return "";
    }
}

string Operator::decompile(int indent) const {
    if (_op == ARRAY) {
        return "[" + _index->decompile(indent) + "]";
    } else if (_op == FUNCTION) {
        string args;
        for (auto arg: _args) {
            args += arg->decompile(0) + ", ";
        }
        if (!_args.empty()) {
            args.resize(args.size() - 2);
        }
        return "(" + args + ")";
    } else {
        return to_string(_op);
    }
}

Operator::Op Operator::getOp() const {
    return _op;
}
