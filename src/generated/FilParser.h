
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


namespace antlrcppfil {


class  FilParser : public antlr4::Parser {
public:
  enum {
    EXPORT = 1, MODULE = 2, FUN = 3, INTERFACE = 4, CLASS = 5, ABSTRACT = 6, 
    OPEN = 7, PRIVATE = 8, PUBLIC = 9, INTERNAL = 10, PROTECTED = 11, CONSTRUCTOR = 12, 
    ENUM = 13, IF = 14, ELSE = 15, SWITCH = 16, DEFAULT = 17, FOR = 18, 
    VAL = 19, VAR = 20, WHILE = 21, TRY = 22, CATCH = 23, TRUE = 24, FALSE = 25, 
    NULL_ = 26, IDENTIFIER = 27, DOT = 28, ARROW = 29, LBRACE = 30, RBRACE = 31, 
    LPAREN = 32, RPAREN = 33, LBRAK = 34, RBRAK = 35, COLON = 36, COMMA = 37, 
    SEMICOLON = 38, EQ = 39, PLUS = 40, MINUS = 41, DIVIDE = 42, TIMES = 43, 
    MOD = 44, FLEFT = 45, FRIGHT = 46, AND = 47, OR = 48, LE = 49, GE = 50, 
    EQEQ = 51, LEQ = 52, GEQ = 53, NEQ = 54, NOT = 55, BAND = 56, BOR = 57, 
    BXOR = 58, INT = 59, FLOAT = 60, STRING = 61, CHAR = 62, COMMENT = 63, 
    COMMENT_BLOCK = 64, SEPARATOR = 65, MODULE_NAME = 66, IMPORT = 67
  };

  enum {
    RuleProgram = 0, RuleModule = 1, RuleImport_ = 2, RuleExpr = 3, RuleFunction = 4, 
    RuleFun_params = 5, RuleFun_param_list = 6, RuleFun_param = 7, RuleFun_body = 8, 
    RuleFunction_decl = 9, RuleLambda = 10, RuleInterface = 11, RuleInterface_body = 12, 
    RuleClass_ = 13, RuleClass_modifier = 14, RuleClass_params = 15, RuleClass_param_list = 16, 
    RuleClass_param = 17, RuleClass_extends = 18, RuleClass_extend_list = 19, 
    RuleClass_extend = 20, RuleClass_body = 21, RuleClass_function = 22, 
    RuleClass_variable = 23, RuleClass_atr_modifier = 24, RuleClass_constructor = 25, 
    RuleEnum_ = 26, RuleEnum_body = 27, RuleCondition = 28, RuleIf_ = 29, 
    RuleIf_condition = 30, RuleIf_body = 31, RuleElse_if = 32, RuleElse_ = 33, 
    RuleSwitch_ = 34, RuleSwitch_condition = 35, RuleSwitch_body = 36, RuleSwitch_case = 37, 
    RuleLoop = 38, RuleFori = 39, RuleFori_condition = 40, RuleForiter = 41, 
    RuleForiter_condition = 42, RuleWhile_ = 43, RuleException = 44, RuleCatch_body = 45, 
    RuleBinary_operator = 46, RuleUnary_calcul = 47, RuleUnary_operator = 48, 
    RuleAssignation = 49, RuleAssignation_operator = 50, RuleCast = 51, 
    RuleFunction_call = 52, RuleFunction_call_params = 53, RuleFunction_call_param_list = 54, 
    RuleVariable_decl = 55, RuleType = 56, RuleLitteral = 57, RuleTemp = 58, 
    RuleExpr_parenthesis = 59, RuleExpr_block = 60
  };

