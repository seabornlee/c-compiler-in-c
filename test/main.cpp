#include "gtest/gtest.h"

int main(int argc, char **argv) {
    int a[10];
    a[10] = 0;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
