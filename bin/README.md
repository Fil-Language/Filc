# Utility scripts

This directory contains scripts to help development and testing of this code

Scripts names follow a specific format to help understand what it does:

- `generate_*` -> Generate code (or something)
- `download_*` -> Download a dependency
- `check_*` -> Do some tests
- `build_*` -> Build something

All the scripts are designed to be run from root of project.

## `generate_version.sh`

Usage: `bin/generate_version.sh <version>`

Update version of project in `VERSION` and `version.svg`.

## `generate_diagram.sh`

Generate railroad diagram from `*.g4` files

## `generate_coverage.sh`

After running unit tests with `ctest`, generate test coverage using `lcov`

## `download_antlr_jar.sh`

Usage: `bin/download_antlr_jar.sh <version>`

Replace current antlr jar with a new one

## `check_no_changes.sh`

Check if there is change in git tree. If so it exits with code 1, else it exits with code 0.
