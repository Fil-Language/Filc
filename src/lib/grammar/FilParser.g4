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
#include "AbstractExpression.h"
#include "Body.h"
#include "Calcul.h"
#include "Condition.h"
#include "Function.h"
#include "Identifier.h"
#include "Literal.h"
#include "Loop.h"
#include "Operator.h"
#include "Program.h"
#include "Type.h"
#include "VariableDeclaration.h"
#include "MessageCollector.h"
#include "Error.h"
#include <string>
#include <vector>
#include <memory>
}

program returns[std::shared_ptr<filc::ast::Program> tree]
@init {
    std::vector<std::string> imports;
    std::vector<std::shared_ptr<filc::ast::AbstractExpression>> expressions;
    bool exported = false;
}
@after {
    $tree = std::make_shared<filc::ast::Program>($m.text, imports, expressions);
}
    : m=module (u=use {
        imports.push_back($u.text);
    })* ((EXPORT {
        exported = true;
    })? e=expression {
        auto e = $e.tree;
        if (e != nullptr) {
            e->setExported(exported);
            expressions.push_back(e);
        }
        exported = false;
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

expression returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
@init {
    std::shared_ptr<filc::ast::Operator> op;
}
    : l=literal {
        $tree = $l.tree;
    }
    | v=variable_declaration {
        $tree = $v.tree;
    }
    | u=unary_calcul {
        $tree = $u.tree;
    }

    // ==== Binary calcul ====
    | el1=expression op1=assignation_operator er1=expression {
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el1.tree, $op1.tree, $er1.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el1.start, $er1.stop));
    }
    | el2=expression op2=(AND | OR) er2=expression {
        op = std::make_shared<filc::ast::ClassicOperator>($op2.text);
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el2.tree, op, $er2.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el2.start, $er2.stop));
    }
    | el3=expression op3=(LESS | GREATER | EQEQ | LEQ | GEQ | NEQ) er3=expression {
        op = std::make_shared<filc::ast::ClassicOperator>($op3.text);
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el3.tree, op, $er3.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el3.start, $er3.stop));
    }
    | el4=expression MOD er4=expression {
        op = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::MOD);
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el4.tree, op, $er4.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el4.start, $er4.stop));
    }
    | el5=expression op5=(STAR | DIV) er5=expression {
        op = std::make_shared<filc::ast::ClassicOperator>($op5.text);
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el5.tree, op, $er5.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el5.start, $er5.stop));
    }
    | el6=expression op6=(PLUS | MINUS) er6=expression {
        op = std::make_shared<filc::ast::ClassicOperator>($op6.text);
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el6.tree, op, $er6.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el6.start, $er6.stop));
    }
    | el7=expression op7=(FLEFT | FRIGHT) er7=expression {
        op = std::make_shared<filc::ast::ClassicOperator>($op7.text);
        $tree = std::make_shared<filc::ast::BinaryCalcul>($el7.tree, op, $er7.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($el7.start, $er7.stop));
    }
    // ==== Binary calcul ====

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
        $tree = $p.tree;
    }
    | i=IDENTIFIER {
        $tree = std::make_shared<filc::ast::Identifier>($i);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($i));
    };

literal returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : b=boolean {
        $tree = $b.tree;
    }
    | n=number {
        $tree = $n.tree;
    }
    | c=CHARACTER {
        $tree = std::make_shared<filc::ast::CharacterLiteral>(
            filc::ast::CharacterLiteral::stringToChar($c.text, $c)
        );
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($c));
    }
    | s=STRING {
        $tree = std::make_shared<filc::ast::StringLiteral>($s.text);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($s));
    };

boolean returns[std::shared_ptr<filc::ast::BooleanLiteral> tree]
    : t=TRUE {
        $tree = std::make_shared<filc::ast::BooleanLiteral>(true);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($t));
    }
    | f=FALSE {
        $tree = std::make_shared<filc::ast::BooleanLiteral>(false);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($f));
    };

number returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : i=INTEGER {
        $tree = std::make_shared<filc::ast::IntegerLiteral>(stoi($i.text));
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($i));
    }
    | f=FLOAT {
        $tree = std::make_shared<filc::ast::FloatLiteral>(stod($f.text), false);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($f));
    }
    | d=DOUBLE {
        $tree = std::make_shared<filc::ast::FloatLiteral>(stod($d.text), true);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($d));
    };

