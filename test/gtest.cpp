#include "gtest/gtest.h"
#include <fstream>

extern int LFU(std::ifstream &file);
extern int perfect(std::ifstream &file);

std::string concat(std::string str)
{
    return PROJECT_DIR_PATH + str;
}

TEST(TestLFU_cache, TestNumber0)
{   
    std::ifstream file(concat("/test/TestLFU0.txt"));
    EXPECT_EQ(LFU(file), 5);
    file.close();
}

TEST(TestLFU_cache, TestNumber1)
{
    std::ifstream file(concat("/test/TestLFU1.txt"));
    EXPECT_EQ(LFU(file), 2);
    file.close();
}

TEST(TestLFU_cache, TestNumber2)
{
    std::ifstream file(concat("/test/TestLFU2.txt"));
    EXPECT_EQ(LFU(file), 3);
    file.close();
}

TEST(TestPerfect_cache, TestNumber0)
{
    std::ifstream file(concat("/test/Testperf0.txt"));
    EXPECT_EQ(perfect(file), 5);
    file.close();
}

TEST(TestPerfect_cache, TestNumber1)
{
    std::ifstream file(concat("/test/Testperf1.txt"));
    EXPECT_EQ(perfect(file), 4);
    file.close();
}

TEST(TestPerfect_cache, TestNumber2)
{
    std::ifstream file(concat("/test/Testperf2.txt"));
    EXPECT_EQ(perfect(file), 7);
    file.close();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
