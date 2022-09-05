
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.11.1

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
    virtual std::any visitProgram(FilParser::ProgramContext *context) = 0;

    virtual std::any visitModule(FilParser::ModuleContext *context) = 0;

    virtual std::any visitImport_(FilParser::Import_Context *context) = 0;

    virtual std::any visitExpr(FilParser::ExprContext *context) = 0;

    virtual std::any visitFunction(FilParser::FunctionContext *context) = 0;

    virtual std::any visitFun_params(FilParser::Fun_paramsContext *context) = 0;

    virtual std::any visitFun_param_list(FilParser::Fun_param_listContext *context) = 0;

    virtual std::any visitFun_param(FilParser::Fun_paramContext *context) = 0;

    virtual std::any visitFun_body(FilParser::Fun_bodyContext *context) = 0;

    virtual std::any visitFunction_decl(FilParser::Function_declContext *context) = 0;

    virtual std::any visitLambda(FilParser::LambdaContext *context) = 0;

    virtual std::any visitInterface(FilParser::InterfaceContext *context) = 0;

    virtual std::any visitInterface_body(FilParser::Interface_bodyContext *context) = 0;

    virtual std::any visitClass_(FilParser::Class_Context *context) = 0;

    virtual std::any visitClass_modifier(FilParser::Class_modifierContext *context) = 0;

    virtual std::any visitClass_params(FilParser::Class_paramsContext *context) = 0;

    virtual std::any visitClass_param_list(FilParser::Class_param_listContext *context) = 0;

    virtual std::any visitClass_param(FilParser::Class_paramContext *context) = 0;

    virtual std::any visitClass_extends(FilParser::Class_extendsContext *context) = 0;

    virtual std::any visitClass_extend_list(FilParser::Class_extend_listContext *context) = 0;

    virtual std::any visitClass_extend(FilParser::Class_extendContext *context) = 0;

    virtual std::any visitClass_body(FilParser::Class_bodyContext *context) = 0;

    virtual std::any visitClass_function(FilParser::Class_functionContext *context) = 0;

    virtual std::any visitClass_variable(FilParser::Class_variableContext *context) = 0;

    virtual std::any visitClass_atr_modifier(FilParser::Class_atr_modifierContext *context) = 0;

    virtual std::any visitClass_constructor(FilParser::Class_constructorContext *context) = 0;

    virtual std::any visitEnum_(FilParser::Enum_Context *context) = 0;

    virtual std::any visitEnum_body(FilParser::Enum_bodyContext *context) = 0;

    virtual std::any visitCondition(FilParser::ConditionContext *context) = 0;

    virtual std::any visitIf_(FilParser::If_Context *context) = 0;

    virtual std::any visitIf_condition(FilParser::If_conditionContext *context) = 0;

    virtual std::any visitIf_body(FilParser::If_bodyContext *context) = 0;

    virtual std::any visitElse_if(FilParser::Else_ifContext *context) = 0;

    virtual std::any visitElse_(FilParser::Else_Context *context) = 0;

    virtual std::any visitSwitch_(FilParser::Switch_Context *context) = 0;

    virtual std::any visitSwitch_condition(FilParser::Switch_conditionContext *context) = 0;

    virtual std::any visitSwitch_body(FilParser::Switch_bodyContext *context) = 0;

    virtual std::any visitSwitch_case(FilParser::Switch_caseContext *context) = 0;

    virtual std::any visitLoop(FilParser::LoopContext *context) = 0;

    virtual std::any visitFori(FilParser::ForiContext *context) = 0;

    virtual std::any visitFori_condition(FilParser::Fori_conditionContext *context) = 0;

    virtual std::any visitForiter(FilParser::ForiterContext *context) = 0;

    virtual std::any visitForiter_condition(FilParser::Foriter_conditionContext *context) = 0;

    virtual std::any visitWhile_(FilParser::While_Context *context) = 0;

    virtual std::any visitException(FilParser::ExceptionContext *context) = 0;

    virtual std::any visitCatch_body(FilParser::Catch_bodyContext *context) = 0;

    virtual std::any visitBinary_operator(FilParser::Binary_operatorContext *context) = 0;

    virtual std::any visitUnary_calcul(FilParser::Unary_calculContext *context) = 0;

    virtual std::any visitUnary_operator(FilParser::Unary_operatorContext *context) = 0;

    virtual std::any visitAssignation(FilParser::AssignationContext *context) = 0;

    virtual std::any visitAssignation_operator(FilParser::Assignation_operatorContext *context) = 0;

    virtual std::any visitCast(FilParser::CastContext *context) = 0;

    virtual std::any visitFunction_call(FilParser::Function_callContext *context) = 0;

    virtual std::any visitFunction_call_params(FilParser::Function_call_paramsContext *context) = 0;

    virtual std::any visitFunction_call_param_list(FilParser::Function_call_param_listContext *context) = 0;

    virtual std::any visitVariable_decl(FilParser::Variable_declContext *context) = 0;

    virtual std::any visitType(FilParser::TypeContext *context) = 0;

    virtual std::any visitLitteral(FilParser::LitteralContext *context) = 0;

    virtual std::any visitTemp(FilParser::TempContext *context) = 0;

    virtual std::any visitExpr_parenthesis(FilParser::Expr_parenthesisContext *context) = 0;

    virtual std::any visitExpr_block(FilParser::Expr_blockContext *context) = 0;


};

}  // namespace antlrcppfil
