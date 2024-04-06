add_subdirectory(lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(filc main.cpp)
target_link_libraries(filc PRIVATE compiler_lib)

target_compile_options(filc PUBLIC -Wall)
