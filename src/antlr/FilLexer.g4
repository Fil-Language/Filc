lexer grammar FilLexer;

// Keywords
EXPORT: 'export';
MODULE: 'module';
FUN: 'fun';
INTERFACE: 'interface';
CLASS: 'class';
ABSTRACT: 'abstract';
OPEN: 'open';
PRIVATE: 'private';
PUBLIC: 'public';
INTERNAL: 'internal';
PROTECTED: 'protected';
CONSTRUCTOR: 'constructor';
ENUM: 'enum';
IF: 'if';
ELSE: 'else';
SWITCH: 'switch';
DEFAULT: 'default';
FOR: 'for';
VAL: 'val';
VAR: 'var';
WHILE: 'while';
TRY: 'try';
CATCH: 'catch';
TRUE: 'true';
FALSE: 'false';
NULL_: 'null';

// Identifier
fragment LETTER: ('a' .. 'z') | ('A' .. 'Z') | '_';
fragment DIGIT: '0' .. '9';
IDENTIFIER: LETTER (LETTER | DIGIT)*;

// Specials symbols
DOT: '.';
ARROW: '->';
LBRACE: '{';
RBRACE: '}';
LPAREN: '(';
RPAREN: ')';
LBRAK: '[';
RBRAK: ']';
COLON: ':';
COMMA: ',';
SEMICOLON: ';';
EQ: '=';
PLUS: '+';
MINUS: '-';
DIVIDE: '/';
TIMES: '*';
MOD: '%';
FLEFT: '<<';
FRIGHT: '>>';
AND: '&&';
OR: '||';
LE: '<';
GE: '>';
EQEQ: '==';
LEQ: '<=';
GEQ: '>=';
NEQ: '!=';
NOT: '!';
BAND: '&';
BOR: '|';
BXOR: '^';

// Integers
INT: DIGIT+;

// Floats
FLOAT: DIGIT* '.' DIGIT+;

// Strings
fragment STRING_CHAR: ~('"' | '\\' | '\n');
STRING:
	'"' (STRING_CHAR | '\\"' | '\\\\')* '"' {
        {
            auto text = getText();
            text = text.substr(1, text.size() - 2);
            setText(text);
        }
};
CHAR: '\'' ~('\'' | '\\' | '\n') '\'';

// Comments
COMMENT: '//' (~('\n' | '\r'))* -> skip;
COMMENT_BLOCK: '/*' .*? '*/' -> skip;

// Ignoring chars
SEPARATOR: (' ' | '\t' | '\r' | '\n' | EOF) -> skip;

// Imports
MODULE_NAME: IDENTIFIER ('.' IDENTIFIER)*;
IMPORT:
	'import' (' ')* MODULE_NAME {
    // TODO : implement the import of file and subfiles
};