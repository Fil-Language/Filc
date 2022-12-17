project(Filc)

# minimum required CMAKE version
cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 17
set(CMAKE_CXX_STANDARD 17)

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

include_directories(
        src
        src/fil
        src/fil/ast
        src/utils
)

# add generated grammar to binary target
add_executable(filc
        src/main.cpp
        # === Utils ===
        src/utils/cxxopts.hpp src/utils/utils.h src/utils/utils.cpp
        # === ANTLR ===
        ${ANTLR_Lexer_CXX_OUTPUTS}
        ${ANTLR_Parser_CXX_OUTPUTS}
        # === Fil ===
        src/VERSION.h
        src/fil/FilCompiler.cpp src/fil/FilCompiler.h
        # === AST ===
        src/fil/ast/AST.hpp src/fil/ast/AST.cpp src/fil/ast/Program.cpp src/fil/ast/AbstractExpr.cpp
        src/fil/ast/BooleanLiteral.cpp src/fil/ast/IntegerLiteral.cpp src/fil/ast/FloatLiteral.cpp
        src/fil/ast/CharLiteral.cpp src/fil/ast/StringLiteral.cpp src/fil/ast/FStringLiteral.cpp
        src/fil/ast/VariableDeclaration.cpp src/fil/ast/Type.cpp src/fil/ast/Assignation.cpp src/fil/ast/Identifier.cpp
        src/fil/ast/Operator.cpp src/fil/ast/UnaryCalcul.cpp src/fil/ast/Function.cpp
        src/fil/ast/FunctionDeclaration.cpp src/fil/ast/FunctionParam.cpp src/fil/ast/BlockBody.cpp
        src/fil/ast/Return.cpp)
target_link_libraries(filc antlr4_static)

target_compile_options(filc PUBLIC)

install(TARGETS filc DESTINATION bin)
