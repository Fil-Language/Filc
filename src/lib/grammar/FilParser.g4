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
#include <memory>
}

program returns[filc::ast::Program *tree]
@init {
    std::vector<std::string> imports;
    std::vector<filc::ast::AbstractExpression *> expressions;
    bool exported = false;
}
@after {
    $tree = new filc::ast::Program($m.text, imports, expressions);
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

expression returns[filc::ast::AbstractExpression *tree]
@init {
    filc::ast::Operator *op;
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
    | el1=expression STAR er1=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::STAR);
        $tree = new filc::ast::BinaryCalcul($el1.tree, op, $er1.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el1.start));
    }
    | el2=expression DIV er2=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::DIV);
        $tree = new filc::ast::BinaryCalcul($el2.tree, op, $er2.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el2.start));
    }
    | el3=expression MOD er3=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MOD);
        $tree = new filc::ast::BinaryCalcul($el3.tree, op, $er3.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el3.start));
    }
    | el4=expression PLUS er4=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::PLUS);
        $tree = new filc::ast::BinaryCalcul($el4.tree, op, $er4.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el4.start));
    }
    | el5=expression MINUS er5=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::MINUS);
        $tree = new filc::ast::BinaryCalcul($el5.tree, op, $er5.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el5.start));
    }
    | el6=expression FLEFT er6=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FLEFT);
        $tree = new filc::ast::BinaryCalcul($el6.tree, op, $er6.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el6.start));
    }
    | el7=expression FRIGHT er7=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::FRIGHT);
        $tree = new filc::ast::BinaryCalcul($el7.tree, op, $er7.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el7.start));
    }
    | el8=expression LESS er8=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LESS);
        $tree = new filc::ast::BinaryCalcul($el8.tree, op, $er8.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el8.start));
    }
    | el9=expression GREATER er9=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::GREATER);
        $tree = new filc::ast::BinaryCalcul($el9.tree, op, $er9.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el9.start));
    }
    | el10=expression EQEQ er10=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::EQEQ);
        $tree = new filc::ast::BinaryCalcul($el10.tree, op, $er10.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el10.start));
    }
    | el11=expression LEQ er11=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::LEQ);
        $tree = new filc::ast::BinaryCalcul($el11.tree, op, $er11.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el11.start));
    }
    | el12=expression GEQ er12=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::GEQ);
        $tree = new filc::ast::BinaryCalcul($el12.tree, op, $er12.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el12.start));
    }
    | el13=expression NEQ er13=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::NEQ);
        $tree = new filc::ast::BinaryCalcul($el13.tree, op, $er13.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el13.start));
    }
    | el14=expression AND er14=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::AND);
        $tree = new filc::ast::BinaryCalcul($el14.tree, op, $er14.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el14.start));
    }
    | el15=expression OR er15=expression {
        op = new filc::ast::ClassicOperator(filc::ast::ClassicOperator::OR);
        $tree = new filc::ast::BinaryCalcul($el15.tree, op, $er15.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el15.start));
    }
    | el16=expression op16=assignation_operator er16=expression {
        $tree = new filc::ast::BinaryCalcul($el16.tree, $op16.tree, $er16.tree);
        $tree->setPosition(new filc::utils::SimplePosition($el16.start));
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
        $tree = new filc::ast::Identifier($i);
        $tree->setPosition(new filc::utils::SimplePosition($i));
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
        $tree->setPosition(new filc::utils::SimplePosition($c));
    }
    | s=STRING {
        $tree = new filc::ast::StringLiteral($s.text);
        $tree->setPosition(new filc::utils::SimplePosition($s));
    };

boolean returns[filc::ast::BooleanLiteral *tree]
    : t=TRUE {
        $tree = new filc::ast::BooleanLiteral(true);
        $tree->setPosition(new filc::utils::SimplePosition($t));
    }
    | f=FALSE {
        $tree = new filc::ast::BooleanLiteral(false);
        $tree->setPosition(new filc::utils::SimplePosition($f));
    };

