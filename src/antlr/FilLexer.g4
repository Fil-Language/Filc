lexer grammar FilLexer;

@lexer::header {
#include "utils.h"
}

// Keywords
EXPORT: 'export';
MODULE: 'module';
IMPORT: 'import';
TRUE: 'true';
FALSE: 'false';
VAL: 'val';
VAR: 'var';
FUN: 'fun';
IF: 'if';
ELSE: 'else';
SWITCH: 'switch';
DEFAULT: 'default';
FOR: 'for';
WHILE: 'while';

// Operators
EQ: '=';
COLON: ':';
LBRACK: '[';
RBRACK: ']';
STAR: '*';
PLUSPLUS: '++';
MINUSMINUS: '--';
REF: '&';
NOT: '!';
AND: '&&';
OR: '||';
LESS: '<';
GREATER: '>';
EQEQ: '==';
LEQ: '<=';
GEQ: '>=';
NEQ: '!=';
FLEFT: '<<';
FRIGHT: '>>';
PLUS: '+';
MINUS: '-';
DIV: '/';
MOD: '%';
LPAREN: '(';
RPAREN: ')';
COMMA: ',';
LBRACE: '{';
RBRACE: '}';
ARROW: '->';
SEMI: ';';

// Literals
fragment DIGIT: [0-9];
INTEGER: DIGIT+;
FLOAT: DIGIT* '.' DIGIT+;
fragment UPPERCASE: [A-Z];
fragment LOWERCASE: [a-z];
fragment LETTER: LOWERCASE | UPPERCASE;
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
CHARACTER: '\'' ~('\'' | '\\' | '\n') '\'' {
    setText(std::to_string(getText()[1]));
};

// Comments
COMMENT: '//' (~('\n' | '\r'))* -> skip;
COMMENT_BLOCK: '/*' .*? '*/' -> skip;

// Ignoring chars
SEPARATOR: (' ' | '\t' | '\r' | '\n' | EOF) -> skip;

// Others
fragment DOT: '.';
fragment MODULE_ID: (LETTER | DIGIT)*;
MODULE_NAME: MODULE_ID (DOT MODULE_ID)*;
