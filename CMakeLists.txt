cmake_minimum_required(VERSION 3.2) 

project(LFU_cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

#add_executable(cache cache.cpp)
#add_executable(perfect_cache perfect_cache.cpp)

#add_executable(tests gtest.cpp)

add_subdirectory(src)
add_subdirectory(test)


#add_subdirectory(googletest) # add googletest subdirectory

#include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

#target_link_libraries(tests PRIVATE gtest) # link google test to this executable
