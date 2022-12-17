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
    : m=module (i=import_ {
        imports.push_back($i.tree);
    })* (exported=EXPORT? e=expr {
        auto e = $e.tree;
        e->isExported($exported ? true : false);
        exprs.push_back(e);
    })* EOF;

module returns[string text]
    : MODULE i1=IDENTIFIER {
        $text = $i1.text;
    } (DOT ii=IDENTIFIER {
        $text += $ii.text;
    })*
    ;

import_ returns[Program *tree]
@init {
    string name;
}
@after {
    $tree = FilCompiler::import(name);
}
    : IMPORT i1=IDENTIFIER {
        name = $i1.text;
    } (DOT ii=IDENTIFIER {
        name += $ii.text;
    })*
    ;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

expr returns[AbstractExpr *tree]
    : e1=literal {
        $tree = $e1.tree;
    }
    | e2=variable_declaration {
        $tree = $e2.tree;
    }
    | e3=assignation {
        $tree = $e3.tree;
    }
    | e4=IDENTIFIER {
        $tree = new Identifier($e4.text);
    }
    | e5=calcul {
        $tree = $e5.tree;
    }
    | e6=function {
        $tree = $e6.tree;
    }
    | RETURN e7=expr {
        $tree = new Return($e7.tree);
    }
    | e8=lambda {
        $tree = $e8.tree;
    }
    | e9=control {
        $tree = $e9.tree;
    }
    | e10=function_call {
        $tree = $e10.tree;
    }
    | cast
    | parenthesis_body
    // Rule for binary calcul, need to be here to avoid left-recursion errors
    // Long but needed, the higher the most priority, the lower the less priority
    // The groups are for operators with same priority
    // TODO : find a way to move this part in another rule without the left-recursion error
    | expr STAR expr
    | expr DIV expr
    | expr MOD expr

    | expr PLUS expr
    | expr MINUS expr

    | expr FLEFT expr
    | expr FRIGHT expr

    | expr AND expr
    | expr OR expr
    | expr LESS expr
    | expr GREATER expr
    | expr EQEQ expr
    | expr LEQ expr
    | expr GEQ expr
    | expr NEQ expr
    ;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

literal returns[AbstractLiteral *tree]
    : l1=boolean {
        $tree = $l1.tree;
    }
    | l2=number {
        $tree = $l2.tree;
    }
    | l3=CHARACTER {
        $tree = new CharLiteral($l3.text);
    }
    | l4=STRING {
        $tree = new StringLiteral($l4.text);
    }
    | l5=FSTRING {
        $tree = new FStringLiteral($l5.text);
    }
    ;

boolean returns[BooleanLiteral *tree]
    : TRUE {
        $tree = new BooleanLiteral(true);
    }
    | FALSE {
        $tree = new BooleanLiteral(false);
    };

