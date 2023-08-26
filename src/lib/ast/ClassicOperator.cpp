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
#include "AST.h"

namespace filc::ast {
    ClassicOperator::ClassicOperator(filc::ast::ClassicOperator::OPERATOR p_operator)
            : _operator(p_operator) {}

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

    auto ClassicOperator::dumpPreLambdaType(filc::ast::AbstractType *return_type,
                                            filc::ast::AbstractType *called_on,
                                            filc::environment::Environment *environment,
                                            filc::message::MessageCollector *collector) const -> LambdaType * {
        return new LambdaType({}, return_type, called_on);
    }

    auto ClassicOperator::dumpPostLambdaType(filc::ast::AbstractType *return_type,
                                             filc::ast::AbstractType *called_on,
                                             filc::environment::Environment *environment,
                                             filc::message::MessageCollector *collector) const -> LambdaType * {
        if (!environment->hasType("void")) {
            environment->addType(new filc::ast::Type(new filc::ast::Identifier("void")));
        }

        return new LambdaType({environment->getType("void")}, return_type, called_on);
    }
}
