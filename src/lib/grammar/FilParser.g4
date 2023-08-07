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
parser grammar FilParser;

options {
    tokenVocab = FilLexer;
}

@parser::header {
#include "AST.h"
#include "MessageCollector.h"
#include "Error.h"
#include <string>
#include <vector>
}

program returns[filc::ast::Program *tree]
@init {
    std::vector<std::string> imports;
    std::vector<filc::ast::AbstractExpression *> expressions;
}
@after {
    $tree = new filc::ast::Program($m.text, imports, expressions);
}
    : m=module (u=use {
        imports.push_back($u.text);
    })* (exp=EXPORT? e=expression {
        auto e = $e.tree;
        if (e != nullptr) {
            e->setExported($exp ? true : false);
            expressions.push_back(e);
        }
    })*;

module returns[std::string text]
@after {
    $text = $mi.text;
}
    : MODULE mi=module_identifier;

use returns[std::string text]
@after {
    $text = $mi.text;
}
    : USE mi=module_identifier;

module_identifier returns[std::string text]
    : i1=IDENTIFIER {
        $text = $i1.text;
    } (DOT ii=IDENTIFIER {
        $text += "." + $ii.text;
    })*;

expression returns[filc::ast::AbstractExpression *tree]
    : l=literal {
        $tree = $l.tree;
    }
    | v=variable_declaration {
        $tree = $v.tree;
    }
    | a=assignation {
        $tree = $a.tree;
    }
    | u=unary_calcul {
        $tree = $u.tree;
    }
    | el=expression bo=binary_operator er=expression {
        $tree = new filc::ast::BinaryCalcul($el.tree, $bo.tree, $er.tree);
    }
    | f=function {
        $tree = $f.tree;
    }
    | lb=lambda {
        $tree = $lb.tree;
    }
    | c=control {
        $tree = $c.tree;
    }
    | p=parenthesis_body {
        $tree = $p.tree[0];
    }
    | i=IDENTIFIER {
        $tree = new filc::ast::Identifier($i);
    };

literal returns[filc::ast::AbstractExpression *tree]
    : b=boolean {
        $tree = $b.tree;
    }
    | n=number {
        $tree = $n.tree;
    }
    | c=CHARACTER {
        $tree = new filc::ast::CharacterLiteral(
            filc::ast::CharacterLiteral::stringToChar($c.text, $c)
        );
        $tree->setPosition(new filc::utils::Position($c));
    }
    | s=STRING {
        $tree = new filc::ast::StringLiteral($s.text);
        $tree->setPosition(new filc::utils::Position($s));
    };

boolean returns[filc::ast::BooleanLiteral *tree]
    : t=TRUE {
        $tree = new filc::ast::BooleanLiteral(true);
        $tree->setPosition(new filc::utils::Position($t));
    }
    | f=FALSE {
        $tree = new filc::ast::BooleanLiteral(false);
        $tree->setPosition(new filc::utils::Position($f));
    };

number returns[filc::ast::AbstractExpression *tree]
    : i=INTEGER {
        $tree = new filc::ast::IntegerLiteral(stoi($i.text));
        $tree->setPosition(new filc::utils::Position($i));
    }
    | f=FLOAT {
        $tree = new filc::ast::FloatLiteral(stod($f.text));
        $tree->setPosition(new filc::utils::Position($f));
    };

variable_declaration returns[filc::ast::VariableDeclaration *tree]
@init {
    bool is_constant = true;
    filc::ast::AbstractExpression *assign = nullptr;
}
@after {
    $tree = new filc::ast::VariableDeclaration(is_constant, new filc::ast::Identifier($i), $t.tree);
    $tree->setPosition(new filc::utils::Position($i));
    if (assign != nullptr) {
        $tree->setAssignation(assign);
    }
}
    : (VAL | VAR {
        is_constant = false;
    }) i=IDENTIFIER COLON t=type (a=assignation {
        assign = $a.tree;
    })?;

assignation returns[filc::ast::AbstractExpression *tree]
    : EQ e=expression {
        $tree = $e.tree;
    };

type returns[filc::ast::AbstractType *tree]
@init {
    filc::ast::AbstractType *previous = nullptr;
}
@after {
    $tree = previous;
}
    : i=IDENTIFIER {
        previous = new filc::ast::Type(new filc::ast::Identifier($i));
    } ((LBRACK it=INTEGER RBRACK {
        int size = stoi($it.text);
        if (size < 0) {
            filc::message::MessageCollector::getCollector()->addError(
                new filc::message::Error(
                    filc::message::ERROR,
                    "Array size must be positive",
                    new filc::utils::Position($it)
                )
            );
        }
        previous = new filc::ast::ArrayType(previous, size);
    }) | STAR {
        previous = new filc::ast::PointerType(previous);
    })*
    | l=lambda_type {
        previous = $l.tree;
    };

