add_executable(tests gtest.cpp caches.cpp)
find_package(GTest REQUIRED)
#add_subdirectory(googletest)

target_include_directories(tests PRIVATE googletest/include ../LFU_cache/lib ../perfect_cache/lib)

target_link_libraries(tests PRIVATE GTest::gtest)

install(TARGETS tests
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT tests)