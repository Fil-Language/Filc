add_subdirectory(lib)

add_executable(filc main.cpp)
target_link_libraries(filc PRIVATE compiler_lib)

target_compile_options(filc PUBLIC -Wall)

install(TARGETS filc DESTINATION bin)