unary_calcul returns[filc::ast::UnaryCalcul *tree]
    : i=IDENTIFIER po=post_operator {
        $tree = new filc::ast::PostUnaryCalcul(new filc::ast::Identifier($i), $po.tree);
    }
    | pr=pre_operator i=IDENTIFIER {
        $tree = new filc::ast::PreUnaryCalcul(new filc::ast::Identifier($i), $pr.tree);
    };

post_operator returns[filc::ast::Operator *tree]
@init {
    std::vector<filc::ast::AbstractExpression *> params;
}
    : PLUSPLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUSMINUS);
    }
    | LBRACK e=expression RBRACK {
        $tree = new filc::ast::ArrayOperator($e.tree);
    }
    | LPAREN (fcp=function_call_params {
        params = $fcp.tree;
    })? RPAREN {
        $tree = new filc::ast::FunctionOperator(params);
    };

pre_operator returns[filc::ast::Operator *tree]
    : PLUSPLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUSMINUS);
    }
    | PLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS);
    }
    | MINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUS);
    }
    | REF {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::REF);
    }
    | STAR {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::STAR);
    }
    | NOT {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::NOT);
    };

binary_operator returns[filc::ast::Operator *tree]
    : STAR {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::STAR);
    }
    | DIV {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::DIV);
    }
    | MOD {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MOD);
    }

    | PLUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS);
    }
    | MINUS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUS);
    }

    | FLEFT {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FLEFT);
    }
    | FRIGHT {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FRIGHT);
    }

    | LESS {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LESS);
    }
    | GREATER {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::GREATER);
    }
    | EQEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::EQEQ);
    }
    | LEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LEQ);
    }
    | GEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::GEQ);
    }
    | NEQ {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::NEQ);
    }

    | AND {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::AND);
    }
    | OR {
        $tree = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::OR);
    };

function returns[filc::ast::Function *tree]
    : fd=function_declaration fb=function_body {
        $tree = new filc::ast::Function($fd.identifier, $fd.parameters, $fd.return_type, $fb.tree);
    };

function_declaration returns[filc::ast::Identifier *identifier, std::vector<filc::ast::FunctionParameter *> parameters, filc::ast::AbstractType *return_type]
@init {
    $parameters = std::vector<filc::ast::FunctionParameter *>();
}
    : FUN fi=function_identifier {
        $identifier = $fi.tree;
    } LPAREN (fp=function_parameters {
        $parameters = $fp.tree;
    })? RPAREN ft=function_type {
        $return_type = $ft.tree;
    };

function_identifier returns[filc::ast::Identifier *tree]
    : OPERATOR fo=function_operator {
        $tree = new filc::ast::Identifier("operator" + $fo.text);
    }
    | i=IDENTIFIER {
        $tree = new filc::ast::Identifier($i);
    };

function_operator
    : (LBRACK RBRACK)
    | STAR
    | PLUSPLUS
    | MINUSMINUS
    | REF
    | NOT
    | AND
    | OR
    | LESS
    | GREATER
    | EQEQ
    | LEQ
    | GEQ
    | FLEFT
    | FRIGHT
    | PLUS
    | MINUS
    | DIV
    | MOD
    | (LPAREN RPAREN);

function_parameters returns[std::vector<filc::ast::FunctionParameter *> tree]
@init {
    $tree = std::vector<filc::ast::FunctionParameter *>();
}
    : fp1=function_parameter {
        $tree.push_back($fp1.tree);
    } (COMMA fpi=function_parameter {
        $tree.push_back($fpi.tree);
    })*;

function_parameter returns[filc::ast::FunctionParameter *tree]
    : i=IDENTIFIER COLON t=type {
        $tree = new filc::ast::FunctionParameter(new filc::ast::Identifier($i), $t.tree);
    };

function_type returns[filc::ast::AbstractType *tree]
    : COLON t=type {
        $tree = $t.tree;
    };

function_body returns[std::vector<filc::ast::AbstractExpression *> tree]
    : a=assignation {
        $tree = std::vector<filc::ast::AbstractExpression *>({$a.tree});
    } | pb=parenthesis_body {
        $tree = $pb.tree;
    } | bb=block_body {
        $tree = $bb.tree;
    };

parenthesis_body returns[std::vector<filc::ast::AbstractExpression *> tree]
    : LPAREN e=expression {
        $tree = std::vector<filc::ast::AbstractExpression *>({$e.tree});
    } RPAREN;

block_body returns[std::vector<filc::ast::AbstractExpression *> tree]
@init {
    $tree = std::vector<filc::ast::AbstractExpression *>();
}
    : LBRACE (e=expression {
        $tree.push_back($e.tree);
    })* RBRACE;

