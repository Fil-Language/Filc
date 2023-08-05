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
parser grammar FilParser;

options {
    tokenVocab = FilLexer;
}

@parser::header {
#include "AST.h"
#include "MessageCollector.h"
#include "Error.h"
#include <string>
#include <vector>
}

program returns[filc::ast::Program *tree]
@init {
    std::vector<std::string> imports;
    std::vector<filc::ast::AbstractExpression *> expressions;
}
@after {
    $tree = new filc::ast::Program($m.text, imports, expressions);
}
    : m=module (u=use {
        imports.push_back($u.text);
    })* (exp=EXPORT? e=expression {
        auto e = $e.tree;
        if (e != nullptr) {
            e->setExported($exp ? true : false);
            expressions.push_back(e);
        }
    })*;

module returns[std::string text]
@after {
    $text = $mi.text;
}
    : MODULE mi=module_identifier;

use returns[std::string text]
@after {
    $text = $mi.text;
}
    : USE mi=module_identifier;

module_identifier returns[std::string text]
    : i1=IDENTIFIER {
        $text = $i1.text;
    } (DOT ii=IDENTIFIER {
        $text += "." + $ii.text;
    })*;

expression returns[filc::ast::AbstractExpression *tree]
    : l=literal {
        $tree = $l.tree;
    }
    | v=variable_declaration {
        $tree = $v.tree;
    }
    | a=assignation {
        $tree = $a.tree;
    }
    | u=unary_calcul {
        $tree = $u.tree;
    }
    | expression binary_operator expression
    | function
    | lambda
    | control
    | parenthesis_body
    | i=IDENTIFIER {
        $tree = new filc::ast::Identifier($i);
    };

literal returns[filc::ast::AbstractExpression *tree]
    : b=boolean {
        $tree = $b.tree;
    }
    | n=number {
        $tree = $n.tree;
    }
    | c=CHARACTER {
        $tree = new filc::ast::CharacterLiteral(
            filc::ast::CharacterLiteral::stringToChar($c.text, $c)
        );
        $tree->setPosition(new filc::utils::Position($c));
    }
    | s=STRING {
        $tree = new filc::ast::StringLiteral($s.text);
        $tree->setPosition(new filc::utils::Position($s));
    };

boolean returns[filc::ast::BooleanLiteral *tree]
    : t=TRUE {
        $tree = new filc::ast::BooleanLiteral(true);
        $tree->setPosition(new filc::utils::Position($t));
    }
    | f=FALSE {
        $tree = new filc::ast::BooleanLiteral(false);
        $tree->setPosition(new filc::utils::Position($f));
    };

number returns[filc::ast::AbstractExpression *tree]
    : i=INTEGER {
        $tree = new filc::ast::IntegerLiteral(stoi($i.text));
        $tree->setPosition(new filc::utils::Position($i));
    }
    | f=FLOAT {
        $tree = new filc::ast::FloatLiteral(stod($f.text));
        $tree->setPosition(new filc::utils::Position($f));
    };

variable_declaration returns[filc::ast::VariableDeclaration *tree]
@init {
    bool is_constant = true;
    filc::ast::AbstractExpression *assign = nullptr;
}
@after {
    $tree = new filc::ast::VariableDeclaration(is_constant, new filc::ast::Identifier($i), $t.tree);
    $tree->setPosition(new filc::utils::Position($i));
    if (assign != nullptr) {
        $tree->setAssignation(assign);
    }
}
    : (VAL | VAR {
        is_constant = false;
    }) i=IDENTIFIER COLON t=type (a=assignation {
        assign = $a.tree;
    })?;

assignation returns[filc::ast::AbstractExpression *tree]
    : EQ e=expression {
        $tree = $e.tree;
    };

type returns[filc::ast::AbstractType *tree]
@init {
    filc::ast::AbstractType *previous = nullptr;
}
@after {
    $tree = previous;
}
    : i=IDENTIFIER {
        previous = new filc::ast::Type(new filc::ast::Identifier($i));
    } ((LBRACK it=INTEGER RBRACK {
        int size = stoi($it.text);
        if (size < 0) {
            filc::message::MessageCollector::getCollector()->addError(
                new filc::message::Error(
                    filc::message::ERROR,
                    "Array size must be positive",
                    new filc::utils::Position($it)
                )
            );
        }
        previous = new filc::ast::ArrayType(previous, size);
    }) | STAR {
        previous = new filc::ast::PointerType(previous);
    })*
    | l=lambda_type {
        previous = $l.tree;
    };