variable_declaration returns[std::shared_ptr<filc::ast::VariableDeclaration> tree]
@init {
    bool is_constant = true;
    std::shared_ptr<filc::ast::AbstractExpression> assign;
}
@after {
    $tree = std::make_shared<filc::ast::VariableDeclaration>(is_constant, std::make_shared<filc::ast::Identifier>($i), $t.tree);
    $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($i, $a.stop));
    if (assign != nullptr) {
        $tree->setAssignation(assign);
    }
}
    : (VAL | VAR {
        is_constant = false;
    }) i=IDENTIFIER COLON t=type (a=assignation {
        assign = $a.tree;
    })?;

assignation returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : EQ e=expression {
        $tree = $e.tree;
    };

type returns[std::shared_ptr<filc::ast::AbstractType> tree]
@init {
    std::shared_ptr<filc::ast::AbstractType> previous = nullptr;
}
@after {
    $tree = previous;
}
    : i=IDENTIFIER {
        previous = std::make_shared<filc::ast::Type>(std::make_shared<filc::ast::Identifier>($i));
    } ((LBRACK it=INTEGER RBRACK {
        int size = stoi($it.text);
        if (size < 0) {
            filc::message::MessageCollector::getCollector()->addError(
                new filc::message::Error(
                    filc::message::ERROR,
                    "Array size must be positive",
                    new filc::utils::SimplePosition($it)
                )
            );
        }
        previous = std::make_shared<filc::ast::ArrayType>(previous, size);
    }) | STAR {
        previous = std::make_shared<filc::ast::PointerType>(previous);
    })*
    | l=lambda_type {
        previous = $l.tree;
    };

unary_calcul returns[std::shared_ptr<filc::ast::UnaryCalcul> tree]
    : i=IDENTIFIER po=post_operator {
        $tree = std::make_shared<filc::ast::PostUnaryCalcul>(std::make_shared<filc::ast::Identifier>($i), $po.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($i, $po.stop));
    }
    | pr=pre_operator i=IDENTIFIER {
        $tree = std::make_shared<filc::ast::PreUnaryCalcul>(std::make_shared<filc::ast::Identifier>($i), $pr.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($pr.start, $i));
    };

post_operator returns[std::shared_ptr<filc::ast::Operator> tree]
@init {
    std::vector<std::shared_ptr<filc::ast::AbstractExpression>> params;
}
    : PLUSPLUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::MINUSMINUS);
    }
    | LBRACK e=expression RBRACK {
        $tree = std::make_shared<filc::ast::ArrayOperator>($e.tree);
    }
    | LPAREN (fcp=function_call_params {
        params = $fcp.tree;
    })? RPAREN {
        $tree = std::make_shared<filc::ast::FunctionOperator>(params);
    };

pre_operator returns[std::shared_ptr<filc::ast::Operator> tree]
    : PLUSPLUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::PLUSPLUS);
    }
    | MINUSMINUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::MINUSMINUS);
    }
    | PLUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::PLUS);
    }
    | MINUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::MINUS);
    }
    | REF {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::REF);
    }
    | STAR {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::STAR);
    }
    | NOT {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::NOT);
    };

assignation_operator returns[std::shared_ptr<filc::ast::AssignationOperator> tree]
@init {
    std::shared_ptr<filc::ast::Operator> op;
}
    : (cbo=classic_binary_operator {
        op = $cbo.tree;
    })? EQ {
        $tree = std::make_shared<filc::ast::AssignationOperator>(op);
    };

classic_binary_operator returns[std::shared_ptr<filc::ast::Operator> tree]
    : STAR {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::STAR);
    }
    | DIV {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::DIV);
    }
    | MOD {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::MOD);
    }

    | PLUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::PLUS);
    }
    | MINUS {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::MINUS);
    }

    | FLEFT {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::FLEFT);
    }
    | FRIGHT {
        $tree = std::make_shared<filc::ast::ClassicOperator>(filc::ast::ClassicOperator::FRIGHT);
    };

function returns[std::shared_ptr<filc::ast::Function> tree]
    : fd=function_declaration fb=function_body {
        $tree = std::make_shared<filc::ast::Function>($fd.identifier, $fd.parameters, $fd.return_type, $fb.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($fd.start, $fb.stop));
    };

