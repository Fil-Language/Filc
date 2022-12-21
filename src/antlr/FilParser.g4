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
        $text += "." + $ii.text;
    })*
    ;

import_ returns[Program *tree]
@init {
    string name;
}
@after {
    $tree = FilCompiler::import(name, $s);
}
    : s=IMPORT i1=IDENTIFIER {
        name = $i1.text;
    } (DOT ii=IDENTIFIER {
        name += "." + $ii.text;
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
        $tree->setPosition($e4);
    }
    | e5=calcul {
        $tree = $e5.tree;
    }
    | e6=function {
        $tree = $e6.tree;
    }
    | r=RETURN e7=expr {
        $tree = new Return($e7.tree);
        $tree->setPosition($r);
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
    | e11=cast {
        $tree = $e11.tree;
    }
    | e12=parenthesis_body {
        $tree = $e12.tree;
    }
    // Rule for binary calcul, need to be here to avoid left-recursion errors
    // Long but needed, the higher the most priority, the lower the less priority
    // The groups are for operators with same priority
    // TODO : find a way to move this part in another rule without the left-recursion error
    | b1=expr STAR b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::STAR), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr DIV b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::DIV), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr MOD b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::MOD), $b2.tree);
        $tree->setPosition($b1.start);
    }

    | b1=expr PLUS b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::PLUS), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr MINUS b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::MINUS), $b2.tree);
        $tree->setPosition($b1.start);
    }

    | b1=expr FLEFT b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::FLEFT), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr FRIGHT b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::FRIGHT), $b2.tree);
        $tree->setPosition($b1.start);
    }

    | b1=expr AND b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::AND), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr OR b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::OR), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr LESS b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::LESS), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr GREATER b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::GREATER), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr EQEQ b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::EQEQ), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr LEQ b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::LEQ), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr GEQ b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::GEQ), $b2.tree);
        $tree->setPosition($b1.start);
    }
    | b1=expr NEQ b2=expr {
        $tree = new BinaryCalcul($b1.tree, new Operator(Operator::NEQ), $b2.tree);
        $tree->setPosition($b1.start);
    }
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
        $tree->setPosition($l3);
    }
    | l4=STRING {
        $tree = new StringLiteral($l4.text);
        $tree->setPosition($l4);
    }
    | l5=FSTRING {
        $tree = new FStringLiteral($l5.text);
        $tree->setPosition($l5);
    }
    ;

boolean returns[BooleanLiteral *tree]
    : b1=TRUE {
        $tree = new BooleanLiteral(true);
        $tree->setPosition($b1);
    }
    | b2=FALSE {
        $tree = new BooleanLiteral(false);
        $tree->setPosition($b2);
    };

number returns[AbstractLiteral *tree]
    : i=INTEGER {
        $tree = new IntegerLiteral(stoi($i.text));
        $tree->setPosition($i);
    }
    | f=FLOAT {
        $tree = new FloatLiteral(stof($f.text));
        $tree->setPosition($f);
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
    $tree->setPosition($v);
}
    : (v=VAL {
        isVal = true;
    } | v=VAR) i=IDENTIFIER {
        name = new Identifier($i.text);
        name->setPosition($i);
    } ((COLON t=type {
        vt = $t.tree;
    }) | (COLON t=type {
        vt = $t.tree;
    })? a=assignation {
        va = $a.tree;
    });

assignation returns[Assignation *tree]
    : s=EQ e=expr {
        $tree = new Assignation($e.tree);
        $tree->setPosition($s);
    };

