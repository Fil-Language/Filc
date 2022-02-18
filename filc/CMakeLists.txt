#  _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
#      Created by Kevin Traini
#
#      Fil compiler
#
#      GNU General Public License v3.0
#  _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

if (NOT UNIX)
    message(WARNING "Unsupported operating system")
endif ()

cmake_minimum_required(VERSION 3.10)
project(filc)

set(CMAKE_CXX_STANDARD 17)

set(filc-GENERATED_SRC
        ${PROJECT_SOURCE_DIR}/generated/FilLexer.cpp
        ${PROJECT_SOURCE_DIR}/generated/FilParser.cpp
        ${PROJECT_SOURCE_DIR}/generated/FilParserBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/generated/FilParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/generated/FilParserListener.cpp
        ${PROJECT_SOURCE_DIR}/generated/FilParserVisitor.cpp
        )

foreach (src_file ${filc-GENERATED_SRC})
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            GENERATED TRUE
    )
endforeach (src_file ${filc-GENERATED_SRC})


add_custom_target(GenerateParser DEPENDS ${filc-GENERATED_SRC})
add_custom_command(OUTPUT ${filc-GENERATED_SRC}
        COMMAND
        ${CMAKE_COMMAND} -E make_directory "${PROJECT_SOURCE_DIR}/generated/"
        COMMAND
        antlr4 -Werror -Dlanguage=Cpp -listener -visitor -o "${PROJECT_SOURCE_DIR}/generated/" -package antlrcpp "${PROJECT_SOURCE_DIR}/grammar/FilLexer.g4" "${PROJECT_SOURCE_DIR}/grammar/FilParser.g4"
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        DEPENDS ${PROJECT_SOURCE_DIR}/grammar/FilLexer.g4 ${PROJECT_SOURCE_DIR}/grammar/FilParser.g4
        )

include_directories(
        ${PROJECT_SOURCE_DIR}/antlr4/runtime/src
        ${PROJECT_SOURCE_DIR}/antlr4/runtime/src/misc
        ${PROJECT_SOURCE_DIR}/antlr4/runtime/src/atn
        ${PROJECT_SOURCE_DIR}/antlr4/runtime/src/dfa
        ${PROJECT_SOURCE_DIR}/antlr4/runtime/src/tree
        ${PROJECT_SOURCE_DIR}/antlr4/runtime/src/support
        ${PROJECT_SOURCE_DIR}/generated
)

set(filc_SRC
        ${filc-GENERATED_SRC}
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/CompilerOptions.h
        ${PROJECT_SOURCE_DIR}/src/CompilerOptions.cpp
        ${PROJECT_SOURCE_DIR}/src/tools.h
        ${PROJECT_SOURCE_DIR}/src/FilCompiler.cpp
        ${PROJECT_SOURCE_DIR}/src/FilCompiler.h)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(flags_1 "-Wno-overloaded-virtual")
else ()
    set(flags_1 "-MP /wd4251")
endif ()

foreach (src_file ${filc_SRC})
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
    )
endforeach (src_file ${filc_SRC})

add_executable(filc ${filc_SRC})

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(filc PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif ()

add_dependencies(filc GenerateParser)

target_link_libraries(filc antlr4-runtime)

install(TARGETS filc
        DESTINATION "share"
        COMPONENT dev
        )