number returns[filc::ast::AbstractExpression *tree]
    : i=INTEGER {
        $tree = new filc::ast::IntegerLiteral(stoi($i.text));
        $tree->setPosition(new filc::utils::SimplePosition($i));
    }
    | f=FLOAT {
        $tree = new filc::ast::FloatLiteral(stod($f.text), false);
        $tree->setPosition(new filc::utils::SimplePosition($f));
    }
    | d=DOUBLE {
        $tree = new filc::ast::FloatLiteral(stod($d.text), true);
        $tree->setPosition(new filc::utils::SimplePosition($d));
    };

variable_declaration returns[filc::ast::VariableDeclaration *tree]
@init {
    bool is_constant = true;
    filc::ast::AbstractExpression *assign = nullptr;
}
@after {
    $tree = new filc::ast::VariableDeclaration(is_constant, new filc::ast::Identifier($i), $t.tree);
    $tree->setPosition(new filc::utils::SimplePosition($i));
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

type returns[std::shared_ptr<filc::ast::AbstractType> tree]
@init {
    std::shared_ptr<filc::ast::AbstractType> previous = nullptr;
}
@after {
    $tree = previous;
}
    : i=IDENTIFIER {
        previous = std::shared_ptr<filc::ast::AbstractType>(new filc::ast::Type(new filc::ast::Identifier($i)));
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
        previous = std::shared_ptr<filc::ast::AbstractType>(new filc::ast::ArrayType(previous, size));
    }) | STAR {
        previous = std::shared_ptr<filc::ast::AbstractType>(new filc::ast::PointerType(previous));
    })*
    | l=lambda_type {
        previous = $l.tree;
    };

unary_calcul returns[filc::ast::UnaryCalcul *tree]
    : i=IDENTIFIER po=post_operator {
        $tree = new filc::ast::PostUnaryCalcul(new filc::ast::Identifier($i), $po.tree);
        $tree->setPosition(new filc::utils::SimplePosition($i));
    }
    | pr=pre_operator i=IDENTIFIER {
        $tree = new filc::ast::PreUnaryCalcul(new filc::ast::Identifier($i), $pr.tree);
        $tree->setPosition(new filc::utils::SimplePosition($pr.start));
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

assignation_operator returns[filc::ast::AssignationOperator *tree]
@init {
    filc::ast::Operator *op = nullptr;
}
    : (cbo=classic_binary_operator {
        op = $cbo.tree;
    })? EQ {
        $tree = new filc::ast::AssignationOperator(op);
    };

classic_binary_operator returns[filc::ast::Operator *tree]
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
    };

function returns[filc::ast::Function *tree]
    : fd=function_declaration fb=function_body {
        $tree = new filc::ast::Function($fd.identifier, $fd.parameters, $fd.return_type, $fb.tree);
        $tree->setPosition(new filc::utils::SimplePosition($fd.start));
    };

