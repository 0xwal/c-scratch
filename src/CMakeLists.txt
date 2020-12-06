

add_library(${PROJECT_NAME}
            include/common.h
            include/string_length.h
            string_length.c
            )

target_include_directories(${PROJECT_NAME} PUBLIC ./include)
