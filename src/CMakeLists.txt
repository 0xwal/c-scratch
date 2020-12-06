

add_library(${PROJECT_NAME}
            include/common.h

            include/string_length.h
            string_length.c

            include/to_lower.h
            to_lower.c

            include/to_upper.h
            to_upper.c

            include/word_count.h
            word_count.c
            )

target_include_directories(${PROJECT_NAME} PUBLIC ./include)
