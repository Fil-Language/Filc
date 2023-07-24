include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/cc366710bbf40a9816d47c35802d06dbaccb8792.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests
        unit/tools.h
        unit/utils/OptionsParserTest.cpp unit/utils/PositionTest.cpp
        unit/message/MessageTest.cpp unit/message/MessageCollectorTest.cpp
        unit/ast/ProgramTest.cpp unit/grammar/ParserTest.cpp)
target_include_directories(tests PUBLIC unit)

target_link_libraries(tests PRIVATE GTest::gtest_main compiler_lib)

include(GoogleTest)
gtest_discover_tests(tests)
