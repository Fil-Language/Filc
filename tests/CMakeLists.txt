include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests
        unit/utils/OptionsParserTest.cpp unit/utils/PositionTest.cpp
        unit/message/MessageTest.cpp unit/message/MessageCollectorTest.cpp
        unit/grammar/ParserTest.cpp
        unit/ast/ProgramTest.cpp unit/ast/BooleanLiteralTest.cpp unit/ast/IntegerLiteralTest.cpp unit/ast/FloatLiteralTest.cpp
        unit/ast/CharacterLiteralTest.cpp unit/ast/StringLiteralTest.cpp
        unit/ast/VariableDeclarationTest.cpp)
target_include_directories(tests PUBLIC unit)

target_link_libraries(tests PRIVATE gtest_main gtest gmock compiler_lib)

include(GoogleTest)
gtest_discover_tests(tests)
