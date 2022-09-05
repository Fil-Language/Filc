project(Filc)

cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

set(antlr4-jar ${PROJECT_SOURCE_DIR}/bin/antlr-4.11.1-complete.jar)

set(antlr4-output
        ${PROJECT_SOURCE_DIR}/src/generated/FilLexer.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/FilLexer.h
        ${PROJECT_SOURCE_DIR}/src/generated/FilParser.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/FilParser.h
        ${PROJECT_SOURCE_DIR}/src/generated/FilParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/FilParserBaseVisitor.h
        ${PROJECT_SOURCE_DIR}/src/generated/FilParserVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/FilParserVisitor.h
)

foreach(src_file ${antlr4-output})
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            GENERATED TRUE
    )
endforeach(src_file ${antlr4-output})

add_custom_target(GenerateLexerParser
        COMMAND java -jar ${antlr4-jar} -Dlanguage=Cpp -visitor -no-listener -o ${PROJECT_SOURCE_DIR}/src/generated/ -package antlrcppfil ${PROJECT_SOURCE_DIR}/src/antlr/FilLexer.g4 ${PROJECT_SOURCE_DIR}/src/antlr/FilParser.g4
        DEPENDS ${PROJECT_SOURCE_DIR}/src/antlr/FilLexer.g4 ${PROJECT_SOURCE_DIR}/src/antlr/FilParser.g4
)

include_directories(
        src
        src/generated
        src/utils
        antlr-runtime/src
)

add_executable(filc
        src/main.cpp
        src/utils/cxxopts.hpp
        ${antlr4-output}
)

add_dependencies(filc GenerateLexerParser)

target_link_libraries(filc  antlr4-runtime.a)

install(TARGETS filc DESTINATION bin)