function_declaration returns[std::shared_ptr<filc::ast::Identifier> identifier, std::vector<std::shared_ptr<filc::ast::FunctionParameter>> parameters, std::shared_ptr<filc::ast::AbstractType> return_type]
@init {
    $parameters = std::vector<std::shared_ptr<filc::ast::FunctionParameter>>();
}
    : FUN fi=function_identifier {
        $identifier = $fi.tree;
    } LPAREN (fp=function_parameters {
        $parameters = $fp.tree;
    })? RPAREN ft=function_type {
        $return_type = $ft.tree;
    };

function_identifier returns[std::shared_ptr<filc::ast::Identifier> tree]
    : o=OPERATOR fo=function_operator {
        $tree = std::make_shared<filc::ast::Identifier>("operator" + $fo.text);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($o));
    }
    | i=IDENTIFIER {
        $tree = std::make_shared<filc::ast::Identifier>($i);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($i));
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

function_parameters returns[std::vector<std::shared_ptr<filc::ast::FunctionParameter>> tree]
@init {
    $tree = std::vector<std::shared_ptr<filc::ast::FunctionParameter>>();
}
    : fp1=function_parameter {
        $tree.push_back($fp1.tree);
    } (COMMA fpi=function_parameter {
        $tree.push_back($fpi.tree);
    })*;

function_parameter returns[std::shared_ptr<filc::ast::FunctionParameter> tree]
    : i=IDENTIFIER COLON t=type {
        $tree = std::make_shared<filc::ast::FunctionParameter>(std::make_shared<filc::ast::Identifier>($i), $t.tree);
    };

function_type returns[std::shared_ptr<filc::ast::AbstractType> tree]
    : COLON t=type {
        $tree = $t.tree;
    };

function_body returns[std::shared_ptr<filc::ast::BlockBody> tree]
    : a=assignation {
        $tree = std::shared_ptr<filc::ast::BlockBody>(new filc::ast::BlockBody({$a.tree}));
    } | pb=parenthesis_body {
        $tree = $pb.tree;
    } | bb=block_body {
        $tree = $bb.tree;
    };

parenthesis_body returns[std::shared_ptr<filc::ast::BlockBody> tree]
    : LPAREN e=expression {
        $tree = std::shared_ptr<filc::ast::BlockBody>(new filc::ast::BlockBody({$e.tree}));
    } RPAREN;

block_body returns[std::shared_ptr<filc::ast::BlockBody> tree]
@init {
    auto expressions = std::vector<std::shared_ptr<filc::ast::AbstractExpression>>();
}
@after {
    $tree = std::make_shared<filc::ast::BlockBody>(expressions);
}
    : LBRACE (e=expression {
        expressions.push_back($e.tree);
    })* RBRACE;

lambda returns[std::shared_ptr<filc::ast::Lambda> tree]
@init {
    std::vector<std::shared_ptr<filc::ast::FunctionParameter>> parameters;
    std::shared_ptr<filc::ast::BlockBody> body;
}
@after {
    $tree = std::make_shared<filc::ast::Lambda>(parameters, $ft.tree, body);
    $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($lp));
}
    : lp=LPAREN (fp=function_parameters {
        parameters = $fp.tree;
    })? RPAREN ft=function_type ARROW (e=expression {
        body = std::shared_ptr<filc::ast::BlockBody>(new filc::ast::BlockBody({$e.tree}));
    } | pb=parenthesis_body {
        body = $pb.tree;
    } | bb=block_body {
        body = $bb.tree;
    });

lambda_type returns[std::shared_ptr<filc::ast::LambdaType> tree]
@init {
    std::vector<std::shared_ptr<filc::ast::AbstractType>> arguments;
}
@after {
    $tree = std::make_shared<filc::ast::LambdaType>(arguments, $t.tree);
}
    : LPAREN (t1=type {
        arguments.push_back($t1.tree);
    } (COMMA ti=type {
        arguments.push_back($ti.tree);
    })*)? RPAREN ARROW t=type;

control returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : c=condition {
        $tree = $c.tree;
    } | l=loop {
        $tree = $l.tree;
    };

condition returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : i=if_c {
        $tree = $i.tree;
    } | s=match_c {
        $tree = $s.tree;
    };

if_c returns[std::shared_ptr<filc::ast::If> tree]
    : i=IF ic=if_condition ib=if_body {
        $tree = std::make_shared<filc::ast::If>($ic.tree, $ib.tree);
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($i));
    } (ELSE eb=if_body {
        $tree->setElse($eb.tree);
    })?;

