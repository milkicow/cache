cmake_minimum_required(VERSION 3.2) 

project(LFU_cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_subdirectory(LFU_cache)
add_subdirectory(perfect_cache)
add_subdirectory(test)
