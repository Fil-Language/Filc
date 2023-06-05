# Filc

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Tests](https://github.com/Fil-Language/Filc/actions/workflows/test.yml/badge.svg?branch=master)](https://github.com/Fil-Language/Filc/actions/workflows/test.yml)
![Version](version.svg)

[![CodeFactor](https://www.codefactor.io/repository/github/fil-language/filc/badge)](https://www.codefactor.io/repository/github/fil-language/filc)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/749c60420a9244dbac4ce1e0bd594f1e)](https://www.codacy.com/gh/Fil-Language/Filc/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Fil-Language/Filc&amp;utm_campaign=Badge_Grade)

Fil language compiler (version in `src/VERSION.h`)

Have used `figlet -f slant "Filc"` for the version message.

## Grammar

Refer to documentation for used
grammar : [https://fil.ktraini.com/doc/advanced/grammar](https://fil.ktraini.com/doc/advanced/grammar).

## External dependencies

### Compiler

- [LLVM](https://llvm.org/)
- [Antlr](https://www.antlr.org/)
- [Options parser : https://github.com/jarro2783/cxxopts](https://github.com/jarro2783/cxxopts)

### Tests

- [GoogleTest](https://google.github.io/googletest/)

### GitHub actions

- [Checkout](https://github.com/marketplace/actions/checkout)
- [Install LLVM and Clang](https://github.com/marketplace/actions/install-llvm-and-clang)
- [Codacy coverage report](https://github.com/codacy/codacy-coverage-reporter-action)

### `version.sh`

This script is used to update the version badge and the file `src/VERSION.h`.

- [HTTPie](https://github.com/httpie/httpie)

## Building and Testing

If you want to build and test the compiler, please follow the steps below.

### Building

```shell
# Configure CMake in build directory
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
# Build
cmake --build ./build --target filc
```

### Testing

```shell
# Configure CMake in build directory
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
# Run tests
cmake --build ./build --target tests
```

## Quick note

If during compilation you got a warning with a dev code, please open an issue on GitHub with the warning message and
your code.

|   Dev code   | Meaning                                                          |           File            |
|:------------:|------------------------------------------------------------------|:-------------------------:|
| <kbd>2</kbd> | A module was not imported during part A, and no error was raised | `src/fil/ast/Program.cpp` |

These codes are for events that should not happen, but if they do, it's better to fix them.