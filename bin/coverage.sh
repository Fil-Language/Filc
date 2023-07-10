#!/bin/bash

lcov --directory . --capture --output-file coverage.info

# Remove external files
lcov --remove coverage.info '/usr/*' '*/build/_deps/*' '*/tests/*' '*/src/main.cpp' --output-file coverage.info
# Remove tests files
lcov --remove coverage.info '*/tests/*' --output-file coverage.info
# Remove main.cpp
lcov --remove coverage.info '*/src/main.cpp' --output-file coverage.info
# Remove lib files
lcov --remove coverage.info '*/lib/cxxopts.hpp' --output-file coverage.info

lcov --list coverage.info
