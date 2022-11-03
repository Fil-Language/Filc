lexer grammar FilLexer;

@lexer::header {
#include "utils.h"
}

// Keywords
EXPORT: 'export';
FUN: 'fun';
INTERFACE: 'interface';
CLASS: 'class';
ABSTRACT: 'abstract';
OVERRIDE: 'override';
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
NEW: 'new';
OPERATOR: 'operator';
RETURN: 'return';

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
LT: '<';
GT: '>';
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
FSTRING:
    'f"' (STRING_CHAR | '\\"' | '\\\\')* '"' {
        {
            auto text = getText();
            text = text.substr(1, text.size() - 2);
            setText(text);
        }
};
CHAR: '\'' ~('\'' | '\\' | '\n') '\'' {
    setText(std::to_string(getText()[1]));
};

// Comments
COMMENT: '//' (~('\n' | '\r'))* -> skip;
COMMENT_BLOCK: '/*' .*? '*/' -> skip;

// Ignoring chars
SEPARATOR: (' ' | '\t' | '\r' | '\n' | EOF) -> skip;

// Imports
fragment MODULE_NAME: IDENTIFIER ('.' IDENTIFIER)*;
MODULE: 'module' ' '+ MODULE_NAME {
    setText(ltrim(getText().erase(0, 7)));
};
IMPORT: 'import' ' '* MODULE_NAME {
    setText(ltrim(getText().erase(0, 7)));
};