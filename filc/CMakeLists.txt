#  _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
#      Created by Kevin Traini
#
#      Fil compiler
#
#      GNU General Public License v3.0
#  _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

cmake_minimum_required(VERSION 3.10)
project(filc)

set(CMAKE_CXX_STANDARD 17)

add_executable(filc main.cpp CompilerOptions.cpp CompilerOptions.h)
