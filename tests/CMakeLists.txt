project(${PROJECT_NAME}_tests)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.3)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME} PRIVATE
               string_length.test.cpp
               to_lower.test.cpp
               to_upper.test.cpp
               words_count.test.cpp
               parse_int.test.cpp
               index_of.test.cpp
               xor.test.cpp
               )

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME})


#add_test(Test ${PROJECT_NAME})
include(${Catch2_SOURCE_DIR}/contrib/Catch.cmake)
catch_discover_tests(${PROJECT_NAME})
