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
Program parseTree() {
    return prog()->tree;
}
}

prog returns[Program tree]
@init {
    auto imports = vector<Program>();
    auto exprs_ = vector<AbstractExpr>();
}
@after {
    $tree = Program($m.text, imports, exprs_);
}
    : m=MODULE import_[&imports]* exprs[&exprs_]* EOF;

import_[vector<Program>* imports]
    : i=IMPORT {
        $imports->push_back(FilCompiler::import($i.text));
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

exprs[vector<AbstractExpr>* exprs_]
@init {
    bool exp = false;
}
    : (EXPORT {
        exp = true;
    })? e=expr {
        $e.tree.setExport(exp);
        $exprs_->push_back($e.tree);
    };

expr returns[AbstractExpr tree]
@init {
    $tree = AbstractExpr();
}
    : function // TODO
	| lambda // TODO
	| interface // TODO
	| class_ // TODO
	| enum_ // TODO
	| variable_decl // TODO
	| condition // TODO
	| loop // TODO
	| function_call // TODO
	| exception_ // TODO
	| expr DOT expr // TODO
	| expr ARROW expr // TODO
	| unary_op_pre expr // TODO
    | expr unary_op_post // TODO
    | expr binary_operator expr // TODO
	| expr assignation // TODO
	| cast // TODO
	| IDENTIFIER // TODO
	| class_identifier // TODO
	| litteral // TODO
	| NEW class_identifier function_call_params // TODO
	| (e31=expr_parenthesis {
	    $tree = $e31.tree;
	})
	| (e32=expr_block {
	    $tree = $e32.tree;
	})
	| array_assign; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function: FUN function_name fun_params (COLON type)? fun_body; // TODO

function_name: IDENTIFIER // TODO
             | OPERATOR binary_operator; // TODO

fun_params: LPAREN fun_param_list? RPAREN; // TODO

fun_param_list: fun_param (COMMA fun_param)*; // TODO

fun_param: IDENTIFIER COLON type; // TODO

fun_body: assignation | expr_parenthesis | expr_block; // TODO

function_decl: FUN function_name fun_params (COLON type)?; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

lambda: fun_params ARROW (expr_block | expr_parenthesis); // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

interface: INTERFACE IDENTIFIER class_params? interface_body?; // TODO

interface_body: LBRACE function_decl* RBRACE; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

class_:
	class_modifier? CLASS class_identifier class_params? class_extends? class_body?; // TODO

class_modifier:
    ABSTRACT // TODO
    | OPEN; // TODO

class_identifier: IDENTIFIER TIMES? class_generic?; // TODO

class_generic: LT IDENTIFIER (COMMA IDENTIFIER)* GT; // TODO

class_params: LPAREN class_param_list? RPAREN; // TODO

class_param_list: class_param (COMMA class_param)*; // TODO

class_param:
	variable_decl // TODO
	| IDENTIFIER COLON type (EQ litteral)?; // TODO

class_extends: COLON class_extend_list; // TODO

class_extend_list: class_extend (COMMA class_extend)*; // TODO

class_extend: class_identifier function_call_params?; // TODO

class_body:
	LBRACE class_constructor? (class_variable | class_function)* RBRACE; // TODO

class_function: (ABSTRACT | OVERRIDE)? class_atr_modifier? (function | function_decl); // TODO

class_variable: class_atr_modifier variable_decl; // TODO

class_atr_modifier:
    PRIVATE // TODO
    | PUBLIC // TODO
    | INTERNAL // TODO
    | PROTECTED; // TODO

class_constructor: CONSTRUCTOR expr_block; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

enum_: ENUM IDENTIFIER enum_body?; // TODO

enum_body: LBRACE (IDENTIFIER (COMMA IDENTIFIER)*)? RBRACE; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

condition: if_ | switch_; // TODO

if_: IF if_condition if_body else_if* else_?; // TODO

if_condition: expr_parenthesis; // TODO

if_body: expr_block | expr_parenthesis | expr; // TODO

else_if: ELSE IF if_condition if_body; // TODO

else_: ELSE if_body; // TODO

switch_: SWITCH switch_condition switch_body; // TODO

switch_condition: expr_parenthesis; // TODO

switch_body: LBRACE switch_case* RBRACE; // TODO

switch_case: (litteral | DEFAULT) ARROW ( // TODO
		expr // TODO
		| expr_block // TODO
		| expr_parenthesis // TODO
	);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

loop: fori | foriter | while_; // TODO

fori: FOR fori_condition (expr | expr_block); // TODO

fori_condition:
	LPAREN variable_decl? SEMICOLON expr? SEMICOLON expr? RPAREN; // TODO

foriter: FOR foriter_condition (expr | expr_block); // TODO

foriter_condition:
	LPAREN (VAL | VAR) IDENTIFIER COLON IDENTIFIER RPAREN; // TODO

while_: WHILE if_condition if_body; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

exception_:
	TRY (expr | expr_block | expr_parenthesis) catch_body+; // TODO

catch_body: // TODO
	CATCH LPAREN fun_param RPAREN (
		expr // TODO
		| expr_block // TODO
		| expr_parenthesis // TODO
	);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

binary_operator:
	PLUS // TODO
	| MINUS // TODO
	| DIVIDE // TODO
	| TIMES // TODO
	| MOD // TODO
	| FLEFT // TODO
	| FRIGHT // TODO
	| AND // TODO
	| OR // TODO
	| LT // TODO
	| GT // TODO
	| EQEQ // TODO
	| LEQ // TODO
	| GEQ // TODO
	| NEQ // TODO
	| BAND // TODO
	| BOR // TODO
	| BXOR; // TODO

unary_op_pre:
	PLUS PLUS // TODO
	| MINUS MINUS // TODO
	| TIMES // TODO
	| NOT // TODO
	| BAND; // TODO

unary_op_post:
    PLUS PLUS // TODO
    | MINUS MINUS // TODO
    | (LBRAK expr RBRAK); // TODO

unary_operator:
    PLUS // TODO
	| MINUS // TODO
	| DIVIDE // TODO
	| TIMES // TODO
	| MOD // TODO
	| NOT // TODO
	| BAND // TODO
	| BOR // TODO
	| BXOR; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

assignation: assignation_operator expr; // TODO

assignation_operator: unary_operator? EQ; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cast: LPAREN type RPAREN expr; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function_call: function_name function_call_params; // TODO

function_call_params: LPAREN function_call_param_list? RPAREN; // TODO

function_call_param_list: expr (COMMA expr)*; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

variable_decl: (VAL | VAR) IDENTIFIER (((COLON type)? assignation) | (COLON type)); // TODO

array_assign: LBRACE expr (COMMA expr)* RBRACE; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

type: IDENTIFIER (TIMES | (LBRAK INT? RBRAK))?; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

litteral:
    INT // TODO
    | FLOAT // TODO
    | STRING // TODO
    | FSTRING // TODO
    | CHAR // TODO
    | TRUE // TODO
    | FALSE // TODO
    | NULL_; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

expr_parenthesis returns[ExprParenthesis tree]
@init {
    auto exprs_ = vector<AbstractExpr>();
}
@after {
    $tree = ExprParenthesis(exprs_);
}
    : LPAREN exprs[&exprs_] RPAREN;

expr_block returns[ExprBlock tree]
@init {
    auto exprs_ = vector<AbstractExpr>();
}
@after {
    $tree = ExprBlock(exprs_);
}
    : LBRACE exprs[&exprs_] RBRACE;
