

add_library(${PROJECT_NAME}
            include/common.h

            include/string_length.h
            string_length.c

            include/to_lower.h
            to_lower.c

            include/to_upper.h
            to_upper.c

            include/words_count.h
            words_count.c

            include/parse_int.h
            parse_int.c

            include/index_of.h
            index_of.c

            include/xor.h
            xor.c

            include/factorial.h
            factorial.c

            include/rc4.h
            rc4.c

            include/joaat.h
            joaat.c

            include/pow.h
            pow.c
            )

target_include_directories(${PROJECT_NAME} PUBLIC ./include)

set_target_properties(${PROJECT_NAME}
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output
                      ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output
                      )
