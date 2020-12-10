

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
            )

target_include_directories(${PROJECT_NAME} PUBLIC ./include)
