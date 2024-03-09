file(GLOB_RECURSE E2E_TEST_FILES
        "${PROJECT_SOURCE_DIR}/tests/e2e/*.cpp"
        "${PROJECT_SOURCE_DIR}/tests/e2e/**/*.cpp"
        "${PROJECT_SOURCE_DIR}/tests/e2e/*.h"
        "${PROJECT_SOURCE_DIR}/tests/e2e/**/*.h"
)
message(E2E_TEST_FILES=${E2E_TEST_FILES})

add_executable(e2e-tests ${E2E_TEST_FILES})
add_dependencies(e2e-tests filc)
target_include_directories(e2e-tests PUBLIC .)
target_compile_definitions(e2e-tests PUBLIC FILC_BIN="$<TARGET_FILE:filc>")

target_link_libraries(e2e-tests PRIVATE gtest_main gtest gmock)

gtest_discover_tests(e2e-tests
        PROPERTIES LABELS "e2e"
)