## _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
## ANTLR section
#
## required if linking to static library
#add_definitions(-DANTLR4CPP_STATIC)
#
## using /MD flag for antlr4_runtime (for Visual C++ compilers only)
#set(ANTLR4_WITH_STATIC_CRT OFF)
#
## Specify the version of the antlr4 library needed for this project.
## By default the latest version of antlr4 will be used.  You can specify a
## specific, stable version by setting a repository tag value or a link
## to a zip file containing the libary source.
#set(ANTLR4_TAG 4.9.3)
#set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/${ANTLR4_TAG}.zip)
#
## add external build for antlrcpp
#include(ExternalAntlr4Cpp)
## add antlr4cpp artifacts to project environment
#include_directories(${ANTLR4_INCLUDE_DIRS})
#
## set variable pointing to the antlr tool that supports C++
## this is not required if the jar file can be found under PATH environment
#set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/bin/antlr-${ANTLR4_TAG}-complete.jar)
## add macros to generate ANTLR Cpp code from grammar
#find_package(ANTLR REQUIRED)
#
## Call macro to add lexer and grammar to your build dependencies.
#antlr_target(Lexer ${PROJECT_SOURCE_DIR}/src/antlr/FilLexer.g4 LEXER
#        PACKAGE antlrcppfil)
#antlr_target(Parser ${PROJECT_SOURCE_DIR}/src/antlr/FilParser.g4 PARSER
#        PACKAGE antlrcppfil
#        DEPENDS_ANTLR Lexer
#        COMPILE_FLAGS -lib ${ANTLR_Lexer_OUTPUT_DIR})
#
## include generated files in project environment
#include_directories(${ANTLR_Lexer_OUTPUT_DIR})
#include_directories(${ANTLR_Parser_OUTPUT_DIR})
#
## _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
## LLVM section
#
#find_package(LLVM REQUIRED CONFIG)
#
#message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
#message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
#
#include_directories(${LLVM_INCLUDE_DIRS})
#separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
#add_definitions(${LLVM_DEFINITIONS})
#
#llvm_map_components_to_libnames(llvm_libs support core irreader)

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# Lib section

add_library(compiler_lib
        # === Main ===
        FilCompiler.cpp
        # === Utils ===
        utils/OptionsParser.cpp
        # === Message ===
        message/Message.cpp)
target_include_directories(compiler_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} utils message ../../lib)
target_link_libraries(compiler_lib PUBLIC coverage_config)

target_compile_options(compiler_lib PUBLIC -Wall)
