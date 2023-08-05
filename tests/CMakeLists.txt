include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests
        # === Utils ===
        unit/utils/OptionsParserTest.cpp unit/utils/PositionTest.cpp
        # === Message ===
        unit/message/MessageTest.cpp unit/message/MessageCollectorTest.cpp
        # === Grammar ===
        unit/grammar/ParserTest.cpp
        # === AST ===
        unit/ast/ProgramTest.cpp unit/ast/BooleanLiteralTest.cpp unit/ast/IntegerLiteralTest.cpp
        unit/ast/FloatLiteralTest.cpp unit/ast/CharacterLiteralTest.cpp unit/ast/StringLiteralTest.cpp
        unit/ast/VariableDeclarationTest.cpp unit/ast/IdentifierTest.cpp unit/ast/TypeTest.cpp
        unit/ast/ArrayTypeTest.cpp unit/ast/PointerTypeTest.cpp unit/ast/LambdaTypeTest.cpp unit/ast/UnaryCalculTest.cpp
        unit/ast/ClassicOperatorTest.cpp unit/ast/ArrayOperatorTest.cpp unit/ast/FunctionOperatorTest.cpp
)
target_include_directories(tests PUBLIC unit)

target_link_libraries(tests PRIVATE gtest_main gtest gmock compiler_lib)

include(GoogleTest)
gtest_discover_tests(tests)
