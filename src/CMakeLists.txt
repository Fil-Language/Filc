# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# ANTLR section

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# Specify the version of the antlr4 library needed for this project.
# By default the latest version of antlr4 will be used.  You can specify a
# specific, stable version by setting a repository tag value or a link
# to a zip file containing the libary source.
set(ANTLR4_TAG 4.9.3)
set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/${ANTLR4_TAG}.zip)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antlr4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/bin/antlr-${ANTLR4_TAG}-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(Lexer ${PROJECT_SOURCE_DIR}/src/antlr/FilLexer.g4 LEXER
        PACKAGE antlrcppfil)
antlr_target(Parser ${PROJECT_SOURCE_DIR}/src/antlr/FilParser.g4 PARSER
        PACKAGE antlrcppfil
        DEPENDS_ANTLR Lexer
        COMPILE_FLAGS -lib ${ANTLR_Lexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_Lexer_OUTPUT_DIR})
include_directories(${ANTLR_Parser_OUTPUT_DIR})

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# LLVM section

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# Filc section

include_directories(
        fil
        fil/ast
        fil/environment
        fil/errors
        fil/llvm
        utils
)

add_executable(filc
        main.cpp
        # === Utils ===
        utils/cxxopts.hpp utils/utils.h utils/utils.cpp
        # === ANTLR ===
        ${ANTLR_Lexer_CXX_OUTPUTS}
        ${ANTLR_Parser_CXX_OUTPUTS}
        # === Fil ===
        VERSION.h
        fil/FilCompiler.cpp fil/FilCompiler.h
        # === AST ===
        fil/ast/AST.hpp fil/ast/AST.cpp fil/ast/Program.cpp fil/ast/AbstractExpr.cpp
        fil/ast/BooleanLiteral.cpp fil/ast/IntegerLiteral.cpp fil/ast/FloatLiteral.cpp
        fil/ast/CharLiteral.cpp fil/ast/StringLiteral.cpp
        fil/ast/VariableDeclaration.cpp fil/ast/Type.cpp fil/ast/Assignation.cpp fil/ast/Identifier.cpp
        fil/ast/Operator.cpp fil/ast/UnaryCalcul.cpp fil/ast/Function.cpp
        fil/ast/FunctionDeclaration.cpp fil/ast/FunctionParam.cpp fil/ast/BlockBody.cpp
        fil/ast/Lambda.cpp fil/ast/LambdaType.cpp fil/ast/If.cpp
        fil/ast/Switch.cpp fil/ast/SwitchCase.cpp fil/ast/SwitchPattern.cpp fil/ast/ForI.cpp
        fil/ast/ForICondition.cpp fil/ast/ForIter.cpp fil/ast/ForIterCondition.cpp fil/ast/While.cpp
        fil/ast/FunctionCall.cpp fil/ast/BinaryCalcul.cpp fil/ast/ParenthesisBody.cpp
        fil/ast/AbstractLiteral.cpp fil/ast/AST_decl.h fil/ast/AbstractType.cpp
        # === Environment ===
        fil/environment/Environment.cpp fil/environment/Environment.h fil/environment/Symbol.cpp
        fil/environment/Symbol.h
        # === Errors ===
        fil/errors/ErrorsRegister.cpp fil/errors/ErrorsRegister.h fil/errors/Message.h
        fil/errors/Message.cpp fil/errors/ParserErrorListener.cpp fil/errors/ParserErrorListener.h
        fil/errors/LexerErrorListener.cpp fil/errors/LexerErrorListener.h
        # === LLVM ===
        )
target_link_libraries(filc antlr4_static ${llvm_libs})

target_compile_options(filc PUBLIC -Wall)

install(TARGETS filc DESTINATION bin)

# ====================
# Library for testing

add_library(filc_lib
        main.cpp
        # === Utils ===
        utils/cxxopts.hpp utils/utils.h utils/utils.cpp
        # === ANTLR ===
        ${ANTLR_Lexer_CXX_OUTPUTS}
        ${ANTLR_Parser_CXX_OUTPUTS}
        # === Fil ===
        VERSION.h
        fil/FilCompiler.cpp fil/FilCompiler.h
        # === AST ===
        fil/ast/AST.hpp fil/ast/AST.cpp fil/ast/Program.cpp fil/ast/AbstractExpr.cpp
        fil/ast/BooleanLiteral.cpp fil/ast/IntegerLiteral.cpp fil/ast/FloatLiteral.cpp
        fil/ast/CharLiteral.cpp fil/ast/StringLiteral.cpp
        fil/ast/VariableDeclaration.cpp fil/ast/Type.cpp fil/ast/Assignation.cpp fil/ast/Identifier.cpp
        fil/ast/Operator.cpp fil/ast/UnaryCalcul.cpp fil/ast/Function.cpp
        fil/ast/FunctionDeclaration.cpp fil/ast/FunctionParam.cpp fil/ast/BlockBody.cpp
        fil/ast/Lambda.cpp fil/ast/LambdaType.cpp fil/ast/If.cpp
        fil/ast/Switch.cpp fil/ast/SwitchCase.cpp fil/ast/SwitchPattern.cpp fil/ast/ForI.cpp
        fil/ast/ForICondition.cpp fil/ast/ForIter.cpp fil/ast/ForIterCondition.cpp fil/ast/While.cpp
        fil/ast/FunctionCall.cpp fil/ast/BinaryCalcul.cpp fil/ast/ParenthesisBody.cpp
        fil/ast/AbstractLiteral.cpp fil/ast/AST_decl.h fil/ast/AbstractType.cpp
        # === Environment ===
        fil/environment/Environment.cpp fil/environment/Environment.h fil/environment/Symbol.cpp
        fil/environment/Symbol.h
        # === Errors ===
        fil/errors/ErrorsRegister.cpp fil/errors/ErrorsRegister.h fil/errors/Message.h
        fil/errors/Message.cpp fil/errors/ParserErrorListener.cpp fil/errors/ParserErrorListener.h
        fil/errors/LexerErrorListener.cpp fil/errors/LexerErrorListener.h
        # === LLVM ===
        )

target_link_libraries(filc_lib PUBLIC antlr4_static ${llvm_libs} coverage_config)