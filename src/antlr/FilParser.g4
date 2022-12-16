parser grammar FilParser;

options {
	tokenVocab = FilLexer;
}

@parser::header {
#include "AST.hpp"
#include "FilCompiler.h"

#include <string>
#include <vector>
}

@parser::postinclude {
using namespace ast;
using namespace std;
}

@parser::members {
Program* parseTree() {
    return prog()->tree;
}
}

prog returns[Program *tree]
@init {
    auto imports = vector<Program *>();
    auto exprs = vector<AbstractExpr *>();
}
@after {
    $tree = new Program($m.text, imports, exprs);
}
    : m=module (i=import_ {
        imports.push_back($i.tree);
    })* (exported=EXPORT? e=expr {
        auto e = $e.tree;
        e->isExported($exported ? true : false);
        exprs.push_back(e);
    })* EOF;

module returns[string text]
    : MODULE m=MODULE_NAME {
        $text = $m.text;
    };

import_ returns[Program *tree]
    : IMPORT m=MODULE_NAME {
        $tree = FilCompiler::import($m.text);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

expr returns[AbstractExpr *tree]
    : e1=literal {
        $tree = $e1.tree;
    }
    | variable_declaration
    | assignation
    | IDENTIFIER
    | calcul
    | function
    | lambda
    | control
    | function_call
    | cast
    | parenthesis_body
    // Rule for binary calcul, need to be here to avoid left-recursion errors
    // Long but needed, the higher the most priority, the lower the less priority
    // The groups are for operators with same priority
    // TODO : find a way to move this part in another rule without the left-recursion error
    | expr STAR expr
    | expr DIV expr
    | expr MOD expr

    | expr PLUS expr
    | expr MINUS expr

    | expr FLEFT expr
    | expr FRIGHT expr

    | expr AND expr
    | expr OR expr
    | expr LESS expr
    | expr GREATER expr
    | expr EQEQ expr
    | expr LEQ expr
    | expr GEQ expr
    | expr NEQ expr
    ;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

literal returns[AbstractLiteral *tree]
    : l1=boolean {
        $tree = $l1.tree;
    }
    | l2=number {
        $tree = $l2.tree;
    }
    | CHARACTER
    | STRING
    | FSTRING
    ;

boolean returns[BooleanLiteral *tree]
    : TRUE {
        $tree = new BooleanLiteral(true);
    }
    | FALSE {
        $tree = new BooleanLiteral(false);
    };

number returns[AbstractLiteral *tree]
    : i=INTEGER {
        $tree = new IntegerLiteral(stoi($i.text));
    }
    | FLOAT;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

variable_declaration : (VAL | VAR) IDENTIFIER ((COLON type) | (COLON type)? assignation);

assignation : EQ expr;

type: IDENTIFIER (LBRACK INTEGER RBRACK
                 | STAR)*
    | lambda_type;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

calcul : unary_calcul;

unary_calcul : IDENTIFIER post_operator
             | pre_operator IDENTIFIER;

post_operator : PLUSPLUS | MINUSMINUS | (LBRACK expr RBRACK);

pre_operator : PLUSPLUS | MINUSMINUS | REF | STAR | NOT;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function : function_declaration function_body;

function_declaration : FUN IDENTIFIER LPAREN function_params? RPAREN function_type?;

function_params : IDENTIFIER COLON type (COMMA function_params)*;

function_type : COLON type;

function_body : assignation
              | parenthesis_body
              | block_body;

parenthesis_body : LPAREN expr RPAREN;

block_body : LBRACE expr* RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

lambda : LPAREN function_params? RPAREN function_type? ARROW (expr | parenthesis_body | block_body);

lambda_type: LPAREN (type (COMMA type)*)? RPAREN ARROW type;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

control : condition | loop;

condition : if_ | switch_;

if_ : IF if_condition if_body (ELSE (if_ | if_body))?;

if_condition : LPAREN expr RPAREN;

if_body : expr | block_body;

switch_ : SWITCH if_condition switch_body;

switch_body : LBRACE switch_case RBRACE;

switch_case : switch_pattern ARROW (expr | parenthesis_body | block_body);

switch_pattern : DEFAULT | literal;

loop : for_i | for_iter | while_;

for_i : FOR for_i_condition if_body;

for_i_condition : LPAREN variable_declaration? SEMI expr? SEMI expr? RPAREN;

for_iter : FOR for_iter_condition if_body;

for_iter_condition : LPAREN (VAL | VAR) IDENTIFIER COLON IDENTIFIER RPAREN;

while_ : WHILE if_condition if_body;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function_call : IDENTIFIER LPAREN function_call_params? RPAREN;
function_call_params : expr (COMMA expr)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cast : LPAREN type RPAREN expr;
