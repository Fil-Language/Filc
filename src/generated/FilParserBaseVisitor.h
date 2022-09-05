
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "FilParserVisitor.h"


namespace antlrcppfil {

/**
 * This class provides an empty implementation of FilParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FilParserBaseVisitor : public FilParserVisitor {
public:

  virtual std::any visitProgram(FilParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(FilParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_(FilParser::Import_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(FilParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(FilParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFun_params(FilParser::Fun_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFun_param_list(FilParser::Fun_param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFun_param(FilParser::Fun_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFun_body(FilParser::Fun_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_decl(FilParser::Function_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambda(FilParser::LambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterface(FilParser::InterfaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterface_body(FilParser::Interface_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_(FilParser::Class_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_modifier(FilParser::Class_modifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_params(FilParser::Class_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_param_list(FilParser::Class_param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_param(FilParser::Class_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_extends(FilParser::Class_extendsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_extend_list(FilParser::Class_extend_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_extend(FilParser::Class_extendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_body(FilParser::Class_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_function(FilParser::Class_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_variable(FilParser::Class_variableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_atr_modifier(FilParser::Class_atr_modifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_constructor(FilParser::Class_constructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnum_(FilParser::Enum_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnum_body(FilParser::Enum_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(FilParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_(FilParser::If_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_condition(FilParser::If_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_body(FilParser::If_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_if(FilParser::Else_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_(FilParser::Else_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_(FilParser::Switch_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_condition(FilParser::Switch_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_body(FilParser::Switch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_case(FilParser::Switch_caseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop(FilParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFori(FilParser::ForiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFori_condition(FilParser::Fori_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForiter(FilParser::ForiterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForiter_condition(FilParser::Foriter_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_(FilParser::While_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitException(FilParser::ExceptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatch_body(FilParser::Catch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinary_operator(FilParser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_calcul(FilParser::Unary_calculContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_operator(FilParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignation(FilParser::AssignationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignation_operator(FilParser::Assignation_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCast(FilParser::CastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call(FilParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call_params(FilParser::Function_call_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_call_param_list(FilParser::Function_call_param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_decl(FilParser::Variable_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(FilParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLitteral(FilParser::LitteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemp(FilParser::TempContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_parenthesis(FilParser::Expr_parenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_block(FilParser::Expr_blockContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcppfil
