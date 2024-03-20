# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# ANTLR section

add_definitions(-DANTLR4CPP_STATIC)

set(ANTLR4_WITH_STATIC_CRT OFF)

set(ANTLR4_TAG 4.13.1)
set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/${ANTLR4_TAG}.zip)

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/bin/antlr-${ANTLR4_TAG}-complete.jar)
find_package(ANTLR REQUIRED)

antlr_target(Lexer ${PROJECT_SOURCE_DIR}/src/lib/grammar/FilLexer.g4 LEXER
        PACKAGE filc::antlr)
antlr_target(Parser ${PROJECT_SOURCE_DIR}/src/lib/grammar/FilParser.g4 PARSER
        PACKAGE filc::antlr
        DEPENDS_ANTLR Lexer
        COMPILE_FLAGS -lib ${ANTLR_Lexer_OUTPUT_DIR})

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# LLVM section

find_package(LLVM REQUIRED CONFIG 15)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# yaml-cpp section

FetchContent_Declare(
        yaml-cpp
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG yaml-cpp-0.7.0
)
FetchContent_GetProperties(yaml-cpp)

if(NOT yaml-cpp_POPULATED)
    message(STATUS "Fetching yaml-cpp...")
    FetchContent_Populate(yaml-cpp)
    add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
endif()

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# enquirer section

FetchContent_Declare(
        enquirer
        GIT_REPOSITORY https://github.com/Gashmob/Enquirer.git
        GIT_TAG v1.0.2
)
FetchContent_GetProperties(enquirer)

if(NOT enquirer_POPULATED)
    message(STATUS "Fetching enquirer...")
    FetchContent_Populate(enquirer)
    add_subdirectory(${enquirer_SOURCE_DIR} ${enquirer_BINARY_DIR})
endif()

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# Lib section

file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/lib/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/lib/**/*.cpp"
)
message(SRC_FILES=${SRC_FILES})

SUBDIRLIST(LIB_DIRS "${PROJECT_SOURCE_DIR}/src/lib")
message(LIB_DIRS=${LIB_DIRS})

add_library(compiler_lib
        ${SRC_FILES}
        ${ANTLR_Lexer_CXX_OUTPUTS}
        ${ANTLR_Parser_CXX_OUTPUTS}
)
target_include_directories(compiler_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${LIB_DIRS}
        ${ANTLR4_INCLUDE_DIRS}
        ${ANTLR_Lexer_OUTPUT_DIR}
        ${ANTLR_Parser_OUTPUT_DIR}
        ${LLVM_INCLUDE_DIRS})
target_link_libraries(compiler_lib PUBLIC additional_config antlr4_static ${llvm_libs} yaml-cpp enquirer)
target_compile_definitions(compiler_lib
        PUBLIC FILC_VERSION="${FILC_VERSION}"
)
target_compile_options(compiler_lib PUBLIC -Wall)