number returns[AbstractLiteral *tree]
    : i=INTEGER {
        $tree = new IntegerLiteral(stoi($i.text));
    }
    | f=FLOAT {
        $tree = new FloatLiteral(stof($f.text));
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

variable_declaration returns[VariableDeclaration *tree]
@init {
    bool isVal = false;
    Identifier *name = nullptr;
    AbstractType *vt = nullptr;
    Assignation *va = nullptr;
}
@after {
    $tree = new VariableDeclaration(isVal, name, vt, va);
}
    : (VAL {
        isVal = true;
    } | VAR) i=IDENTIFIER {
        name = new Identifier($i.text);
    } ((COLON t=type {
        vt = $t.tree;
    }) | (COLON t=type {
        vt = $t.tree;
    })? a=assignation {
        va = $a.tree;
    });

assignation returns[Assignation *tree]
    : EQ e=expr {
        $tree = new Assignation($e.tree);
    };

type returns[AbstractType *tree]
@init {
    AbstractType *prev = nullptr;
}
@after {
    $tree = prev;
}
    : i=IDENTIFIER {
        prev = new Type(new Identifier($i.text));
    } (LBRACK s=INTEGER RBRACK {
            prev = new Type(stoi($s.text), prev);
        }
        | STAR {
            prev = new Type(prev);
        })*
    | t=lambda_type {
        prev = $t.tree;
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

calcul returns[UnaryCalcul *tree]
    : c=unary_calcul {
        $tree = $c.tree;
    };

unary_calcul returns[UnaryCalcul *tree]
    : i1=IDENTIFIER o1=post_operator {
        $tree = new UnaryCalcul(new Identifier($i1.text), $o1.tree);
    }
    | o2=pre_operator i2=IDENTIFIER {
        $tree = new UnaryCalcul($o2.tree, new Identifier($i2.text));
    };

post_operator returns[Operator *tree]
    : PLUSPLUS {
        $tree = new Operator(Operator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = new Operator(Operator::MINUSMINUS);
    }
    | (LBRACK e=expr RBRACK) {
        $tree = new Operator($e.tree);
    };

pre_operator returns[Operator *tree]
    : PLUSPLUS {
        $tree = new Operator(Operator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = new Operator(Operator::PLUSPLUS);
    }
    | REF {
        $tree = new Operator(Operator::REF);
    }
    | STAR {
        $tree = new Operator(Operator::STAR);
    }
    | NOT {
        $tree = new Operator(Operator::NOT);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function returns[Function *tree]
    : d=function_declaration b=function_body {
        $tree = new Function($d.tree, $b.tree);
    };

function_declaration returns[FunctionDeclaration *tree]
@init {
    AbstractType *ft = nullptr;
    vector<FunctionParam *> params;
}
@after {
    $tree = new FunctionDeclaration(new Identifier($i.text), params, ft);
}
    : FUN i=IDENTIFIER LPAREN (p=function_params {
        params = $p.tree;
    })? RPAREN (t=function_type {
        ft = $t.tree;
    })?;

function_params returns[vector<FunctionParam *> tree]
@init {
    vector<FunctionParam *> res;
}
@after {
    $tree = res;
}
    : i1=IDENTIFIER COLON t1=type {
        res.push_back(new FunctionParam(new Identifier($i1.text), $t1.tree));
    } (COMMA ii=IDENTIFIER COLON ti=type {
        res.push_back(new FunctionParam(new Identifier($ii.text), $ti.tree));
    })?;

function_type returns[AbstractType *tree]
    : COLON t=type {
        $tree = $t.tree;
    };

function_body returns[AbstractExpr *tree]
    : b1=assignation {
        $tree = $b1.tree;
    }
    | b2=parenthesis_body {
        $tree = $b2.tree;
    }
    | b3=block_body {
        $tree = $b3.tree;
    };

parenthesis_body returns[AbstractExpr *tree]
    : LPAREN e=expr {
        $tree = $e.tree;
    } RPAREN;

block_body returns[BlockBody *tree]
@init {
    vector<AbstractExpr *> res;
}
@after {
    $tree = new BlockBody(res);
}
    : LBRACE (ei=expr {
        res.push_back($ei.tree);
    })* RBRACE;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

lambda returns[Lambda *tree]
@init {
    vector<FunctionParam *> lp;
    AbstractType *lt = nullptr;
    AbstractExpr *lb = nullptr;
}
@after {
    $tree = new Lambda(lp, lt, lb);
}
    : LPAREN (p=function_params {
        lp = $p.tree;
    })? RPAREN (t=function_type {
        lt = $t.tree;
    })? ARROW (b1=expr {
        lb = $b1.tree;
    } | b2=parenthesis_body {
        lb = $b2.tree;
    } | b3=block_body {
        lb = $b3.tree;
    });

lambda_type returns[LambdaType *tree]
@init {
    vector<AbstractType *> args;
}
@after {
    $tree = new LambdaType(args, $r.tree);
}
    : LPAREN (a1=type {
        args.push_back($a1.tree);
    } (COMMA ai=type {
        args.push_back($ai.tree);
    })*)? RPAREN ARROW r=type;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

control returns[AbstractExpr *tree]
    : c=condition {
        $tree = $c.tree;
    }
    | l=loop {
        $tree = $l.tree;
    };

condition returns[AbstractExpr *tree]
    : i=if_ {
        $tree = $i.tree;
    }
    | s=switch_ {
        $tree = $s.tree;
    };

if_ returns[If *tree]
@init {
    AbstractExpr *else_ = nullptr;
}
@after {
    $tree = new If($c.tree, $b.tree, else_);
}
    : IF c=if_condition b=if_body (ELSE (e1=if_ {
        else_ = $e1.tree;
    } | e2=if_body {
        else_ = $e2.tree;
    }))?;

if_condition returns[AbstractExpr *tree]
    : LPAREN e=expr {
        $tree = $e.tree;
    } RPAREN;

if_body returns[AbstractExpr *tree]
    : b1=expr {
        $tree = $b1.tree;
    } | b2=block_body {
        $tree = $b2.tree;
    };

switch_ returns[Switch *tree]
    : SWITCH c=if_condition b=switch_body {
        $tree = new Switch($c.tree, $b.tree);
    };

switch_body returns[vector<SwitchCase *> tree]
@init {
    vector<SwitchCase *> res;
}
    : LBRACE (c=switch_case {
        res.push_back($c.tree);
    })* RBRACE;

switch_case returns[SwitchCase *tree]
@init {
    AbstractExpr *body = nullptr;
}
@after {
    $tree = new SwitchCase($p.tree, body);
}
    : p=switch_pattern ARROW (b1=expr {
        body = $b1.tree;
    } | b2=parenthesis_body {
        body = $b2.tree;
    } | b3=block_body {
        body = $b3.tree;
    });

switch_pattern returns[SwitchPattern *tree]
    : DEFAULT {
        $tree = new SwitchPattern();
    } | l=literal {
        $tree = new SwitchPattern($l.tree);
    };

loop returns[AbstractExpr *tree]
    : l1=for_i {
        $tree = $l1.tree;
    }
    | l2=for_iter {
        $tree = $l2.tree;
    }
    | l3=while_ {
        $tree = $l3.tree;
    };

for_i returns[ForI *tree]
    : FOR c=for_i_condition b=if_body {
        $tree = new ForI($c.tree, $b.tree);
    };

for_i_condition returns[ForICondition *tree]
@init {
    VariableDeclaration *decl = nullptr;
    AbstractExpr *cond = nullptr;
    AbstractExpr *iter = nullptr;
}
@after {
    $tree = new ForICondition(decl, cond, iter);
}
    : LPAREN (d=variable_declaration {
        decl = $d.tree;
    })? SEMI (c=expr {
        cond = $c.tree;
    })? SEMI (i=expr {
        iter = $i.tree;
    })? RPAREN;

for_iter returns[ForIter *tree]
    : FOR c=for_iter_condition b=if_body {
        $tree = new ForIter($c.tree, $b.tree);
    };

for_iter_condition returns[ForIterCondition *tree]
@init {
    bool isVal = false;
}
    : LPAREN (VAL {
        isVal = true;
    } | VAR) i1=IDENTIFIER COLON i2=IDENTIFIER RPAREN {
        $tree = new ForIterCondition(isVal, new Identifier($i1.text), new Identifier($i2.text));
    };

while_ returns[While *tree]
    : WHILE c=if_condition b=if_body {
        $tree = new While($c.tree, $b.tree);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function_call returns[FunctionCall *tree]
@init {
    vector<AbstractExpr *> args;
}
@after {
    $tree = new FunctionCall(new Identifier($n.text), args);
}
    : n=IDENTIFIER LPAREN (p=function_call_params {
        args = $p.tree;
    })? RPAREN;

function_call_params returns[vector<AbstractExpr *> tree]
@init {
    vector<AbstractExpr *> res;
}
@afer {
    $tree = res;
}
    : e1=expr {
        res.push_back($e1.tree);
    } (COMMA ei=expr {
        res.push_back($ei.tree);
    })*;

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cast : LPAREN type RPAREN expr;
