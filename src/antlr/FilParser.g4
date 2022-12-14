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

@parser::members {}

prog : EOF;