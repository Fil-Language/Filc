
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
    IDENTIFIER = 26, DOT = 27, ARROW = 28, LBRACE = 29, RBRACE = 30, LPAREN = 31, 
    RPAREN = 32, LBRAK = 33, RBRAK = 34, COLON = 35, COMMA = 36, SEMICOLON = 37, 
    EQ = 38, PLUS = 39, MINUS = 40, DIVIDE = 41, TIMES = 42, MOD = 43, FLEFT = 44, 
    FRIGHT = 45, AND = 46, OR = 47, LE = 48, GE = 49, EQEQ = 50, LEQ = 51, 
    GEQ = 52, NEQ = 53, BAND = 54, BOR = 55, BXOR = 56, INT = 57, FLOAT = 58, 
    STRING = 59, COMMENT = 60, COMMENT_BLOCK = 61, SEPARATOR = 62, IMPORT = 63
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

