aux_source_directory(./src SRC_LIST)

add_executable(lfu ${SRC_LIST})

target_include_directories(lfu
                           PRIVATE lib)
                           