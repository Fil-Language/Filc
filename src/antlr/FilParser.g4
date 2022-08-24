parser grammar FilParser;

options {
	tokenVocab = FilLexer;
}

program: module import_* expr*;

module: MODULE MODULE_NAME;

import_: IMPORT MODULE_NAME;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

expr:
	function
	| lambda
	| interface
	| class_
	| enum_
	| condition
	| loop
	| exception
	| unary_calcul
    | expr binary_operator expr
	| expr assignation
	| expr DOT expr
	| expr ARROW expr
	| cast
	| IDENTIFIER
	| function_call
	| litteral
	| variable_decl
	| expr_parenthesis
	| expr_block;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function: FUN IDENTIFIER fun_params (COLON type)? fun_body;

fun_params: LPAREN fun_param_list? RPAREN;

fun_param_list: fun_param (COMMA fun_param)*;

fun_param: IDENTIFIER COLON type;

fun_body: assignation | expr_parenthesis | expr_block;

function_decl: FUN IDENTIFIER fun_params (COLON type)?;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

lambda: fun_params ARROW (expr_block | expr_parenthesis);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

interface: INTERFACE IDENTIFIER class_params? interface_body?;

interface_body: LBRACE function_decl* RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

class_:
	class_modifier CLASS IDENTIFIER class_params? class_extends? class_body?;

class_modifier: ABSTRACT | OPEN;

class_params: LPAREN class_param_list? RPAREN;

class_param_list: class_param (COMMA class_param)*;

class_param:
	variable_decl
	| IDENTIFIER COLON type (EQ litteral)?;

class_extends: COLON class_extend_list;

class_extend_list: class_extend (COMMA class_extend)*;

class_extend: IDENTIFIER function_call_params;

class_body:
	LBRACE class_constructor (class_variable | class_function)* RBRACE;

class_function: ABSTRACT? class_atr_modifier function;

class_variable: class_atr_modifier variable_decl;

class_atr_modifier: PRIVATE | PUBLIC | INTERNAL | PROTECTED;

class_constructor: CONSTRUCTOR expr_block;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

enum_: ENUM IDENTIFIER enum_body?;

enum_body: LBRACE (IDENTIFIER (COMMA IDENTIFIER)*)? RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

condition: if_ | switch_;

if_: IF if_condition if_body else_if* else_?;

if_condition: expr_parenthesis;

if_body: expr | expr_block | expr_parenthesis;

else_if: ELSE IF if_condition if_body;

else_: ELSE if_body;

switch_: SWITCH switch_condition switch_body;

switch_condition: expr_parenthesis;

switch_body: LBRACE switch_case* RBRACE;

switch_case: (litteral | DEFAULT) ARROW (
		expr
		| expr_block
		| expr_parenthesis
	);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

loop: fori | foriter | while_;

fori: FOR fori_condition (expr | expr_block);

fori_condition:
	LPAREN variable_decl? SEMICOLON expr? SEMICOLON expr? RPAREN;

foriter: FOR foriter_condition (expr | expr_block);

foriter_condition:
	LPAREN (VAL | VAR) IDENTIFIER COLON IDENTIFIER RPAREN;

while_: WHILE if_condition if_body;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

exception:
	TRY (expr | expr_block | expr_parenthesis) catch_body+;

catch_body:
	CATCH LPAREN fun_param RPAREN (
		expr
		| expr_block
		| expr_parenthesis
	);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

binary_operator:
	PLUS
	| MINUS
	| DIVIDE
	| TIMES
	| MOD
	| FLEFT
	| FRIGHT
	| AND
	| OR
	| LE
	| GE
	| EQEQ
	| LEQ
	| GEQ
	| NEQ
	| BAND
	| BOR
	| BXOR;

unary_calcul: unary_operator expr;

unary_operator:
	PLUS
	| MINUS
	| DIVIDE
	| TIMES
	| MOD
	| NOT
	| BAND
	| BXOR
	| BOR
	| (LBRAK INT RBRAK);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

assignation: assignation_operator expr;

assignation_operator: unary_operator? EQ;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cast: LPAREN type RPAREN expr;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function_call: IDENTIFIER function_call_params;

function_call_params: LPAREN function_call_param_list? RPAREN;

function_call_param_list: expr (COMMA expr)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

variable_decl: (VAL | VAR) IDENTIFIER ((COLON type) | ((COLON type)? assignation));

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

type: IDENTIFIER (TIMES | (LBRAK INT? RBRAK))?;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

litteral: INT | FLOAT | STRING | CHAR | TRUE | FALSE | NULL;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

temp: DOT; // TODO: remove this

expr_parenthesis: LPAREN expr RPAREN;
expr_block: LBRAK expr* RBRAK;