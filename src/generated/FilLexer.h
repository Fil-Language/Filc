
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilLexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  FilLexer : public antlr4::Lexer {
public:
  enum {
    EXPORT = 1, MODULE = 2, FUN = 3, INTERFACE = 4, CLASS = 5, ABSTRACT = 6, 
    OPEN = 7, PRIVATE = 8, PUBLIC = 9, INTERNAL = 10, PROTECTED = 11, CONSTRUCTOR = 12, 
    ENUM = 13, IF = 14, ELSE = 15, SWITCH = 16, DEFAULT = 17, FOR = 18, 
    VAL = 19, VAR = 20, WHILE = 21, TRY = 22, CATCH = 23, TRUE = 24, FALSE = 25, 
    NULL = 26, IDENTIFIER = 27, DOT = 28, ARROW = 29, LBRACE = 30, RBRACE = 31, 
    LPAREN = 32, RPAREN = 33, LBRAK = 34, RBRAK = 35, COLON = 36, COMMA = 37, 
    SEMICOLON = 38, EQ = 39, PLUS = 40, MINUS = 41, DIVIDE = 42, TIMES = 43, 
    MOD = 44, FLEFT = 45, FRIGHT = 46, AND = 47, OR = 48, LE = 49, GE = 50, 
    EQEQ = 51, LEQ = 52, GEQ = 53, NEQ = 54, NOT = 55, BAND = 56, BOR = 57, 
    BXOR = 58, INT = 59, FLOAT = 60, STRING = 61, CHAR = 62, COMMENT = 63, 
    COMMENT_BLOCK = 64, SEPARATOR = 65, MODULE_NAME = 66, IMPORT = 67
  };

  FilLexer(antlr4::CharStream *input);
  ~FilLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);
  void IMPORTAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

