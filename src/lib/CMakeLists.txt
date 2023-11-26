# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# ANTLR section

add_definitions(-DANTLR4CPP_STATIC)

set(ANTLR4_WITH_STATIC_CRT OFF)

set(ANTLR4_TAG 4.13.0)
set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/${ANTLR4_TAG}.zip)

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/bin/antlr-${ANTLR4_TAG}-complete.jar)
find_package(ANTLR REQUIRED)

antlr_target(Lexer ${PROJECT_SOURCE_DIR}/src/lib/grammar/FilLexer.g4 LEXER
        PACKAGE filc::grammar)
antlr_target(Parser ${PROJECT_SOURCE_DIR}/src/lib/grammar/FilParser.g4 PARSER
        PACKAGE filc::grammar
        DEPENDS_ANTLR Lexer
        COMPILE_FLAGS -lib ${ANTLR_Lexer_OUTPUT_DIR})

## _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
## LLVM section

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# Lib section

add_library(compiler_lib
        # === Main ===
        FilCompiler.cpp
        # === Utils ===
        utils/OptionsParser.cpp
        utils/Position.cpp
        utils/tools.cpp
        # === ANTLR ===
        ${ANTLR_Lexer_CXX_OUTPUTS}
        ${ANTLR_Parser_CXX_OUTPUTS}
        grammar/Parser.cpp
        # === Message ===
        message/Message.cpp
        message/MessageCollector.cpp
        message/Warning.cpp
        message/Error.cpp
        message/DevWarning.cpp
        message/Antlr4ErrorListener.cpp
        # === AST ===
        ast/Program.cpp
        ast/AbstractExpression.cpp
        ast/BooleanLiteral.cpp
        ast/IntegerLiteral.cpp
        ast/FloatLiteral.cpp
        ast/CharacterLiteral.cpp
        ast/StringLiteral.cpp
        ast/VariableDeclaration.cpp
        ast/Identifier.cpp
        ast/Type.cpp
        ast/ArrayType.cpp
        ast/PointerType.cpp
        ast/LambdaType.cpp
        ast/UnaryCalcul.cpp
        ast/ClassicOperator.cpp
        ast/ArrayOperator.cpp
        ast/FunctionOperator.cpp
        ast/PreUnaryCalcul.cpp
        ast/PostUnaryCalcul.cpp
        ast/BinaryCalcul.cpp
        ast/Function.cpp
        ast/FunctionParameter.cpp
        ast/Lambda.cpp
        ast/If.cpp
        ast/Switch.cpp
        ast/SwitchCase.cpp
        ast/ForI.cpp
        ast/ForIter.cpp
        ast/While.cpp
        ast/AssignationOperator.cpp
        ast/AbstractType.cpp
        ast/BlockBody.cpp
        # === Environment ===
        environment/Environment.cpp
        environment/Name.cpp
)
target_include_directories(compiler_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        utils
        message
        grammar
        ast
        environment
        ${ANTLR4_INCLUDE_DIRS}
        ${ANTLR_Lexer_OUTPUT_DIR}
        ${ANTLR_Parser_OUTPUT_DIR}
        ${LLVM_INCLUDE_DIRS}
        ../../lib)
target_link_libraries(compiler_lib PUBLIC additional_config antlr4_static ${llvm_libs})

target_compile_options(compiler_lib PUBLIC -Wall)
