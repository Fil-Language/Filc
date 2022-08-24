
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.8


#include "FilParserVisitor.h"

#include "FilParser.h"


using namespace antlrcpp;
using namespace antlr4;

FilParser::FilParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FilParser::~FilParser() {
  delete _interpreter;
}

std::string FilParser::getGrammarFileName() const {
  return "FilParser.g4";
}

const std::vector<std::string>& FilParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FilParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

FilParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::ModuleContext* FilParser::ProgramContext::module() {
  return getRuleContext<FilParser::ModuleContext>(0);
}

std::vector<FilParser::Import_Context *> FilParser::ProgramContext::import_() {
  return getRuleContexts<FilParser::Import_Context>();
}

FilParser::Import_Context* FilParser::ProgramContext::import_(size_t i) {
  return getRuleContext<FilParser::Import_Context>(i);
}

std::vector<FilParser::ExprContext *> FilParser::ProgramContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::ProgramContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}


size_t FilParser::ProgramContext::getRuleIndex() const {
  return FilParser::RuleProgram;
}


antlrcpp::Any FilParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ProgramContext* FilParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, FilParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    module();
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::IMPORT) {
      setState(123);
      import_();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::FUN)
      | (1ULL << FilParser::INTERFACE)
      | (1ULL << FilParser::ABSTRACT)
      | (1ULL << FilParser::OPEN)
      | (1ULL << FilParser::ENUM)
      | (1ULL << FilParser::IF)
      | (1ULL << FilParser::SWITCH)
      | (1ULL << FilParser::FOR)
      | (1ULL << FilParser::VAL)
      | (1ULL << FilParser::VAR)
      | (1ULL << FilParser::WHILE)
      | (1ULL << FilParser::TRY)
      | (1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::IDENTIFIER)
      | (1ULL << FilParser::LPAREN)
      | (1ULL << FilParser::LBRAK)
      | (1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::NOT)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0)) {
      setState(129);
      expr(0);
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleContext ------------------------------------------------------------------

FilParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ModuleContext::MODULE() {
  return getToken(FilParser::MODULE, 0);
}

tree::TerminalNode* FilParser::ModuleContext::MODULE_NAME() {
  return getToken(FilParser::MODULE_NAME, 0);
}


size_t FilParser::ModuleContext::getRuleIndex() const {
  return FilParser::RuleModule;
}


antlrcpp::Any FilParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ModuleContext* FilParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 2, FilParser::RuleModule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(FilParser::MODULE);
    setState(136);
    match(FilParser::MODULE_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_Context ------------------------------------------------------------------

FilParser::Import_Context::Import_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Import_Context::IMPORT() {
  return getToken(FilParser::IMPORT, 0);
}

tree::TerminalNode* FilParser::Import_Context::MODULE_NAME() {
  return getToken(FilParser::MODULE_NAME, 0);
}


size_t FilParser::Import_Context::getRuleIndex() const {
  return FilParser::RuleImport_;
}


antlrcpp::Any FilParser::Import_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitImport_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Import_Context* FilParser::import_() {
  Import_Context *_localctx = _tracker.createInstance<Import_Context>(_ctx, getState());
  enterRule(_localctx, 4, FilParser::RuleImport_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(FilParser::IMPORT);
    setState(139);
    match(FilParser::MODULE_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FilParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::FunctionContext* FilParser::ExprContext::function() {
  return getRuleContext<FilParser::FunctionContext>(0);
}

FilParser::LambdaContext* FilParser::ExprContext::lambda() {
  return getRuleContext<FilParser::LambdaContext>(0);
}

FilParser::InterfaceContext* FilParser::ExprContext::interface() {
  return getRuleContext<FilParser::InterfaceContext>(0);
}

FilParser::Class_Context* FilParser::ExprContext::class_() {
  return getRuleContext<FilParser::Class_Context>(0);
}

FilParser::Enum_Context* FilParser::ExprContext::enum_() {
  return getRuleContext<FilParser::Enum_Context>(0);
}

FilParser::ConditionContext* FilParser::ExprContext::condition() {
  return getRuleContext<FilParser::ConditionContext>(0);
}

FilParser::LoopContext* FilParser::ExprContext::loop() {
  return getRuleContext<FilParser::LoopContext>(0);
}

FilParser::ExceptionContext* FilParser::ExprContext::exception() {
  return getRuleContext<FilParser::ExceptionContext>(0);
}

FilParser::Unary_calculContext* FilParser::ExprContext::unary_calcul() {
  return getRuleContext<FilParser::Unary_calculContext>(0);
}

FilParser::CastContext* FilParser::ExprContext::cast() {
  return getRuleContext<FilParser::CastContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Function_callContext* FilParser::ExprContext::function_call() {
  return getRuleContext<FilParser::Function_callContext>(0);
}

FilParser::LitteralContext* FilParser::ExprContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}

FilParser::Variable_declContext* FilParser::ExprContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::ExprContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

FilParser::Expr_blockContext* FilParser::ExprContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

std::vector<FilParser::ExprContext *> FilParser::ExprContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::ExprContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

FilParser::Binary_operatorContext* FilParser::ExprContext::binary_operator() {
  return getRuleContext<FilParser::Binary_operatorContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::DOT() {
  return getToken(FilParser::DOT, 0);
}

tree::TerminalNode* FilParser::ExprContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::AssignationContext* FilParser::ExprContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}


size_t FilParser::ExprContext::getRuleIndex() const {
  return FilParser::RuleExpr;
}


antlrcpp::Any FilParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


FilParser::ExprContext* FilParser::expr() {
   return expr(0);
}

FilParser::ExprContext* FilParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FilParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FilParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, FilParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(142);
      function();
      break;
    }

    case 2: {
      setState(143);
      lambda();
      break;
    }

    case 3: {
      setState(144);
      interface();
      break;
    }

    case 4: {
      setState(145);
      class_();
      break;
    }

    case 5: {
      setState(146);
      enum_();
      break;
    }

    case 6: {
      setState(147);
      condition();
      break;
    }

    case 7: {
      setState(148);
      loop();
      break;
    }

    case 8: {
      setState(149);
      exception();
      break;
    }

    case 9: {
      setState(150);
      unary_calcul();
      break;
    }

    case 10: {
      setState(151);
      cast();
      break;
    }

    case 11: {
      setState(152);
      match(FilParser::IDENTIFIER);
      break;
    }

    case 12: {
      setState(153);
      function_call();
      break;
    }

    case 13: {
      setState(154);
      litteral();
      break;
    }

    case 14: {
      setState(155);
      variable_decl();
      break;
    }

    case 15: {
      setState(156);
      expr_parenthesis();
      break;
    }

    case 16: {
      setState(157);
      expr_block();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(174);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(172);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(160);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(161);
          binary_operator();
          setState(162);
          expr(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(164);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(165);
          match(FilParser::DOT);
          setState(166);
          expr(10);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(167);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(168);
          match(FilParser::ARROW);
          setState(169);
          expr(9);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(171);
          assignation();
          break;
        }

        } 
      }
      setState(176);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

FilParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::FunctionContext::FUN() {
  return getToken(FilParser::FUN, 0);
}

tree::TerminalNode* FilParser::FunctionContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Fun_paramsContext* FilParser::FunctionContext::fun_params() {
  return getRuleContext<FilParser::Fun_paramsContext>(0);
}

FilParser::Fun_bodyContext* FilParser::FunctionContext::fun_body() {
  return getRuleContext<FilParser::Fun_bodyContext>(0);
}

tree::TerminalNode* FilParser::FunctionContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::FunctionContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}


size_t FilParser::FunctionContext::getRuleIndex() const {
  return FilParser::RuleFunction;
}


antlrcpp::Any FilParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

FilParser::FunctionContext* FilParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 8, FilParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(FilParser::FUN);
    setState(178);
    match(FilParser::IDENTIFIER);
    setState(179);
    fun_params();
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::COLON) {
      setState(180);
      match(FilParser::COLON);
      setState(181);
      type();
    }
    setState(184);
    fun_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_paramsContext ------------------------------------------------------------------

FilParser::Fun_paramsContext::Fun_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Fun_paramsContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Fun_paramsContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Fun_param_listContext* FilParser::Fun_paramsContext::fun_param_list() {
  return getRuleContext<FilParser::Fun_param_listContext>(0);
}


size_t FilParser::Fun_paramsContext::getRuleIndex() const {
  return FilParser::RuleFun_params;
}


antlrcpp::Any FilParser::Fun_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_params(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_paramsContext* FilParser::fun_params() {
  Fun_paramsContext *_localctx = _tracker.createInstance<Fun_paramsContext>(_ctx, getState());
  enterRule(_localctx, 10, FilParser::RuleFun_params);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(FilParser::LPAREN);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::IDENTIFIER) {
      setState(187);
      fun_param_list();
    }
    setState(190);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_param_listContext ------------------------------------------------------------------

FilParser::Fun_param_listContext::Fun_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::Fun_paramContext *> FilParser::Fun_param_listContext::fun_param() {
  return getRuleContexts<FilParser::Fun_paramContext>();
}

FilParser::Fun_paramContext* FilParser::Fun_param_listContext::fun_param(size_t i) {
  return getRuleContext<FilParser::Fun_paramContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Fun_param_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Fun_param_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Fun_param_listContext::getRuleIndex() const {
  return FilParser::RuleFun_param_list;
}


antlrcpp::Any FilParser::Fun_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_param_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_param_listContext* FilParser::fun_param_list() {
  Fun_param_listContext *_localctx = _tracker.createInstance<Fun_param_listContext>(_ctx, getState());
  enterRule(_localctx, 12, FilParser::RuleFun_param_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    fun_param();
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(193);
      match(FilParser::COMMA);
      setState(194);
      fun_param();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_paramContext ------------------------------------------------------------------

FilParser::Fun_paramContext::Fun_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Fun_paramContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Fun_paramContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Fun_paramContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}


size_t FilParser::Fun_paramContext::getRuleIndex() const {
  return FilParser::RuleFun_param;
}


antlrcpp::Any FilParser::Fun_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_param(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_paramContext* FilParser::fun_param() {
  Fun_paramContext *_localctx = _tracker.createInstance<Fun_paramContext>(_ctx, getState());
  enterRule(_localctx, 14, FilParser::RuleFun_param);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(FilParser::IDENTIFIER);
    setState(201);
    match(FilParser::COLON);
    setState(202);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_bodyContext ------------------------------------------------------------------

FilParser::Fun_bodyContext::Fun_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::AssignationContext* FilParser::Fun_bodyContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::Fun_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

FilParser::Expr_blockContext* FilParser::Fun_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::Fun_bodyContext::getRuleIndex() const {
  return FilParser::RuleFun_body;
}


antlrcpp::Any FilParser::Fun_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_bodyContext* FilParser::fun_body() {
  Fun_bodyContext *_localctx = _tracker.createInstance<Fun_bodyContext>(_ctx, getState());
  enterRule(_localctx, 16, FilParser::RuleFun_body);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(204);
      assignation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(205);
      expr_parenthesis();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(206);
      expr_block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_declContext ------------------------------------------------------------------

FilParser::Function_declContext::Function_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_declContext::FUN() {
  return getToken(FilParser::FUN, 0);
}

tree::TerminalNode* FilParser::Function_declContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Fun_paramsContext* FilParser::Function_declContext::fun_params() {
  return getRuleContext<FilParser::Fun_paramsContext>(0);
}

tree::TerminalNode* FilParser::Function_declContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Function_declContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}


size_t FilParser::Function_declContext::getRuleIndex() const {
  return FilParser::RuleFunction_decl;
}


antlrcpp::Any FilParser::Function_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_decl(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_declContext* FilParser::function_decl() {
  Function_declContext *_localctx = _tracker.createInstance<Function_declContext>(_ctx, getState());
  enterRule(_localctx, 18, FilParser::RuleFunction_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(FilParser::FUN);
    setState(210);
    match(FilParser::IDENTIFIER);
    setState(211);
    fun_params();
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::COLON) {
      setState(212);
      match(FilParser::COLON);
      setState(213);
      type();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaContext ------------------------------------------------------------------

FilParser::LambdaContext::LambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Fun_paramsContext* FilParser::LambdaContext::fun_params() {
  return getRuleContext<FilParser::Fun_paramsContext>(0);
}

tree::TerminalNode* FilParser::LambdaContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::Expr_blockContext* FilParser::LambdaContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::LambdaContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::LambdaContext::getRuleIndex() const {
  return FilParser::RuleLambda;
}


antlrcpp::Any FilParser::LambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitLambda(this);
  else
    return visitor->visitChildren(this);
}

FilParser::LambdaContext* FilParser::lambda() {
  LambdaContext *_localctx = _tracker.createInstance<LambdaContext>(_ctx, getState());
  enterRule(_localctx, 20, FilParser::RuleLambda);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    fun_params();
    setState(217);
    match(FilParser::ARROW);
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::LBRAK: {
        setState(218);
        expr_block();
        break;
      }

      case FilParser::LPAREN: {
        setState(219);
        expr_parenthesis();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceContext ------------------------------------------------------------------

FilParser::InterfaceContext::InterfaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::InterfaceContext::INTERFACE() {
  return getToken(FilParser::INTERFACE, 0);
}

tree::TerminalNode* FilParser::InterfaceContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Class_paramsContext* FilParser::InterfaceContext::class_params() {
  return getRuleContext<FilParser::Class_paramsContext>(0);
}

FilParser::Interface_bodyContext* FilParser::InterfaceContext::interface_body() {
  return getRuleContext<FilParser::Interface_bodyContext>(0);
}


size_t FilParser::InterfaceContext::getRuleIndex() const {
  return FilParser::RuleInterface;
}


antlrcpp::Any FilParser::InterfaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitInterface(this);
  else
    return visitor->visitChildren(this);
}

FilParser::InterfaceContext* FilParser::interface() {
  InterfaceContext *_localctx = _tracker.createInstance<InterfaceContext>(_ctx, getState());
  enterRule(_localctx, 22, FilParser::RuleInterface);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(FilParser::INTERFACE);
    setState(223);
    match(FilParser::IDENTIFIER);
    setState(225);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(224);
      class_params();
      break;
    }

    }
    setState(228);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(227);
      interface_body();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_bodyContext ------------------------------------------------------------------

FilParser::Interface_bodyContext::Interface_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Interface_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Interface_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<FilParser::Function_declContext *> FilParser::Interface_bodyContext::function_decl() {
  return getRuleContexts<FilParser::Function_declContext>();
}

FilParser::Function_declContext* FilParser::Interface_bodyContext::function_decl(size_t i) {
  return getRuleContext<FilParser::Function_declContext>(i);
}


size_t FilParser::Interface_bodyContext::getRuleIndex() const {
  return FilParser::RuleInterface_body;
}


antlrcpp::Any FilParser::Interface_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitInterface_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Interface_bodyContext* FilParser::interface_body() {
  Interface_bodyContext *_localctx = _tracker.createInstance<Interface_bodyContext>(_ctx, getState());
  enterRule(_localctx, 24, FilParser::RuleInterface_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(FilParser::LBRACE);
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::FUN) {
      setState(231);
      function_decl();
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(237);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_Context ------------------------------------------------------------------

FilParser::Class_Context::Class_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Class_modifierContext* FilParser::Class_Context::class_modifier() {
  return getRuleContext<FilParser::Class_modifierContext>(0);
}

tree::TerminalNode* FilParser::Class_Context::CLASS() {
  return getToken(FilParser::CLASS, 0);
}

tree::TerminalNode* FilParser::Class_Context::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Class_paramsContext* FilParser::Class_Context::class_params() {
  return getRuleContext<FilParser::Class_paramsContext>(0);
}

FilParser::Class_extendsContext* FilParser::Class_Context::class_extends() {
  return getRuleContext<FilParser::Class_extendsContext>(0);
}

FilParser::Class_bodyContext* FilParser::Class_Context::class_body() {
  return getRuleContext<FilParser::Class_bodyContext>(0);
}


size_t FilParser::Class_Context::getRuleIndex() const {
  return FilParser::RuleClass_;
}


antlrcpp::Any FilParser::Class_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_Context* FilParser::class_() {
  Class_Context *_localctx = _tracker.createInstance<Class_Context>(_ctx, getState());
  enterRule(_localctx, 26, FilParser::RuleClass_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    class_modifier();
    setState(240);
    match(FilParser::CLASS);
    setState(241);
    match(FilParser::IDENTIFIER);
    setState(243);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(242);
      class_params();
      break;
    }

    }
    setState(246);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(245);
      class_extends();
      break;
    }

    }
    setState(249);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(248);
      class_body();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_modifierContext ------------------------------------------------------------------

FilParser::Class_modifierContext::Class_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_modifierContext::ABSTRACT() {
  return getToken(FilParser::ABSTRACT, 0);
}

tree::TerminalNode* FilParser::Class_modifierContext::OPEN() {
  return getToken(FilParser::OPEN, 0);
}


size_t FilParser::Class_modifierContext::getRuleIndex() const {
  return FilParser::RuleClass_modifier;
}


antlrcpp::Any FilParser::Class_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_modifier(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_modifierContext* FilParser::class_modifier() {
  Class_modifierContext *_localctx = _tracker.createInstance<Class_modifierContext>(_ctx, getState());
  enterRule(_localctx, 28, FilParser::RuleClass_modifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!(_la == FilParser::ABSTRACT

    || _la == FilParser::OPEN)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_paramsContext ------------------------------------------------------------------

FilParser::Class_paramsContext::Class_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_paramsContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Class_paramsContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Class_param_listContext* FilParser::Class_paramsContext::class_param_list() {
  return getRuleContext<FilParser::Class_param_listContext>(0);
}


size_t FilParser::Class_paramsContext::getRuleIndex() const {
  return FilParser::RuleClass_params;
}


antlrcpp::Any FilParser::Class_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_params(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_paramsContext* FilParser::class_params() {
  Class_paramsContext *_localctx = _tracker.createInstance<Class_paramsContext>(_ctx, getState());
  enterRule(_localctx, 30, FilParser::RuleClass_params);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(FilParser::LPAREN);
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::VAL)
      | (1ULL << FilParser::VAR)
      | (1ULL << FilParser::IDENTIFIER))) != 0)) {
      setState(254);
      class_param_list();
    }
    setState(257);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_param_listContext ------------------------------------------------------------------

FilParser::Class_param_listContext::Class_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::Class_paramContext *> FilParser::Class_param_listContext::class_param() {
  return getRuleContexts<FilParser::Class_paramContext>();
}

FilParser::Class_paramContext* FilParser::Class_param_listContext::class_param(size_t i) {
  return getRuleContext<FilParser::Class_paramContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Class_param_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Class_param_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Class_param_listContext::getRuleIndex() const {
  return FilParser::RuleClass_param_list;
}


antlrcpp::Any FilParser::Class_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_param_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_param_listContext* FilParser::class_param_list() {
  Class_param_listContext *_localctx = _tracker.createInstance<Class_param_listContext>(_ctx, getState());
  enterRule(_localctx, 32, FilParser::RuleClass_param_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    class_param();
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(260);
      match(FilParser::COMMA);
      setState(261);
      class_param();
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_paramContext ------------------------------------------------------------------

FilParser::Class_paramContext::Class_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Variable_declContext* FilParser::Class_paramContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

tree::TerminalNode* FilParser::Class_paramContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Class_paramContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Class_paramContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}

tree::TerminalNode* FilParser::Class_paramContext::EQ() {
  return getToken(FilParser::EQ, 0);
}

FilParser::LitteralContext* FilParser::Class_paramContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}


size_t FilParser::Class_paramContext::getRuleIndex() const {
  return FilParser::RuleClass_param;
}


antlrcpp::Any FilParser::Class_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_param(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_paramContext* FilParser::class_param() {
  Class_paramContext *_localctx = _tracker.createInstance<Class_paramContext>(_ctx, getState());
  enterRule(_localctx, 34, FilParser::RuleClass_param);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::VAL:
      case FilParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(267);
        variable_decl();
        break;
      }

      case FilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(268);
        match(FilParser::IDENTIFIER);
        setState(269);
        match(FilParser::COLON);
        setState(270);
        type();
        setState(273);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FilParser::EQ) {
          setState(271);
          match(FilParser::EQ);
          setState(272);
          litteral();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_extendsContext ------------------------------------------------------------------

FilParser::Class_extendsContext::Class_extendsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_extendsContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::Class_extend_listContext* FilParser::Class_extendsContext::class_extend_list() {
  return getRuleContext<FilParser::Class_extend_listContext>(0);
}


size_t FilParser::Class_extendsContext::getRuleIndex() const {
  return FilParser::RuleClass_extends;
}


antlrcpp::Any FilParser::Class_extendsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_extends(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_extendsContext* FilParser::class_extends() {
  Class_extendsContext *_localctx = _tracker.createInstance<Class_extendsContext>(_ctx, getState());
  enterRule(_localctx, 36, FilParser::RuleClass_extends);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(FilParser::COLON);
    setState(278);
    class_extend_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_extend_listContext ------------------------------------------------------------------

FilParser::Class_extend_listContext::Class_extend_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::Class_extendContext *> FilParser::Class_extend_listContext::class_extend() {
  return getRuleContexts<FilParser::Class_extendContext>();
}

FilParser::Class_extendContext* FilParser::Class_extend_listContext::class_extend(size_t i) {
  return getRuleContext<FilParser::Class_extendContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Class_extend_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Class_extend_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Class_extend_listContext::getRuleIndex() const {
  return FilParser::RuleClass_extend_list;
}


antlrcpp::Any FilParser::Class_extend_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_extend_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_extend_listContext* FilParser::class_extend_list() {
  Class_extend_listContext *_localctx = _tracker.createInstance<Class_extend_listContext>(_ctx, getState());
  enterRule(_localctx, 38, FilParser::RuleClass_extend_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(280);
    class_extend();
    setState(285);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(281);
        match(FilParser::COMMA);
        setState(282);
        class_extend(); 
      }
      setState(287);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_extendContext ------------------------------------------------------------------

FilParser::Class_extendContext::Class_extendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_extendContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Function_call_paramsContext* FilParser::Class_extendContext::function_call_params() {
  return getRuleContext<FilParser::Function_call_paramsContext>(0);
}


size_t FilParser::Class_extendContext::getRuleIndex() const {
  return FilParser::RuleClass_extend;
}


antlrcpp::Any FilParser::Class_extendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_extend(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_extendContext* FilParser::class_extend() {
  Class_extendContext *_localctx = _tracker.createInstance<Class_extendContext>(_ctx, getState());
  enterRule(_localctx, 40, FilParser::RuleClass_extend);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(FilParser::IDENTIFIER);
    setState(289);
    function_call_params();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_bodyContext ------------------------------------------------------------------

FilParser::Class_bodyContext::Class_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

FilParser::Class_constructorContext* FilParser::Class_bodyContext::class_constructor() {
  return getRuleContext<FilParser::Class_constructorContext>(0);
}

tree::TerminalNode* FilParser::Class_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<FilParser::Class_variableContext *> FilParser::Class_bodyContext::class_variable() {
  return getRuleContexts<FilParser::Class_variableContext>();
}

FilParser::Class_variableContext* FilParser::Class_bodyContext::class_variable(size_t i) {
  return getRuleContext<FilParser::Class_variableContext>(i);
}

std::vector<FilParser::Class_functionContext *> FilParser::Class_bodyContext::class_function() {
  return getRuleContexts<FilParser::Class_functionContext>();
}

FilParser::Class_functionContext* FilParser::Class_bodyContext::class_function(size_t i) {
  return getRuleContext<FilParser::Class_functionContext>(i);
}


size_t FilParser::Class_bodyContext::getRuleIndex() const {
  return FilParser::RuleClass_body;
}


antlrcpp::Any FilParser::Class_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_bodyContext* FilParser::class_body() {
  Class_bodyContext *_localctx = _tracker.createInstance<Class_bodyContext>(_ctx, getState());
  enterRule(_localctx, 42, FilParser::RuleClass_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    match(FilParser::LBRACE);
    setState(292);
    class_constructor();
    setState(297);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::ABSTRACT)
      | (1ULL << FilParser::PRIVATE)
      | (1ULL << FilParser::PUBLIC)
      | (1ULL << FilParser::INTERNAL)
      | (1ULL << FilParser::PROTECTED))) != 0)) {
      setState(295);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(293);
        class_variable();
        break;
      }

      case 2: {
        setState(294);
        class_function();
        break;
      }

      }
      setState(299);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(300);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_functionContext ------------------------------------------------------------------

FilParser::Class_functionContext::Class_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Class_atr_modifierContext* FilParser::Class_functionContext::class_atr_modifier() {
  return getRuleContext<FilParser::Class_atr_modifierContext>(0);
}

FilParser::FunctionContext* FilParser::Class_functionContext::function() {
  return getRuleContext<FilParser::FunctionContext>(0);
}

tree::TerminalNode* FilParser::Class_functionContext::ABSTRACT() {
  return getToken(FilParser::ABSTRACT, 0);
}


size_t FilParser::Class_functionContext::getRuleIndex() const {
  return FilParser::RuleClass_function;
}


antlrcpp::Any FilParser::Class_functionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_function(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_functionContext* FilParser::class_function() {
  Class_functionContext *_localctx = _tracker.createInstance<Class_functionContext>(_ctx, getState());
  enterRule(_localctx, 44, FilParser::RuleClass_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::ABSTRACT) {
      setState(302);
      match(FilParser::ABSTRACT);
    }
    setState(305);
    class_atr_modifier();
    setState(306);
    function();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_variableContext ------------------------------------------------------------------

FilParser::Class_variableContext::Class_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Class_atr_modifierContext* FilParser::Class_variableContext::class_atr_modifier() {
  return getRuleContext<FilParser::Class_atr_modifierContext>(0);
}

FilParser::Variable_declContext* FilParser::Class_variableContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}


size_t FilParser::Class_variableContext::getRuleIndex() const {
  return FilParser::RuleClass_variable;
}


antlrcpp::Any FilParser::Class_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_variable(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_variableContext* FilParser::class_variable() {
  Class_variableContext *_localctx = _tracker.createInstance<Class_variableContext>(_ctx, getState());
  enterRule(_localctx, 46, FilParser::RuleClass_variable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    class_atr_modifier();
    setState(309);
    variable_decl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_atr_modifierContext ------------------------------------------------------------------

FilParser::Class_atr_modifierContext::Class_atr_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::PRIVATE() {
  return getToken(FilParser::PRIVATE, 0);
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::PUBLIC() {
  return getToken(FilParser::PUBLIC, 0);
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::INTERNAL() {
  return getToken(FilParser::INTERNAL, 0);
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::PROTECTED() {
  return getToken(FilParser::PROTECTED, 0);
}


size_t FilParser::Class_atr_modifierContext::getRuleIndex() const {
  return FilParser::RuleClass_atr_modifier;
}


antlrcpp::Any FilParser::Class_atr_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_atr_modifier(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_atr_modifierContext* FilParser::class_atr_modifier() {
  Class_atr_modifierContext *_localctx = _tracker.createInstance<Class_atr_modifierContext>(_ctx, getState());
  enterRule(_localctx, 48, FilParser::RuleClass_atr_modifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::PRIVATE)
      | (1ULL << FilParser::PUBLIC)
      | (1ULL << FilParser::INTERNAL)
      | (1ULL << FilParser::PROTECTED))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_constructorContext ------------------------------------------------------------------

FilParser::Class_constructorContext::Class_constructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_constructorContext::CONSTRUCTOR() {
  return getToken(FilParser::CONSTRUCTOR, 0);
}

FilParser::Expr_blockContext* FilParser::Class_constructorContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::Class_constructorContext::getRuleIndex() const {
  return FilParser::RuleClass_constructor;
}


antlrcpp::Any FilParser::Class_constructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_constructor(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_constructorContext* FilParser::class_constructor() {
  Class_constructorContext *_localctx = _tracker.createInstance<Class_constructorContext>(_ctx, getState());
  enterRule(_localctx, 50, FilParser::RuleClass_constructor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    match(FilParser::CONSTRUCTOR);
    setState(314);
    expr_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_Context ------------------------------------------------------------------

FilParser::Enum_Context::Enum_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Enum_Context::ENUM() {
  return getToken(FilParser::ENUM, 0);
}

tree::TerminalNode* FilParser::Enum_Context::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Enum_bodyContext* FilParser::Enum_Context::enum_body() {
  return getRuleContext<FilParser::Enum_bodyContext>(0);
}


size_t FilParser::Enum_Context::getRuleIndex() const {
  return FilParser::RuleEnum_;
}


antlrcpp::Any FilParser::Enum_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitEnum_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Enum_Context* FilParser::enum_() {
  Enum_Context *_localctx = _tracker.createInstance<Enum_Context>(_ctx, getState());
  enterRule(_localctx, 52, FilParser::RuleEnum_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(FilParser::ENUM);
    setState(317);
    match(FilParser::IDENTIFIER);
    setState(319);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(318);
      enum_body();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_bodyContext ------------------------------------------------------------------

FilParser::Enum_bodyContext::Enum_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Enum_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Enum_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> FilParser::Enum_bodyContext::IDENTIFIER() {
  return getTokens(FilParser::IDENTIFIER);
}

tree::TerminalNode* FilParser::Enum_bodyContext::IDENTIFIER(size_t i) {
  return getToken(FilParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> FilParser::Enum_bodyContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Enum_bodyContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Enum_bodyContext::getRuleIndex() const {
  return FilParser::RuleEnum_body;
}


antlrcpp::Any FilParser::Enum_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitEnum_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Enum_bodyContext* FilParser::enum_body() {
  Enum_bodyContext *_localctx = _tracker.createInstance<Enum_bodyContext>(_ctx, getState());
  enterRule(_localctx, 54, FilParser::RuleEnum_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(FilParser::LBRACE);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::IDENTIFIER) {
      setState(322);
      match(FilParser::IDENTIFIER);
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FilParser::COMMA) {
        setState(323);
        match(FilParser::COMMA);
        setState(324);
        match(FilParser::IDENTIFIER);
        setState(329);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(332);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

FilParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::If_Context* FilParser::ConditionContext::if_() {
  return getRuleContext<FilParser::If_Context>(0);
}

FilParser::Switch_Context* FilParser::ConditionContext::switch_() {
  return getRuleContext<FilParser::Switch_Context>(0);
}


size_t FilParser::ConditionContext::getRuleIndex() const {
  return FilParser::RuleCondition;
}


antlrcpp::Any FilParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ConditionContext* FilParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 56, FilParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(334);
        if_();
        break;
      }

      case FilParser::SWITCH: {
        enterOuterAlt(_localctx, 2);
        setState(335);
        switch_();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_Context ------------------------------------------------------------------

FilParser::If_Context::If_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::If_Context::IF() {
  return getToken(FilParser::IF, 0);
}

FilParser::If_conditionContext* FilParser::If_Context::if_condition() {
  return getRuleContext<FilParser::If_conditionContext>(0);
}

FilParser::If_bodyContext* FilParser::If_Context::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}

std::vector<FilParser::Else_ifContext *> FilParser::If_Context::else_if() {
  return getRuleContexts<FilParser::Else_ifContext>();
}

FilParser::Else_ifContext* FilParser::If_Context::else_if(size_t i) {
  return getRuleContext<FilParser::Else_ifContext>(i);
}

FilParser::Else_Context* FilParser::If_Context::else_() {
  return getRuleContext<FilParser::Else_Context>(0);
}


size_t FilParser::If_Context::getRuleIndex() const {
  return FilParser::RuleIf_;
}


antlrcpp::Any FilParser::If_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitIf_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::If_Context* FilParser::if_() {
  If_Context *_localctx = _tracker.createInstance<If_Context>(_ctx, getState());
  enterRule(_localctx, 58, FilParser::RuleIf_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(338);
    match(FilParser::IF);
    setState(339);
    if_condition();
    setState(340);
    if_body();
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(341);
        else_if(); 
      }
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
    setState(348);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(347);
      else_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_conditionContext ------------------------------------------------------------------

FilParser::If_conditionContext::If_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Expr_parenthesisContext* FilParser::If_conditionContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::If_conditionContext::getRuleIndex() const {
  return FilParser::RuleIf_condition;
}


antlrcpp::Any FilParser::If_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitIf_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::If_conditionContext* FilParser::if_condition() {
  If_conditionContext *_localctx = _tracker.createInstance<If_conditionContext>(_ctx, getState());
  enterRule(_localctx, 60, FilParser::RuleIf_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    expr_parenthesis();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_bodyContext ------------------------------------------------------------------

FilParser::If_bodyContext::If_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::ExprContext* FilParser::If_bodyContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::If_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::If_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::If_bodyContext::getRuleIndex() const {
  return FilParser::RuleIf_body;
}


antlrcpp::Any FilParser::If_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitIf_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::If_bodyContext* FilParser::if_body() {
  If_bodyContext *_localctx = _tracker.createInstance<If_bodyContext>(_ctx, getState());
  enterRule(_localctx, 62, FilParser::RuleIf_body);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(352);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(353);
      expr_block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(354);
      expr_parenthesis();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_ifContext ------------------------------------------------------------------

FilParser::Else_ifContext::Else_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Else_ifContext::ELSE() {
  return getToken(FilParser::ELSE, 0);
}

tree::TerminalNode* FilParser::Else_ifContext::IF() {
  return getToken(FilParser::IF, 0);
}

FilParser::If_conditionContext* FilParser::Else_ifContext::if_condition() {
  return getRuleContext<FilParser::If_conditionContext>(0);
}

FilParser::If_bodyContext* FilParser::Else_ifContext::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}


size_t FilParser::Else_ifContext::getRuleIndex() const {
  return FilParser::RuleElse_if;
}


antlrcpp::Any FilParser::Else_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitElse_if(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Else_ifContext* FilParser::else_if() {
  Else_ifContext *_localctx = _tracker.createInstance<Else_ifContext>(_ctx, getState());
  enterRule(_localctx, 64, FilParser::RuleElse_if);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(FilParser::ELSE);
    setState(358);
    match(FilParser::IF);
    setState(359);
    if_condition();
    setState(360);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_Context ------------------------------------------------------------------

FilParser::Else_Context::Else_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Else_Context::ELSE() {
  return getToken(FilParser::ELSE, 0);
}

FilParser::If_bodyContext* FilParser::Else_Context::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}


size_t FilParser::Else_Context::getRuleIndex() const {
  return FilParser::RuleElse_;
}


antlrcpp::Any FilParser::Else_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitElse_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Else_Context* FilParser::else_() {
  Else_Context *_localctx = _tracker.createInstance<Else_Context>(_ctx, getState());
  enterRule(_localctx, 66, FilParser::RuleElse_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    match(FilParser::ELSE);
    setState(363);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_Context ------------------------------------------------------------------

FilParser::Switch_Context::Switch_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Switch_Context::SWITCH() {
  return getToken(FilParser::SWITCH, 0);
}

FilParser::Switch_conditionContext* FilParser::Switch_Context::switch_condition() {
  return getRuleContext<FilParser::Switch_conditionContext>(0);
}

FilParser::Switch_bodyContext* FilParser::Switch_Context::switch_body() {
  return getRuleContext<FilParser::Switch_bodyContext>(0);
}


size_t FilParser::Switch_Context::getRuleIndex() const {
  return FilParser::RuleSwitch_;
}


antlrcpp::Any FilParser::Switch_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_Context* FilParser::switch_() {
  Switch_Context *_localctx = _tracker.createInstance<Switch_Context>(_ctx, getState());
  enterRule(_localctx, 68, FilParser::RuleSwitch_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(FilParser::SWITCH);
    setState(366);
    switch_condition();
    setState(367);
    switch_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_conditionContext ------------------------------------------------------------------

FilParser::Switch_conditionContext::Switch_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Expr_parenthesisContext* FilParser::Switch_conditionContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::Switch_conditionContext::getRuleIndex() const {
  return FilParser::RuleSwitch_condition;
}


antlrcpp::Any FilParser::Switch_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_conditionContext* FilParser::switch_condition() {
  Switch_conditionContext *_localctx = _tracker.createInstance<Switch_conditionContext>(_ctx, getState());
  enterRule(_localctx, 70, FilParser::RuleSwitch_condition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    expr_parenthesis();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_bodyContext ------------------------------------------------------------------

FilParser::Switch_bodyContext::Switch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Switch_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Switch_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<FilParser::Switch_caseContext *> FilParser::Switch_bodyContext::switch_case() {
  return getRuleContexts<FilParser::Switch_caseContext>();
}

FilParser::Switch_caseContext* FilParser::Switch_bodyContext::switch_case(size_t i) {
  return getRuleContext<FilParser::Switch_caseContext>(i);
}


size_t FilParser::Switch_bodyContext::getRuleIndex() const {
  return FilParser::RuleSwitch_body;
}


antlrcpp::Any FilParser::Switch_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_bodyContext* FilParser::switch_body() {
  Switch_bodyContext *_localctx = _tracker.createInstance<Switch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 72, FilParser::RuleSwitch_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(FilParser::LBRACE);
    setState(375);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::DEFAULT)
      | (1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0)) {
      setState(372);
      switch_case();
      setState(377);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(378);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_caseContext ------------------------------------------------------------------

FilParser::Switch_caseContext::Switch_caseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Switch_caseContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::LitteralContext* FilParser::Switch_caseContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}

tree::TerminalNode* FilParser::Switch_caseContext::DEFAULT() {
  return getToken(FilParser::DEFAULT, 0);
}

FilParser::ExprContext* FilParser::Switch_caseContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::Switch_caseContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::Switch_caseContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::Switch_caseContext::getRuleIndex() const {
  return FilParser::RuleSwitch_case;
}


antlrcpp::Any FilParser::Switch_caseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_case(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_caseContext* FilParser::switch_case() {
  Switch_caseContext *_localctx = _tracker.createInstance<Switch_caseContext>(_ctx, getState());
  enterRule(_localctx, 74, FilParser::RuleSwitch_case);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::TRUE:
      case FilParser::FALSE:
      case FilParser::NULL_:
      case FilParser::INT:
      case FilParser::FLOAT:
      case FilParser::STRING:
      case FilParser::CHAR: {
        setState(380);
        litteral();
        break;
      }

      case FilParser::DEFAULT: {
        setState(381);
        match(FilParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(384);
    match(FilParser::ARROW);
    setState(388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(385);
      expr(0);
      break;
    }

    case 2: {
      setState(386);
      expr_block();
      break;
    }

    case 3: {
      setState(387);
      expr_parenthesis();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

FilParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::ForiContext* FilParser::LoopContext::fori() {
  return getRuleContext<FilParser::ForiContext>(0);
}

FilParser::ForiterContext* FilParser::LoopContext::foriter() {
  return getRuleContext<FilParser::ForiterContext>(0);
}

FilParser::While_Context* FilParser::LoopContext::while_() {
  return getRuleContext<FilParser::While_Context>(0);
}


size_t FilParser::LoopContext::getRuleIndex() const {
  return FilParser::RuleLoop;
}


antlrcpp::Any FilParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

FilParser::LoopContext* FilParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 76, FilParser::RuleLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(390);
      fori();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(391);
      foriter();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(392);
      while_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForiContext ------------------------------------------------------------------

FilParser::ForiContext::ForiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ForiContext::FOR() {
  return getToken(FilParser::FOR, 0);
}

FilParser::Fori_conditionContext* FilParser::ForiContext::fori_condition() {
  return getRuleContext<FilParser::Fori_conditionContext>(0);
}

FilParser::ExprContext* FilParser::ForiContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::ForiContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::ForiContext::getRuleIndex() const {
  return FilParser::RuleFori;
}


antlrcpp::Any FilParser::ForiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFori(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ForiContext* FilParser::fori() {
  ForiContext *_localctx = _tracker.createInstance<ForiContext>(_ctx, getState());
  enterRule(_localctx, 78, FilParser::RuleFori);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(FilParser::FOR);
    setState(396);
    fori_condition();
    setState(399);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(397);
      expr(0);
      break;
    }

    case 2: {
      setState(398);
      expr_block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fori_conditionContext ------------------------------------------------------------------

FilParser::Fori_conditionContext::Fori_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Fori_conditionContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> FilParser::Fori_conditionContext::SEMICOLON() {
  return getTokens(FilParser::SEMICOLON);
}

tree::TerminalNode* FilParser::Fori_conditionContext::SEMICOLON(size_t i) {
  return getToken(FilParser::SEMICOLON, i);
}

tree::TerminalNode* FilParser::Fori_conditionContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Variable_declContext* FilParser::Fori_conditionContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

std::vector<FilParser::ExprContext *> FilParser::Fori_conditionContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Fori_conditionContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}


size_t FilParser::Fori_conditionContext::getRuleIndex() const {
  return FilParser::RuleFori_condition;
}


antlrcpp::Any FilParser::Fori_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFori_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fori_conditionContext* FilParser::fori_condition() {
  Fori_conditionContext *_localctx = _tracker.createInstance<Fori_conditionContext>(_ctx, getState());
  enterRule(_localctx, 80, FilParser::RuleFori_condition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(FilParser::LPAREN);
    setState(403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::VAL

    || _la == FilParser::VAR) {
      setState(402);
      variable_decl();
    }
    setState(405);
    match(FilParser::SEMICOLON);
    setState(407);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::FUN)
      | (1ULL << FilParser::INTERFACE)
      | (1ULL << FilParser::ABSTRACT)
      | (1ULL << FilParser::OPEN)
      | (1ULL << FilParser::ENUM)
      | (1ULL << FilParser::IF)
      | (1ULL << FilParser::SWITCH)
      | (1ULL << FilParser::FOR)
      | (1ULL << FilParser::VAL)
      | (1ULL << FilParser::VAR)
      | (1ULL << FilParser::WHILE)
      | (1ULL << FilParser::TRY)
      | (1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::IDENTIFIER)
      | (1ULL << FilParser::LPAREN)
      | (1ULL << FilParser::LBRAK)
      | (1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::NOT)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0)) {
      setState(406);
      expr(0);
    }
    setState(409);
    match(FilParser::SEMICOLON);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::FUN)
      | (1ULL << FilParser::INTERFACE)
      | (1ULL << FilParser::ABSTRACT)
      | (1ULL << FilParser::OPEN)
      | (1ULL << FilParser::ENUM)
      | (1ULL << FilParser::IF)
      | (1ULL << FilParser::SWITCH)
      | (1ULL << FilParser::FOR)
      | (1ULL << FilParser::VAL)
      | (1ULL << FilParser::VAR)
      | (1ULL << FilParser::WHILE)
      | (1ULL << FilParser::TRY)
      | (1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::IDENTIFIER)
      | (1ULL << FilParser::LPAREN)
      | (1ULL << FilParser::LBRAK)
      | (1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::NOT)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0)) {
      setState(410);
      expr(0);
    }
    setState(413);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForiterContext ------------------------------------------------------------------

FilParser::ForiterContext::ForiterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ForiterContext::FOR() {
  return getToken(FilParser::FOR, 0);
}

FilParser::Foriter_conditionContext* FilParser::ForiterContext::foriter_condition() {
  return getRuleContext<FilParser::Foriter_conditionContext>(0);
}

FilParser::ExprContext* FilParser::ForiterContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::ForiterContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::ForiterContext::getRuleIndex() const {
  return FilParser::RuleForiter;
}


antlrcpp::Any FilParser::ForiterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitForiter(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ForiterContext* FilParser::foriter() {
  ForiterContext *_localctx = _tracker.createInstance<ForiterContext>(_ctx, getState());
  enterRule(_localctx, 82, FilParser::RuleForiter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    match(FilParser::FOR);
    setState(416);
    foriter_condition();
    setState(419);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(417);
      expr(0);
      break;
    }

    case 2: {
      setState(418);
      expr_block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foriter_conditionContext ------------------------------------------------------------------

FilParser::Foriter_conditionContext::Foriter_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Foriter_conditionContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> FilParser::Foriter_conditionContext::IDENTIFIER() {
  return getTokens(FilParser::IDENTIFIER);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::IDENTIFIER(size_t i) {
  return getToken(FilParser::IDENTIFIER, i);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::VAL() {
  return getToken(FilParser::VAL, 0);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::VAR() {
  return getToken(FilParser::VAR, 0);
}


size_t FilParser::Foriter_conditionContext::getRuleIndex() const {
  return FilParser::RuleForiter_condition;
}


antlrcpp::Any FilParser::Foriter_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitForiter_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Foriter_conditionContext* FilParser::foriter_condition() {
  Foriter_conditionContext *_localctx = _tracker.createInstance<Foriter_conditionContext>(_ctx, getState());
  enterRule(_localctx, 84, FilParser::RuleForiter_condition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(FilParser::LPAREN);
    setState(422);
    _la = _input->LA(1);
    if (!(_la == FilParser::VAL

    || _la == FilParser::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(423);
    match(FilParser::IDENTIFIER);
    setState(424);
    match(FilParser::COLON);
    setState(425);
    match(FilParser::IDENTIFIER);
    setState(426);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_Context ------------------------------------------------------------------

FilParser::While_Context::While_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::While_Context::WHILE() {
  return getToken(FilParser::WHILE, 0);
}

FilParser::If_conditionContext* FilParser::While_Context::if_condition() {
  return getRuleContext<FilParser::If_conditionContext>(0);
}

FilParser::If_bodyContext* FilParser::While_Context::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}


size_t FilParser::While_Context::getRuleIndex() const {
  return FilParser::RuleWhile_;
}


antlrcpp::Any FilParser::While_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitWhile_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::While_Context* FilParser::while_() {
  While_Context *_localctx = _tracker.createInstance<While_Context>(_ctx, getState());
  enterRule(_localctx, 86, FilParser::RuleWhile_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(FilParser::WHILE);
    setState(429);
    if_condition();
    setState(430);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExceptionContext ------------------------------------------------------------------

FilParser::ExceptionContext::ExceptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ExceptionContext::TRY() {
  return getToken(FilParser::TRY, 0);
}

FilParser::ExprContext* FilParser::ExceptionContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::ExceptionContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::ExceptionContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

std::vector<FilParser::Catch_bodyContext *> FilParser::ExceptionContext::catch_body() {
  return getRuleContexts<FilParser::Catch_bodyContext>();
}

FilParser::Catch_bodyContext* FilParser::ExceptionContext::catch_body(size_t i) {
  return getRuleContext<FilParser::Catch_bodyContext>(i);
}


size_t FilParser::ExceptionContext::getRuleIndex() const {
  return FilParser::RuleException;
}


antlrcpp::Any FilParser::ExceptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitException(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ExceptionContext* FilParser::exception() {
  ExceptionContext *_localctx = _tracker.createInstance<ExceptionContext>(_ctx, getState());
  enterRule(_localctx, 88, FilParser::RuleException);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(FilParser::TRY);
    setState(436);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(433);
      expr(0);
      break;
    }

    case 2: {
      setState(434);
      expr_block();
      break;
    }

    case 3: {
      setState(435);
      expr_parenthesis();
      break;
    }

    }
    setState(439); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(438);
              catch_body();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(441); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Catch_bodyContext ------------------------------------------------------------------

FilParser::Catch_bodyContext::Catch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Catch_bodyContext::CATCH() {
  return getToken(FilParser::CATCH, 0);
}

tree::TerminalNode* FilParser::Catch_bodyContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

FilParser::Fun_paramContext* FilParser::Catch_bodyContext::fun_param() {
  return getRuleContext<FilParser::Fun_paramContext>(0);
}

tree::TerminalNode* FilParser::Catch_bodyContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::ExprContext* FilParser::Catch_bodyContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::Catch_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::Catch_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::Catch_bodyContext::getRuleIndex() const {
  return FilParser::RuleCatch_body;
}


antlrcpp::Any FilParser::Catch_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitCatch_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Catch_bodyContext* FilParser::catch_body() {
  Catch_bodyContext *_localctx = _tracker.createInstance<Catch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 90, FilParser::RuleCatch_body);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    match(FilParser::CATCH);
    setState(444);
    match(FilParser::LPAREN);
    setState(445);
    fun_param();
    setState(446);
    match(FilParser::RPAREN);
    setState(450);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(447);
      expr(0);
      break;
    }

    case 2: {
      setState(448);
      expr_block();
      break;
    }

    case 3: {
      setState(449);
      expr_parenthesis();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

FilParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Binary_operatorContext::PLUS() {
  return getToken(FilParser::PLUS, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::MINUS() {
  return getToken(FilParser::MINUS, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::DIVIDE() {
  return getToken(FilParser::DIVIDE, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::MOD() {
  return getToken(FilParser::MOD, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::FLEFT() {
  return getToken(FilParser::FLEFT, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::FRIGHT() {
  return getToken(FilParser::FRIGHT, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::AND() {
  return getToken(FilParser::AND, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::OR() {
  return getToken(FilParser::OR, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::LE() {
  return getToken(FilParser::LE, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::GE() {
  return getToken(FilParser::GE, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::EQEQ() {
  return getToken(FilParser::EQEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::LEQ() {
  return getToken(FilParser::LEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::GEQ() {
  return getToken(FilParser::GEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::NEQ() {
  return getToken(FilParser::NEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::BAND() {
  return getToken(FilParser::BAND, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::BOR() {
  return getToken(FilParser::BOR, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::BXOR() {
  return getToken(FilParser::BXOR, 0);
}


size_t FilParser::Binary_operatorContext::getRuleIndex() const {
  return FilParser::RuleBinary_operator;
}


antlrcpp::Any FilParser::Binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitBinary_operator(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Binary_operatorContext* FilParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 92, FilParser::RuleBinary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::FLEFT)
      | (1ULL << FilParser::FRIGHT)
      | (1ULL << FilParser::AND)
      | (1ULL << FilParser::OR)
      | (1ULL << FilParser::LE)
      | (1ULL << FilParser::GE)
      | (1ULL << FilParser::EQEQ)
      | (1ULL << FilParser::LEQ)
      | (1ULL << FilParser::GEQ)
      | (1ULL << FilParser::NEQ)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_calculContext ------------------------------------------------------------------

FilParser::Unary_calculContext::Unary_calculContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Unary_operatorContext* FilParser::Unary_calculContext::unary_operator() {
  return getRuleContext<FilParser::Unary_operatorContext>(0);
}

FilParser::ExprContext* FilParser::Unary_calculContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}


size_t FilParser::Unary_calculContext::getRuleIndex() const {
  return FilParser::RuleUnary_calcul;
}


antlrcpp::Any FilParser::Unary_calculContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitUnary_calcul(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Unary_calculContext* FilParser::unary_calcul() {
  Unary_calculContext *_localctx = _tracker.createInstance<Unary_calculContext>(_ctx, getState());
  enterRule(_localctx, 94, FilParser::RuleUnary_calcul);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    unary_operator();
    setState(455);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

FilParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Unary_operatorContext::PLUS() {
  return getToken(FilParser::PLUS, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::MINUS() {
  return getToken(FilParser::MINUS, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::DIVIDE() {
  return getToken(FilParser::DIVIDE, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::MOD() {
  return getToken(FilParser::MOD, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::NOT() {
  return getToken(FilParser::NOT, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::BAND() {
  return getToken(FilParser::BAND, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::BXOR() {
  return getToken(FilParser::BXOR, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::BOR() {
  return getToken(FilParser::BOR, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::INT() {
  return getToken(FilParser::INT, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}


size_t FilParser::Unary_operatorContext::getRuleIndex() const {
  return FilParser::RuleUnary_operator;
}


antlrcpp::Any FilParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Unary_operatorContext* FilParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 96, FilParser::RuleUnary_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(469);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(457);
        match(FilParser::PLUS);
        break;
      }

      case FilParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(458);
        match(FilParser::MINUS);
        break;
      }

      case FilParser::DIVIDE: {
        enterOuterAlt(_localctx, 3);
        setState(459);
        match(FilParser::DIVIDE);
        break;
      }

      case FilParser::TIMES: {
        enterOuterAlt(_localctx, 4);
        setState(460);
        match(FilParser::TIMES);
        break;
      }

      case FilParser::MOD: {
        enterOuterAlt(_localctx, 5);
        setState(461);
        match(FilParser::MOD);
        break;
      }

      case FilParser::NOT: {
        enterOuterAlt(_localctx, 6);
        setState(462);
        match(FilParser::NOT);
        break;
      }

      case FilParser::BAND: {
        enterOuterAlt(_localctx, 7);
        setState(463);
        match(FilParser::BAND);
        break;
      }

      case FilParser::BXOR: {
        enterOuterAlt(_localctx, 8);
        setState(464);
        match(FilParser::BXOR);
        break;
      }

      case FilParser::BOR: {
        enterOuterAlt(_localctx, 9);
        setState(465);
        match(FilParser::BOR);
        break;
      }

      case FilParser::LBRAK: {
        enterOuterAlt(_localctx, 10);
        setState(466);
        match(FilParser::LBRAK);
        setState(467);
        match(FilParser::INT);
        setState(468);
        match(FilParser::RBRAK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignationContext ------------------------------------------------------------------

FilParser::AssignationContext::AssignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Assignation_operatorContext* FilParser::AssignationContext::assignation_operator() {
  return getRuleContext<FilParser::Assignation_operatorContext>(0);
}

FilParser::ExprContext* FilParser::AssignationContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}


size_t FilParser::AssignationContext::getRuleIndex() const {
  return FilParser::RuleAssignation;
}


antlrcpp::Any FilParser::AssignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitAssignation(this);
  else
    return visitor->visitChildren(this);
}

FilParser::AssignationContext* FilParser::assignation() {
  AssignationContext *_localctx = _tracker.createInstance<AssignationContext>(_ctx, getState());
  enterRule(_localctx, 98, FilParser::RuleAssignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    assignation_operator();
    setState(472);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignation_operatorContext ------------------------------------------------------------------

FilParser::Assignation_operatorContext::Assignation_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Assignation_operatorContext::EQ() {
  return getToken(FilParser::EQ, 0);
}

FilParser::Unary_operatorContext* FilParser::Assignation_operatorContext::unary_operator() {
  return getRuleContext<FilParser::Unary_operatorContext>(0);
}


size_t FilParser::Assignation_operatorContext::getRuleIndex() const {
  return FilParser::RuleAssignation_operator;
}


antlrcpp::Any FilParser::Assignation_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitAssignation_operator(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Assignation_operatorContext* FilParser::assignation_operator() {
  Assignation_operatorContext *_localctx = _tracker.createInstance<Assignation_operatorContext>(_ctx, getState());
  enterRule(_localctx, 100, FilParser::RuleAssignation_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::LBRAK)
      | (1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::NOT)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR))) != 0)) {
      setState(474);
      unary_operator();
    }
    setState(477);
    match(FilParser::EQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastContext ------------------------------------------------------------------

FilParser::CastContext::CastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::CastContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

FilParser::TypeContext* FilParser::CastContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}

tree::TerminalNode* FilParser::CastContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::ExprContext* FilParser::CastContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}


size_t FilParser::CastContext::getRuleIndex() const {
  return FilParser::RuleCast;
}


antlrcpp::Any FilParser::CastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitCast(this);
  else
    return visitor->visitChildren(this);
}

FilParser::CastContext* FilParser::cast() {
  CastContext *_localctx = _tracker.createInstance<CastContext>(_ctx, getState());
  enterRule(_localctx, 102, FilParser::RuleCast);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(FilParser::LPAREN);
    setState(480);
    type();
    setState(481);
    match(FilParser::RPAREN);
    setState(482);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

FilParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_callContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Function_call_paramsContext* FilParser::Function_callContext::function_call_params() {
  return getRuleContext<FilParser::Function_call_paramsContext>(0);
}


size_t FilParser::Function_callContext::getRuleIndex() const {
  return FilParser::RuleFunction_call;
}


antlrcpp::Any FilParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_callContext* FilParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 104, FilParser::RuleFunction_call);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(FilParser::IDENTIFIER);
    setState(485);
    function_call_params();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_call_paramsContext ------------------------------------------------------------------

FilParser::Function_call_paramsContext::Function_call_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_call_paramsContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Function_call_paramsContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Function_call_param_listContext* FilParser::Function_call_paramsContext::function_call_param_list() {
  return getRuleContext<FilParser::Function_call_param_listContext>(0);
}


size_t FilParser::Function_call_paramsContext::getRuleIndex() const {
  return FilParser::RuleFunction_call_params;
}


antlrcpp::Any FilParser::Function_call_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_call_params(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_call_paramsContext* FilParser::function_call_params() {
  Function_call_paramsContext *_localctx = _tracker.createInstance<Function_call_paramsContext>(_ctx, getState());
  enterRule(_localctx, 106, FilParser::RuleFunction_call_params);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    match(FilParser::LPAREN);
    setState(489);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::FUN)
      | (1ULL << FilParser::INTERFACE)
      | (1ULL << FilParser::ABSTRACT)
      | (1ULL << FilParser::OPEN)
      | (1ULL << FilParser::ENUM)
      | (1ULL << FilParser::IF)
      | (1ULL << FilParser::SWITCH)
      | (1ULL << FilParser::FOR)
      | (1ULL << FilParser::VAL)
      | (1ULL << FilParser::VAR)
      | (1ULL << FilParser::WHILE)
      | (1ULL << FilParser::TRY)
      | (1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::IDENTIFIER)
      | (1ULL << FilParser::LPAREN)
      | (1ULL << FilParser::LBRAK)
      | (1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::NOT)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0)) {
      setState(488);
      function_call_param_list();
    }
    setState(491);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_call_param_listContext ------------------------------------------------------------------

FilParser::Function_call_param_listContext::Function_call_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::ExprContext *> FilParser::Function_call_param_listContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Function_call_param_listContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Function_call_param_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Function_call_param_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Function_call_param_listContext::getRuleIndex() const {
  return FilParser::RuleFunction_call_param_list;
}


antlrcpp::Any FilParser::Function_call_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_call_param_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_call_param_listContext* FilParser::function_call_param_list() {
  Function_call_param_listContext *_localctx = _tracker.createInstance<Function_call_param_listContext>(_ctx, getState());
  enterRule(_localctx, 108, FilParser::RuleFunction_call_param_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    expr(0);
    setState(498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(494);
      match(FilParser::COMMA);
      setState(495);
      expr(0);
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

FilParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Variable_declContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Variable_declContext::VAL() {
  return getToken(FilParser::VAL, 0);
}

tree::TerminalNode* FilParser::Variable_declContext::VAR() {
  return getToken(FilParser::VAR, 0);
}

tree::TerminalNode* FilParser::Variable_declContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Variable_declContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}

FilParser::AssignationContext* FilParser::Variable_declContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}


size_t FilParser::Variable_declContext::getRuleIndex() const {
  return FilParser::RuleVariable_decl;
}


antlrcpp::Any FilParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Variable_declContext* FilParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 110, FilParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    _la = _input->LA(1);
    if (!(_la == FilParser::VAL

    || _la == FilParser::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(502);
    match(FilParser::IDENTIFIER);
    setState(510);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(503);
      match(FilParser::COLON);
      setState(504);
      type();
      break;
    }

    case 2: {
      setState(507);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::COLON) {
        setState(505);
        match(FilParser::COLON);
        setState(506);
        type();
      }
      setState(509);
      assignation();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FilParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::TypeContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::TypeContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::TypeContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

tree::TerminalNode* FilParser::TypeContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}

tree::TerminalNode* FilParser::TypeContext::INT() {
  return getToken(FilParser::INT, 0);
}


size_t FilParser::TypeContext::getRuleIndex() const {
  return FilParser::RuleType;
}


antlrcpp::Any FilParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FilParser::TypeContext* FilParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 112, FilParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    match(FilParser::IDENTIFIER);
    setState(519);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(513);
      match(FilParser::TIMES);
      break;
    }

    case 2: {
      setState(514);
      match(FilParser::LBRAK);
      setState(516);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::INT) {
        setState(515);
        match(FilParser::INT);
      }
      setState(518);
      match(FilParser::RBRAK);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LitteralContext ------------------------------------------------------------------

FilParser::LitteralContext::LitteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::LitteralContext::INT() {
  return getToken(FilParser::INT, 0);
}

tree::TerminalNode* FilParser::LitteralContext::FLOAT() {
  return getToken(FilParser::FLOAT, 0);
}

tree::TerminalNode* FilParser::LitteralContext::STRING() {
  return getToken(FilParser::STRING, 0);
}

tree::TerminalNode* FilParser::LitteralContext::CHAR() {
  return getToken(FilParser::CHAR, 0);
}

tree::TerminalNode* FilParser::LitteralContext::TRUE() {
  return getToken(FilParser::TRUE, 0);
}

tree::TerminalNode* FilParser::LitteralContext::FALSE() {
  return getToken(FilParser::FALSE, 0);
}

tree::TerminalNode* FilParser::LitteralContext::NULL_() {
  return getToken(FilParser::NULL_, 0);
}


size_t FilParser::LitteralContext::getRuleIndex() const {
  return FilParser::RuleLitteral;
}


antlrcpp::Any FilParser::LitteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitLitteral(this);
  else
    return visitor->visitChildren(this);
}

FilParser::LitteralContext* FilParser::litteral() {
  LitteralContext *_localctx = _tracker.createInstance<LitteralContext>(_ctx, getState());
  enterRule(_localctx, 114, FilParser::RuleLitteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(521);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempContext ------------------------------------------------------------------

FilParser::TempContext::TempContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::TempContext::DOT() {
  return getToken(FilParser::DOT, 0);
}


size_t FilParser::TempContext::getRuleIndex() const {
  return FilParser::RuleTemp;
}


antlrcpp::Any FilParser::TempContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitTemp(this);
  else
    return visitor->visitChildren(this);
}

FilParser::TempContext* FilParser::temp() {
  TempContext *_localctx = _tracker.createInstance<TempContext>(_ctx, getState());
  enterRule(_localctx, 116, FilParser::RuleTemp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(523);
    match(FilParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_parenthesisContext ------------------------------------------------------------------

FilParser::Expr_parenthesisContext::Expr_parenthesisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Expr_parenthesisContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

FilParser::ExprContext* FilParser::Expr_parenthesisContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

tree::TerminalNode* FilParser::Expr_parenthesisContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}


size_t FilParser::Expr_parenthesisContext::getRuleIndex() const {
  return FilParser::RuleExpr_parenthesis;
}


antlrcpp::Any FilParser::Expr_parenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_parenthesis(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Expr_parenthesisContext* FilParser::expr_parenthesis() {
  Expr_parenthesisContext *_localctx = _tracker.createInstance<Expr_parenthesisContext>(_ctx, getState());
  enterRule(_localctx, 118, FilParser::RuleExpr_parenthesis);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(525);
    match(FilParser::LPAREN);
    setState(526);
    expr(0);
    setState(527);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_blockContext ------------------------------------------------------------------

FilParser::Expr_blockContext::Expr_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Expr_blockContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

tree::TerminalNode* FilParser::Expr_blockContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}

std::vector<FilParser::ExprContext *> FilParser::Expr_blockContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Expr_blockContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}


size_t FilParser::Expr_blockContext::getRuleIndex() const {
  return FilParser::RuleExpr_block;
}


antlrcpp::Any FilParser::Expr_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_block(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Expr_blockContext* FilParser::expr_block() {
  Expr_blockContext *_localctx = _tracker.createInstance<Expr_blockContext>(_ctx, getState());
  enterRule(_localctx, 120, FilParser::RuleExpr_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(FilParser::LBRAK);
    setState(533);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FilParser::FUN)
      | (1ULL << FilParser::INTERFACE)
      | (1ULL << FilParser::ABSTRACT)
      | (1ULL << FilParser::OPEN)
      | (1ULL << FilParser::ENUM)
      | (1ULL << FilParser::IF)
      | (1ULL << FilParser::SWITCH)
      | (1ULL << FilParser::FOR)
      | (1ULL << FilParser::VAL)
      | (1ULL << FilParser::VAR)
      | (1ULL << FilParser::WHILE)
      | (1ULL << FilParser::TRY)
      | (1ULL << FilParser::TRUE)
      | (1ULL << FilParser::FALSE)
      | (1ULL << FilParser::NULL_)
      | (1ULL << FilParser::IDENTIFIER)
      | (1ULL << FilParser::LPAREN)
      | (1ULL << FilParser::LBRAK)
      | (1ULL << FilParser::PLUS)
      | (1ULL << FilParser::MINUS)
      | (1ULL << FilParser::DIVIDE)
      | (1ULL << FilParser::TIMES)
      | (1ULL << FilParser::MOD)
      | (1ULL << FilParser::NOT)
      | (1ULL << FilParser::BAND)
      | (1ULL << FilParser::BOR)
      | (1ULL << FilParser::BXOR)
      | (1ULL << FilParser::INT)
      | (1ULL << FilParser::FLOAT)
      | (1ULL << FilParser::STRING)
      | (1ULL << FilParser::CHAR))) != 0)) {
      setState(530);
      expr(0);
      setState(535);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(536);
    match(FilParser::RBRAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FilParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> FilParser::_decisionToDFA;
atn::PredictionContextCache FilParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FilParser::_atn;
std::vector<uint16_t> FilParser::_serializedATN;

std::vector<std::string> FilParser::_ruleNames = {
  "program", "module", "import_", "expr", "function", "fun_params", "fun_param_list", 
  "fun_param", "fun_body", "function_decl", "lambda", "interface", "interface_body", 
  "class_", "class_modifier", "class_params", "class_param_list", "class_param", 
  "class_extends", "class_extend_list", "class_extend", "class_body", "class_function", 
  "class_variable", "class_atr_modifier", "class_constructor", "enum_", 
  "enum_body", "condition", "if_", "if_condition", "if_body", "else_if", 
  "else_", "switch_", "switch_condition", "switch_body", "switch_case", 
  "loop", "fori", "fori_condition", "foriter", "foriter_condition", "while_", 
  "exception", "catch_body", "binary_operator", "unary_calcul", "unary_operator", 
  "assignation", "assignation_operator", "cast", "function_call", "function_call_params", 
  "function_call_param_list", "variable_decl", "type", "litteral", "temp", 
  "expr_parenthesis", "expr_block"
};

std::vector<std::string> FilParser::_literalNames = {
  "", "'export'", "'module'", "'fun'", "'interface'", "'class'", "'abstract'", 
  "'open'", "'private'", "'public'", "'internal'", "'protected'", "'constructor'", 
  "'enum'", "'if'", "'else'", "'switch'", "'default'", "'for'", "'val'", 
  "'var'", "'while'", "'try'", "'catch'", "'true'", "'false'", "'null'", 
  "", "'.'", "'->'", "'{'", "'}'", "'('", "')'", "'['", "']'", "':'", "','", 
  "';'", "'='", "'+'", "'-'", "'/'", "'*'", "'%'", "'<<'", "'>>'", "'&&'", 
  "'||'", "'<'", "'>'", "'=='", "'<='", "'>='", "'!='", "'!'", "'&'", "'|'", 
  "'^'"
};

std::vector<std::string> FilParser::_symbolicNames = {
  "", "EXPORT", "MODULE", "FUN", "INTERFACE", "CLASS", "ABSTRACT", "OPEN", 
  "PRIVATE", "PUBLIC", "INTERNAL", "PROTECTED", "CONSTRUCTOR", "ENUM", "IF", 
  "ELSE", "SWITCH", "DEFAULT", "FOR", "VAL", "VAR", "WHILE", "TRY", "CATCH", 
  "TRUE", "FALSE", "NULL_", "IDENTIFIER", "DOT", "ARROW", "LBRACE", "RBRACE", 
  "LPAREN", "RPAREN", "LBRAK", "RBRAK", "COLON", "COMMA", "SEMICOLON", "EQ", 
  "PLUS", "MINUS", "DIVIDE", "TIMES", "MOD", "FLEFT", "FRIGHT", "AND", "OR", 
  "LE", "GE", "EQEQ", "LEQ", "GEQ", "NEQ", "NOT", "BAND", "BOR", "BXOR", 
  "INT", "FLOAT", "STRING", "CHAR", "COMMENT", "COMMENT_BLOCK", "SEPARATOR", 
  "MODULE_NAME", "IMPORT"
};

dfa::Vocabulary FilParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FilParser::_tokenNames;

FilParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x45, 0x21d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x3, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x7f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x82, 0xb, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x85, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x88, 0xb, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0xa1, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0xaf, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xb2, 
    0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0xb9, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xbf, 
    0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 
    0xc6, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xc9, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd2, 0xa, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xd9, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xdf, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xe4, 0xa, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0xe7, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xeb, 0xa, 0xe, 
    0xc, 0xe, 0xe, 0xe, 0xee, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xf6, 0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0xf9, 0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0xfc, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x102, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x109, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x10c, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x114, 0xa, 0x13, 0x5, 0x13, 
    0x116, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x7, 0x15, 0x11e, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x121, 
    0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x7, 0x17, 0x12a, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0x12d, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x5, 0x18, 0x132, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x142, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x148, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 
    0x14b, 0xb, 0x1d, 0x5, 0x1d, 0x14d, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x153, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x159, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0x15c, 0xb, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x15f, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x166, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x178, 0xa, 0x26, 0xc, 0x26, 
    0xe, 0x26, 0x17b, 0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x181, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x187, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x18c, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x192, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x196, 0xa, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x19a, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x5, 0x2a, 0x19e, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x1a6, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x5, 0x2e, 0x1b7, 0xa, 0x2e, 0x3, 0x2e, 0x6, 0x2e, 0x1ba, 0xa, 0x2e, 
    0xd, 0x2e, 0xe, 0x2e, 0x1bb, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1c5, 0xa, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x1d8, 0xa, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x5, 0x34, 0x1de, 0xa, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x1ec, 
    0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 
    0x38, 0x1f3, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x1f6, 0xb, 0x38, 0x3, 
    0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 
    0x1fe, 0xa, 0x39, 0x3, 0x39, 0x5, 0x39, 0x201, 0xa, 0x39, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x207, 0xa, 0x3a, 0x3, 0x3a, 
    0x5, 0x3a, 0x20a, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x7, 
    0x3e, 0x216, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x219, 0xb, 0x3e, 0x3, 
    0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x2, 0x3, 0x8, 0x3f, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x2, 0x7, 0x3, 
    0x2, 0x8, 0x9, 0x3, 0x2, 0xa, 0xd, 0x3, 0x2, 0x15, 0x16, 0x4, 0x2, 0x2a, 
    0x38, 0x3a, 0x3c, 0x4, 0x2, 0x1a, 0x1c, 0x3d, 0x40, 0x2, 0x233, 0x2, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x89, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xe, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xca, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0x16, 0xda, 0x3, 0x2, 0x2, 0x2, 0x18, 0xe0, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x105, 0x3, 0x2, 0x2, 0x2, 0x24, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x117, 0x3, 0x2, 0x2, 0x2, 0x28, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x122, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x125, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x131, 0x3, 0x2, 0x2, 0x2, 0x30, 0x136, 0x3, 0x2, 0x2, 0x2, 0x32, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x36, 0x13e, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x143, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x154, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x165, 0x3, 0x2, 0x2, 0x2, 0x42, 0x167, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x46, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x173, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x175, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x18d, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x193, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1a1, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x1d7, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1dd, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1e6, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x1ef, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x72, 0x202, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x76, 0x20d, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x213, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x80, 0x5, 0x4, 0x3, 0x2, 0x7d, 0x7f, 0x5, 0x6, 0x4, 0x2, 0x7e, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 0x85, 0x5, 0x8, 0x5, 
    0x2, 0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 
    0x7, 0x4, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x44, 0x2, 0x2, 0x8b, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x45, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x44, 
    0x2, 0x2, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x8, 0x5, 0x1, 
    0x2, 0x90, 0xa1, 0x5, 0xa, 0x6, 0x2, 0x91, 0xa1, 0x5, 0x16, 0xc, 0x2, 
    0x92, 0xa1, 0x5, 0x18, 0xd, 0x2, 0x93, 0xa1, 0x5, 0x1c, 0xf, 0x2, 0x94, 
    0xa1, 0x5, 0x36, 0x1c, 0x2, 0x95, 0xa1, 0x5, 0x3a, 0x1e, 0x2, 0x96, 
    0xa1, 0x5, 0x4e, 0x28, 0x2, 0x97, 0xa1, 0x5, 0x5a, 0x2e, 0x2, 0x98, 
    0xa1, 0x5, 0x60, 0x31, 0x2, 0x99, 0xa1, 0x5, 0x68, 0x35, 0x2, 0x9a, 
    0xa1, 0x7, 0x1d, 0x2, 0x2, 0x9b, 0xa1, 0x5, 0x6a, 0x36, 0x2, 0x9c, 0xa1, 
    0x5, 0x74, 0x3b, 0x2, 0x9d, 0xa1, 0x5, 0x70, 0x39, 0x2, 0x9e, 0xa1, 
    0x5, 0x78, 0x3d, 0x2, 0x9f, 0xa1, 0x5, 0x7a, 0x3e, 0x2, 0xa0, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0x91, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x93, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x95, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x96, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0xc, 0xd, 
    0x2, 0x2, 0xa3, 0xa4, 0x5, 0x5e, 0x30, 0x2, 0xa4, 0xa5, 0x5, 0x8, 0x5, 
    0xe, 0xa5, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0xc, 0xb, 0x2, 0x2, 
    0xa7, 0xa8, 0x7, 0x1e, 0x2, 0x2, 0xa8, 0xaf, 0x5, 0x8, 0x5, 0xc, 0xa9, 
    0xaa, 0xc, 0xa, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x1f, 0x2, 0x2, 0xab, 0xaf, 
    0x5, 0x8, 0x5, 0xb, 0xac, 0xad, 0xc, 0xc, 0x2, 0x2, 0xad, 0xaf, 0x5, 
    0x64, 0x33, 0x2, 0xae, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xae, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x5, 0x2, 0x2, 0xb4, 0xb5, 
    0x7, 0x1d, 0x2, 0x2, 0xb5, 0xb8, 0x5, 0xc, 0x7, 0x2, 0xb6, 0xb7, 0x7, 
    0x26, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x72, 0x3a, 0x2, 0xb8, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbb, 0x5, 0x12, 0xa, 0x2, 0xbb, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0xbc, 0xbe, 0x7, 0x22, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0xe, 0x8, 0x2, 0xbe, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x23, 0x2, 0x2, 0xc1, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc7, 0x5, 0x10, 0x9, 0x2, 0xc3, 0xc4, 0x7, 0x27, 
    0x2, 0x2, 0xc4, 0xc6, 0x5, 0x10, 0x9, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x1d, 0x2, 0x2, 0xcb, 0xcc, 
    0x7, 0x26, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x72, 0x3a, 0x2, 0xcd, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xd2, 0x5, 0x64, 0x33, 0x2, 0xcf, 0xd2, 0x5, 0x78, 
    0x3d, 0x2, 0xd0, 0xd2, 0x5, 0x7a, 0x3e, 0x2, 0xd1, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0x13, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x5, 0x2, 0x2, 0xd4, 
    0xd5, 0x7, 0x1d, 0x2, 0x2, 0xd5, 0xd8, 0x5, 0xc, 0x7, 0x2, 0xd6, 0xd7, 
    0x7, 0x26, 0x2, 0x2, 0xd7, 0xd9, 0x5, 0x72, 0x3a, 0x2, 0xd8, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xdb, 0x5, 0xc, 0x7, 0x2, 0xdb, 0xde, 0x7, 0x1f, 0x2, 
    0x2, 0xdc, 0xdf, 0x5, 0x7a, 0x3e, 0x2, 0xdd, 0xdf, 0x5, 0x78, 0x3d, 
    0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0x17, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x6, 0x2, 0x2, 0xe1, 
    0xe3, 0x7, 0x1d, 0x2, 0x2, 0xe2, 0xe4, 0x5, 0x20, 0x11, 0x2, 0xe3, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x1a, 0xe, 0x2, 0xe6, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xec, 0x7, 0x20, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x14, 0xb, 0x2, 
    0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 
    0x21, 0x2, 0x2, 0xf0, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x5, 0x1e, 
    0x10, 0x2, 0xf2, 0xf3, 0x7, 0x7, 0x2, 0x2, 0xf3, 0xf5, 0x7, 0x1d, 0x2, 
    0x2, 0xf4, 0xf6, 0x5, 0x20, 0x11, 0x2, 0xf5, 0xf4, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf9, 0x5, 0x26, 0x14, 0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x5, 
    0x2c, 0x17, 0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x9, 0x2, 0x2, 
    0x2, 0xfe, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xff, 0x101, 0x7, 0x22, 0x2, 0x2, 
    0x100, 0x102, 0x5, 0x22, 0x12, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 
    0x103, 0x104, 0x7, 0x23, 0x2, 0x2, 0x104, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0x10a, 0x5, 0x24, 0x13, 0x2, 0x106, 0x107, 0x7, 0x27, 0x2, 0x2, 
    0x107, 0x109, 0x5, 0x24, 0x13, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 
    0x109, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x10c, 
    0x10a, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x116, 0x5, 0x70, 0x39, 0x2, 0x10e, 
    0x10f, 0x7, 0x1d, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x26, 0x2, 0x2, 0x110, 
    0x113, 0x5, 0x72, 0x3a, 0x2, 0x111, 0x112, 0x7, 0x29, 0x2, 0x2, 0x112, 
    0x114, 0x5, 0x74, 0x3b, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x26, 0x2, 0x2, 0x118, 
    0x119, 0x5, 0x28, 0x15, 0x2, 0x119, 0x27, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x11f, 0x5, 0x2a, 0x16, 0x2, 0x11b, 0x11c, 0x7, 0x27, 0x2, 0x2, 0x11c, 
    0x11e, 0x5, 0x2a, 0x16, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x121, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x29, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 0x1d, 0x2, 0x2, 0x123, 0x124, 
    0x5, 0x6c, 0x37, 0x2, 0x124, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 
    0x7, 0x20, 0x2, 0x2, 0x126, 0x12b, 0x5, 0x34, 0x1b, 0x2, 0x127, 0x12a, 
    0x5, 0x30, 0x19, 0x2, 0x128, 0x12a, 0x5, 0x2e, 0x18, 0x2, 0x129, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 
    0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x21, 0x2, 0x2, 0x12f, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x130, 0x132, 0x7, 0x8, 0x2, 0x2, 0x131, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 
    0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x5, 0x32, 0x1a, 0x2, 0x134, 0x135, 
    0x5, 0xa, 0x6, 0x2, 0x135, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x5, 
    0x32, 0x1a, 0x2, 0x137, 0x138, 0x5, 0x70, 0x39, 0x2, 0x138, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x13a, 0x9, 0x3, 0x2, 0x2, 0x13a, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x13c, 0x7, 0xe, 0x2, 0x2, 0x13c, 0x13d, 0x5, 0x7a, 
    0x3e, 0x2, 0x13d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0xf, 
    0x2, 0x2, 0x13f, 0x141, 0x7, 0x1d, 0x2, 0x2, 0x140, 0x142, 0x5, 0x38, 
    0x1d, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 
    0x2, 0x2, 0x142, 0x37, 0x3, 0x2, 0x2, 0x2, 0x143, 0x14c, 0x7, 0x20, 
    0x2, 0x2, 0x144, 0x149, 0x7, 0x1d, 0x2, 0x2, 0x145, 0x146, 0x7, 0x27, 
    0x2, 0x2, 0x146, 0x148, 0x7, 0x1d, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 
    0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x14f, 0x7, 0x21, 0x2, 0x2, 0x14f, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x150, 0x153, 0x5, 0x3c, 0x1f, 0x2, 0x151, 0x153, 0x5, 0x46, 
    0x24, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x7, 0x10, 
    0x2, 0x2, 0x155, 0x156, 0x5, 0x3e, 0x20, 0x2, 0x156, 0x15a, 0x5, 0x40, 
    0x21, 0x2, 0x157, 0x159, 0x5, 0x42, 0x22, 0x2, 0x158, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x44, 
    0x23, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x5, 0x78, 
    0x3d, 0x2, 0x161, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x166, 0x5, 0x8, 
    0x5, 0x2, 0x163, 0x166, 0x5, 0x7a, 0x3e, 0x2, 0x164, 0x166, 0x5, 0x78, 
    0x3d, 0x2, 0x165, 0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x166, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x168, 0x7, 0x11, 0x2, 0x2, 0x168, 0x169, 0x7, 0x10, 0x2, 
    0x2, 0x169, 0x16a, 0x5, 0x3e, 0x20, 0x2, 0x16a, 0x16b, 0x5, 0x40, 0x21, 
    0x2, 0x16b, 0x43, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x11, 0x2, 
    0x2, 0x16d, 0x16e, 0x5, 0x40, 0x21, 0x2, 0x16e, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x170, 0x7, 0x12, 0x2, 0x2, 0x170, 0x171, 0x5, 0x48, 0x25, 
    0x2, 0x171, 0x172, 0x5, 0x4a, 0x26, 0x2, 0x172, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x174, 0x5, 0x78, 0x3d, 0x2, 0x174, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x179, 0x7, 0x20, 0x2, 0x2, 0x176, 0x178, 0x5, 0x4c, 0x27, 
    0x2, 0x177, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 
    0x2, 0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x17d, 0x7, 0x21, 0x2, 0x2, 0x17d, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x17e, 0x181, 0x5, 0x74, 0x3b, 0x2, 0x17f, 0x181, 0x7, 0x13, 0x2, 
    0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 
    0x2, 0x181, 0x182, 0x3, 0x2, 0x2, 0x2, 0x182, 0x186, 0x7, 0x1f, 0x2, 
    0x2, 0x183, 0x187, 0x5, 0x8, 0x5, 0x2, 0x184, 0x187, 0x5, 0x7a, 0x3e, 
    0x2, 0x185, 0x187, 0x5, 0x78, 0x3d, 0x2, 0x186, 0x183, 0x3, 0x2, 0x2, 
    0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x187, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18c, 0x5, 0x50, 0x29, 
    0x2, 0x189, 0x18c, 0x5, 0x54, 0x2b, 0x2, 0x18a, 0x18c, 0x5, 0x58, 0x2d, 
    0x2, 0x18b, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x18d, 0x18e, 0x7, 0x14, 0x2, 0x2, 0x18e, 0x191, 0x5, 0x52, 0x2a, 0x2, 
    0x18f, 0x192, 0x5, 0x8, 0x5, 0x2, 0x190, 0x192, 0x5, 0x7a, 0x3e, 0x2, 
    0x191, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x190, 0x3, 0x2, 0x2, 0x2, 
    0x192, 0x51, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x7, 0x22, 0x2, 0x2, 
    0x194, 0x196, 0x5, 0x70, 0x39, 0x2, 0x195, 0x194, 0x3, 0x2, 0x2, 0x2, 
    0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 0x2, 
    0x197, 0x199, 0x7, 0x28, 0x2, 0x2, 0x198, 0x19a, 0x5, 0x8, 0x5, 0x2, 
    0x199, 0x198, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19d, 0x7, 0x28, 0x2, 0x2, 
    0x19c, 0x19e, 0x5, 0x8, 0x5, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 
    0x19f, 0x1a0, 0x7, 0x23, 0x2, 0x2, 0x1a0, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x1a1, 0x1a2, 0x7, 0x14, 0x2, 0x2, 0x1a2, 0x1a5, 0x5, 0x56, 0x2c, 0x2, 
    0x1a3, 0x1a6, 0x5, 0x8, 0x5, 0x2, 0x1a4, 0x1a6, 0x5, 0x7a, 0x3e, 0x2, 
    0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
    0x1a6, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x22, 0x2, 0x2, 
    0x1a8, 0x1a9, 0x9, 0x4, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x1d, 0x2, 0x2, 
    0x1aa, 0x1ab, 0x7, 0x26, 0x2, 0x2, 0x1ab, 0x1ac, 0x7, 0x1d, 0x2, 0x2, 
    0x1ac, 0x1ad, 0x7, 0x23, 0x2, 0x2, 0x1ad, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1af, 0x7, 0x17, 0x2, 0x2, 0x1af, 0x1b0, 0x5, 0x3e, 0x20, 0x2, 
    0x1b0, 0x1b1, 0x5, 0x40, 0x21, 0x2, 0x1b1, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x1b2, 0x1b6, 0x7, 0x18, 0x2, 0x2, 0x1b3, 0x1b7, 0x5, 0x8, 0x5, 0x2, 
    0x1b4, 0x1b7, 0x5, 0x7a, 0x3e, 0x2, 0x1b5, 0x1b7, 0x5, 0x78, 0x3d, 0x2, 
    0x1b6, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 0x2, 
    0x1b6, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 0x3, 0x2, 0x2, 0x2, 
    0x1b8, 0x1ba, 0x5, 0x5c, 0x2f, 0x2, 0x1b9, 0x1b8, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
    0x1be, 0x7, 0x19, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 0x22, 0x2, 0x2, 0x1bf, 
    0x1c0, 0x5, 0x10, 0x9, 0x2, 0x1c0, 0x1c4, 0x7, 0x23, 0x2, 0x2, 0x1c1, 
    0x1c5, 0x5, 0x8, 0x5, 0x2, 0x1c2, 0x1c5, 0x5, 0x7a, 0x3e, 0x2, 0x1c3, 
    0x1c5, 0x5, 0x78, 0x3d, 0x2, 0x1c4, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x9, 0x5, 0x2, 0x2, 0x1c7, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x5, 0x62, 0x32, 0x2, 0x1c9, 0x1ca, 
    0x5, 0x8, 0x5, 0x2, 0x1ca, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1d8, 0x7, 
    0x2a, 0x2, 0x2, 0x1cc, 0x1d8, 0x7, 0x2b, 0x2, 0x2, 0x1cd, 0x1d8, 0x7, 
    0x2c, 0x2, 0x2, 0x1ce, 0x1d8, 0x7, 0x2d, 0x2, 0x2, 0x1cf, 0x1d8, 0x7, 
    0x2e, 0x2, 0x2, 0x1d0, 0x1d8, 0x7, 0x39, 0x2, 0x2, 0x1d1, 0x1d8, 0x7, 
    0x3a, 0x2, 0x2, 0x1d2, 0x1d8, 0x7, 0x3c, 0x2, 0x2, 0x1d3, 0x1d8, 0x7, 
    0x3b, 0x2, 0x2, 0x1d4, 0x1d5, 0x7, 0x24, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 
    0x3d, 0x2, 0x2, 0x1d6, 0x1d8, 0x7, 0x25, 0x2, 0x2, 0x1d7, 0x1cb, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1cd, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1cf, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d1, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d3, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x1d9, 0x1da, 0x5, 0x66, 0x34, 0x2, 0x1da, 0x1db, 0x5, 0x8, 
    0x5, 0x2, 0x1db, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1de, 0x5, 0x62, 
    0x32, 0x2, 0x1dd, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x3, 0x2, 
    0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x29, 
    0x2, 0x2, 0x1e0, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x7, 0x22, 
    0x2, 0x2, 0x1e2, 0x1e3, 0x5, 0x72, 0x3a, 0x2, 0x1e3, 0x1e4, 0x7, 0x23, 
    0x2, 0x2, 0x1e4, 0x1e5, 0x5, 0x8, 0x5, 0x2, 0x1e5, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x1e6, 0x1e7, 0x7, 0x1d, 0x2, 0x2, 0x1e7, 0x1e8, 0x5, 0x6c, 0x37, 
    0x2, 0x1e8, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1eb, 0x7, 0x22, 0x2, 
    0x2, 0x1ea, 0x1ec, 0x5, 0x6e, 0x38, 0x2, 0x1eb, 0x1ea, 0x3, 0x2, 0x2, 
    0x2, 0x1eb, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x3, 0x2, 0x2, 
    0x2, 0x1ed, 0x1ee, 0x7, 0x23, 0x2, 0x2, 0x1ee, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1f4, 0x5, 0x8, 0x5, 0x2, 0x1f0, 0x1f1, 0x7, 0x27, 0x2, 
    0x2, 0x1f1, 0x1f3, 0x5, 0x8, 0x5, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 
    0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x9, 0x4, 0x2, 0x2, 
    0x1f8, 0x200, 0x7, 0x1d, 0x2, 0x2, 0x1f9, 0x1fa, 0x7, 0x26, 0x2, 0x2, 
    0x1fa, 0x201, 0x5, 0x72, 0x3a, 0x2, 0x1fb, 0x1fc, 0x7, 0x26, 0x2, 0x2, 
    0x1fc, 0x1fe, 0x5, 0x72, 0x3a, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fd, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 
    0x1ff, 0x201, 0x5, 0x64, 0x33, 0x2, 0x200, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x200, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x201, 0x71, 0x3, 0x2, 0x2, 0x2, 0x202, 
    0x209, 0x7, 0x1d, 0x2, 0x2, 0x203, 0x20a, 0x7, 0x2d, 0x2, 0x2, 0x204, 
    0x206, 0x7, 0x24, 0x2, 0x2, 0x205, 0x207, 0x7, 0x3d, 0x2, 0x2, 0x206, 
    0x205, 0x3, 0x2, 0x2, 0x2, 0x206, 0x207, 0x3, 0x2, 0x2, 0x2, 0x207, 
    0x208, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20a, 0x7, 0x25, 0x2, 0x2, 0x209, 
    0x203, 0x3, 0x2, 0x2, 0x2, 0x209, 0x204, 0x3, 0x2, 0x2, 0x2, 0x209, 
    0x20a, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x73, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 
    0x9, 0x6, 0x2, 0x2, 0x20c, 0x75, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x7, 
    0x1e, 0x2, 0x2, 0x20e, 0x77, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x210, 0x7, 
    0x22, 0x2, 0x2, 0x210, 0x211, 0x5, 0x8, 0x5, 0x2, 0x211, 0x212, 0x7, 
    0x23, 0x2, 0x2, 0x212, 0x79, 0x3, 0x2, 0x2, 0x2, 0x213, 0x217, 0x7, 
    0x24, 0x2, 0x2, 0x214, 0x216, 0x5, 0x8, 0x5, 0x2, 0x215, 0x214, 0x3, 
    0x2, 0x2, 0x2, 0x216, 0x219, 0x3, 0x2, 0x2, 0x2, 0x217, 0x215, 0x3, 
    0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21a, 0x3, 
    0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 0x7, 
    0x25, 0x2, 0x2, 0x21b, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x37, 0x80, 0x86, 0xa0, 
    0xae, 0xb0, 0xb8, 0xbe, 0xc7, 0xd1, 0xd8, 0xde, 0xe3, 0xe6, 0xec, 0xf5, 
    0xf8, 0xfb, 0x101, 0x10a, 0x113, 0x115, 0x11f, 0x129, 0x12b, 0x131, 
    0x141, 0x149, 0x14c, 0x152, 0x15a, 0x15e, 0x165, 0x179, 0x180, 0x186, 
    0x18b, 0x191, 0x195, 0x199, 0x19d, 0x1a5, 0x1b6, 0x1bb, 0x1c4, 0x1d7, 
    0x1dd, 0x1eb, 0x1f4, 0x1fd, 0x200, 0x206, 0x209, 0x217, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FilParser::Initializer FilParser::_init;
