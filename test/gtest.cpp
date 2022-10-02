#include "gtest/gtest.h"

extern int LFU();
extern int perfect();

TEST(TestLFU_cache, TestNumber0)
{
    EXPECT_EQ(LFU(), 5);
}

TEST(TestLFU_cache, TestNumber1)
{
    EXPECT_EQ(LFU(), 2);
}

TEST(TestLFU_cache, TestNumber2)
{
    EXPECT_EQ(LFU(), 3);
}

TEST(TestPerfect_cache, TestNumber0)
{
    EXPECT_EQ(perfect(), 5);
}

TEST(TestPerfect_cache, TestNumber1)
{
    EXPECT_EQ(perfect(), 3);
}

TEST(TestPerfect_cache, TestNumber2)
{
    EXPECT_EQ(perfect(), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