type returns[AbstractType *tree]
@init {
    AbstractType *prev = nullptr;
}
@after {
    $tree = prev;
}
    : i=IDENTIFIER {
        auto id = new Identifier($i.text);
        id->setPosition($i);
        prev = new Type(id);
        prev->setPosition($i);
    } (st=LBRACK s=INTEGER RBRACK {
            prev = new Type(stoi($s.text), prev);
            prev->setPosition($st);
        }
        | st=STAR {
            prev = new Type(prev);
            prev->setPosition($st);
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
        auto id = new Identifier($i1.text);
        id->setPosition($i1);
        $tree = new UnaryCalcul(id, $o1.tree);
        $tree->setPosition($i1);
    }
    | o2=pre_operator i2=IDENTIFIER {
        auto id = new Identifier($i2.text);
        id->setPosition($i2);
        $tree = new UnaryCalcul($o2.tree, id);
        $tree->setPosition($o2.start);
    };

post_operator returns[Operator *tree]
    : o1=PLUSPLUS {
        $tree = new Operator(Operator::PLUSPLUS);
        $tree->setPosition($o1);
    }
    | o2=MINUSMINUS {
        $tree = new Operator(Operator::MINUSMINUS);
        $tree->setPosition($o2);
    }
    | (o3=LBRACK e=expr RBRACK) {
        $tree = new Operator($e.tree);
        $tree->setPosition($o3);
    };

pre_operator returns[Operator *tree]
    : o1=PLUSPLUS {
        $tree = new Operator(Operator::PLUSPLUS);
        $tree->setPosition($o1);
    }
    | o2=MINUSMINUS {
        $tree = new Operator(Operator::PLUSPLUS);
        $tree->setPosition($o2);
    }
    | o3=REF {
        $tree = new Operator(Operator::REF);
        $tree->setPosition($o3);
    }
    | o4=STAR {
        $tree = new Operator(Operator::STAR);
        $tree->setPosition($o4);
    }
    | o5=NOT {
        $tree = new Operator(Operator::NOT);
        $tree->setPosition($o5);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function returns[Function *tree]
    : d=function_declaration b=function_body {
        $tree = new Function($d.tree, $b.tree);
        $tree->setPosition($d.start);
    };

function_declaration returns[FunctionDeclaration *tree]
@init {
    AbstractType *ft = nullptr;
    vector<FunctionParam *> params;
}
@after {
    auto id = new Identifier($i.text);
    id->setPosition($i);
    $tree = new FunctionDeclaration(id, params, ft);
    $tree->setPosition($f);
}
    : f=FUN i=IDENTIFIER LPAREN (p=function_params {
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
        auto id = new Identifier($i1.text);
        id->setPosition($i1);
        auto param1 = new FunctionParam(id, $t1.tree);
        param1->setPosition($i1);
        res.push_back(param1);
    } (COMMA ii=IDENTIFIER COLON ti=type {
        auto id = new Identifier($ii.text);
        id->setPosition($ii);
        auto paramI = new FunctionParam(id, $ti.tree);
        paramI->setPosition($ii);
        res.push_back(paramI);
    })?;

function_type returns[AbstractType *tree]
    : COLON t=type {
        $tree = $t.tree;
        $tree->setPosition($t.start);
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

parenthesis_body returns[ParenthesisBody *tree]
    : LPAREN e=expr {
        $tree = new ParenthesisBody($e.tree);
        $tree->setPosition($e.start);
    } RPAREN;

block_body returns[BlockBody *tree]
@init {
    vector<AbstractExpr *> res;
}
@after {
    $tree = new BlockBody(res);
    $tree->setPosition($s);
}
    : s=LBRACE (ei=expr {
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
    $tree->setPosition($s);
}
    : s=LPAREN (p=function_params {
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
    $tree->setPosition($s);
}
    : s=LPAREN (a1=type {
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
    $tree->setPosition($s);
}
    : s=IF c=if_condition b=if_body (ELSE (e1=if_ {
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
    : s=SWITCH c=if_condition b=switch_body {
        $tree = new Switch($c.tree, $b.tree);
        $tree->setPosition($s);
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
    $tree->setPosition($p.start);
}
    : p=switch_pattern ARROW (b1=expr {
        body = $b1.tree;
    } | b2=parenthesis_body {
        body = $b2.tree;
    } | b3=block_body {
        body = $b3.tree;
    });

switch_pattern returns[SwitchPattern *tree]
    : s=DEFAULT {
        $tree = new SwitchPattern();
        $tree->setPosition($s);
    } | l=literal {
        $tree = new SwitchPattern($l.tree);
        $tree->setPosition($l.start);
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
    : s=FOR c=for_i_condition b=if_body {
        $tree = new ForI($c.tree, $b.tree);
        $tree->setPosition($s);
    };

for_i_condition returns[ForICondition *tree]
@init {
    VariableDeclaration *decl = nullptr;
    AbstractExpr *cond = nullptr;
    AbstractExpr *iter = nullptr;
}
@after {
    $tree = new ForICondition(decl, cond, iter);
    $tree->setPosition($s);
}
    : s=LPAREN (d=variable_declaration {
        decl = $d.tree;
    })? SEMI (c=expr {
        cond = $c.tree;
    })? SEMI (i=expr {
        iter = $i.tree;
    })? RPAREN;

for_iter returns[ForIter *tree]
    : s=FOR c=for_iter_condition b=if_body {
        $tree = new ForIter($c.tree, $b.tree);
        $tree->setPosition($s);
    };

for_iter_condition returns[ForIterCondition *tree]
@init {
    bool isVal = false;
}
    : s=LPAREN (VAL {
        isVal = true;
    } | VAR) i1=IDENTIFIER COLON i2=IDENTIFIER RPAREN {
        auto id1 = new Identifier($i1.text);
        id1->setPosition($i1);
        auto id2 = new Identifier($i2.text);
        id2->setPosition($i2);
        $tree = new ForIterCondition(isVal, id1, id2);
        $tree->setPosition($s);
    };

while_ returns[While *tree]
    : s=WHILE c=if_condition b=if_body {
        $tree = new While($c.tree, $b.tree);
        $tree->setPosition($s);
    };

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

function_call returns[FunctionCall *tree]
@init {
    vector<AbstractExpr *> args;
}
@after {
    auto id = new Identifier($n.text);
    id->setPosition($n);
    $tree = new FunctionCall(id, args);
    $tree->setPosition($n);
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

cast returns[Cast *tree]
    : s=LPAREN t=type RPAREN e=expr {
        $tree = new Cast($t.tree, $e.tree);
        $tree->setPosition($s);
    };
