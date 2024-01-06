add_executable(e2e-tests
        test_tools.h
        options.cpp
)
add_dependencies(e2e-tests filc)
target_include_directories(e2e-tests PUBLIC .)
target_compile_definitions(e2e-tests PUBLIC FILC_DIR="${FILC_DIR}")

target_link_libraries(e2e-tests PRIVATE gtest_main gtest gmock)

gtest_discover_tests(e2e-tests
        PROPERTIES LABELS "e2e"
)