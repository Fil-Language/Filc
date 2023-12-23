# Filc

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![Version](version.svg)

[![Tests](https://github.com/Fil-Language/Filc/actions/workflows/tests.yml/badge.svg?branch=master)](https://github.com/Fil-Language/Filc/actions/workflows/tests.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/749c60420a9244dbac4ce1e0bd594f1e)](https://www.codacy.com/gh/Fil-Language/Filc/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Fil-Language/Filc&amp;utm_campaign=Badge_Grade)
[![codecov](https://codecov.io/gh/Fil-Language/Filc/branch/master/graph/badge.svg?token=BRT1CEUTW9)](https://codecov.io/gh/Fil-Language/Filc)

Fil language compiler (version in `src/lib/utils/VERSION.h`)

Have used `figlet -f slant "Filc"` for the version message.

## Grammar

Refer to the [diagram](src/lib/grammar/diagram.html) for used grammar.

## External dependencies

All the external dependencies are listed in [DEPENDENCIES.md](./DEPENDENCIES.md)

## Building and Testing

If you want to build and test the compiler, please follow the steps below.

### Building

```shell
# Configure CMake in build directory
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
# Build
cmake --build ./build --target filc
# Install
sudo cmake --install ./build
```

### Testing

```shell
# Configure CMake in build directory
cmake -B ./build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON -DCODE_COVERAGE=ON
# Build
cmake --build ./build
# Run tests
cd build && ctest
# Get coverage
cd - && ./bin/coverage.sh
```

## Quick note

If during compilation you got a warning with a dev code, please open an issue on GitHub with the warning message and
your code.

Dev warning are show like this :

```
DEV WARNING[<code>]: <message>
      --> <filename>
<line> | <code>
       |   ^
```

|   Dev code   | Meaning                                              | File                                   |
|:------------:|:-----------------------------------------------------|:---------------------------------------|
| <kbd>2</kbd> | Lexer found a character that is not regular          | `src/lib/ast/CharacterLiteral.cpp`     |
| <kbd>3</kdb> | A function that should not be called has been called | Several files (refer to error message) |

These codes are for events that should not happen, but if they do, it's better to fix them.

## Acknowledgements

Thanks to JetBrains for helping me develop this project by offering me
an [open source license](https://jb.gg/OpenSourceSupport)

![JetBrains Logo (Main) logo](https://resources.jetbrains.com/storage/products/company/brand/logos/jb_beam.svg)