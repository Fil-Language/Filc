lexer grammar FilLexer;


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

// Identifiers
fragment LETTER: 'a'..'z' | 'A'..'Z' | '_';
fragment DIGIT: '0'..'9';
fragment CHAR: LETTER | DIGIT;
IDENTIFIER: LETTER CHAR*;

// Special symbols
PLUS: '+';
MINUS: '-';
MUL: '*';
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
SIMPLEQUOTE: '\'';

// Literals
INTEGER: DIGIT+;
FLOAT: DIGIT+ '.' DIGIT* | '.' DIGIT+;
STRINGCHAR: ~('"' | '\\' | '\n');
STRING: QUOTE STRINGCHAR* QUOTE;
MULILINESTRING: (QUOTE QUOTE QUOTE) CHAR (QUOTE QUOTE QUOTE);
CHARACTER: SIMPLEQUOTE STRINGCHAR* SIMPLEQUOTE;

// Comments
COMMENT: '//' ~('\n') { skip(); };
MULTILINECOMMENT: '/*' .*? '*/' { skip(); };