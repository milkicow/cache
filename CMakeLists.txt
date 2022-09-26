cmake_minimum_required(VERSION 3.2) 

project(LFU_cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(cache cache.cpp)
add_executable(perfect_cache perfect_cache.cpp)	
