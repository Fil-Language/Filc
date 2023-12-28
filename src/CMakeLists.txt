add_subdirectory(lib)

add_executable(filc main.cpp)
target_link_libraries(filc PRIVATE compiler_lib)

target_compile_options(filc PUBLIC -Wall)

set(FILC_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Where filc is build")
message(FILC_DIR=${FILC_DIR})

install(TARGETS filc DESTINATION bin)
