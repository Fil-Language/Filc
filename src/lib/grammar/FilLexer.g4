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
lexer grammar FilLexer;

MODULE: 'module';
USE: 'use';
FROM: 'from';
EXPORT: 'export';
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
OPERATOR: 'operator';

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
DOT: '.';
ARROW: '->';
SEMI: ';';

fragment DIGIT: [0-9];
fragment SIGN: ('+'|'-');
INTEGER: SIGN? DIGIT+;
FLOAT: SIGN? DIGIT* '.' DIGIT+;
fragment UPPERCASE: [A-Z];
fragment LOWERCASE: [a-z];
fragment LETTER: UPPERCASE | LOWERCASE;
fragment STRING_CHAR: ~('"' | '\\' | '\n');
STRING: '"' (STRING_CHAR | '\\"' | '\\\\')* '"';
CHARACTER: '\'' ~('\'' | '\\' | '\n') '\'';

COMMENT: '//' (~('\n' | '\r'))* -> skip;
COMMENT_BLOCK: '/*' .*? '*/' -> skip;
SEPARATOR: (' ' | '\t' | '\r' | '\n' | EOF) -> skip;

IDENTIFIER: (LETTER | '_') (LETTER | DIGIT | '_')*;
