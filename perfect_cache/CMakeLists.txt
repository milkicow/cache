aux_source_directory(./src SRC_LIST)

add_executable(perfect ${SRC_LIST})

target_include_directories(perfect
                           PRIVATE lib)
