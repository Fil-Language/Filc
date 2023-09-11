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
#include "DevWarning.h"

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

    auto ClassicOperator::dumpPreLambdaType(AbstractType *type,
                                            filc::environment::Environment *environment,
                                            filc::message::MessageCollector *collector,
                                            filc::utils::Position *position) const -> LambdaType * {
        switch (_operator) {
            case PLUSPLUS:
            case MINUSMINUS:
                return new LambdaType({new PointerType(type)}, new PointerType(type));
            case PLUS:
            case MINUS:
            case REF:
            case STAR:
            case NOT:
                return new LambdaType({type}, type);
            case DIV:
            case MOD:
            case FLEFT:
            case FRIGHT:
            case LESS:
            case GREATER:
            case EQEQ:
            case LEQ:
            case GEQ:
            case NEQ:
            case AND:
            case OR:
                collector->addError(new filc::message::DevWarning(
                        3,
                        position,
                        "ClassicOperator::dumpPreLambdaType should not be called but has been called"
                ));
                return nullptr;
        }

        return nullptr;
    }

    auto ClassicOperator::dumpPostLambdaType(AbstractType *type,
                                             filc::environment::Environment *environment,
                                             filc::message::MessageCollector *collector,
                                             filc::utils::Position *position) const -> LambdaType * {
        switch (_operator) {
            case PLUSPLUS:
            case MINUSMINUS:
                return new LambdaType({type}, type);
            case PLUS:
            case MINUS:
            case REF:
            case STAR:
            case NOT:
            case DIV:
            case MOD:
            case FLEFT:
            case FRIGHT:
            case LESS:
            case GREATER:
            case EQEQ:
            case LEQ:
            case GEQ:
            case NEQ:
            case AND:
            case OR:
                collector->addError(new filc::message::DevWarning(
                        3,
                        position,
                        "ClassicOperator::dumpPostLambdaType should not be called but has been called"
                ));
                return nullptr;
        }

        return nullptr;
    }
}
