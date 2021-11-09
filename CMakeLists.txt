cmake_minimum_required(VERSION 3.15)

project(scratch C)

add_subdirectory(src)

#include(CTest)
enable_testing()

add_subdirectory(tests)

add_subdirectory(demo)
