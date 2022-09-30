add_executable(tests gtest.cpp)


add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
target_link_libraries(tests 
                            PRIVATE gtest)