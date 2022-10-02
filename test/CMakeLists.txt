add_executable(tests gtest.cpp caches.cpp)
add_subdirectory(googletest)

target_include_directories(tests PRIVATE googletest/include ../LFU_cache/lib ../perfect_cache/lib)

target_link_libraries(tests PRIVATE gtest)

install(TARGETS tests
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT tests)