if_condition returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : LPAREN e=expression {
        $tree = $e.tree;
    } RPAREN;

if_body returns[std::shared_ptr<filc::ast::BlockBody> tree]
    : e=expression {
        $tree = std::shared_ptr<filc::ast::BlockBody>(new filc::ast::BlockBody({$e.tree}));
    } | bb=block_body {
        $tree = $bb.tree;
    };

match_c returns[std::shared_ptr<filc::ast::Match> tree]
    : m=MATCH ic=if_condition mb=match_body {
        $tree = std::make_shared<filc::ast::Match>($ic.tree, $mb.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($m, $mb.stop));
    };

match_body returns[std::vector<std::shared_ptr<filc::ast::MatchCase>> tree]
@init {
    $tree = std::vector<std::shared_ptr<filc::ast::MatchCase>>();
}
    : LBRACE (mc=match_case {
        $tree.push_back($mc.tree);
    })* RBRACE;

match_case returns[std::shared_ptr<filc::ast::MatchCase> tree]
@init {
    std::shared_ptr<filc::ast::BlockBody> body;
}
@after {
    $tree = std::make_shared<filc::ast::MatchCase>($mp.tree, body);
    $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($mp.start));
}
    : mp=match_pattern ARROW (pb=parenthesis_body {
        body = $pb.tree;
    } | bb=block_body {
        body = $bb.tree;
    } | e=expression {
        body = std::shared_ptr<filc::ast::BlockBody>(new filc::ast::BlockBody({$e.tree}));
    });

match_pattern returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : u=UNDERSCORE {
        $tree = std::make_shared<filc::ast::Identifier>("_");
        $tree->setPosition(std::make_shared<filc::utils::SimplePosition>($u));
    } | l=literal {
        $tree = $l.tree;
    };

loop returns[std::shared_ptr<filc::ast::AbstractExpression> tree]
    : fi=for_i {
        $tree = $fi.tree;
    } | fit=for_iter {
        $tree = $fit.tree;
    } | w=while_l {
        $tree = $w.tree;
    };

for_i returns[std::shared_ptr<filc::ast::ForI> tree]
    : f=FOR fic=for_i_condition ib=if_body {
        $tree = std::make_shared<filc::ast::ForI>($fic.declaration, $fic.limit, $fic.iteration, $ib.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($f, $ib.stop));
    };

for_i_condition returns[std::shared_ptr<filc::ast::VariableDeclaration> declaration, std::shared_ptr<filc::ast::AbstractExpression> limit, std::shared_ptr<filc::ast::AbstractExpression> iteration]
    : LPAREN (vd=variable_declaration {
        $declaration = $vd.tree;
    })? SEMI (e1=expression {
        $limit = $e1.tree;
    })? SEMI (e2=expression {
        $iteration = $e2.tree;
    })? RPAREN;

for_iter returns[std::shared_ptr<filc::ast::ForIter> tree]
    : f=FOR fic=for_iter_condition ib=if_body {
        $tree = std::make_shared<filc::ast::ForIter>($fic.constant, $fic.identifier, $fic.array, $ib.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($f, $ib.stop));
    };

for_iter_condition returns[bool constant, std::shared_ptr<filc::ast::Identifier> identifier, std::shared_ptr<filc::ast::AbstractExpression> array]
@init {
    $constant = true;
}
    : LPAREN (VAL | VAR {
        $constant = false;
    }) i=IDENTIFIER {
        $identifier = std::make_shared<filc::ast::Identifier>($i);
        $identifier->setPosition(std::make_shared<filc::utils::SimplePosition>($i));
    } COLON e=expression {
        $array = $e.tree;
    } RPAREN;

while_l returns[std::shared_ptr<filc::ast::While> tree]
    : w=WHILE ic=if_condition ib=if_body {
        $tree = std::make_shared<filc::ast::While>($ic.tree, $ib.tree);
        $tree->setPosition(std::make_shared<filc::utils::DoublePosition>($w, $ib.stop));
    };

function_call_params returns[std::vector<std::shared_ptr<filc::ast::AbstractExpression>> tree]
@init {
    $tree = std::vector<std::shared_ptr<filc::ast::AbstractExpression>>();
}
    : e1=expression {
        $tree.push_back($e1.tree);
    } (COMMA ei=expression {
        $tree.push_back($ei.tree);
    })*;