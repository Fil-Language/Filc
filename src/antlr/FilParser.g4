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
	| (e5=enum_ {
	    $tree = $e5.tree;
	})
	| (e6=variable_decl {
	    $tree = $e6.tree;
	})
	| (e7=condition {
	    $tree = $e7.tree;
	})
	| (e8=loop {
	    $tree = $e8.tree;
	})
	| (e9=function_call {
	    $tree = $e9.tree;
	})
	| (e10=exception_ {
	    $tree = $e10.tree;
	})
	| e11=expr DOT e12=expr {
	    $tree = new DotExpr($e11.tree, $e12.tree);
	}
	| e13=expr ARROW e14=expr {
	    $tree = new ArrowExpr($e13.tree, $e14.tree);
	}
	| (e15=unary_op_pre e16=expr {
	    $tree = new UnaryCalcul($e15.tree, $e16.tree);
	})
    | e17=expr e18=unary_op_post {
        $tree = new UnaryCalcul($e17.tree, $e18.tree);
    }
    | e19=expr e20=binary_operator e21=expr {
        $tree = new BinaryCalcul($e19.tree, $e20.tree, $e21.tree);
    }
	| e22=expr e23=assignation {
	    $tree = new Assignation($e22.tree, $e23.op, $e23.right);
	}
	| (e24=cast {
	    $tree = $e24.tree;
	})
	| (e25=IDENTIFIER {
	    $tree = new Identifier($e25.text);
	})
	| (e26=class_identifier {
	    $tree = $e26.tree;
	})
	| (e27=literal {
	    $tree = $e27.tree;
	})
	| (NEW e28=class_identifier e29=function_call_params {
	    $tree = new New($e28.tree, $e29.tree);
	})
	| (e30=expr_parenthesis {
	    $tree = $e30.tree;
	})
	| (e31=expr_block {
	    $tree = $e31.tree;
	})
	| (e32=array_assign {
	    $tree = $e32.tree;
	})
	| RETURN e33=expr {
	    $tree = new Return($e33.tree);
	};

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function returns[Function *tree]
@init {
    Type *rType = 0;
}
    : FUN n=function_name p=fun_params (COLON t=type {
        rType = $t.tree;
    })? b=fun_body {
        $tree = new Function($n.tree, $p.tree, $b.tree, rType);
    };

