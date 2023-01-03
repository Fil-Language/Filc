# Filc

[![Tests](https://github.com/Fil-Language/Filc/actions/workflows/test.yml/badge.svg?branch=master)](https://github.com/Fil-Language/Filc/actions/workflows/test.yml)

[![wakatime](https://wakatime.com/badge/user/c1e2386d-065c-4366-b163-d98f957273dc/project/4027e072-9adb-4c9e-a1a1-52cd4d188c7d.svg)](https://wakatime.com/badge/user/c1e2386d-065c-4366-b163-d98f957273dc/project/4027e072-9adb-4c9e-a1a1-52cd4d188c7d)

Fil language compiler (version in `src/VERSION.h`)

Have used `figlet -f slant "Filc"` for the version message.

## Grammar

Refer to documentation for used grammar : [https://github.com/Fil-Language/Documentation](https://github.com/Fil-Language/Documentation).

## External dependencies

### Compiler

- [Antlr](https://www.antlr.org/)
- [Options parser : https://github.com/jarro2783/cxxopts](https://github.com/jarro2783/cxxopts)

### Tests

Tests are written with [Node.js](https://nodejs.org), you need at least version 16.

- [Colors](https://www.npmjs.com/package/colors)

## Building and Testing

If you want to build and test the compiler, please follow the steps below.

### Building

```shell
# Configure CMake in build directory
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
# Build
cmake --build ./build
```

### Testing

```shell
# Go to test directory
cd test
# Install dependencies
npm install
# Run tests
npm test
```