add_executable(unit-tests
        test_tools.h test_tools.cpp
        # === Utils ===
        utils/OptionsParserTest.cpp
        utils/PositionTest.cpp
        utils/ToolsTest.cpp
        utils/command/CommandTest.cpp
        utils/command/CommandCollectorTest.cpp
        utils/command/HelpCommandTest.cpp
        utils/command/VersionCommandTest.cpp
        utils/command/InitCommandTest.cpp
        # === Message ===
        message/MessageTest.cpp
        message/MessageCollectorTest.cpp
        message/WarningTest.cpp
        message/ErrorTest.cpp
        message/DevWarningTest.cpp
        message/Antlr4ErrorListenerTest.cpp
        # === Grammar ===
        grammar/ParserTest.cpp
        # === AST ===
        ast/ProgramTest.cpp
        ast/BooleanLiteralTest.cpp
        ast/IntegerLiteralTest.cpp
        ast/FloatLiteralTest.cpp
        ast/CharacterLiteralTest.cpp
        ast/StringLiteralTest.cpp
        ast/VariableDeclarationTest.cpp
        ast/IdentifierTest.cpp
        ast/TypeTest.cpp
        ast/ArrayTypeTest.cpp
        ast/PointerTypeTest.cpp
        ast/LambdaTypeTest.cpp
        ast/UnaryCalculTest.cpp
        ast/ClassicOperatorTest.cpp
        ast/ArrayOperatorTest.cpp
        ast/FunctionOperatorTest.cpp
        ast/PreUnaryCalculTest.cpp
        ast/PostUnaryCalculTest.cpp
        ast/BinaryCalculTest.cpp
        ast/FunctionTest.cpp
        ast/FunctionParameterTest.cpp
        ast/LambdaTest.cpp
        ast/IfTest.cpp
        ast/SwitchTest.cpp
        ast/SwitchCaseTest.cpp
        ast/ForITest.cpp
        ast/ForIterTest.cpp
        ast/WhileTest.cpp
        ast/AssignationOperatorTest.cpp
        ast/AbstractExpressionTest.cpp
        ast/AbstractTypeTest.cpp
        ast/BlockBodyTest.cpp
        # === Environment ===
        environment/EnvironmentTest.cpp
        environment/NameTest.cpp
)
target_include_directories(unit-tests PUBLIC .)

target_link_libraries(unit-tests PRIVATE gtest_main gtest gmock compiler_lib)

gtest_discover_tests(unit-tests
        PROPERTIES LABELS "unit"
)