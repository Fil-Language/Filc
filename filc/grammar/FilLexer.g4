/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */
lexer grammar FilLexer;

options {
    language = CPP;
}


// Reserved words
PACKAGE: 'package';
IMPORT: 'import';
AS: 'as';
FROM: 'from';
THIS: 'this';
NULL_: 'null';
SUPER: 'super';
EXPORT: 'export';
INTERFACE: 'interface';
OPEN: 'open';
ABSTRACT: 'abstract';
CLASS: 'class';
CONSTRUCTOR: 'constructor';
VAL: 'val';
VAR: 'var';
FUN: 'fun';
IF: 'if';
ELSE: 'else';
ELIF: 'elif';
SWITCH: 'switch';
CASE: 'case';
DEFAULT: 'default';
TRY: 'try';
CATCH: 'catch';
FOR: 'for';
WHILE: 'while';
RETURN: 'return';
NEW: 'new';
PUBLIC: 'public';
PROTECTED: 'protected';
INTERNAL: 'internal';
PRIVATE: 'private';
IS: 'is';
TRUE: 'true';
FALSE: 'false';
INT_TYPE: 'int';
FLOAT_TYPE: 'float';
DOUBLE_TYPE: 'double';
BOOLEAN_TYPE: 'boolean';
CHAR_TYPE: 'char';
IN: 'in';

// Identifiers
fragment LETTER: 'a'..'z' | 'A'..'Z' | '_';
fragment DIGIT: '0'..'9';
fragment CHAR: LETTER | DIGIT;
IDENTIFIER: LETTER CHAR*;

// Special symbols
PLUS: '+';
MINUS: '-';
MULT: '*';
DIV: '/';
MOD: '%';
PLUSPLUS: '++';
MINUSMINUS: '--';
LT: '<';
GT: '>';
LTE: '<=';
GTE: '>=';
EQ: '==';
NEQ: '!=';
AND: '&&';
OR: '||';
NOT: '!';
ASSIGN: '=';
BINAND: '&';
BINOR: '|';
BINXOR: '^';
LTLT: '<<';
GTGT: '>>';
DOT: '.';
COMMA: ',';
SEMICOLON: ';';
COLON: ':';
LPAREN: '(';
RPAREN: ')';
LBRACKET: '[';
RBRACKET: ']';
LBRACE: '{';
RBRACE: '}';
ARROW: '->';
QUOTE: '"';
SIMPLE_QUOTE: '\'';

// Separators
WS: (' ' | '\t' | '\r' | '\n')+ { skip(); };

// Literals
INTEGER: DIGIT+;
FLOAT: DIGIT+ '.' DIGIT* | '.' DIGIT+;
STRING_CHAR: ~('"' | '\\' | '\n');
STRING: QUOTE STRING_CHAR* QUOTE;
MULTILINE_STRING: (QUOTE QUOTE QUOTE) CHAR (QUOTE QUOTE QUOTE);
CHARACTER: SIMPLE_QUOTE STRING_CHAR* SIMPLE_QUOTE;

// Comments
COMMENT: '//' ~('\n') { skip(); };
MULTILINE_COMMENT: '/*' .*? '*/' { skip(); };