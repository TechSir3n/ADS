#include <gtest/gtest.h>

#include <cassert>
#include <type_traits>

using namespace ADS;

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