  FilParser(antlr4::TokenStream *input);
  ~FilParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ModuleContext;
  class Import_Context;
  class ExprContext;
  class FunctionContext;
  class Fun_paramsContext;
  class Fun_param_listContext;
  class Fun_paramContext;
  class Fun_bodyContext;
  class Function_declContext;
  class LambdaContext;
  class InterfaceContext;
  class Interface_bodyContext;
  class Class_Context;
  class Class_modifierContext;
  class Class_paramsContext;
  class Class_param_listContext;
  class Class_paramContext;
  class Class_extendsContext;
  class Class_extend_listContext;
  class Class_extendContext;
  class Class_bodyContext;
  class Class_functionContext;
  class Class_variableContext;
  class Class_atr_modifierContext;
  class Class_constructorContext;
  class Enum_Context;
  class Enum_bodyContext;
  class ConditionContext;
  class If_Context;
  class If_conditionContext;
  class If_bodyContext;
  class Else_ifContext;
  class Else_Context;
  class Switch_Context;
  class Switch_conditionContext;
  class Switch_bodyContext;
  class Switch_caseContext;
  class LoopContext;
  class ForiContext;
  class Fori_conditionContext;
  class ForiterContext;
  class Foriter_conditionContext;
  class While_Context;
  class ExceptionContext;
  class Catch_bodyContext;
  class Binary_operatorContext;
  class Unary_calculContext;
  class Unary_operatorContext;
  class AssignationContext;
  class Assignation_operatorContext;
  class CastContext;
  class Function_callContext;
  class Function_call_paramsContext;
  class Function_call_param_listContext;
  class Variable_declContext;
  class TypeContext;
  class LitteralContext;
  class TempContext;
  class Expr_parenthesisContext;
  class Expr_blockContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ModuleContext *module();
    std::vector<Import_Context *> import_();
    Import_Context* import_(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *MODULE_NAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  Import_Context : public antlr4::ParserRuleContext {
  public:
    Import_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    antlr4::tree::TerminalNode *MODULE_NAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_Context* import_();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    LambdaContext *lambda();
    InterfaceContext *interface();
    Class_Context *class_();
    Enum_Context *enum_();
    ConditionContext *condition();
    LoopContext *loop();
    ExceptionContext *exception();
    Unary_calculContext *unary_calcul();
    CastContext *cast();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Function_callContext *function_call();
    LitteralContext *litteral();
    Variable_declContext *variable_decl();
    Expr_parenthesisContext *expr_parenthesis();
    Expr_blockContext *expr_block();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Binary_operatorContext *binary_operator();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ARROW();
    AssignationContext *assignation();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Fun_paramsContext *fun_params();
    Fun_bodyContext *fun_body();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  Fun_paramsContext : public antlr4::ParserRuleContext {
  public:
    Fun_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Fun_param_listContext *fun_param_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_paramsContext* fun_params();

  class  Fun_param_listContext : public antlr4::ParserRuleContext {
  public:
    Fun_param_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Fun_paramContext *> fun_param();
    Fun_paramContext* fun_param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_param_listContext* fun_param_list();

  class  Fun_paramContext : public antlr4::ParserRuleContext {
  public:
    Fun_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_paramContext* fun_param();

  class  Fun_bodyContext : public antlr4::ParserRuleContext {
  public:
    Fun_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignationContext *assignation();
    Expr_parenthesisContext *expr_parenthesis();
    Expr_blockContext *expr_block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_bodyContext* fun_body();

  class  Function_declContext : public antlr4::ParserRuleContext {
  public:
    Function_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Fun_paramsContext *fun_params();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_declContext* function_decl();

  class  LambdaContext : public antlr4::ParserRuleContext {
  public:
    LambdaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Fun_paramsContext *fun_params();
    antlr4::tree::TerminalNode *ARROW();
    Expr_blockContext *expr_block();
    Expr_parenthesisContext *expr_parenthesis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaContext* lambda();

  class  InterfaceContext : public antlr4::ParserRuleContext {
  public:
    InterfaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Class_paramsContext *class_params();
    Interface_bodyContext *interface_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceContext* interface();

  class  Interface_bodyContext : public antlr4::ParserRuleContext {
  public:
    Interface_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<Function_declContext *> function_decl();
    Function_declContext* function_decl(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_bodyContext* interface_body();

  class  Class_Context : public antlr4::ParserRuleContext {
  public:
    Class_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_modifierContext *class_modifier();
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Class_paramsContext *class_params();
    Class_extendsContext *class_extends();
    Class_bodyContext *class_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_Context* class_();

  class  Class_modifierContext : public antlr4::ParserRuleContext {
  public:
    Class_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *OPEN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_modifierContext* class_modifier();

  class  Class_paramsContext : public antlr4::ParserRuleContext {
  public:
    Class_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Class_param_listContext *class_param_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_paramsContext* class_params();

  class  Class_param_listContext : public antlr4::ParserRuleContext {
  public:
    Class_param_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Class_paramContext *> class_param();
    Class_paramContext* class_param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_param_listContext* class_param_list();

  class  Class_paramContext : public antlr4::ParserRuleContext {
  public:
    Class_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_declContext *variable_decl();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    antlr4::tree::TerminalNode *EQ();
    LitteralContext *litteral();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_paramContext* class_param();

  class  Class_extendsContext : public antlr4::ParserRuleContext {
  public:
    Class_extendsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    Class_extend_listContext *class_extend_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_extendsContext* class_extends();

  class  Class_extend_listContext : public antlr4::ParserRuleContext {
  public:
    Class_extend_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Class_extendContext *> class_extend();
    Class_extendContext* class_extend(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_extend_listContext* class_extend_list();

  class  Class_extendContext : public antlr4::ParserRuleContext {
  public:
    Class_extendContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Function_call_paramsContext *function_call_params();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_extendContext* class_extend();

  class  Class_bodyContext : public antlr4::ParserRuleContext {
  public:
    Class_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    Class_constructorContext *class_constructor();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<Class_variableContext *> class_variable();
    Class_variableContext* class_variable(size_t i);
    std::vector<Class_functionContext *> class_function();
    Class_functionContext* class_function(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_bodyContext* class_body();

  class  Class_functionContext : public antlr4::ParserRuleContext {
  public:
    Class_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_atr_modifierContext *class_atr_modifier();
    FunctionContext *function();
    antlr4::tree::TerminalNode *ABSTRACT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_functionContext* class_function();

  class  Class_variableContext : public antlr4::ParserRuleContext {
  public:
    Class_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_atr_modifierContext *class_atr_modifier();
    Variable_declContext *variable_decl();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_variableContext* class_variable();

  class  Class_atr_modifierContext : public antlr4::ParserRuleContext {
  public:
    Class_atr_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *INTERNAL();
    antlr4::tree::TerminalNode *PROTECTED();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_atr_modifierContext* class_atr_modifier();

  class  Class_constructorContext : public antlr4::ParserRuleContext {
  public:
    Class_constructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTRUCTOR();
    Expr_blockContext *expr_block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_constructorContext* class_constructor();

  class  Enum_Context : public antlr4::ParserRuleContext {
  public:
    Enum_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Enum_bodyContext *enum_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_Context* enum_();

  class  Enum_bodyContext : public antlr4::ParserRuleContext {
  public:
    Enum_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_bodyContext* enum_body();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_Context *if_();
    Switch_Context *switch_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  If_Context : public antlr4::ParserRuleContext {
  public:
    If_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    If_conditionContext *if_condition();
    If_bodyContext *if_body();
    std::vector<Else_ifContext *> else_if();
    Else_ifContext* else_if(size_t i);
    Else_Context *else_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_Context* if_();

  class  If_conditionContext : public antlr4::ParserRuleContext {
  public:
    If_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_parenthesisContext *expr_parenthesis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_conditionContext* if_condition();

  class  If_bodyContext : public antlr4::ParserRuleContext {
  public:
    If_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    Expr_blockContext *expr_block();
    Expr_parenthesisContext *expr_parenthesis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_bodyContext* if_body();

  class  Else_ifContext : public antlr4::ParserRuleContext {
  public:
    Else_ifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *IF();
    If_conditionContext *if_condition();
    If_bodyContext *if_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_ifContext* else_if();

  class  Else_Context : public antlr4::ParserRuleContext {
  public:
    Else_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    If_bodyContext *if_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_Context* else_();

  class  Switch_Context : public antlr4::ParserRuleContext {
  public:
    Switch_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    Switch_conditionContext *switch_condition();
    Switch_bodyContext *switch_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_Context* switch_();

  class  Switch_conditionContext : public antlr4::ParserRuleContext {
  public:
    Switch_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_parenthesisContext *expr_parenthesis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_conditionContext* switch_condition();

  class  Switch_bodyContext : public antlr4::ParserRuleContext {
  public:
    Switch_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<Switch_caseContext *> switch_case();
    Switch_caseContext* switch_case(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_bodyContext* switch_body();

  class  Switch_caseContext : public antlr4::ParserRuleContext {
  public:
    Switch_caseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARROW();
    LitteralContext *litteral();
    antlr4::tree::TerminalNode *DEFAULT();
    ExprContext *expr();
    Expr_blockContext *expr_block();
    Expr_parenthesisContext *expr_parenthesis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_caseContext* switch_case();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForiContext *fori();
    ForiterContext *foriter();
    While_Context *while_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopContext* loop();

  class  ForiContext : public antlr4::ParserRuleContext {
  public:
    ForiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Fori_conditionContext *fori_condition();
    ExprContext *expr();
    Expr_blockContext *expr_block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForiContext* fori();

  class  Fori_conditionContext : public antlr4::ParserRuleContext {
  public:
    Fori_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    Variable_declContext *variable_decl();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fori_conditionContext* fori_condition();

  class  ForiterContext : public antlr4::ParserRuleContext {
  public:
    ForiterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Foriter_conditionContext *foriter_condition();
    ExprContext *expr();
    Expr_blockContext *expr_block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForiterContext* foriter();

  class  Foriter_conditionContext : public antlr4::ParserRuleContext {
  public:
    Foriter_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *VAL();
    antlr4::tree::TerminalNode *VAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Foriter_conditionContext* foriter_condition();

  class  While_Context : public antlr4::ParserRuleContext {
  public:
    While_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    If_conditionContext *if_condition();
    If_bodyContext *if_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_Context* while_();

  class  ExceptionContext : public antlr4::ParserRuleContext {
  public:
    ExceptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    ExprContext *expr();
    Expr_blockContext *expr_block();
    Expr_parenthesisContext *expr_parenthesis();
    std::vector<Catch_bodyContext *> catch_body();
    Catch_bodyContext* catch_body(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptionContext* exception();

  class  Catch_bodyContext : public antlr4::ParserRuleContext {
  public:
    Catch_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCH();
    antlr4::tree::TerminalNode *LPAREN();
    Fun_paramContext *fun_param();
    antlr4::tree::TerminalNode *RPAREN();
    ExprContext *expr();
    Expr_blockContext *expr_block();
    Expr_parenthesisContext *expr_parenthesis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Catch_bodyContext* catch_body();

  class  Binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *FLEFT();
    antlr4::tree::TerminalNode *FRIGHT();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *EQEQ();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BOR();
    antlr4::tree::TerminalNode *BXOR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Unary_calculContext : public antlr4::ParserRuleContext {
  public:
    Unary_calculContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_operatorContext *unary_operator();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_calculContext* unary_calcul();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BXOR();
    antlr4::tree::TerminalNode *BOR();
    antlr4::tree::TerminalNode *LBRAK();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *RBRAK();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  AssignationContext : public antlr4::ParserRuleContext {
  public:
    AssignationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignation_operatorContext *assignation_operator();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignationContext* assignation();

  class  Assignation_operatorContext : public antlr4::ParserRuleContext {
  public:
    Assignation_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    Unary_operatorContext *unary_operator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignation_operatorContext* assignation_operator();

  class  CastContext : public antlr4::ParserRuleContext {
  public:
    CastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    TypeContext *type();
    antlr4::tree::TerminalNode *RPAREN();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CastContext* cast();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Function_call_paramsContext *function_call_params();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();

  class  Function_call_paramsContext : public antlr4::ParserRuleContext {
  public:
    Function_call_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Function_call_param_listContext *function_call_param_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_call_paramsContext* function_call_params();

  class  Function_call_param_listContext : public antlr4::ParserRuleContext {
  public:
    Function_call_param_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_call_param_listContext* function_call_param_list();

  class  Variable_declContext : public antlr4::ParserRuleContext {
  public:
    Variable_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *VAL();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    AssignationContext *assignation();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declContext* variable_decl();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *LBRAK();
    antlr4::tree::TerminalNode *RBRAK();
    antlr4::tree::TerminalNode *INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  LitteralContext : public antlr4::ParserRuleContext {
  public:
    LitteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *NULL_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LitteralContext* litteral();

  class  TempContext : public antlr4::ParserRuleContext {
  public:
    TempContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TempContext* temp();

  class  Expr_parenthesisContext : public antlr4::ParserRuleContext {
  public:
    Expr_parenthesisContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_parenthesisContext* expr_parenthesis();

  class  Expr_blockContext : public antlr4::ParserRuleContext {
  public:
    Expr_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRAK();
    antlr4::tree::TerminalNode *RBRAK();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_blockContext* expr_block();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcppfil
