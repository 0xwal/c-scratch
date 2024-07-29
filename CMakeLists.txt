cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
project(scratch C)

add_subdirectory(src)

#include(CTest)
enable_testing()

add_subdirectory(tests)

add_subdirectory(demo)
