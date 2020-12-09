project(${PROJECT_NAME}_demo LANGUAGES C)


list(APPEND _ALL_DEMO
     string_length
     to_lower
     to_upper
     words_count
     parse_int
     index_of)

foreach (d ${_ALL_DEMO})

    add_executable(${d} "${d}.c")
    target_link_libraries(${d} PRIVATE ${CMAKE_PROJECT_NAME})

endforeach ()
