
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "FilParserVisitor.h"


/**
 * This class provides an empty implementation of FilParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FilParserBaseVisitor : public FilParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(FilParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule(FilParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_(FilParser::Import_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(FilParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(FilParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_params(FilParser::Fun_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_param_list(FilParser::Fun_param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_param(FilParser::Fun_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFun_body(FilParser::Fun_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_decl(FilParser::Function_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambda(FilParser::LambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface(FilParser::InterfaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_body(FilParser::Interface_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_(FilParser::Class_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_modifier(FilParser::Class_modifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_params(FilParser::Class_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_param_list(FilParser::Class_param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_param(FilParser::Class_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_extends(FilParser::Class_extendsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_extend_list(FilParser::Class_extend_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_extend(FilParser::Class_extendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_body(FilParser::Class_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_function(FilParser::Class_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_variable(FilParser::Class_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_atr_modifier(FilParser::Class_atr_modifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_constructor(FilParser::Class_constructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_(FilParser::Enum_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_body(FilParser::Enum_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(FilParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_(FilParser::If_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_condition(FilParser::If_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_body(FilParser::If_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElse_if(FilParser::Else_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElse_(FilParser::Else_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_(FilParser::Switch_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_condition(FilParser::Switch_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_body(FilParser::Switch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitch_case(FilParser::Switch_caseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop(FilParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFori(FilParser::ForiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFori_condition(FilParser::Fori_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForiter(FilParser::ForiterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForiter_condition(FilParser::Foriter_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_(FilParser::While_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitException(FilParser::ExceptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCatch_body(FilParser::Catch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_operator(FilParser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_calcul(FilParser::Unary_calculContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(FilParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignation(FilParser::AssignationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignation_operator(FilParser::Assignation_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCast(FilParser::CastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call(FilParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call_params(FilParser::Function_call_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call_param_list(FilParser::Function_call_param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_decl(FilParser::Variable_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(FilParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLitteral(FilParser::LitteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTemp(FilParser::TempContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_parenthesis(FilParser::Expr_parenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_block(FilParser::Expr_blockContext *ctx) override {
    return visitChildren(ctx);
  }


};

