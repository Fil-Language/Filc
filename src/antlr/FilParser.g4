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
    : m=MODULE (i=import_ {
        imports.push_back($i.tree);
    })* (e=expr {
        exprs.push_back($e.tree);
    })* EOF;

import_ returns[Program *tree]
    : i=IMPORT {
        $tree = FilCompiler::import($i.text);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

expr returns[AbstractExpr *tree]
@init {
    $tree = new AbstractExpr();
}
    : (e1=function {
        $tree = $e1.tree;
    })
	| (e2=lambda {
	    $tree = $e2.tree;
	})
	| (e3=interface {
	    $tree = $e3.tree;
	})
	| (e4=class_ {
	    $tree = $e4.tree;
	})
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
	| (e26=class_identifier {
	    $tree = $e26.tree;
	})
	| (e27=literal {
	    $tree = $e27.tree;
	})
	| NEW class_identifier function_call_params // TODO
	| (e31=expr_parenthesis {
	    $tree = $e31.tree;
	})
	| (e32=expr_block {
	    $tree = $e32.tree;
	})
	| array_assign; // TODO

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function returns[Function *tree]
@init {
    Type *rType = 0;
}
    : FUN n=function_name p=fun_params (COLON t=type {
        rType = $t.tree;
    })? b=fun_body {
        $tree = new Function($n.text, $p.tree, $b.tree, rType);
    };

function_name returns[std::string text]
    : (i=IDENTIFIER {
        $text = $i.text;
    })
    | (o=OPERATOR b=binary_operator {
        $text = $o.text + $b.text;
    });

fun_params returns[std::vector<FunctionParam *> tree]
@init {
    $tree = std::vector<FunctionParam *>();
}
    : LPAREN (p=fun_param_list {
        $tree = $p.tree;
    })? RPAREN;

fun_param_list returns[std::vector<FunctionParam *> tree]
@init {
    $tree = std::vector<FunctionParam *>();
}
    : p1=fun_param {
        $tree.push_back($p1.tree);
    } (COMMA pi=fun_param {
        $tree.push_back($pi.tree);
    })*;

fun_param returns[FunctionParam *tree]
    : i=IDENTIFIER COLON t=type {
        $tree = new FunctionParam($i.text, $t.tree);
    };

fun_body returns[AbstractExpr *tree]
    : (e1=assignation {
        $tree = new AbstractExpr();
    })
    | (e2=expr_parenthesis {
        $tree = $e2.tree;
    })
    | (e3=expr_block {
        $tree = $e3.tree;
    });

function_decl returns[FunctionDecl *tree]
@init {
    Type *rType = 0;
}
    : FUN n=function_name p=fun_params (COLON t=type {
        rType = $t.tree;
    })? {
        $tree = new FunctionDecl($n.text, $p.tree, rType);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

lambda returns[Lambda *tree]
@init {
    AbstractExpr *body;
}
    : p=fun_params ARROW ((b1=expr_block {
        body = $b1.tree;
    }) | (b2=expr_parenthesis {
        body = $b2.tree;
    })) {
        $tree = new Lambda($p.tree, body);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

interface returns[Interface *tree]
@init {
    auto body = vector<FunctionDecl *>();
    std::vector<ClassParam *> params;
}
    : INTERFACE i=IDENTIFIER (p=class_params {
        params = $p.tree;
    })? (b=interface_body {
        body = $b.tree;
    })? {
        $tree = new Interface($i.text, params, body);
    };

interface_body returns[std::vector<FunctionDecl *> tree]
@init {
    $tree = std::vector<FunctionDecl *>();
}
    : LBRACE (d=function_decl {
        $tree.push_back($d.tree);
    })* RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

class_ returns[Class *tree]
@init {
    std::string modifier;
    auto params = std::vector<ClassParam *>();
    auto extends = std::vector<ClassExtend *>();
}
    : (m=class_modifier {
        modifier = $m.text;
    })? CLASS n=class_identifier (p=class_params {
        params = $p.tree;
    })? (e=class_extends {
        extends = $e.tree;
    })? class_body? {
        $tree = new Class(modifier, $n.tree, params, extends);
    }; // TODO : class_body

class_modifier returns[std::string text]
    : (m1=ABSTRACT {
        $text = $m1.text;
    })
    | (m2=OPEN {
        $text = $m2.text;
    });

class_identifier returns[ClassIdentifier *tree]
@init {
    auto generic = std::vector<std::string>();
}
    : i=IDENTIFIER (g=class_generic {
        generic = $g.tree;
    })? {
        $tree = new ClassIdentifier($i.text, generic);
    };

class_generic returns[std::vector<std::string> tree]
@init {
    $tree = std::vector<std::string>();
}
    : LT i1=IDENTIFIER {
        $tree.push_back($i1.text);
    } (COMMA ii=IDENTIFIER {
        $tree.push_back($ii.text);
    })* GT;

class_params returns[std::vector<ClassParam *> tree]
@init {
    $tree = std::vector<ClassParam *>();
}
    : LPAREN (p=class_param_list {
        $tree = $p.tree;
    })? RPAREN;

class_param_list returns[std::vector<ClassParam *> tree]
@init {
    $tree = std::vector<ClassParam *>();
}
    : (p1=class_param {
        $tree.push_back($p1.tree);
    }) (COMMA pi=class_param {
        $tree.push_back($pi.tree);
    })*;

class_param returns[ClassParam *tree]
@init {
    AbstractLiteral *value = 0;
}
    : (d=variable_decl {
        $tree = new ClassParam(new AbstractExpr());
    }) // TODO : variable_decl
	| (n=IDENTIFIER COLON t=type (EQ l=literal {
	    value = $l.tree;
	})? {
	    $tree = new ClassParam($n.text, $t.tree, value);
	});

class_extends returns[std::vector<ClassExtend *> tree]
    : COLON e=class_extend_list {
        $tree = $e.tree;
    };

class_extend_list returns[std::vector<ClassExtend *> tree]
@init {
    $tree = std::vector<ClassExtend *>();
}
    : e1=class_extend {
        $tree.push_back($e1.tree);
    } (COMMA ei=class_extend {
        $tree.push_back($ei.tree);
    })*;

class_extend returns[ClassExtend *tree]
    : i=class_identifier function_call_params? {
        $tree = new ClassExtend($i.tree);
    }; // TODO : function_call_params

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

switch_case: (literal | DEFAULT) ARROW ( // TODO
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

catch_body // TODO
	: CATCH LPAREN fun_param RPAREN (
		expr // TODO
		| expr_block // TODO
		| expr_parenthesis // TODO
	);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

binary_operator returns[std::string text]
    : (b1=PLUS {
        $text = $b1.text;
    })
	| (b2=MINUS {
	    $text = $b2.text;
	})
	| (b3=DIVIDE {
	    $text = $b3.text;
	})
	| (b4=TIMES {
	    $text = $b4.text;
	})
	| (b5=MOD {
	    $text = $b5.text;
	})
	| (b6=FLEFT {
	    $text = $b6.text;
	})
	| (b7=FRIGHT {
	    $text = $b7.text;
	})
	| (b8=AND {
	    $text = $b8.text;
	})
	| (b9=OR {
	    $text = $b9.text;
	})
	| (b10=LT {
	    $text = $b10.text;
	})
	| (b11=GT {
	    $text = $b11.text;
	})
	| (b12=EQEQ {
	    $text = $b12.text;
	})
	| (b13=LEQ {
	    $text = $b13.text;
	})
	| (b14=GEQ {
	    $text = $b14.text;
	})
	| (b15=NEQ {
	    $text = $b15.text;
	})
	| (b16=BAND {
	    $text = $b16.text;
	})
	| (b17=BOR {
	    $text = $b17.text;
	})
	| (b18=BXOR {
	    $text = $b18.text;
	});

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

type returns[Type *tree]
    : i=IDENTIFIER (TIMES | (LBRAK INT? RBRAK))? {
        $tree = new Type($i.text);
    }; // TODO : get * and []

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

literal returns[AbstractLiteral *tree]
    : (l1=INT {
        $tree = new Integer(stoi($l1.text));
    })
    | (l2=FLOAT {
        $tree = new Double(stod($l2.text));
    })
    | (l3=STRING {
        $tree = new String($l3.text);
    })
    | (l4=FSTRING {
        $tree = new FString($l4.text);
    })
    | (l5=CHAR {
        $tree = new Char($l5.text[0]);
    })
    | (TRUE {
        $tree = new True();
    })
    | (FALSE {
        $tree = new False();
    })
    | (NULL_ {
        $tree = new Null();
    });

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

expr_parenthesis returns[ExprParenthesis *tree]
@init {
    auto exprs = vector<AbstractExpr *>();
}
@after {
    $tree = new ExprParenthesis(exprs);
}
    : LPAREN (e=expr {
        exprs.push_back($e.tree);
    })* RPAREN;

expr_block returns[ExprBlock *tree]
@init {
    auto exprs = vector<AbstractExpr *>();
}
@after {
    $tree = new ExprBlock(exprs);
}
    : LBRACE (e=expr {
        exprs.push_back($e.tree);
    })* RBRACE;