function_declaration returns[filc::ast::Identifier *identifier, std::vector<filc::ast::FunctionParameter *> parameters, std::shared_ptr<filc::ast::AbstractType> return_type]
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
    : o=OPERATOR fo=function_operator {
        $tree = new filc::ast::Identifier("operator" + $fo.text);
        $tree->setPosition(new filc::utils::SimplePosition($o));
    }
    | i=IDENTIFIER {
        $tree = new filc::ast::Identifier($i);
        $tree->setPosition(new filc::utils::SimplePosition($i));
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

function_type returns[std::shared_ptr<filc::ast::AbstractType> tree]
    : COLON t=type {
        $tree = $t.tree;
    };

function_body returns[filc::ast::BlockBody *tree]
    : a=assignation {
        $tree = new filc::ast::BlockBody({$a.tree});
    } | pb=parenthesis_body {
        $tree = $pb.tree;
    } | bb=block_body {
        $tree = $bb.tree;
    };

parenthesis_body returns[filc::ast::BlockBody *tree]
    : LPAREN e=expression {
        $tree = new filc::ast::BlockBody({$e.tree});
    } RPAREN;

block_body returns[filc::ast::BlockBody *tree]
@init {
    auto expressions = std::vector<filc::ast::AbstractExpression *>();
}
@after {
    $tree = new filc::ast::BlockBody(expressions);
}
    : LBRACE (e=expression {
        expressions.push_back($e.tree);
    })* RBRACE;

lambda returns[filc::ast::Lambda *tree]
@init {
    std::vector<filc::ast::FunctionParameter *> parameters;
    filc::ast::BlockBody *body;
}
@after {
    $tree = new filc::ast::Lambda(parameters, $ft.tree, body);
    $tree->setPosition(new filc::utils::SimplePosition($lp));
}
    : lp=LPAREN (fp=function_parameters {
        parameters = $fp.tree;
    })? RPAREN ft=function_type ARROW (e=expression {
        body = new filc::ast::BlockBody({$e.tree});
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
    : i=IF ic=if_condition ib=if_body {
        $tree = new filc::ast::If($ic.tree, $ib.tree);
        $tree->setPosition(new filc::utils::SimplePosition($i));
    } (ELSE (ic2=if_c {
        $tree->setElse($ic2.tree);
    } | ib2=if_body {
        auto *else_body = new filc::ast::If(new filc::ast::Identifier("true"), $ib2.tree);
        $tree->setPosition(new filc::utils::SimplePosition($ib2.start));
        $tree->setElse(else_body);
    }))?;

if_condition returns[filc::ast::AbstractExpression *tree]
    : LPAREN e=expression {
        $tree = $e.tree;
    } RPAREN;

if_body returns[filc::ast::BlockBody *tree]
    : e=expression {
        $tree = new filc::ast::BlockBody({$e.tree});
    } | bb=block_body {
        $tree = $bb.tree;
    };

switch_c returns[filc::ast::Switch *tree]
    : s=SWITCH ic=if_condition sb=switch_body {
        $tree = new filc::ast::Switch($ic.tree, $sb.tree);
        $tree->setPosition(new filc::utils::SimplePosition($s));
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
    filc::ast::BlockBody *body;
}
@after {
    $tree = new filc::ast::SwitchCase($sp.tree, body);
    $tree->setPosition(new filc::utils::SimplePosition($sp.start));
}
    : sp=switch_pattern ARROW (pb=parenthesis_body {
        body = $pb.tree;
    } | bb=block_body {
        body = $bb.tree;
    } | e=expression {
        body = new filc::ast::BlockBody({$e.tree});
    });

switch_pattern returns[filc::ast::AbstractExpression *tree]
    : d=DEFAULT {
        $tree = new filc::ast::Identifier("default");
        $tree->setPosition(new filc::utils::SimplePosition($d));
    } | l=literal {
        $tree = $l.tree;
    };

loop returns[filc::ast::AbstractExpression *tree]
    : fi=for_i {
        $tree = $fi.tree;
    } | fit=for_iter {
        $tree = $fit.tree;
    } | w=while_l {
        $tree = $w.tree;
    };

for_i returns[filc::ast::ForI *tree]
    : f=FOR fic=for_i_condition ib=if_body {
        $tree = new filc::ast::ForI($fic.declaration, $fic.limit, $fic.iteration, $ib.tree);
        $tree->setPosition(new filc::utils::SimplePosition($f));
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

for_iter returns[filc::ast::ForIter *tree]
    : f=FOR fic=for_iter_condition ib=if_body {
        $tree = new filc::ast::ForIter($fic.constant, $fic.identifier, $fic.array, $ib.tree);
        $tree->setPosition(new filc::utils::SimplePosition($f));
    };

for_iter_condition returns[bool constant, filc::ast::Identifier *identifier, filc::ast::AbstractExpression *array]
@init {
    $constant = true;
}
    : LPAREN (VAL | VAR {
        $constant = false;
    }) i=IDENTIFIER {
        $identifier = new filc::ast::Identifier($i);
        $identifier->setPosition(new filc::utils::SimplePosition($i));
    } COLON e=expression {
        $array = $e.tree;
    } RPAREN;

while_l returns[filc::ast::While *tree]
    : w=WHILE ic=if_condition ib=if_body {
        $tree = new filc::ast::While($ic.tree, $ib.tree);
        $tree->setPosition(new filc::utils::SimplePosition($w));
    };

function_call_params returns[std::vector<filc::ast::AbstractExpression *> tree]
@init {
    $tree = std::vector<filc::ast::AbstractExpression *>();
}
    : e1=expression {
        $tree.push_back($e1.tree);
    } (COMMA ei=expression {
        $tree.push_back($ei.tree);
    })*;