lambda returns[filc::ast::Lambda *tree]
@init {
    std::vector<filc::ast::FunctionParameter *> parameters;
    std::vector<filc::ast::AbstractExpression *> body;
}
@after {
    $tree = new filc::ast::Lambda(parameters, $ft.tree, body);
}
    : LPAREN (fp=function_parameters {
        parameters = $fp.tree;
    })? RPAREN ft=function_type ARROW (e=expression {
        body.push_back($e.tree);
    } | pb=parenthesis_body {
        body = $pb.tree;
    } | bb=block_body {
        body = $bb.tree;
    });

lambda_type returns[filc::ast::LambdaType *tree]
@init {
    std::vector<filc::ast::AbstractType *> arguments;
}
@after {
    $tree = new filc::ast::LambdaType(arguments, $t.tree);
}
    : LPAREN (t1=type {
        arguments.push_back($t1.tree);
    } (COMMA ti=type {
        arguments.push_back($ti.tree);
    })*)? RPAREN ARROW t=type;

control returns[filc::ast::AbstractExpression *tree]
    : c=condition {
        $tree = $c.tree;
    } | l=loop {
        $tree = $l.tree;
    };

condition returns[filc::ast::AbstractExpression *tree]
    : i=if_c {
        $tree = $i.tree;
    } | s=switch_c {
        $tree = $s.tree;
    };

if_c returns[filc::ast::If *tree]
    : IF ic=if_condition ib=if_body {
        $tree = new filc::ast::If($ic.tree, $ib.tree);
    } (ELSE (ic2=if_c {
        $tree->setElse($ic2.tree);
    } | ib2=if_body {
        $tree->setElse(new filc::ast::If(new filc::ast::Identifier("true"), $ib2.tree));
    }))?;

if_condition returns[filc::ast::AbstractExpression *tree]
    : LPAREN e=expression {
        $tree = $e.tree;
    } RPAREN;

if_body returns[std::vector<filc::ast::AbstractExpression *> tree]
@init {
    $tree = std::vector<filc::ast::AbstractExpression *>();
}
    : e=expression {
        $tree.push_back($e.tree);
    } | bb=block_body {
        $tree = $bb.tree;
    };

switch_c returns[filc::ast::Switch *tree]
    : SWITCH ic=if_condition sb=switch_body {
        $tree = new filc::ast::Switch($ic.tree, $sb.tree);
    };

switch_body returns[std::vector<filc::ast::SwitchCase *> tree]
@init {
    $tree = std::vector<filc::ast::SwitchCase *>();
}
    : LBRACE (sc=switch_case {
        $tree.push_back($sc.tree);
    })* RBRACE;

switch_case returns[filc::ast::SwitchCase *tree]
@init {
    std::vector<filc::ast::AbstractExpression *> body;
}
@after {
    $tree = new filc::ast::SwitchCase($sp.tree, body);
}
    : sp=switch_pattern ARROW (e=expression {
        body.push_back($e.tree);
    } | pb=parenthesis_body {
        body = $pb.tree;
    } | bb=block_body {
        body = $bb.tree;
    });

switch_pattern returns[filc::ast::AbstractExpression *tree]
    : DEFAULT {
        $tree = new filc::ast::Identifier("default");
    } | l=literal {
        $tree = $l.tree;
    };

loop returns[filc::ast::AbstractExpression *tree]
    : fi=for_i {
        $tree = $fi.tree;
    } | for_iter | while_l;

for_i returns[filc::ast::ForI *tree]
    : FOR fic=for_i_condition ib=if_body {
        $tree = new filc::ast::ForI($fic.declaration, $fic.limit, $fic.iteration, $ib.tree);
    };

for_i_condition returns[filc::ast::VariableDeclaration *declaration, filc::ast::AbstractExpression *limit, filc::ast::AbstractExpression *iteration]
@init {
    $declaration = nullptr;
    $limit = nullptr;
    $iteration = nullptr;
}
    : LPAREN (vd=variable_declaration {
        $declaration = $vd.tree;
    })? SEMI (e1=expression {
        $limit = $e1.tree;
    })? SEMI (e2=expression {
        $iteration = $e2.tree;
    })? RPAREN;

for_iter
    : FOR for_iter_condition if_body;

for_iter_condition
    : LPAREN (VAL | VAR) IDENTIFIER COLON expression RPAREN;

while_l
    : WHILE if_condition if_body;

function_call_params returns[std::vector<filc::ast::AbstractExpression *> tree]
@init {
    $tree = std::vector<filc::ast::AbstractExpression *>();
}
    : e1=expression {
        $tree.push_back($e1.tree);
    } (COMMA ei=expression {
        $tree.push_back($ei.tree);
    })*;
