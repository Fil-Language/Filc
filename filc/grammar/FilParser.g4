/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */
parser grammar FilParser;

options {
	tokenVocab = FilLexer;

	language = CPP;
}

// TODO : Add abstractProgram();
@parser::declarations {

}

// TODO : Add abstractProgram() returns prog().tree;
@parser::definitions {

}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Begin of the program
prog
    : package import_* expr* EOF;

package
    : PACKAGE IDENTIFIER (DOT IDENTIFIER)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Import
import_
    : IMPORT import_what file_identifier;

import_what
    : /* Nothing */
    | IDENTIFIER import_as FROM;

import_as
    : /* Nothing */
    | AS IDENTIFIER;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Expressions
expr
    : decl_class
    | decl_interface
    | decl_var
    | decl_function
    | lambda
    | control
    | loop
    | function_call
    | expr DOT function_call
    | return_
    | new_
    | THIS
    | NULL_
    | SUPER
    | LPAREN expr RPAREN
    | expr SEMICOLON expr
    | expr assign_operator expr
    | expr binary_operator expr
    | unary_operator expr | expr unary_operator
    | value
    | IDENTIFIER;

list_expr
    : expr (COMMA expr)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Interfaces
decl_interface
    : EXPORT? INTERFACE IDENTIFIER LPAREN list_field? RPAREN (COLON list_identifier)? (LBRACE interface_body RBRACE)?;

interface_body
    : (decl_var | decl_method)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Classes
decl_class
    : EXPORT? (OPEN | ABSTRACT)? CLASS IDENTIFIER (LPAREN ((field | param) (COMMA (field | param))*)? RPAREN)? (COLON list_identifier)? (LBRACE class_body RBRACE)?;

class_body
    : (decl_var | decl_method | constructor)*;

constructor
    : CONSTRUCTOR LBRACE (expr)* RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Variables
decl_var
    : EXPORT? visibility (VAL | VAR) IDENTIFIER (COLON type)? (ASSIGN expr)? (COMMA IDENTIFIER (COLON type)? (ASSIGN expr)?)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Methods & functions & lambda
decl_method
    : visibility ABSTRACT? FUN IDENTIFIER LPAREN list_param? RPAREN (COLON type)? function_body?;

decl_function
    : EXPORT? FUN IDENTIFIER LPAREN list_param RPAREN (COLON type)? function_body;

function_body
    : ASSIGN expr
    | LPAREN expr RPAREN
    | LBRACE expr* RBRACE;

lambda
    : LPAREN list_identifier? RPAREN ARROW function_body;

lambda_type
    : LPAREN type_list? RPAREN ARROW type;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Assign

assign_operator
    : binary_operator? ASSIGN;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Control
control
    : if_
    | switch_
    | exception;

if_
    : IF LPAREN expr RPAREN control_body (ELIF LPAREN expr RPAREN control_body)* (ELSE control_body)?;

control_body
    : expr
    | LBRACE expr* RBRACE;

switch_
    : SWITCH LPAREN expr RPAREN LBRACE switch_body RBRACE;

switch_body
    : ((CASE expr | DEFAULT) ARROW control_body)*;

exception
    : TRY LBRACE expr* RBRACE (CATCH LPAREN IDENTIFIER IDENTIFIER RPAREN LBRACE expr* RBRACE)*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Loop
loop
    : for_ | while_;

for_
    : FOR for_condition control_body;

for_condition
    : (IDENTIFIER IN expr)
    | expr? SEMICOLON expr? SEMICOLON expr?;

while_
    : WHILE LPAREN expr RPAREN control_body;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Calcul
unary_operator
    : MINUS | NOT | MULT | BINAND | PLUSPLUS | MINUSMINUS
    | LBRACKET expr RBRACKET;

binary_operator
    : PLUS | MINUS | MULT | DIV | MOD | LTLT | GTGT | AND | OR | EQ | NEQ | LTE | GTE | LT | GT | BINAND | BINOR | BINXOR;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Others
function_call
    : IDENTIFIER LPAREN list_expr? RPAREN;

return_
    : RETURN expr;

new_
    : NEW IDENTIFIER ((LPAREN list_expr? RPAREN) | (LBRACKET expr RBRACKET));

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Utils
visibility
    : PUBLIC | PROTECTED | INTERNAL | PRIVATE;

list_field
    : field (COMMA field);

field
    : visibility (VAL | VAR) IDENTIFIER COLON (MULT | BINAND)? type (ASSIGN expr)?;

list_param
    : param (COMMA param)*;

param
    : IDENTIFIER COLON (MULT | BINAND)? type (ASSIGN expr)?;

list_identifier
    : IDENTIFIER (COMMA IDENTIFIER)*;

file_identifier
    : (IDENTIFIER (DOT IDENTIFIER)*)
    | STRING;

type
    : (IDENTIFIER | lambda_type | generic_type) (MULT | LBRACKET RBRACKET)*;

generic_type
    : INT_TYPE | FLOAT_TYPE | DOUBLE_TYPE | BOOLEAN_TYPE | CHAR_TYPE;

type_list
    : type (COMMA type);

value
    : INTEGER | FLOAT | TRUE | FALSE | CHARACTER | STRING | MULTILINE_STRING;