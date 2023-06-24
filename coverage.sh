#!/bin/bash

lcov --directory . --capture --output-file coverage.info

lcov --remove coverage.info '/usr/*' '*/build/_deps/*' --output-file coverage.info

lcov --list coverage.info
