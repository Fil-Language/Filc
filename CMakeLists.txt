include(cmake/policies.cmake)

cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

message("C++ compiler is: ${CMAKE_CXX_COMPILER}")
message("Build target is: ${CMAKE_CXX_COMPILER_TARGET}")

file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/VERSION FILC_VERSION)

project(
        Filc
        VERSION ${FILC_VERSION}
        LANGUAGES CXX C
)

include(FetchContent)

# _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
# Code Coverage configuration

add_library(additional_config INTERFACE)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(additional_config INTERFACE
            -O0        # no optimization
            -g         # generate debug info
            --coverage # sets all required flags
    )
    target_link_options(additional_config INTERFACE --coverage)
else ()
    target_compile_options(additional_config INTERFACE
            -O3        # full optimization
    )
endif ()

add_subdirectory(src)

option(BUILD_TESTING "Build the testing tree." OFF)
if (BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    add_subdirectory(tests)
endif ()
