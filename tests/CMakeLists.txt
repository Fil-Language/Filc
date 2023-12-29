include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(e2e-tests
        e2e/test_tools.h
        e2e/options.cpp
)
add_dependencies(e2e-tests filc)
target_include_directories(e2e-tests PUBLIC e2e)
target_compile_definitions(e2e-tests PUBLIC FILC_DIR="${FILC_DIR}")

target_link_libraries(e2e-tests PRIVATE gtest_main gtest gmock)

add_executable(unit-tests
        unit/test_tools.h
        # === Utils ===
        unit/utils/OptionsParserTest.cpp
        unit/utils/PositionTest.cpp
        unit/utils/ToolsTest.cpp
        # === Message ===
        unit/message/MessageTest.cpp
        unit/message/MessageCollectorTest.cpp
        unit/message/WarningTest.cpp
        unit/message/ErrorTest.cpp
        unit/message/DevWarningTest.cpp
        unit/message/Antlr4ErrorListenerTest.cpp
        # === Grammar ===
        unit/grammar/ParserTest.cpp
        # === AST ===
        unit/ast/ProgramTest.cpp
        unit/ast/BooleanLiteralTest.cpp
        unit/ast/IntegerLiteralTest.cpp
        unit/ast/FloatLiteralTest.cpp
        unit/ast/CharacterLiteralTest.cpp
        unit/ast/StringLiteralTest.cpp
        unit/ast/VariableDeclarationTest.cpp
        unit/ast/IdentifierTest.cpp
        unit/ast/TypeTest.cpp
        unit/ast/ArrayTypeTest.cpp
        unit/ast/PointerTypeTest.cpp
        unit/ast/LambdaTypeTest.cpp
        unit/ast/UnaryCalculTest.cpp
        unit/ast/ClassicOperatorTest.cpp
        unit/ast/ArrayOperatorTest.cpp
        unit/ast/FunctionOperatorTest.cpp
        unit/ast/PreUnaryCalculTest.cpp
        unit/ast/PostUnaryCalculTest.cpp
        unit/ast/BinaryCalculTest.cpp
        unit/ast/FunctionTest.cpp
        unit/ast/FunctionParameterTest.cpp
        unit/ast/LambdaTest.cpp
        unit/ast/IfTest.cpp
        unit/ast/SwitchTest.cpp
        unit/ast/SwitchCaseTest.cpp
        unit/ast/ForITest.cpp
        unit/ast/ForIterTest.cpp
        unit/ast/WhileTest.cpp
        unit/ast/AssignationOperatorTest.cpp
        unit/ast/AbstractExpressionTest.cpp
        # === Environment ===
        unit/environment/EnvironmentTest.cpp
        unit/environment/NameTest.cpp
)
target_include_directories(unit-tests PUBLIC unit)

target_link_libraries(unit-tests PRIVATE gtest_main gtest gmock compiler_lib)

include(GoogleTest)
gtest_discover_tests(unit-tests
        PROPERTIES LABELS "unit"
)
gtest_discover_tests(e2e-tests
        PROPERTIES LABELS "e2e"
)
