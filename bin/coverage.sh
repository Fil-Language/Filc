#!/bin/bash

# Check that command lcov is installed
if ! type "lcov" >/dev/null; then
  echo -e "\033[31mlcov command not found. Please install it.\033[0m"
  exit 1
fi

lcov --directory . --capture --output-file coverage.info

# Remove external files
lcov --remove coverage.info '/usr/*' '*/build/_deps/*' '*/tests/*' '*/src/main.cpp' --output-file coverage.info
# Remove tests files
lcov --remove coverage.info '*/tests/*' --output-file coverage.info
# Remove main.cpp
lcov --remove coverage.info '*/src/main.cpp' --output-file coverage.info
# Remove lib files
lcov --remove coverage.info '*/lib/cxxopts.hpp' --output-file coverage.info
# Remove antlr4 files
lcov --remove coverage.info '*antlr4*' --output-file coverage.info

lcov --list coverage.info
