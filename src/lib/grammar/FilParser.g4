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
    | variable_declaration
    | assignation
    | unary_calcul
    | expression binary_operator expression
    | function
    | lambda
    | control
    | parenthesis_body
    | IDENTIFIER;

literal returns[filc::ast::AbstractExpression *tree]
    : b=boolean {
        $tree = $b.tree;
    }
    | n=number {
        $tree = $n.tree;
    }
    | CHARACTER
    | STRING;

boolean returns[filc::ast::BooleanLiteral *tree]
    : TRUE {
        $tree = new filc::ast::BooleanLiteral(true);
    }
    | FALSE {
        $tree = new filc::ast::BooleanLiteral(false);
    };

number returns[filc::ast::AbstractExpression *tree]
    : i=INTEGER {
        $tree = new filc::ast::IntegerLiteral(42);
    }
    | FLOAT;

variable_declaration
    : (VAL | VAR) IDENTIFIER COLON type assignation?;

assignation
    : EQ expression;

type
    : IDENTIFIER ((LBRACK INTEGER RBRACK) | STAR)*
    | lambda_type;

unary_calcul
    : IDENTIFIER post_operator
    | pre_operator IDENTIFIER;

post_operator
    : PLUSPLUS
    | MINUSMINUS
    | LBRACK expression RBRACK
    | LPAREN function_call_params RPAREN;

pre_operator
    : PLUSPLUS
    | MINUSMINUS
    | PLUS
    | MINUS
    | REF
    | STAR
    | NOT;

binary_operator
    : STAR
    | DIV
    | MOD

    | PLUS
    | MINUS

    | FLEFT
    | FRIGHT

    | LESS
    | GREATER
    | EQEQ
    | LEQ
    | GEQ
    | NEQ

    | AND
    | OR;

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

lambda_type
    : LPAREN (type (COMMA type)*)? RPAREN ARROW type;

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

function_call_params
    : expression (COMMA expression)*;
