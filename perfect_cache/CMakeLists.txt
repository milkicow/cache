aux_source_directory(./src SRC_LIST)

add_executable(perfect ${SRC_LIST})

target_include_directories(perfect
                           PRIVATE lib)

install(TARGETS perfect
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT perfect)