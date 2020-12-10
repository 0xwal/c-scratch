cmake_minimum_required(VERSION 3.15)

project(scratch)

add_subdirectory(src)

#include(CTest)
enable_testing()

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
add_subdirectory(demo)
