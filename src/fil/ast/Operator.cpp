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

Operator::Operator(Op p_operator)
    : _operator(p_operator), _index(nullptr) {}

Operator::Operator(AbstractExpr *index)
    : _operator(ARRAY), _index(index) {}

Operator::Operator(const vector<AbstractExpr *> &args)
    : _operator(FUNCTION), _index(nullptr), _args(args) {}

auto toString(Operator::Op p_operator) -> string {
    switch (p_operator) {
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

auto Operator::decompile(int indent) const -> string {
    if (_operator == ARRAY) {
        return "[" + _index->decompile(indent) + "]";
    }
    if (_operator == FUNCTION) {
        string args;
        for (auto *arg: _args) {
            args += arg->decompile(0) + ", ";
        }
        if (!_args.empty()) {
            args.resize(args.size() - 2);
        }
        return "(" + args + ")";
    }
    return toString(_operator);
}

auto Operator::getOp() const -> Operator::Op {
    return _operator;
}
