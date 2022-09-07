
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcppfil {


class  FilParser : public antlr4::Parser {
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

  enum {
    RuleProgram = 0, RuleExpr = 1, RuleFunction = 2, RuleFunction_name = 3, 
    RuleFun_params = 4, RuleFun_param_list = 5, RuleFun_param = 6, RuleFun_body = 7, 
    RuleFunction_decl = 8, RuleLambda = 9, RuleInterface = 10, RuleInterface_body = 11, 
    RuleClass_ = 12, RuleClass_modifier = 13, RuleClass_identifier = 14, 
    RuleClass_generic = 15, RuleClass_params = 16, RuleClass_param_list = 17, 
    RuleClass_param = 18, RuleClass_extends = 19, RuleClass_extend_list = 20, 
    RuleClass_extend = 21, RuleClass_body = 22, RuleClass_function = 23, 
    RuleClass_variable = 24, RuleClass_atr_modifier = 25, RuleClass_constructor = 26, 
    RuleEnum_ = 27, RuleEnum_body = 28, RuleCondition = 29, RuleIf_ = 30, 
    RuleIf_condition = 31, RuleIf_body = 32, RuleElse_if = 33, RuleElse_ = 34, 
    RuleSwitch_ = 35, RuleSwitch_condition = 36, RuleSwitch_body = 37, RuleSwitch_case = 38, 
    RuleLoop = 39, RuleFori = 40, RuleFori_condition = 41, RuleForiter = 42, 
    RuleForiter_condition = 43, RuleWhile_ = 44, RuleException = 45, RuleCatch_body = 46, 
    RuleBinary_operator = 47, RuleUnary_op_pre = 48, RuleUnary_op_post = 49, 
    RuleUnary_operator = 50, RuleAssignation = 51, RuleAssignation_operator = 52, 
    RuleCast = 53, RuleFunction_call = 54, RuleFunction_call_params = 55, 
    RuleFunction_call_param_list = 56, RuleVariable_decl = 57, RuleArray_assign = 58, 
    RuleType = 59, RuleLitteral = 60, RuleExpr_parenthesis = 61, RuleExpr_block = 62
  };

  explicit FilParser(antlr4::TokenStream *input);

  FilParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FilParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class ExprContext;
  class FunctionContext;
  class Function_nameContext;
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
  class Class_identifierContext;
  class Class_genericContext;
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
  class Unary_op_preContext;
  class Unary_op_postContext;
  class Unary_operatorContext;
  class AssignationContext;
  class Assignation_operatorContext;
  class CastContext;
  class Function_callContext;
  class Function_call_paramsContext;
  class Function_call_param_listContext;
  class Variable_declContext;
  class Array_assignContext;
  class TypeContext;
  class LitteralContext;
  class Expr_parenthesisContext;
  class Expr_blockContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    std::vector<antlr4::tree::TerminalNode *> IMPORT();
    antlr4::tree::TerminalNode* IMPORT(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EXPORT();
    antlr4::tree::TerminalNode* EXPORT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    LambdaContext *lambda();
    InterfaceContext *interface();
    Class_Context *class_();
    Enum_Context *enum_();
    Variable_declContext *variable_decl();
    ConditionContext *condition();
    LoopContext *loop();
    Function_callContext *function_call();
    ExceptionContext *exception();
    Unary_op_preContext *unary_op_pre();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    CastContext *cast();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Class_identifierContext *class_identifier();
    LitteralContext *litteral();
    antlr4::tree::TerminalNode *NEW();
    Function_call_paramsContext *function_call_params();
    Expr_parenthesisContext *expr_parenthesis();
    Expr_blockContext *expr_block();
    Array_assignContext *array_assign();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ARROW();
    Binary_operatorContext *binary_operator();
    Unary_op_postContext *unary_op_post();
    AssignationContext *assignation();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUN();
    Function_nameContext *function_name();
    Fun_paramsContext *fun_params();
    Fun_bodyContext *fun_body();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  Function_nameContext : public antlr4::ParserRuleContext {
  public:
    Function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPERATOR();
    Binary_operatorContext *binary_operator();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_nameContext* function_name();

  class  Fun_paramsContext : public antlr4::ParserRuleContext {
  public:
    Fun_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Fun_param_listContext *fun_param_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_param_listContext* fun_param_list();

  class  Fun_paramContext : public antlr4::ParserRuleContext {
  public:
    Fun_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_paramContext* fun_param();

  class  Fun_bodyContext : public antlr4::ParserRuleContext {
  public:
    Fun_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignationContext *assignation();
    Expr_parenthesisContext *expr_parenthesis();
    Expr_blockContext *expr_block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_bodyContext* fun_body();

  class  Function_declContext : public antlr4::ParserRuleContext {
  public:
    Function_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUN();
    Function_nameContext *function_name();
    Fun_paramsContext *fun_params();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_bodyContext* interface_body();

  class  Class_Context : public antlr4::ParserRuleContext {
  public:
    Class_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    Class_identifierContext *class_identifier();
    Class_modifierContext *class_modifier();
    Class_paramsContext *class_params();
    Class_extendsContext *class_extends();
    Class_bodyContext *class_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_Context* class_();

  class  Class_modifierContext : public antlr4::ParserRuleContext {
  public:
    Class_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *OPEN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_modifierContext* class_modifier();

  class  Class_identifierContext : public antlr4::ParserRuleContext {
  public:
    Class_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *TIMES();
    Class_genericContext *class_generic();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_identifierContext* class_identifier();

  class  Class_genericContext : public antlr4::ParserRuleContext {
  public:
    Class_genericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_genericContext* class_generic();

  class  Class_paramsContext : public antlr4::ParserRuleContext {
  public:
    Class_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Class_param_listContext *class_param_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_paramContext* class_param();

  class  Class_extendsContext : public antlr4::ParserRuleContext {
  public:
    Class_extendsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    Class_extend_listContext *class_extend_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_extend_listContext* class_extend_list();

  class  Class_extendContext : public antlr4::ParserRuleContext {
  public:
    Class_extendContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_identifierContext *class_identifier();
    Function_call_paramsContext *function_call_params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_extendContext* class_extend();

  class  Class_bodyContext : public antlr4::ParserRuleContext {
  public:
    Class_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    Class_constructorContext *class_constructor();
    std::vector<Class_variableContext *> class_variable();
    Class_variableContext* class_variable(size_t i);
    std::vector<Class_functionContext *> class_function();
    Class_functionContext* class_function(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_bodyContext* class_body();

  class  Class_functionContext : public antlr4::ParserRuleContext {
  public:
    Class_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    Function_declContext *function_decl();
    Class_atr_modifierContext *class_atr_modifier();
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *OVERRIDE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_functionContext* class_function();

  class  Class_variableContext : public antlr4::ParserRuleContext {
  public:
    Class_variableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_atr_modifierContext *class_atr_modifier();
    Variable_declContext *variable_decl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_atr_modifierContext* class_atr_modifier();

  class  Class_constructorContext : public antlr4::ParserRuleContext {
  public:
    Class_constructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTRUCTOR();
    Expr_blockContext *expr_block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_constructorContext* class_constructor();

  class  Enum_Context : public antlr4::ParserRuleContext {
  public:
    Enum_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Enum_bodyContext *enum_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_bodyContext* enum_body();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_Context *if_();
    Switch_Context *switch_();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_Context* if_();

  class  If_conditionContext : public antlr4::ParserRuleContext {
  public:
    If_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_parenthesisContext *expr_parenthesis();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_conditionContext* if_condition();

  class  If_bodyContext : public antlr4::ParserRuleContext {
  public:
    If_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_blockContext *expr_block();
    Expr_parenthesisContext *expr_parenthesis();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_ifContext* else_if();

  class  Else_Context : public antlr4::ParserRuleContext {
  public:
    Else_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    If_bodyContext *if_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_Context* else_();

  class  Switch_Context : public antlr4::ParserRuleContext {
  public:
    Switch_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    Switch_conditionContext *switch_condition();
    Switch_bodyContext *switch_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_Context* switch_();

  class  Switch_conditionContext : public antlr4::ParserRuleContext {
  public:
    Switch_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_parenthesisContext *expr_parenthesis();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_caseContext* switch_case();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForiContext *fori();
    ForiterContext *foriter();
    While_Context *while_();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Foriter_conditionContext* foriter_condition();

  class  While_Context : public antlr4::ParserRuleContext {
  public:
    While_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    If_conditionContext *if_condition();
    If_bodyContext *if_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *EQEQ();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BOR();
    antlr4::tree::TerminalNode *BXOR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Unary_op_preContext : public antlr4::ParserRuleContext {
  public:
    Unary_op_preContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *BAND();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_op_preContext* unary_op_pre();

  class  Unary_op_postContext : public antlr4::ParserRuleContext {
  public:
    Unary_op_postContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *LBRAK();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RBRAK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_op_postContext* unary_op_post();

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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  AssignationContext : public antlr4::ParserRuleContext {
  public:
    AssignationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignation_operatorContext *assignation_operator();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignationContext* assignation();

  class  Assignation_operatorContext : public antlr4::ParserRuleContext {
  public:
    Assignation_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    Unary_operatorContext *unary_operator();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CastContext* cast();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_nameContext *function_name();
    Function_call_paramsContext *function_call_params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();

  class  Function_call_paramsContext : public antlr4::ParserRuleContext {
  public:
    Function_call_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Function_call_param_listContext *function_call_param_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_call_param_listContext* function_call_param_list();

  class  Variable_declContext : public antlr4::ParserRuleContext {
  public:
    Variable_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *VAL();
    antlr4::tree::TerminalNode *VAR();
    AssignationContext *assignation();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declContext* variable_decl();

  class  Array_assignContext : public antlr4::ParserRuleContext {
  public:
    Array_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_assignContext* array_assign();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *LBRAK();
    antlr4::tree::TerminalNode *RBRAK();
    antlr4::tree::TerminalNode *INT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  LitteralContext : public antlr4::ParserRuleContext {
  public:
    LitteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FSTRING();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *NULL_();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LitteralContext* litteral();

  class  Expr_parenthesisContext : public antlr4::ParserRuleContext {
  public:
    Expr_parenthesisContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_parenthesisContext* expr_parenthesis();

  class  Expr_blockContext : public antlr4::ParserRuleContext {
  public:
    Expr_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_blockContext* expr_block();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace antlrcppfil
