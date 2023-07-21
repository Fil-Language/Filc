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
}

program returns[filc::ast::Program *tree]
@after {
    $tree = new filc::ast::Program($m.text);
}
    : m=module use* (EXPORT? expr)*;

module returns[std::string text]
@after {
    $text = $im.text;
}
    : MODULE im=module_identifier;

use
    : USE module_identifier;

module_identifier returns[std::string text]
@init {
    std::string result;
}
@after {
    $text = result;
}
    : i1=IDENTIFIER {
        result = $i1.text;
    } (DOT ii=IDENTIFIER {
        result += "." + $ii.text;
    })*;

expr
    : literal
    | variable_declaration
    | assignation
    | unary_calcul
    | expr binary_operator expr
    | function
    | lambda
    | control
    | parenthesis_body
    | IDENTIFIER;

literal
    : boolean
    | number
    | CHARACTER
    | STRING;

boolean
    : TRUE | FALSE;

number
    : INTEGER | FALSE;

variable_declaration
    : (VAL | VAR) IDENTIFIER COLON type assignation?;

assignation
    : EQ expr;

type
    : IDENTIFIER ((LBRACK INTEGER RBRACK) | STAR)*
    | lambda_type;

unary_calcul
    : IDENTIFIER post_operator
    | pre_operator IDENTIFIER;

post_operator
    : PLUSPLUS
    | MINUSMINUS
    | LBRACK expr RBRACK
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
    : LPAREN expr RPAREN;

block_body
    : LBRACE expr* RBRACE;

lambda
    : LPAREN function_params? RPAREN function_type ARROW (expr | parenthesis_body | block_body);

lambda_type
    : LPAREN (type (COMMA type)*)? RPAREN ARROW type;

control
    : condition | loop;

condition
    : if_ | switch_;

if_
    : IF if_condition if_body (ELSE (if_ | if_body))?;

if_condition
    : LPAREN expr RPAREN;

if_body
    : expr | block_body;

switch_
    : SWITCH if_condition switch_body;

switch_body
    : LBRACE switch_case* RBRACE;

switch_case
    : switch_pattern ARROW (expr | parenthesis_body | block_body);

switch_pattern
    : DEFAULT | literal;

loop
    : for_i | for_iter | while_;

for_i
    : FOR for_i_condition if_body;

for_i_condition
    : LPAREN variable_declaration? SEMI expr? SEMI expr? RPAREN;

for_iter
    : FOR for_iter_condition if_body;

for_iter_condition
    : LPAREN (VAL | VAR) IDENTIFIER COLON expr RPAREN;

while_
    : WHILE if_condition if_body;

function_call_params
    : expr (COMMA expr)*;
