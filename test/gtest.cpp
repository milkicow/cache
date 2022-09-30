#include "gtest/gtest.h"
#include "../lib/cache.hpp"
#include "../lib/perfect_cache.hpp"
 
TEST(TestLFU_cache, TestNumber0)
{
    EXPECT_EQ(lfu::LFU_cache(), 5);
}

TEST(TestLFU_cache, TestNumber1)
{
    EXPECT_EQ(lfu::LFU_cache(), 2);
}

TEST(TestLFU_cache, TestNumber2)
{
    EXPECT_EQ(lfu::LFU_cache(), 3);
}

TEST(TestPerfect_cache, TestNumber0)
{
    EXPECT_EQ(perfect_cache::perfect_cache(), 5);
}

TEST(TestPerfect_cache, TestNumber1)
{
    EXPECT_EQ(perfect_cache::perfect_cache(), 3);
}

TEST(TestPerfect_cache, TestNumber2)
{
    EXPECT_EQ(perfect_cache::perfect_cache(), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