function_name returns[Identifier *tree]
    : (i=IDENTIFIER {
        $tree = new Identifier($i.text);
    })
    | (o=OPERATOR b=binary_operator {
        $tree = new OperatorIdentifier($o.text, $b.tree);
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
        $tree = new FunctionParam(new Identifier($i.text), $t.tree);
    };

fun_body returns[AbstractExpr *tree]
    : (e1=assignation {
        $tree = $e1.right;
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
        $tree = new FunctionDecl($n.tree, $p.tree, rType);
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
        $tree = new Interface(new Identifier($i.text), params, body);
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
    ExprBlock *constructor = 0;
    std::vector<ClassVariable *> variables;
    std::vector<ClassFunction *> functions;
}
    : (m=class_modifier {
        modifier = $m.text;
    })? CLASS n=class_identifier (p=class_params {
        params = $p.tree;
    })? (e=class_extends {
        extends = $e.tree;
    })? (b=class_body {
        constructor = $b.constructor;
        variables = $b.variables;
        functions = $b.functions;
    })? {
        $tree = new Class(modifier, $n.tree, params, extends, constructor, variables, functions);
    };

class_modifier returns[std::string text]
    : (m1=ABSTRACT {
        $text = $m1.text;
    })
    | (m2=OPEN {
        $text = $m2.text;
    });

class_identifier returns[ClassIdentifier *tree]
@init {
    auto generic = std::vector<Type *>();
}
    : i=IDENTIFIER (g=class_generic {
        generic = $g.tree;
    })? {
        $tree = new ClassIdentifier($i.text, generic);
    };

class_generic returns[std::vector<Type *> tree]
@init {
    $tree = std::vector<Type *>();
}
    : LT i1=IDENTIFIER {
        $tree.push_back(new Type($i1.text));
    } (COMMA ii=IDENTIFIER {
        $tree.push_back(new Type($ii.text));
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
        $tree = new ClassParam($d.tree);
    })
	| (n=IDENTIFIER COLON t=type (EQ l=literal {
	    value = $l.tree;
	})? {
	    $tree = new ClassParam(new Identifier($n.text), $t.tree, value);
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
@init {
    auto args = std::vector<AbstractExpr *>();
}
    : i=class_identifier (p=function_call_params {
        args = $p.tree;
    })? {
        $tree = new ClassExtend($i.tree, args);
    };

class_body returns[ExprBlock *constructor, std::vector<ClassVariable *> variables, std::vector<ClassFunction *> functions]
@init {
    $variables = std::vector<ClassVariable *>();
    $functions = std::vector<ClassFunction *>();
}
    : LBRACE (c=class_constructor {
        $constructor = $c.tree;
    })? (v=class_variable {
        $variables.push_back($v.tree);
    } | f=class_function {
        $functions.push_back($f.tree);
    })* RBRACE;

class_function returns[ClassFunction *tree]
@init {
    std::string modifier;
    std::string visibility;
    AST *function_;
}
@after {
    $tree = new ClassFunction(modifier, visibility, function_);
}
    : ((a=ABSTRACT {
        modifier = $a.text;
    }) | (o=OVERRIDE {
        modifier = $o.text;
    }))? (v=class_atr_visibility {
        visibility = $v.text;
    })? ((f=function {
        function_ = $f.tree;
    }) | (d=function_decl {
        function_ = $d.tree;
    }));

class_variable returns[ClassVariable *tree]
    : v=class_atr_visibility d=variable_decl {
        $tree = new ClassVariable($v.text, $d.tree);
    };

class_atr_visibility returns[std::string text]
    : (m1=PRIVATE {
        $text = $m1.text;
    })
    | (m2=PUBLIC {
        $text = $m2.text;
    })
    | (m3=INTERNAL {
        $text = $m3.text;
    })
    | (m4=PROTECTED {
        $text = $m4.text;
    });

class_constructor returns[ExprBlock *tree]
    : CONSTRUCTOR e=expr_block {
        $tree = $e.tree;
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

enum_ returns[Enum *tree]
@init {
    std::vector<Identifier *> values;
}
    : ENUM i=IDENTIFIER (b=enum_body {
        values = $b.tree;
    })? {
        $tree = new Enum(new Identifier($i.text), values);
    };

enum_body returns[std::vector<Identifier *> tree]
@init {
    $tree = std::vector<Identifier *>();
}
    : LBRACE (i1=IDENTIFIER {
        $tree.push_back(new Identifier($i1.text));
    } (COMMA ii=IDENTIFIER {
        $tree.push_back(new Identifier($ii.text));
    })*)? RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

condition returns[AbstractExpr *tree]
    : (c1=if_ {
        $tree = $c1.tree;
    })
    | (c2=switch_ {
        $tree = $c2.tree;
    });

if_ returns[If *tree]
@init {
    AbstractExpr *_else = 0;
    std::vector<If *> elseif;
}
@after {
    $tree = new If($c.tree, $b.tree, elseif, _else);
}
    : IF c=if_condition b=if_body (ei=else_if {
        elseif.push_back($ei.tree);
    })* (e=else_ {
        _else = $e.tree;
    })?;

if_condition returns[ExprParenthesis *tree]
    : e=expr_parenthesis {
        $tree = $e.tree;
    };

if_body returns[AbstractExpr *tree]
    : (e1=expr_block {
        $tree = $e1.tree;
    })
    | (e2=expr_parenthesis {
        $tree = $e2.tree;
    })
    | (e3=expr {
        $tree = $e3.tree;
    });

else_if returns[If *tree]
    : ELSE IF c=if_condition b=if_body {
        $tree = new If($c.tree, $b.tree);
    };

else_ returns[AbstractExpr *tree]
    : ELSE b=if_body {
        $tree = $b.tree;
    };

switch_ returns[Switch *tree]
    : SWITCH c=switch_condition b=switch_body {
        $tree = new Switch($c.tree, $b.tree);
    };

switch_condition returns[ExprParenthesis *tree]
    : e=expr_parenthesis {
        $tree = $e.tree;
    };

switch_body returns[std::vector<SwitchCase *> tree]
@init {
    $tree = std::vector<SwitchCase *>();
}
    : LBRACE (c=switch_case {
        $tree.push_back($c.tree);
    })* RBRACE;

switch_case returns[SwitchCase *tree]
@init {
    bool isDefault = true;
    AbstractLiteral *value = 0;
    AbstractExpr *body = 0;
}
    : (l=literal {
        value = $l.tree;
        isDefault = false;
    } | DEFAULT) ARROW (
		(e1=expr {
		    body = $e1.tree;
		})
		| (e2=expr_block {
		    body = $e2.tree;
		})
		| (e3=expr_parenthesis {
		    body = $e3.tree;
		})
	) {
	    if (isDefault) {
	        $tree = new SwitchCase(body);
	    } else {
	        $tree = new SwitchCase(value, body);
	    }
	};

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

loop returns[AbstractLoop *tree]
    : (l1=fori {
        $tree = $l1.tree;
    })
    | (l2=foriter {
        $tree = $l2.tree;
    })
    | (l3=while_ {
        $tree = $l3.tree;
    });

fori returns[For *tree]
@init {
    AbstractExpr *body = 0;
}
    : FOR c=fori_condition
    ((b1=expr {
        body = $b1.tree;
    }) | (b2=expr_block {
        body = $b2.tree;
    })) {
        $tree = new For($c.it, $c.cond, $c.inc, body);
    };

fori_condition returns[VariableDecl *it, AbstractExpr *cond, AbstractExpr *inc]
@init {
    $it = 0;
    $cond = 0;
    $inc = 0;
}
    : LPAREN (i=variable_decl {
        $it = $i.tree;
    })? SEMICOLON (c=expr {
        $cond = $c.tree;
    })? SEMICOLON (n=expr {
        $inc = $n.tree;
    })? RPAREN;

foriter returns[ForIter *tree]
@init {
    AbstractExpr *body = 0;
}
    : FOR c=foriter_condition
    ((b1=expr {
        body = $b1.tree;
    }) | (b2=expr_block {
        body = $b2.tree;
    })) {
        $tree = new ForIter($c.mod, $c.iterator, $c.iterable, body);
    };

foriter_condition returns[std::string mod, Identifier *iterator, Identifier *iterable]
    : LPAREN ((m1=VAL {
        $mod = $m1.text;
    }) | (m2=VAR {
        $mod = $m2.text;
    }))
    (i1=IDENTIFIER {
        $iterator = new Identifier($i1.text);
    }) COLON
    (i2=IDENTIFIER {
        $iterable = new Identifier($i2.text);
    }) RPAREN;

while_ returns[While *tree]
@init {
    AbstractExpr *body = 0;
}
    : WHILE c=if_condition
    ((b1=expr {
        body = $b1.tree;
    }) | (b2=expr_block {
        body = $b2.tree;
    })) {
        $tree = new While($c.tree, body);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

exception_ returns[Try *tree]
@init {
    AbstractExpr *body = 0;
    auto catches = std::vector<Catch *>();
}
@after {
    $tree = new Try(body, catches);
}
	: TRY ((b1=expr {
	    body = $b1.tree;
	}) | (b2=expr_block {
	    body = $b2.tree;
	}) | (b3=expr_parenthesis {
	    body = $b3.tree;
	}))
	(c=catch_body {
	    catches.push_back($c.tree);
	})+;

catch_body returns[Catch *tree]
@init {
    AbstractExpr *body = 0;
}
	: CATCH LPAREN fun_param RPAREN (
		(b1=expr {
		    body = $b1.tree;
		})
		| (b2=expr_block {
		    body = $b2.tree;
		})
		| (b3=expr_parenthesis {
		    body = $b3.tree;
		})
	);

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

binary_operator returns[Operator *tree]
    : (PLUS {
        $tree = new Operator(Operator::PLUS);
    })
	| (MINUS {
	    $tree = new Operator(Operator::MINUS);
	})
	| (DIVIDE {
	    $tree = new Operator(Operator::DIVIDE);
	})
	| (TIMES {
	    $tree = new Operator(Operator::TIMES);
	})
	| (MOD {
	    $tree = new Operator(Operator::MOD);
	})
	| (FLEFT {
	    $tree = new Operator(Operator::FLEFT);
	})
	| (FRIGHT {
	    $tree = new Operator(Operator::FRIGHT);
	})
	| (AND {
	    $tree = new Operator(Operator::AND);
	})
	| (OR {
	    $tree = new Operator(Operator::OR);
	})
	| (LT {
	    $tree = new Operator(Operator::LT);
	})
	| (GT {
	    $tree = new Operator(Operator::GT);
	})
	| (EQEQ {
	    $tree = new Operator(Operator::EQEQ);
	})
	| (LEQ {
	    $tree = new Operator(Operator::LEQ);
	})
	| (GEQ {
	    $tree = new Operator(Operator::GEQ);
	})
	| (NEQ {
	    $tree = new Operator(Operator::NEQ);
	})
	| (BAND {
	    $tree = new Operator(Operator::BAND);
	})
	| (BOR {
	    $tree = new Operator(Operator::BOR);
	})
	| (BXOR {
	    $tree = new Operator(Operator::BXOR);
	});

unary_op_pre returns[Operator *tree]
    : (PLUS PLUS {
        $tree = new Operator(Operator::PLUSPLUS);
    })
	| (MINUS MINUS {
	    $tree = new Operator(Operator::MINMIN);
	})
	| (TIMES {
	    $tree = new Operator(Operator::TIMES);
	})
	| (NOT {
	    $tree = new Operator(Operator::NOT);
	})
	| (BAND {
	    $tree = new Operator(Operator::BAND);
	});

unary_op_post returns[Operator *tree]
    : (PLUS PLUS {
        $tree = new Operator(Operator::PLUSPLUS);
    })
    | (MINUS MINUS {
        $tree = new Operator(Operator::MINMIN);
    })
    | (LBRAK e=expr RBRAK {
        $tree = new Operator(Operator::ARRAY, $e.tree);
    });

unary_operator returns[Operator *tree]
    : (PLUS {
        $tree = new Operator(Operator::PLUS);
    })
	| (MINUS {
	    $tree = new Operator(Operator::MINUS);
	})
	| (DIVIDE {
	    $tree = new Operator(Operator::DIVIDE);
	})
	| (TIMES {
	    $tree = new Operator(Operator::TIMES);
	})
	| (MOD {
	    $tree = new Operator(Operator::MOD);
	})
	| (NOT {
	    $tree = new Operator(Operator::NOT);
	})
	| (BAND {
	    $tree = new Operator(Operator::BAND);
	})
	| (BOR {
	    $tree = new Operator(Operator::BOR);
	})
	| (BXOR {
	    $tree = new Operator(Operator::BXOR);
	});

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

assignation returns[AssignationOperator *op, AbstractExpr *right]
    : o=assignation_operator {
        $op = $o.tree;
    } e=expr {
        $right = $e.tree;
    };

assignation_operator returns[AssignationOperator *tree]
@init {
    Operator *op = 0;
}
    : (o=unary_operator {
        op = $o.tree;
    })? EQ {
        $tree = new AssignationOperator(op);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cast returns[Cast *tree]
    : LPAREN t=type RPAREN e=expr {
        $tree = new Cast($t.tree, $e.tree);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function_call returns[FunctionCall *tree]
    : n=function_name p=function_call_params {
        $tree = new FunctionCall($n.tree, $p.tree);
    };

function_call_params returns[std::vector<AbstractExpr *> tree]
@init {
    $tree = std::vector<AbstractExpr *>();
}
    : LPAREN (p=function_call_param_list {
        $tree = $p.tree;
    })? RPAREN;

function_call_param_list returns[std::vector<AbstractExpr *> tree]
@init {
    $tree = std::vector<AbstractExpr *>();
}
    : (e1=expr {
        $tree.push_back($e1.tree);
    }) (COMMA (ei=expr {
        $tree.push_back($ei.tree);
    }))*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

variable_decl returns[VariableDecl *tree]
@init {
    bool isVal = false;
    Type *type_ = 0;
    AssignationOperator *op = 0;
    AbstractExpr *value = 0;
}
@after {
    if (op && value) {
        $tree = new VariableDecl(isVal, new Identifier($i.text), type_, op, value);
    } else {
        $tree = new VariableDecl(isVal, new Identifier($i.text), type_);
    }
}
    : (VAL {
        isVal = true;
    } | VAR) i=IDENTIFIER (((COLON t1=type {
        type_ = $t1.tree;
    })? (a=assignation {
        op = $a.op;
        value = $a.right;
    })) | (COLON t2=type {
        type_ = $t2.tree;
    }));

array_assign returns[Array *tree]
@init {
    std::vector<AbstractExpr *> values;
}
@after {
    $tree = new Array(values);
}
    : LBRACE (e1=expr {
        values.push_back($e1.tree);
    }) (COMMA (ei=expr {
        values.push_back($ei.tree);
    }))* RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

type returns[Type *tree]
@init {
    bool isPointer = false;
    bool isArray = false;
    int arraySize = 0;
}
@after {
    if (isPointer) {
        $tree = new Type($i.text, true);
    } else if (isArray) {
        $tree = new Type($i.text, arraySize);
    } else {
        $tree = new Type($i.text);
    }
}
    : i=IDENTIFIER (TIMES {
        isPointer = true;
    } | (LBRAK (s=INT {
        arraySize = stoi($s.text);
    })? RBRAK {
        isArray = true;
    }))?;

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
