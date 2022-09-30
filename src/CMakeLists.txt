add_executable(lfu cache.cpp)
add_executable(perfect perfect_cache.cpp)

target_include_directories(lfu PRIVATE ../lib)
target_include_directories(perfect PRIVATE ../lib)