unary_calcul returns[filc::ast::UnaryCalcul *tree]
    : i=IDENTIFIER post_operator {
        $tree = new filc::ast::UnaryCalcul(new filc::ast::Identifier($i));
    }
    | pre_operator i=IDENTIFIER {
        $tree = new filc::ast::UnaryCalcul(new filc::ast::Identifier($i));
    };

post_operator returns[filc::ast::Operator *tree]
@init {
    std::vector<filc::ast::AbstractExpression *> params;
}
    : PLUSPLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUSMINUS);
    }
    | LBRACK e=expression RBRACK {
        $tree = new filc::ast::ArrayOperator($e.tree);
    }
    | LPAREN (fcp=function_call_params {
        params = $fcp.tree;
    })? RPAREN {
        $tree = new filc::ast::FunctionOperator(params);
    };

pre_operator returns[filc::ast::Operator *tree]
    : PLUSPLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUSMINUS);
    }
    | PLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS);
    }
    | MINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUS);
    }
    | REF {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::REF);
    }
    | STAR {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::STAR);
    }
    | NOT {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::NOT);
    };

binary_operator returns[filc::ast::Operator *tree]
    : STAR {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::STAR);
    }
    | DIV {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::DIV);
    }
    | MOD {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MOD);
    }

    | PLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS);
    }
    | MINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUS);
    }

    | FLEFT {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FLEFT);
    }
    | FRIGHT {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FRIGHT);
    }

    | LESS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LESS);
    }
    | GREATER {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::GREATER);
    }
    | EQEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::EQEQ);
    }
    | LEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LEQ);
    }
    | GEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::GEQ);
    }
    | NEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::NEQ);
    }

    | AND {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::AND);
    }
    | OR {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::OR);
    };

function
    : function_declaration function_body;

function_declaration
    : FUN function_identifier LPAREN function_params? RPAREN function_type;

function_identifier
    : OPERATOR function_operator
    | IDENTIFIER;

function_operator
    : (LBRACK RBRACK)
    | STAR
    | PLUSPLUS
    | MINUSMINUS
    | REF
    | NOT
    | AND
    | OR
    | LESS
    | GREATER
    | EQEQ
    | LEQ
    | GEQ
    | FLEFT
    | FRIGHT
    | PLUS
    | MINUS
    | DIV
    | MOD
    | (LPAREN RPAREN);

function_params
    : function_param (COMMA function_param)*;

function_param
    : IDENTIFIER COLON type;

function_type
    : COLON type;

function_body
    : assignation | parenthesis_body | block_body;

parenthesis_body
    : LPAREN expression RPAREN;

block_body
    : LBRACE expression* RBRACE;

lambda
    : LPAREN function_params? RPAREN function_type ARROW (expression | parenthesis_body | block_body);

lambda_type returns[filc::ast::LambdaType *tree]
@init {
    std::vector<filc::ast::AbstractType *> arguments;
}
@after {
    $tree = new filc::ast::LambdaType(arguments, $t.tree);
}
    : LPAREN (t1=type {
        arguments.push_back($t1.tree);
    } (COMMA ti=type {
        arguments.push_back($ti.tree);
    })*)? RPAREN ARROW t=type;

control
    : condition | loop;

condition
    : if_ | switch_;

if_
    : IF if_condition if_body (ELSE (if_ | if_body))?;

if_condition
    : LPAREN expression RPAREN;

if_body
    : expression | block_body;

switch_
    : SWITCH if_condition switch_body;

switch_body
    : LBRACE switch_case* RBRACE;

switch_case
    : switch_pattern ARROW (expression | parenthesis_body | block_body);

switch_pattern
    : DEFAULT | literal;

loop
    : for_i | for_iter | while_;

for_i
    : FOR for_i_condition if_body;

for_i_condition
    : LPAREN variable_declaration? SEMI expression? SEMI expression? RPAREN;

for_iter
    : FOR for_iter_condition if_body;

for_iter_condition
    : LPAREN (VAL | VAR) IDENTIFIER COLON expression RPAREN;

while_
    : WHILE if_condition if_body;

function_call_params returns[std::vector<filc::ast::AbstractExpression *> tree]
@init {
    $tree = std::vector<filc::ast::AbstractExpression *>();
}
    : e1=expression {
        $tree.push_back($e1.tree);
    } (COMMA ei=expression {
        $tree.push_back($ei.tree);
    })*;
