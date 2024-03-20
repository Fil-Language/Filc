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
#include "Operator.h"
#include <stdexcept>

using namespace filc::ast;

ClassicOperator::ClassicOperator(ClassicOperator::OPERATOR p_operator): _operator(p_operator) {}

ClassicOperator::ClassicOperator(const std::string &p_operator) {
    if (p_operator == "++") {
        _operator = PLUSPLUS;
    } else if (p_operator == "--") {
        _operator = MINUSMINUS;
    } else if (p_operator == "+") {
        _operator = PLUS;
    } else if (p_operator == "-") {
        _operator = MINUS;
    } else if (p_operator == "&") {
        _operator = REF;
    } else if (p_operator == "*") {
        _operator = STAR;
    } else if (p_operator == "!") {
        _operator = NOT;
    } else if (p_operator == "/") {
        _operator = DIV;
    } else if (p_operator == "%") {
        _operator = MOD;
    } else if (p_operator == "<<") {
        _operator = FLEFT;
    } else if (p_operator == ">>") {
        _operator = FRIGHT;
    } else if (p_operator == "<") {
        _operator = LESS;
    } else if (p_operator == ">") {
        _operator = GREATER;
    } else if (p_operator == "==") {
        _operator = EQEQ;
    } else if (p_operator == "<=") {
        _operator = LEQ;
    } else if (p_operator == ">=") {
        _operator = GEQ;
    } else if (p_operator == "!=") {
        _operator = NEQ;
    } else if (p_operator == "&&") {
        _operator = AND;
    } else if (p_operator == "||") {
        _operator = OR;
    } else {
        throw std::logic_error("Operator '" + p_operator + "' is invalid");
    }
}

auto ClassicOperator::getOperator() const -> OPERATOR {
    return _operator;
}

auto ClassicOperator::dump() const -> std::string {
    switch (_operator) {
    case PLUSPLUS:
        return "++";
    case MINUSMINUS:
        return "--";
    case PLUS:
        return "+";
    case MINUS:
        return "-";
    case REF:
        return "&";
    case STAR:
        return "*";
    case NOT:
        return "!";
    case DIV:
        return "/";
    case MOD:
        return "%";
    case FLEFT:
        return "<<";
    case FRIGHT:
        return ">>";
    case LESS:
        return "<";
    case GREATER:
        return ">";
    case EQEQ:
        return "==";
    case LEQ:
        return "<=";
    case GEQ:
        return ">=";
    case NEQ:
        return "!=";
    case AND:
        return "&&";
    case OR:
        return "||";
    }

    throw std::logic_error("Should not come here");
}

auto ClassicOperator::accept(Visitor *visitor) -> void {
    visitor->visitClassicOperator(this);
}
