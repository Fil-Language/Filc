
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "FilParser.h"


namespace antlrcppfil {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by FilParser.
 */
class  FilParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FilParser.
   */
    virtual antlrcpp::Any visitProgram(FilParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitModule(FilParser::ModuleContext *context) = 0;

    virtual antlrcpp::Any visitImport_(FilParser::Import_Context *context) = 0;

    virtual antlrcpp::Any visitExpr(FilParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitFunction(FilParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFun_params(FilParser::Fun_paramsContext *context) = 0;

    virtual antlrcpp::Any visitFun_param_list(FilParser::Fun_param_listContext *context) = 0;

    virtual antlrcpp::Any visitFun_param(FilParser::Fun_paramContext *context) = 0;

    virtual antlrcpp::Any visitFun_body(FilParser::Fun_bodyContext *context) = 0;

    virtual antlrcpp::Any visitFunction_decl(FilParser::Function_declContext *context) = 0;

    virtual antlrcpp::Any visitLambda(FilParser::LambdaContext *context) = 0;

    virtual antlrcpp::Any visitInterface(FilParser::InterfaceContext *context) = 0;

    virtual antlrcpp::Any visitInterface_body(FilParser::Interface_bodyContext *context) = 0;

    virtual antlrcpp::Any visitClass_(FilParser::Class_Context *context) = 0;

    virtual antlrcpp::Any visitClass_modifier(FilParser::Class_modifierContext *context) = 0;

    virtual antlrcpp::Any visitClass_params(FilParser::Class_paramsContext *context) = 0;

    virtual antlrcpp::Any visitClass_param_list(FilParser::Class_param_listContext *context) = 0;

    virtual antlrcpp::Any visitClass_param(FilParser::Class_paramContext *context) = 0;

    virtual antlrcpp::Any visitClass_extends(FilParser::Class_extendsContext *context) = 0;

    virtual antlrcpp::Any visitClass_extend_list(FilParser::Class_extend_listContext *context) = 0;

    virtual antlrcpp::Any visitClass_extend(FilParser::Class_extendContext *context) = 0;

    virtual antlrcpp::Any visitClass_body(FilParser::Class_bodyContext *context) = 0;

    virtual antlrcpp::Any visitClass_function(FilParser::Class_functionContext *context) = 0;

    virtual antlrcpp::Any visitClass_variable(FilParser::Class_variableContext *context) = 0;

    virtual antlrcpp::Any visitClass_atr_modifier(FilParser::Class_atr_modifierContext *context) = 0;

    virtual antlrcpp::Any visitClass_constructor(FilParser::Class_constructorContext *context) = 0;

    virtual antlrcpp::Any visitEnum_(FilParser::Enum_Context *context) = 0;

    virtual antlrcpp::Any visitEnum_body(FilParser::Enum_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCondition(FilParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitIf_(FilParser::If_Context *context) = 0;

    virtual antlrcpp::Any visitIf_condition(FilParser::If_conditionContext *context) = 0;

    virtual antlrcpp::Any visitIf_body(FilParser::If_bodyContext *context) = 0;

    virtual antlrcpp::Any visitElse_if(FilParser::Else_ifContext *context) = 0;

    virtual antlrcpp::Any visitElse_(FilParser::Else_Context *context) = 0;

    virtual antlrcpp::Any visitSwitch_(FilParser::Switch_Context *context) = 0;

    virtual antlrcpp::Any visitSwitch_condition(FilParser::Switch_conditionContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_body(FilParser::Switch_bodyContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_case(FilParser::Switch_caseContext *context) = 0;

    virtual antlrcpp::Any visitLoop(FilParser::LoopContext *context) = 0;

    virtual antlrcpp::Any visitFori(FilParser::ForiContext *context) = 0;

    virtual antlrcpp::Any visitFori_condition(FilParser::Fori_conditionContext *context) = 0;

    virtual antlrcpp::Any visitForiter(FilParser::ForiterContext *context) = 0;

    virtual antlrcpp::Any visitForiter_condition(FilParser::Foriter_conditionContext *context) = 0;

    virtual antlrcpp::Any visitWhile_(FilParser::While_Context *context) = 0;

    virtual antlrcpp::Any visitException(FilParser::ExceptionContext *context) = 0;

    virtual antlrcpp::Any visitCatch_body(FilParser::Catch_bodyContext *context) = 0;

    virtual antlrcpp::Any visitBinary_operator(FilParser::Binary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitUnary_calcul(FilParser::Unary_calculContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(FilParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitAssignation(FilParser::AssignationContext *context) = 0;

    virtual antlrcpp::Any visitAssignation_operator(FilParser::Assignation_operatorContext *context) = 0;

    virtual antlrcpp::Any visitCast(FilParser::CastContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(FilParser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call_params(FilParser::Function_call_paramsContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call_param_list(FilParser::Function_call_param_listContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl(FilParser::Variable_declContext *context) = 0;

    virtual antlrcpp::Any visitType(FilParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitLitteral(FilParser::LitteralContext *context) = 0;

    virtual antlrcpp::Any visitTemp(FilParser::TempContext *context) = 0;

    virtual antlrcpp::Any visitExpr_parenthesis(FilParser::Expr_parenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExpr_block(FilParser::Expr_blockContext *context) = 0;


};

}  // namespace antlrcppfil
