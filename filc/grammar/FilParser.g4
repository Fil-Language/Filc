/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */
parser grammar FilParser;

options {
	tokenVocab = FilLexer;
}

@parser::header {}

@parser::preinclude {}

@parser::postinclude {}

@parser::context {}

@parser::members {}

@parser::declarations {}

@parser::definitions {}

@parser::listenerpreinclude {}
@parser::listenerpostinclude {}
@parser::listenerdeclarations {}
@parser::listenermembers {}
@parser::listenerdefinitions {}

@parser::baselistenerpreinclude {}
@parser::baselistenerpostinclude {}
@parser::baselistenerdeclarations {}
@parser::baselistenermembers {}
@parser::baselistenerdefinitions {}

@parser::visitorpreinclude {}
@parser::visitorpostinclude {}
@parser::visitordeclarations {}
@parser::visitormembers {}
@parser::visitordefinitions {}

@parser::basevisitorpreinclude {}
@parser::basevisitorpostinclude {}
@parser::basevisitordeclarations {}
@parser::basevisitormembers {}
@parser::basevisitordefinitions {}

main:
    EOF;