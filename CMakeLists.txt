#  _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
#      Created by Kevin Traini
#
#      Fil compiler
#
#      GNU General Public License v3.0
#  _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cmake_minimum_required(VERSION 3.10)
project(filc)

set(CMAKE_CXX_STANDARD 17)

set(filc-GENERATED_SRC
        ${PROJECT_SOURCE_DIR}/generated/FilParser.h
        )

add_custom_target(GenerateParser DEPENDS ${filc-GENERATED_SRC})
add_custom_command(OUTPUT ${filc-GENERATED_SRC}
        COMMAND
        ${CMAKE_COMMAND} -E make_directory "${PROJECT_SOURCE_DIR}/generated/"
        COMMAND
        cd "${PROJECT_SOURCE_DIR}/owl" && make
        COMMAND
        cd "${PROJECT_SOURCE_DIR}" && "${PROJECT_SOURCE_DIR}/owl/owl" -c ${PROJECT_SOURCE_DIR}/grammar/FilParser.owl -o ${PROJECT_SOURCE_DIR}/generated/FilParser.h
        #WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        DEPENDS ${PROJECT_SOURCE_DIR}/grammar/FilParser.owl
        )

set(filc_SRC
        ${filc-GENERATED_SRC}
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/CompilerOptions.h
        ${PROJECT_SOURCE_DIR}/src/CompilerOptions.cpp
        ${PROJECT_SOURCE_DIR}/src/tools.h
        ${PROJECT_SOURCE_DIR}/src/FilCompiler.cpp
        ${PROJECT_SOURCE_DIR}/src/FilCompiler.h)

add_executable(filc ${filc_SRC})

add_dependencies(filc GenerateParser)
