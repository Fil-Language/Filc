
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilLexer.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcppfil {


class  FilLexer : public antlr4::Lexer {
public:
  enum {
    EXPORT = 1, FUN = 2, INTERFACE = 3, CLASS = 4, ABSTRACT = 5, OVERRIDE = 6, 
    OPEN = 7, PRIVATE = 8, PUBLIC = 9, INTERNAL = 10, PROTECTED = 11, CONSTRUCTOR = 12, 
    ENUM = 13, IF = 14, ELSE = 15, SWITCH = 16, DEFAULT = 17, FOR = 18, 
    VAL = 19, VAR = 20, WHILE = 21, TRY = 22, CATCH = 23, TRUE = 24, FALSE = 25, 
    NULL_ = 26, NEW = 27, OPERATOR = 28, IDENTIFIER = 29, DOT = 30, ARROW = 31, 
    LBRACE = 32, RBRACE = 33, LPAREN = 34, RPAREN = 35, LBRAK = 36, RBRAK = 37, 
    COLON = 38, COMMA = 39, SEMICOLON = 40, EQ = 41, PLUS = 42, MINUS = 43, 
    DIVIDE = 44, TIMES = 45, MOD = 46, FLEFT = 47, FRIGHT = 48, AND = 49, 
    OR = 50, LT = 51, GT = 52, EQEQ = 53, LEQ = 54, GEQ = 55, NEQ = 56, 
    NOT = 57, BAND = 58, BOR = 59, BXOR = 60, INT = 61, FLOAT = 62, STRING = 63, 
    FSTRING = 64, CHAR = 65, COMMENT = 66, COMMENT_BLOCK = 67, SEPARATOR = 68, 
    MODULE = 69, IMPORT = 70
  };

  explicit FilLexer(antlr4::CharStream *input);

  ~FilLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);
  void FSTRINGAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace antlrcppfil
