find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(tests gtest.cpp caches.cpp)
target_include_directories(tests PRIVATE ../LFU_cache/lib ../perfect_cache/lib)
 
target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
 
install(TARGETS tests
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
COMPONENT tests)
