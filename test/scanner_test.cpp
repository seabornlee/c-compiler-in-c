
#include "gtest/gtest.h"

TEST(ScannerTest, shouldGetNextToken) {
    EXPECT_EQ(18.0, 18.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
