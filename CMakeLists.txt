project(Filc)

cmake_minimum_required(VERSION 3.10)

include_directories(
        src
        src/generated
        src/utils
        /usr/include/antlr4-runtime
)

add_executable(filc
        src/main.cpp
        src/utils/cxxopts.hpp
        src/generated/FilLexer.cpp
        src/generated/FilLexer.h
        )

target_link_libraries(filc  antlr4-runtime.a)

install(TARGETS filc DESTINATION bin)